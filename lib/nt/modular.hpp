#pragma once
#include <utility>
#include <cassert>
#include <cstdint>

namespace nt {

using ll = long long;
using u64 = __uint64_t;
using u128 = __uint128_t;

// O(log min(a, m)) でモジュラ逆元を求める (gcd(a, m) == 1 を仮定)
inline ll inv_mod(ll a, ll m) {
    assert(m > 0);
    a %= m;
    if (a < 0) a += m;
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
    }
    assert(a == 1);
    u %= m;
    if (u < 0) u += m;
    return u;
}

// O(log n) で a^n mod m を計算
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

} // namespace nt