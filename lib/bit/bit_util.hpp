#include <bit>
#include <concepts>

// 立っているビット数が同じで、次に大きい値を返す（Gosper's Hack）
template <std::unsigned_integral T>
constexpr T next_combination(T v) {
    if (v == 0) return 0;
    T c = v & -v;
    T r = v + c;
    return (((r ^ v) >> 2) >> std::countr_zero(v)) | r;
}

// 整数からグレイコードへの変換
template <std::unsigned_integral T>
constexpr T to_gray(T n) {
    return n ^ (n >> 1);
}

// グレイコードから元の整数への復元
template <std::unsigned_integral T>
constexpr T from_gray(T g) {
    T n = 0;
    for (; g; g >>= 1) {
        n ^= g;
    }
    return n;
}