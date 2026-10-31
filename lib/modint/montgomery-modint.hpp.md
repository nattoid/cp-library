---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/fps/arbitrary-fps.hpp
    title: lib/fps/arbitrary-fps.hpp
  - icon: ':warning:'
    path: lib/fps/fps-circular.hpp
    title: "\u4E09\u89D2\u95A2\u6570"
  - icon: ':warning:'
    path: lib/ntt/arbitrary-ntt.hpp
    title: lib/ntt/arbitrary-ntt.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/modint/montgomery-modint.hpp\"\n#include <cstdint>\n\
    \ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    static constexpr u32 get_r() {\n        u32 ret = mod;\n        for (i32\
    \ i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n        return ret;\n    }\n\n   \
    \ static constexpr u32 r = get_r();\n    static constexpr u32 n2 = -u64(mod) %\
    \ mod;\n    static_assert(mod < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n    static_assert((mod\
    \ & 1) == 1, \"invalid, mod % 2 == 0\");\n    static_assert(r * mod == 1, \"this\
    \ code has bugs.\");\n\n    u32 a;\n\n    constexpr LazyMontgomeryModInt() : a(0)\
    \ {\n    }\n    constexpr LazyMontgomeryModInt(const int64_t& b)\n        : a(reduce(u64(b\
    \ % mod + mod) * n2)) {};\n\n    static constexpr u32 reduce(const u64& b) {\n\
    \        return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n    }\n\n    constexpr\
    \ mint& operator+=(const mint& b) {\n        if (i32(a += b.a - 2 * mod) < 0)\
    \ a += 2 * mod;\n        return *this;\n    }\n\n    constexpr mint& operator-=(const\
    \ mint& b) {\n        if (i32(a -= b.a) < 0) a += 2 * mod;\n        return *this;\n\
    \    }\n\n    constexpr mint& operator*=(const mint& b) {\n        a = reduce(u64(a)\
    \ * b.a);\n        return *this;\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& b) {\n        *this *= b.inverse();\n        return *this;\n    }\n\n\
    \    constexpr mint operator+(const mint& b) const {\n        return mint(*this)\
    \ += b;\n    }\n    constexpr mint operator-(const mint& b) const {\n        return\
    \ mint(*this) -= b;\n    }\n    constexpr mint operator*(const mint& b) const\
    \ {\n        return mint(*this) *= b;\n    }\n    constexpr mint operator/(const\
    \ mint& b) const {\n        return mint(*this) /= b;\n    }\n    constexpr bool\
    \ operator==(const mint& b) const {\n        return (a >= mod ? a - mod : a) ==\
    \ (b.a >= mod ? b.a - mod : b.a);\n    }\n    constexpr bool operator!=(const\
    \ mint& b) const {\n        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a\
    \ - mod : b.a);\n    }\n    constexpr mint operator-() const {\n        return\
    \ mint() - mint(*this);\n    }\n    constexpr mint operator+() const {\n     \
    \   return mint(*this);\n    }\n\n    constexpr mint pow(u64 n) const {\n    \
    \    mint ret(1), mul(*this);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n    constexpr mint inverse() const {\n        int x\
    \ = get(), y = mod, u = 1, v = 0, t = 0, tmp = 0;\n        while (y > 0) {\n \
    \           t = x / y;\n            x -= t * y, u -= t * v;\n            tmp =\
    \ x, x = y, y = tmp;\n            tmp = u, u = v, v = tmp;\n        }\n      \
    \  return mint{u};\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& b) {\n        return os << b.get();\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& b) {\n        int64_t t;\n        is >> t;\n\
    \        b = LazyMontgomeryModInt<mod>(t);\n        return (is);\n    }\n\n  \
    \  constexpr u32 get() const {\n        u32 ret = reduce(a);\n        return ret\
    \ >= mod ? ret - mod : ret;\n    }\n\n    static constexpr u32 get_mod() {\n \
    \       return mod;\n    }\n};\n"
  code: "#pragma once\n#include <cstdint>\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt\
    \ {\n    using mint = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr u32 get_r()\
    \ {\n        u32 ret = mod;\n        for (i32 i = 0; i < 4; ++i) ret *= 2 - mod\
    \ * ret;\n        return ret;\n    }\n\n    static constexpr u32 r = get_r();\n\
    \    static constexpr u32 n2 = -u64(mod) % mod;\n    static_assert(mod < (1 <<\
    \ 30), \"invalid, mod >= 2 ^ 30\");\n    static_assert((mod & 1) == 1, \"invalid,\
    \ mod % 2 == 0\");\n    static_assert(r * mod == 1, \"this code has bugs.\");\n\
    \n    u32 a;\n\n    constexpr LazyMontgomeryModInt() : a(0) {\n    }\n    constexpr\
    \ LazyMontgomeryModInt(const int64_t& b)\n        : a(reduce(u64(b % mod + mod)\
    \ * n2)) {};\n\n    static constexpr u32 reduce(const u64& b) {\n        return\
    \ (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n    }\n\n    constexpr mint& operator+=(const\
    \ mint& b) {\n        if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n       \
    \ return *this;\n    }\n\n    constexpr mint& operator-=(const mint& b) {\n  \
    \      if (i32(a -= b.a) < 0) a += 2 * mod;\n        return *this;\n    }\n\n\
    \    constexpr mint& operator*=(const mint& b) {\n        a = reduce(u64(a) *\
    \ b.a);\n        return *this;\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& b) {\n        *this *= b.inverse();\n        return *this;\n    }\n\n\
    \    constexpr mint operator+(const mint& b) const {\n        return mint(*this)\
    \ += b;\n    }\n    constexpr mint operator-(const mint& b) const {\n        return\
    \ mint(*this) -= b;\n    }\n    constexpr mint operator*(const mint& b) const\
    \ {\n        return mint(*this) *= b;\n    }\n    constexpr mint operator/(const\
    \ mint& b) const {\n        return mint(*this) /= b;\n    }\n    constexpr bool\
    \ operator==(const mint& b) const {\n        return (a >= mod ? a - mod : a) ==\
    \ (b.a >= mod ? b.a - mod : b.a);\n    }\n    constexpr bool operator!=(const\
    \ mint& b) const {\n        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a\
    \ - mod : b.a);\n    }\n    constexpr mint operator-() const {\n        return\
    \ mint() - mint(*this);\n    }\n    constexpr mint operator+() const {\n     \
    \   return mint(*this);\n    }\n\n    constexpr mint pow(u64 n) const {\n    \
    \    mint ret(1), mul(*this);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n    constexpr mint inverse() const {\n        int x\
    \ = get(), y = mod, u = 1, v = 0, t = 0, tmp = 0;\n        while (y > 0) {\n \
    \           t = x / y;\n            x -= t * y, u -= t * v;\n            tmp =\
    \ x, x = y, y = tmp;\n            tmp = u, u = v, v = tmp;\n        }\n      \
    \  return mint{u};\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& b) {\n        return os << b.get();\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& b) {\n        int64_t t;\n        is >> t;\n\
    \        b = LazyMontgomeryModInt<mod>(t);\n        return (is);\n    }\n\n  \
    \  constexpr u32 get() const {\n        u32 ret = reduce(a);\n        return ret\
    \ >= mod ? ret - mod : ret;\n    }\n\n    static constexpr u32 get_mod() {\n \
    \       return mod;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/modint/montgomery-modint.hpp
  requiredBy:
  - lib/ntt/arbitrary-ntt.hpp
  - lib/fps/arbitrary-fps.hpp
  - lib/fps/fps-circular.hpp
  timestamp: '2026-10-17 10:16:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/modint/montgomery-modint.hpp
layout: document
redirect_from:
- /library/lib/modint/montgomery-modint.hpp
- /library/lib/modint/montgomery-modint.hpp.html
title: lib/modint/montgomery-modint.hpp
---
