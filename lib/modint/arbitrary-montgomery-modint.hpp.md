---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/fps/fps-sqrt.hpp
    title: "\u5E73\u65B9\u6839"
  - icon: ':warning:'
    path: lib/modulo/mod-sqrt.hpp
    title: mod sqrt(Tonelli-Shanks algorithm)
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/modint/arbitrary-montgomery-modint.hpp\"\n\n#include\
    \ <iostream>\n\ntemplate <typename Int, typename UInt, typename Long, typename\
    \ ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n  using mint = ArbitraryLazyMontgomeryModIntBase;\n\
    \n  inline static UInt mod;\n  inline static UInt r;\n  inline static UInt n2;\n\
    \  static constexpr int bit_length = sizeof(UInt) * 8;\n\n  static UInt get_r()\
    \ {\n    UInt ret = mod;\n    while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n\
    \    return ret;\n  }\n  static void set_mod(UInt m) {\n    assert(m < (UInt(1u)\
    \ << (bit_length - 2)));\n    assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m)\
    \ % m, r = get_r();\n  }\n  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() :\
    \ a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const Long &b)\n      : a(reduce(ULong(b\
    \ % mod + mod) * n2)){};\n\n  static UInt reduce(const ULong &b) {\n    return\
    \ (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n  }\n\n  mint &operator+=(const\
    \ mint &b) {\n    if (Int(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n  mint &operator-=(const mint &b) {\n    if (Int(a -= b.a) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n  mint &operator*=(const mint &b) {\n    a = reduce(ULong(a)\
    \ * b.a);\n    return *this;\n  }\n  mint &operator/=(const mint &b) {\n    *this\
    \ *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint &b) const\
    \ { return mint(*this) += b; }\n  mint operator-(const mint &b) const { return\
    \ mint(*this) -= b; }\n  mint operator*(const mint &b) const { return mint(*this)\
    \ *= b; }\n  mint operator/(const mint &b) const { return mint(*this) /= b; }\n\
    \n  bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const mint &b) const\
    \ {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n\
    \  }\n  mint operator-() const { return mint(0) - mint(*this); }\n  mint operator+()\
    \ const { return mint(*this); }\n\n  mint pow(ULong n) const {\n    mint ret(1),\
    \ mul(*this);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *=\
    \ mul, n >>= 1;\n    }\n    return ret;\n  }\n\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend std::istream\
    \ &operator>>(std::istream &is, mint &b) {\n    Long t;\n    is >> t;\n    b =\
    \ ArbitraryLazyMontgomeryModIntBase(t);\n    return (is);\n  }\n\n  mint inverse()\
    \ const {\n    Int x = get(), y = get_mod(), u = 1, v = 0;\n    while (y > 0)\
    \ {\n      Int t = x / y;\n      std::swap(x -= t * y, y);\n      std::swap(u\
    \ -= t * v, v);\n    }\n    return mint{u};\n  }\n\n  UInt get() const {\n   \
    \ UInt ret = reduce(a);\n    return ret >= mod ? ret - mod : ret;\n  }\n\n  static\
    \ UInt get_mod() { return mod; }\n};\n\n// id \u306B\u9069\u5F53\u306A\u4E71\u6570\
    \u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt\
    \ =\n    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long,\n   \
    \                                   unsigned long long, id>;\ntemplate <int id>\n\
    using ArbitraryLazyMontgomeryModInt64bit =\n    ArbitraryLazyMontgomeryModIntBase<long\
    \ long, unsigned long long, __int128_t,\n                                    \
    \  __uint128_t, id>;\n"
  code: "#pragma once\n\n#include <iostream>\n\ntemplate <typename Int, typename UInt,\
    \ typename Long, typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase\
    \ {\n  using mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt\
    \ mod;\n  inline static UInt r;\n  inline static UInt n2;\n  static constexpr\
    \ int bit_length = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret\
    \ = mod;\n    while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n\
    \  }\n  static void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length\
    \ - 2)));\n    assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n\
    \  }\n  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ mint &b) {\n    return os << b.get();\n  }\n\n  friend std::istream &operator>>(std::istream\
    \ &is, mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      std::swap(x\
    \ -= t * y, y);\n      std::swap(u -= t * v, v);\n    }\n    return mint{u};\n\
    \  }\n\n  UInt get() const {\n    UInt ret = reduce(a);\n    return ret >= mod\
    \ ? ret - mod : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n//\
    \ id \u306B\u9069\u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\
    \u3046\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;"
  dependsOn: []
  isVerificationFile: false
  path: lib/modint/arbitrary-montgomery-modint.hpp
  requiredBy:
  - lib/modulo/mod-sqrt.hpp
  - lib/fps/fps-sqrt.hpp
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/modint/arbitrary-montgomery-modint.hpp
layout: document
redirect_from:
- /library/lib/modint/arbitrary-montgomery-modint.hpp
- /library/lib/modint/arbitrary-montgomery-modint.hpp.html
title: lib/modint/arbitrary-montgomery-modint.hpp
---
