#pragma once
#include <cassert>
#include <cstdint>

#include "modular.hpp"  // pow_modを使用

namespace nt {

// a の平方剰余 mod p を求める (Tonelli-Shanks algorithm)
// 存在しない場合は -1 を返す。p は素数を仮定。
inline long long mod_sqrt(long long a, long long p) {
    assert(0 <= a && a < p);
    if (a == 0) return 0;
    if (p == 2) return a;

    if (pow_mod(a, (p - 1) >> 1, p) != 1) return -1;

    long long b = 1;
    while (pow_mod(b, (p - 1) >> 1, p) == 1) {
        b++;
    }

    long long m = p - 1, e = 0;
    while (m % 2 == 0) {
        m >>= 1;
        e++;
    }

    long long x = pow_mod(a, (m + 1) >> 1, p);
    long long y = pow_mod(a, m, p);
    long long z = pow_mod(b, m, p);

    while (y != 1) {
        long long j = 0;
        long long t = y;
        while (t != 1) {
            j++;
            t = (long long)((__uint128_t)t * t % p);
        }

        long long z_pow = z;
        for (long long i = 0; i < e - j - 1; i++) {
            z_pow = (long long)((__uint128_t)z_pow * z_pow % p);
        }

        x = (long long)((__uint128_t)x * z_pow % p);
        z = (long long)((__uint128_t)z_pow * z_pow % p);
        y = (long long)((__uint128_t)y * z % p);
        e = j;
    }
    return x;
}

}  // namespace nt