#pragma once

/**
 * @file discrete_log.hpp
 * @brief 離散対数問題 (Extended Baby-step Giant-step)
 */

#include <cassert>
#include <cmath>
#include <cstdint>
#include <numeric>
#include <vector>

#include "modular.hpp"

namespace nt {

/** @cond INTERNAL */
namespace internal {

// BSGS用の高速オープンアドレスハッシュテーブル (値の上書き対応)
struct FastHashMap {
    int cap, mask;
    std::vector<u64> keys;
    std::vector<int> vals;
    std::vector<bool> used;

    FastHashMap(int max_elements) {
        cap = 8;
        while (cap < max_elements * 2) cap <<= 1;
        mask = cap - 1;
        keys.resize(cap);
        vals.resize(cap);
        used.assign(cap, false);
    }

    static inline u64 hash(u64 x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    inline void insert(u64 k, int v) {
        int i = hash(k) & mask;
        while (used[i] && keys[i] != k) {
            i = (i + 1) & mask;
        }
        keys[i] = k;
        vals[i] = v;  // より大きい j で上書きすることで i*step - j を最小化
        used[i] = true;
    }

    inline int find(u64 k) const {
        int i = hash(k) & mask;
        while (used[i]) {
            if (keys[i] == k) return vals[i];
            i = (i + 1) & mask;
        }
        return -1;
    }
};

}  // namespace internal
/** @endcond */

/**
 * @brief 離散対数問題 a^x = b (mod m) を満たす最小の x を求める (exBSGS)
 * @param a 底
 * @param b 真数
 * @param m 法 (m >= 1)
 * @param allow_zero x = 0 を解として許容するか (デフォルト: true, 0^0 = 1
 * と定義)
 * @return ll 条件を満たす最小の x (存在しない場合は -1)
 * @note 計算量: 時間・空間ともに O(sqrt(m))
 */
inline ll discrete_log(ll a, ll b, ll m, bool allow_zero = true) {
    assert(m >= 1);
    if (m == 1) return allow_zero ? 0 : 1;

    a %= m;
    if (a < 0) a += m;
    b %= m;
    if (b < 0) b += m;

    if (allow_zero && b == 1) return 0;
    if (a == 0) {
        if (b == 0) return 1;
        return -1;
    }

    // 1. gcd(a, m) > 1 の間、因子を括り出して互いに素な問題に帰着させる
    ll k = 0, c = 1 % m;
    while (true) {
        if ((allow_zero || k > 0) && c == b) return k;
        ll g = std::gcd(a, m);
        if (g == 1) break;
        if (b % g != 0) return -1;
        b /= g;
        m /= g;
        c = (ll)((u128)c * (a / g) % m);
        k++;
    }

    // 2. c * a^{x - k} = b (mod m) を BSGS で解く (gcd(a, m) == 1)
    // x - k = i * step - j (1 <= i <= step, 0 <= j < step) とおく
    // c * (a^step)^i = b * a^j (mod m)
    ll step = std::sqrtl(m) + 1;
    internal::FastHashMap mp(step);

    ll cur = b;
    for (int j = 0; j < step; j++) {
        mp.insert(cur, j);
        cur = (ll)((u128)cur * a % m);
    }

    ll a_step = pow_mod(a, step, m);
    cur = c;
    for (ll i = 1; i <= step; i++) {
        cur = (ll)((u128)cur * a_step % m);
        int j = mp.find(cur);
        if (j != -1) {
            return i * step - j + k;
        }
    }

    return -1;
}

}  // namespace nt