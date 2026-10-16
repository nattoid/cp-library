---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/nt/factorize.hpp
    title: lib/nt/factorize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/nt/factorize.test.cpp
    title: verify/nt/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/nt/modular.hpp\"\n#include <utility>\n#include <cassert>\n\
    #include <cstdint>\n\nnamespace nt {\n\nusing ll = long long;\nusing u64 = __uint64_t;\n\
    using u128 = __uint128_t;\n\n// O(log min(a, m)) \u3067\u30E2\u30B8\u30E5\u30E9\
    \u9006\u5143\u3092\u6C42\u3081\u308B (gcd(a, m) == 1 \u3092\u4EEE\u5B9A)\ninline\
    \ ll inv_mod(ll a, ll m) {\n    assert(m > 0);\n    a %= m;\n    if (a < 0) a\
    \ += m;\n    ll b = m, u = 1, v = 0;\n    while (b) {\n        ll t = a / b;\n\
    \        a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u, v);\n\
    \    }\n    assert(a == 1);\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n\
    }\n\n// O(log n) \u3067 a^n mod m \u3092\u8A08\u7B97\ninline ll pow_mod(ll a,\
    \ ll n, ll m) {\n    assert(n >= 0 && m > 0);\n    if (m == 1) return 0;\n   \
    \ ll res = 1;\n    a %= m;\n    if (a < 0) a += m;\n    while (n > 0) {\n    \
    \    if (n & 1) res = (ll)((u128)res * a % m);\n        a = (ll)((u128)a * a %\
    \ m);\n        n >>= 1;\n    }\n    return res;\n}\n\n} // namespace nt\n"
  code: "#pragma once\n#include <utility>\n#include <cassert>\n#include <cstdint>\n\
    \nnamespace nt {\n\nusing ll = long long;\nusing u64 = __uint64_t;\nusing u128\
    \ = __uint128_t;\n\n// O(log min(a, m)) \u3067\u30E2\u30B8\u30E5\u30E9\u9006\u5143\
    \u3092\u6C42\u3081\u308B (gcd(a, m) == 1 \u3092\u4EEE\u5B9A)\ninline ll inv_mod(ll\
    \ a, ll m) {\n    assert(m > 0);\n    a %= m;\n    if (a < 0) a += m;\n    ll\
    \ b = m, u = 1, v = 0;\n    while (b) {\n        ll t = a / b;\n        a -= t\
    \ * b; std::swap(a, b);\n        u -= t * v; std::swap(u, v);\n    }\n    assert(a\
    \ == 1);\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n// O(log n)\
    \ \u3067 a^n mod m \u3092\u8A08\u7B97\ninline ll pow_mod(ll a, ll n, ll m) {\n\
    \    assert(n >= 0 && m > 0);\n    if (m == 1) return 0;\n    ll res = 1;\n  \
    \  a %= m;\n    if (a < 0) a += m;\n    while (n > 0) {\n        if (n & 1) res\
    \ = (ll)((u128)res * a % m);\n        a = (ll)((u128)a * a % m);\n        n >>=\
    \ 1;\n    }\n    return res;\n}\n\n} // namespace nt"
  dependsOn: []
  isVerificationFile: false
  path: lib/nt/modular.hpp
  requiredBy:
  - lib/nt/factorize.hpp
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/nt/factorize.test.cpp
documentation_of: lib/nt/modular.hpp
layout: document
redirect_from:
- /library/lib/nt/modular.hpp
- /library/lib/nt/modular.hpp.html
title: lib/nt/modular.hpp
---
