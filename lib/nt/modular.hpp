/**
 * @file modular.hpp
 * @brief モジュラ演算、64bit減算型遅延モンゴメリ演算器、extgcd、CRT
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
 * @brief 64bit 減算型遅延モンゴメリ演算器 (mod < 2^62 かつ奇数)
 * @details 値域 [0, 2*mod)
 * で遅延評価を行う。コンストラクタは除算を含まず極めて高速。
 */
struct Montgomery {
    u64 mod;
    u64 minv;  // mod * minv == 1 (mod 2^64)

    constexpr Montgomery(u64 n) : mod(n), minv(n) {
        assert((n & 1) == 1);
        for (int i = 0; i < 5; i++) minv *= 2 - mod * minv;
    }

    // モンゴメリ空間における 1 (R mod n)
    inline u64 one() const {
        return (-mod) % mod;
    }

    // モンゴメリ変換用定数 R^2 mod n
    inline u64 r2() const {
        return (-u128(mod)) % mod;
    }

    // (a * b + c) * R^{-1} mod n (出力は [0, 2*mod))
    inline u64 fma(u64 a, u64 b, u64 c) const {
        u128 d = u128(a) * b;
        u64 e = c + mod + (d >> 64);
        u64 f = u64(d) * minv;
        u64 g = (u128(f) * mod) >> 64;
        return e - g;
    }

    // a * b * R^{-1} mod n (出力は [0, 2*mod))
    inline u64 mul(u64 a, u64 b) const {
        return fma(a, b, 0);
    }

    // [0, 2*mod) -> [0, mod) への正規化
    inline u64 norm(u64 a) const {
        return a >= mod ? a - mod : a;
    }

    // モンゴメリ空間上でのべき乗 a_mont^exp (出力は正規化済み [0, mod))
    inline u64 pow(u64 a_mont, u64 exp, u64 one_mont) const {
        u64 res = one_mont;
        while (exp > 0) {
            if (exp & 1) res = mul(res, a_mont);
            a_mont = mul(a_mont, a_mont);
            exp >>= 1;
        }
        return norm(res);
    }
};

/**
 * @brief 拡張ユークリッドの互除法 (非再帰)
 * @details a*x + b*y = g = gcd(|a|, |b|) となる (g, x, y) を求める
 */
inline std::tuple<ll, ll, ll> extgcd(ll a, ll b) {
    ll x = 1, y = 0, x1 = 0, y1 = 1;
    while (b != 0) {
        ll q = a / b;
        ll a2 = a - q * b;
        a = b;
        b = a2;
        ll x2 = x - q * x1;
        x = x1;
        x1 = x2;
        ll y2 = y - q * y1;
        y = y1;
        y1 = y2;
    }
    if (a < 0) {
        a = -a;
        x = -x;
        y = -y;
    }
    return {a, x, y};
}

inline ll extgcd(ll a, ll b, ll& x, ll& y) {
    auto [g, u, v] = extgcd(a, b);
    x = u;
    y = v;
    return g;
}

/**
 * @brief モジュラ逆元を求める (gcd(a, m) == 1 を仮定)
 */
inline ll inv_mod(ll a, ll m) {
    assert(m > 0);
    auto [g, x, y] = extgcd(a, m);
    assert(g == 1);
    return x < 0 ? x + m : x;
}

/**
 * @brief a^n mod m を計算する
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
    ll r = r1 + t * m1;
    return {r, lcm};
}

/**
 * @brief 中国剰余定理 (配列版)
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