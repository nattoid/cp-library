/**
 * @file factorize.hpp
 * @brief
 * 素数判定、素因数分解、約数列挙、オイラーのφ関数などを提供する整数論ライブラリ
 * @see https://andantesoft.hatenablog.com/entry/2025/05/21/164352
 * @see https://judge.yosupo.jp/submission/189742
 */

#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <utility>
#include <vector>

#include "modular.hpp"

namespace nt {

/** @cond INTERNAL */
namespace internal {

using u64 = uint64_t;
using u128 = __uint128_t;

// Binary GCD (Stein's algorithm)
inline u64 gcd_stein(u64 x, u64 y) {
    if (x == 0) return y;
    if (y == 0) return x;
    int n = __builtin_ctzll(x);
    int m = __builtin_ctzll(y);
    x >>= n;
    y >>= m;
    while (x != y) {
        int s = __builtin_ctzll(x - y);
        bool f = x > y;
        u64 max_v = f ? x : y;
        y = f ? y : x;
        x = (max_v - y) >> s;
    }
    return x << (n < m ? n : m);
}

// 64bit 減算型遅延モンゴメリ演算器 (mod < 2^62 かつ奇数)
struct Montgomery {
    u64 mod;
    u64 minv;  // mod * minv == 1 (mod 2^64)

    Montgomery(u64 n) : mod(n), minv(n) {
        for (int i = 0; i < 5; i++) minv *= 2 - mod * minv;
    }

    inline u64 fma(u64 a, u64 b, u64 c) const {
        u128 d = u128(a) * b;
        u64 e = c + mod + (d >> 64);
        u64 f = u64(d) * minv;
        u64 g = (u128(f) * mod) >> 64;
        return e - g;
    }

