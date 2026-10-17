/**
 * @file mod_sqrt.hpp
 * @brief 平方剰余 (Tonelli-Shanks algorithm)
 * @see https://nyaannyaan.github.io/library/modulo/mod-sqrt.hpp
 */

#pragma once
#include <cassert>
#include <cstdint>

#include "modular.hpp"

namespace nt {

/**
 * @brief x^2 = a (mod p) を満たす x を1つ求める (Tonelli-Shanks)
 * @param a 真数
 * @param p 素数 (p >= 2, p < 2^62)
 * @return ll 解 x (0 <= x < p, 存在しない場合は -1)
 * @note 計算量: O(log^2 p) (モンゴメリ乗算により定数倍高速)
 */
inline ll mod_sqrt(ll a, ll p) {
    assert(p >= 2);
    a %= p;
    if (a < 0) a += p;
    if (a == 0) return 0;
    if (p == 2) return a;

    Montgomery m(p);
    u64 one = m.one();
    u64 minus_one = p - one;
    u64 r2 = m.r2();

    u64 a_mont = m.mul(a, r2);
    if (m.pow(a_mont, (p - 1) >> 1, one) != one) return -1;

    // p == 3 (mod 4) の場合は a^{(p+1)/4} mod p が直ちに解となる
    if ((p & 3) == 3) {
        u64 x_mont = m.pow(a_mont, (p + 1) >> 2, one);
        return m.mul(x_mont, 1);
    }

    // 非平方剰余 b を探す
    u64 b_mont = one;
    for (u64 b = 2;; b++) {
        b_mont = m.mul(b, r2);
        if (m.pow(b_mont, (p - 1) >> 1, one) == minus_one) break;
    }

    u64 q = p - 1;
    int e = __builtin_ctzll(q);
    q >>= e;

    u64 x = m.pow(a_mont, (q + 1) >> 1, one);
    u64 y = m.pow(a_mont, q, one);
    u64 z = m.pow(b_mont, q, one);

    while (y != one) {
        int j = 0;
        u64 t = y;
        while (t != one) {
            j++;
            t = m.norm(m.mul(t, t));
        }

        u64 z_pow = z;
        for (int i = 0; i < e - j - 1; i++) {
            z_pow = m.mul(z_pow, z_pow);
        }
        z_pow = m.norm(z_pow);

        x = m.norm(m.mul(x, z_pow));
        z = m.norm(m.mul(z_pow, z_pow));
        y = m.norm(m.mul(y, z));
        e = j;
    }

    return m.mul(x, 1);  // モンゴメリ空間から通常の空間へ戻す (常に [0, p) に収まる)
}

}  // namespace nt