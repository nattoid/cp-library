#pragma once

/**
 * @file factorize.hpp
 * @brief
 * 素数判定、素因数分解、約数列挙、オイラーのφ関数などを提供する整数論ライブラリ
 * @see https://andantesoft.hatenablog.com/entry/2025/05/21/164352
 * @see https://judge.yosupo.jp/submission/189742
 */

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <utility>
#include <vector>

#include "modular.hpp"

namespace nt {

/** @cond INTERNAL */
namespace internal {

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

}  // namespace internal
/** @endcond */

/**
 * @brief Miller-Rabin素数判定法 (モンゴメリ乗算版)
 */
inline bool is_prime(ll n_) {
    if (n_ <= 1) return false;
    u64 n = n_;
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return false;

    Montgomery m(n);
    u64 d = n - 1;
    int s = __builtin_ctzll(d);
    d >>= s;

    u64 one = m.one();
    u64 minus_one = n - one;
    u64 r2 = m.r2();

    auto check = [&](const auto& bases) {
        for (u64 a : bases) {
            if (n <= a) break;
            u64 a_mont = m.mul(a, r2);
            u64 x = m.pow(a_mont, d, one);
            if (x == one || x == minus_one) continue;
            bool composite = true;
            for (int r = 1; r < s; r++) {
                x = m.norm(m.mul(x, x));
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
        static constexpr u64 bases_small[] = {2, 7, 61};
        return check(bases_small);
    } else {
        static constexpr u64 bases_large[] = {2, 325, 9375, 28178,
                                              450775, 9780504, 1795265022};
        return check(bases_large);
    }
}

/**
 * @brief Pollard's rhoアルゴリズムによる素因数探索
 */
inline ll pollard_rho(ll n_) {
    assert(n_ > 1);
    u64 n = n_;
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;

    using internal::gcd_stein;
    const Montgomery m(n);

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

// factorize, divisors_from_factors, divisors, phi
// は変更なしのため省略せずそのまま維持
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

inline std::vector<ll> divisors(ll n) {
    if (n <= 0) return {};
    return divisors_from_factors(factorize(n));
}

inline ll phi(ll n) {
    if (n <= 0) return 0;
    ll res = n;
    for (const auto& [p, e] : factorize(n)) {
        res -= res / p;
    }
    return res;
}

}  // namespace nt