    inline u64 mul(u64 a, u64 b) const {
        return fma(a, b, 0);
    }
};

}  // namespace internal
/** @endcond */

/**
 * @brief Miller-Rabin素数判定法 (モンゴメリ乗算版)
 * @param n_ 判定する整数
 * @return true 素数である
 * @return false 合成数である、または1以下
 * @note 計算量: O(log N)
 */
inline bool is_prime(ll n_) {
    if (n_ <= 1) return false;
    internal::u64 n = n_;
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return false;

    internal::Montgomery m(n);
    internal::u64 d = n - 1;
    int s = __builtin_ctzll(d);
    d >>= s;

    // モンゴメリ空間における 1 と n - 1、および変換用定数 R^2 mod n
    internal::u64 one = (-n) % n;
    internal::u64 minus_one = n - one;
    internal::u64 r2 = (-internal::u128(n)) % n;

    auto mod_pow_mont = [&](internal::u64 a_mont, internal::u64 exp) {
        internal::u64 res = one;
        while (exp > 0) {
            if (exp & 1) res = m.mul(res, a_mont);
            a_mont = m.mul(a_mont, a_mont);
            exp >>= 1;
        }
        return res >= n ? res - n : res;
    };

    auto check = [&](const auto& bases) {
        for (internal::u64 a : bases) {
            if (n <= a) break;
            internal::u64 a_mont = m.mul(a, r2);
            internal::u64 x = mod_pow_mont(a_mont, d);
            if (x == one || x == minus_one) continue;
            bool composite = true;
            for (int r = 1; r < s; r++) {
                x = m.mul(x, x);
                if (x >= n) x -= n;
                if (x == one) return false;
                if (x == minus_one) {
                    composite = false;
                    break;
                }
            }
            if (composite) return false;
        }
        return true;
    };

    if (n < 4759123141ULL) {
        static constexpr internal::u64 bases_small[] = {2, 7, 61};
        return check(bases_small);
    } else {
        static constexpr internal::u64 bases_large[] = {
            2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        return check(bases_large);
    }
}

/**
 * @brief Pollard's rhoアルゴリズムによる素因数探索
 * @param n_ 素因数を探す対象の整数 (合成数であることを前提とする)
 * @return ll 見つかった素因数 (n_ の非自明な約数)
 * @note 計算量: 期待値 O(N^{1/4})
 */
inline ll pollard_rho(ll n_) {
    assert(n_ > 1);
    internal::u64 n = n_;
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;

    using internal::gcd_stein;
    using internal::u64;
    const internal::Montgomery m(n);

    constexpr u64 C1 = 1, C2 = 2, M = 512;
    u64 Z1 = 1, Z2 = 2;

retry:
    u64 z1 = Z1, z2 = Z2;
    for (size_t k = M;; k *= 2) {
        const u64 x1 = z1 + n;
        const u64 x2 = z2 + n;
        for (size_t j = 0; j < k; j += M) {
            const u64 y1 = z1;
            const u64 y2 = z2;

            u64 q1 = 1, q2 = 2;
            z1 = m.fma(z1, z1, C1);
            z2 = m.fma(z2, z2, C2);
            for (size_t i = 0; i < M; ++i) {
                u64 t1 = x1 - z1;
                u64 t2 = x2 - z2;
                z1 = m.fma(z1, z1, C1);
                z2 = m.fma(z2, z2, C2);
                q1 = m.mul(q1, t1);
                q2 = m.mul(q2, t2);
            }
            q1 = m.mul(q1, x1 - z1);
            q2 = m.mul(q2, x2 - z2);

            u64 q3 = m.mul(q1, q2);
            u64 g3 = gcd_stein(n, q3);
            if (g3 == 1) continue;
            if (g3 != n) return g3;

            u64 g1 = gcd_stein(n, q1);
            u64 g2 = gcd_stein(n, q2);

            u64 C = g1 != 1 ? C1 : C2;
            u64 x = g1 != 1 ? x1 : x2;
            u64 z = g1 != 1 ? y1 : y2;
            u64 g = g1 != 1 ? g1 : g2;

            if (g == n) {
                do {
                    z = m.fma(z, z, C);
                    g = gcd_stein(n, x - z);
                } while (g == 1);
            }
            if (g != n) return g;

            Z1 += 2;
            Z2 += 2;
            goto retry;
        }
    }
}

/**
 * @brief 高速素因数分解
 * @param n 分解する整数
 * @return std::vector<std::pair<ll, int>> (素因数, 指数)
 * のペアを素因数の昇順に格納した配列
 * @note 計算量: 期待値 O(N^{1/4})
 */
inline std::vector<std::pair<ll, int>> factorize(ll n) {
    std::vector<std::pair<ll, int>> res;
    if (n <= 1) return res;

    int cnt2 = __builtin_ctzll(n);
    if (cnt2 > 0) {
        res.emplace_back(2, cnt2);
        n >>= cnt2;
    }
    if (n == 1) return res;

    std::vector<ll> primes;
    auto dfs = [&](auto self, ll m) -> void {
        if (m <= 1) return;
        if (is_prime(m)) {
            primes.push_back(m);
            return;
        }
        ll d = pollard_rho(m);
        self(self, d);
        self(self, m / d);
    };
    dfs(dfs, n);
    std::sort(primes.begin(), primes.end());

    ll cur = primes[0];
    int cnt = 1;
    for (size_t i = 1; i < primes.size(); i++) {
        if (primes[i] == cur) {
            cnt++;
        } else {
            res.emplace_back(cur, cnt);
            cur = primes[i];
            cnt = 1;
        }
    }
    res.emplace_back(cur, cnt);
    return res;
}

/**
 * @brief 素因数分解の結果から約数を列挙する
 * @tparam T 整数型
 * @param factors factorize() 等で得られた (素因数, 指数) の配列
 * @return std::vector<T> 約数を昇順にソートした配列
 */
template <typename T>
inline std::vector<T> divisors_from_factors(
    const std::vector<std::pair<T, int>>& factors) {
    size_t sz = 1;
    for (const auto& [p, e] : factors) sz *= (e + 1);
    std::vector<T> res;
    res.reserve(sz);
    res.push_back(1);

    for (const auto& [p, e] : factors) {
        size_t cur_sz = res.size();
        T p_pow = 1;
        for (int i = 1; i <= e; i++) {
            p_pow *= p;
            for (size_t j = 0; j < cur_sz; j++) {
                res.push_back(res[j] * p_pow);
            }
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

/**
 * @brief 単一の整数の約数を昇順に列挙する
 * @param n 対象の整数
 * @return std::vector<ll> 約数を昇順にソートした配列
 * @note 計算量: 期待値 O(N^{1/4} + D log D) (Dは約数の個数)
 */
inline std::vector<ll> divisors(ll n) {
    if (n <= 0) return {};
    return divisors_from_factors(factorize(n));
}

/**
 * @brief オイラーのφ関数
 * @details nと互いに素な1以上n以下の整数の個数を求める
 * @param n 対象の整数
 * @return ll φ(n) の値
 * @note 計算量: 期待値 O(N^{1/4})
 */
inline ll phi(ll n) {
    if (n <= 0) return 0;
    ll res = n;
    for (const auto& [p, e] : factorize(n)) {
        res -= res / p;
    }
    return res;
}

}  // namespace nt