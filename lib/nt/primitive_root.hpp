/**
 * @file primitive_root.hpp
 * @brief 乗法位数 (Order) と原始根 (Primitive Root) の探索
 */

#pragma once
#include <cassert>
#include <cstdint>
#include <numeric>
#include <utility>
#include <vector>

#include "factorize.hpp"
#include "modular.hpp"

namespace nt {

/**
 * @brief 法 m における a の乗法位数 ord_m(a) を求める (前計算利用版)
 * @param a 底
 * @param m 法 (m >= 1)
 * @param phi_m オイラーのφ関数値 phi(m)
 * @param phi_factors phi(m) の素因数分解リスト
 * @return ll a^k = 1 (mod m) を満たす最小の正整数 k (gcd(a, m) != 1 の場合は 0)
 */
inline ll order(ll a, ll m, ll phi_m,
                const std::vector<std::pair<ll, int>>& phi_factors) {
    assert(m >= 1);
    if (m == 1) return 1;
    a %= m;
    if (a < 0) a += m;
    if (std::gcd(a, m) != 1) return 0;

    ll res = phi_m;
    if (m & 1) {
        Montgomery mont(m);
        u64 one = mont.one();
        u64 a_mont = mont.mul(a, mont.r2());
        for (const auto& [p, e] : phi_factors) {
            while (res % p == 0 && mont.pow(a_mont, res / p, one) == one) {
                res /= p;
            }
        }
    } else {
        for (const auto& [p, e] : phi_factors) {
            while (res % p == 0 && pow_mod(a, res / p, m) == 1) {
                res /= p;
            }
        }
    }
    return res;
}

/**
 * @brief 法 m における a の乗法位数 ord_m(a) を求める
 * @param a 底 (gcd(a, m) == 1 でない場合は 0 を返す)
 * @param m 法 (m >= 1)
 * @return ll a^k = 1 (mod m) を満たす最小の正整数 k (存在しない場合は 0)
 * @note 計算量: 期待値 O(m^{1/4})
 */
inline ll order(ll a, ll m) {
    assert(m >= 1);
    if (m == 1) return 1;
    a %= m;
    if (a < 0) a += m;
    if (std::gcd(a, m) != 1) return 0;

    ll phi_m = phi(m);
    auto phi_factors = factorize(phi_m);
    return order(a, m, phi_m, phi_factors);
}

/**
 * @brief 素数 p に対する最小の原始根を求める
 * (減算型遅延モンゴメリ乗算による高速版)
 * @param p 素数 (p >= 2)
 * @return ll 最小の原始根
 * @note 計算量: 期待値 O((p - 1)^{1/4})
 */
inline ll primitive_root_prime(ll p) {
    assert(p >= 2);
    if (p == 2) return 1;
    if (p == 998244353) return 3;

    auto factors = factorize(p - 1);
    std::vector<u64> exps;
    exps.reserve(factors.size());
    for (const auto& [q, e] : factors) {
        exps.push_back((p - 1) / q);
    }

    Montgomery m(p);
    u64 one = m.one();
    u64 r2 = m.r2();

    for (u64 g = 2;; g++) {
        u64 g_mont = m.mul(g, r2);
        bool ok = true;
        for (u64 exp : exps) {
            if (m.pow(g_mont, exp, one) == one) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

/**
 * @brief 一般の正整数 n に対する最小の原始根を求める
 * @details 原始根が存在する n (n = 1, 2, 4, p^k, 2p^k (pは奇素数))
 * に対して最小の原始根を返す
 * @param n 対象の正整数 (n >= 1)
 * @return ll 最小の原始根 (存在しない場合は -1)
 * @note 計算量: 期待値 O(n^{1/4})
 */
inline ll primitive_root(ll n) {
    assert(n >= 1);
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 4) return 3;
    if (is_prime(n)) return primitive_root_prime(n);

    // 原始根の存在判定: n = p^k または 2*p^k (pは奇素数)
    ll m = n;
    if ((m & 1) == 0) {
        m >>= 1;
        if ((m & 1) == 0) return -1;  // 4より大きい4の倍数は原始根を持たない
    }

    auto factors_m = factorize(m);
    if (factors_m.size() != 1) {
        return -1;  // 異なる2つ以上の奇素数で割れる場合は存在しない
    }

    ll p = factors_m[0].first;
    ll phi_n = (m / p) * (p - 1);

    // phi(n) の素因数リストを作成 (p と p-1 の素因数)
    auto factors_phi = factorize(p - 1);
    std::vector<u64> exps;
    exps.reserve(factors_phi.size() + 1);
    if (factors_m[0].second >= 2) {
        exps.push_back(phi_n / p);
    }
    for (const auto& [q, e] : factors_phi) {
        exps.push_back(phi_n / q);
    }

    // n = p^k または n = 2*p^k のいずれであっても、
    // 奇数の法 m = p^k 上での位数が phi(n) == phi(m) に一致するかをモンゴメリ乗算で判定できる！
    Montgomery mont(m);
    u64 one = mont.one();
    u64 r2 = mont.r2();
    u64 step = (n & 1) ? 1 : 2;
    u64 start = (n & 1) ? 2 : 3;

    for (u64 g = start;; g += step) {
        if (g % p == 0) continue;
        u64 g_mont = mont.mul(g % m, r2);
        bool ok = true;
        for (u64 exp : exps) {
            if (mont.pow(g_mont, exp, one) == one) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

}  // namespace nt