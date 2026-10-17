/**
 * @file modular.hpp
 * @brief モジュラ演算、拡張ユークリッドの互除法、中国剰余定理 (CRT)
 */

#pragma once
#include <cassert>
#include <cstdint>
#include <tuple>
#include <utility>
#include <vector>

namespace nt {

using ll = long long;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

/**
 * @brief 拡張ユークリッドの互除法 (非再帰)
 * @details a*x + b*y = g = gcd(|a|, |b|) となる (g, x, y) を求める
 * @param a 整数
 * @param b 整数
 * @return std::tuple<ll, ll, ll> {g, x, y} (g >= 0)
 * @note 計算量: O(log min(|a|, |b|))
 */
inline std::tuple<ll, ll, ll> extgcd(ll a, ll b) {
    ll x = 1, y = 0, x1 = 0, y1 = 1;
    ll a1 = a, b1 = b;
    while (b1 != 0) {
        ll q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }
    if (a1 < 0) {
        a1 = -a1;
        x = -x;
        y = -y;
    }
    return {a1, x, y};
}

/**
 * @brief 拡張ユークリッドの互除法 (参照渡し版)
 */
inline ll extgcd(ll a, ll b, ll& x, ll& y) {
    auto [g, u, v] = extgcd(a, b);
    x = u;
    y = v;
    return g;
}

/**
 * @brief モジュラ逆元を求める (gcd(a, m) == 1 を仮定)
 * @note 計算量: O(log min(a, m))
 */
inline ll inv_mod(ll a, ll m) {
    assert(m > 0);
    a %= m;
    if (a < 0) a += m;
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
    }
    assert(a == 1);
    u %= m;
    if (u < 0) u += m;
    return u;
}

/**
 * @brief a^n mod m を計算する
 * @note 計算量: O(log n)
 */
inline ll pow_mod(ll a, ll n, ll m) {
    assert(n >= 0 && m > 0);
    if (m == 1) return 0;
    ll res = 1;
    a %= m;
    if (a < 0) a += m;
    while (n > 0) {
        if (n & 1) res = (ll)((u128)res * a % m);
        a = (ll)((u128)a * a % m);
        n >>= 1;
    }
    return res;
}

/**
 * @brief 中国剰余定理 (2変数版)
 * @details x = r1 (mod m1), x = r2 (mod m2) を満たす x = r (mod lcm(m1, m2))
 * を求める
 * @return std::pair<ll, ll> {r, lcm(m1, m2)} (解なしの場合は {0, 0})
 * @note lcm(m1, m2) が ll に収まることを前提とする
 */
inline std::pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    assert(m1 >= 1 && m2 >= 1);
    r1 %= m1;
    if (r1 < 0) r1 += m1;
    r2 %= m2;
    if (r2 < 0) r2 += m2;

    auto [g, p, q] = extgcd(m1, m2);
    if ((r2 - r1) % g != 0) return {0, 0};

    ll u = m2 / g;
    ll t = (ll)((i128)(r2 - r1) / g % u * p % u);
    if (t < 0) t += u;

    ll lcm = m1 * u;
    ll r = r1 + (ll)((i128)t * m1 % lcm);
    if (r >= lcm) r -= lcm;
    return {r, lcm};
}

/**
 * @brief 中国剰余定理 (配列版)
 * @details x = r[i] (mod m[i]) をすべて満たす x = rem (mod lcm) を求める
 * @return std::pair<ll, ll> {rem, lcm} (解なしの場合は {0, 0}, 空配列の場合は
 * {0, 1})
 */
inline std::pair<ll, ll> crt(const std::vector<ll>& r,
                             const std::vector<ll>& m) {
    assert(r.size() == m.size());
    ll r0 = 0, m0 = 1;
    for (size_t i = 0; i < r.size(); i++) {
        auto [r1, m1] = crt(r0, m0, r[i], m[i]);
        if (m1 == 0) return {0, 0};
        r0 = r1;
        m0 = m1;
    }
    return {r0, m0};
}

}  // namespace nt