---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/nt/discrete_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (Extended Baby-step Giant-step)"
  - icon: ':heavy_check_mark:'
    path: lib/nt/factorize.hpp
    title: lib/nt/factorize.hpp
  - icon: ':warning:'
    path: lib/nt/mod-sqrt.hpp
    title: lib/nt/mod-sqrt.hpp
  - icon: ':warning:'
    path: lib/nt/primitive_root.hpp
    title: "\u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive Root)\
      \ \u306E\u63A2\u7D22"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/nt/factorize.test.cpp
    title: verify/nt/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u3001\u62E1\u5F35\u30E6\u30FC\
      \u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u3001\u4E2D\u56FD\u5270\u4F59\
      \u5B9A\u7406 (CRT)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/nt/modular.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @file modular.hpp\n * @brief \u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\
    \u3001\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
    \u3001\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (CRT)\n */\n\n#pragma once\n#include\
    \ <cassert>\n#include <cstdint>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace nt {\n\nusing ll = long long;\nusing u64 = uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n/**\n * @brief \u62E1\u5F35\
    \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5 (\u975E\u518D\u5E30\
    )\n * @details a*x + b*y = g = gcd(|a|, |b|) \u3068\u306A\u308B (g, x, y) \u3092\
    \u6C42\u3081\u308B\n * @param a \u6574\u6570\n * @param b \u6574\u6570\n * @return\
    \ std::tuple<ll, ll, ll> {g, x, y} (g >= 0)\n * @note \u8A08\u7B97\u91CF: O(log\
    \ min(|a|, |b|))\n */\ninline std::tuple<ll, ll, ll> extgcd(ll a, ll b) {\n  \
    \  ll x = 1, y = 0, x1 = 0, y1 = 1;\n    ll a1 = a, b1 = b;\n    while (b1 !=\
    \ 0) {\n        ll q = a1 / b1;\n        std::tie(x, x1) = std::make_tuple(x1,\
    \ x - q * x1);\n        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);\n \
    \       std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);\n    }\n    if (a1\
    \ < 0) {\n        a1 = -a1;\n        x = -x;\n        y = -y;\n    }\n    return\
    \ {a1, x, y};\n}\n\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u4E92\u9664\u6CD5 (\u53C2\u7167\u6E21\u3057\u7248)\n */\ninline ll extgcd(ll\
    \ a, ll b, ll& x, ll& y) {\n    auto [g, u, v] = extgcd(a, b);\n    x = u;\n \
    \   y = v;\n    return g;\n}\n\n/**\n * @brief \u30E2\u30B8\u30E5\u30E9\u9006\u5143\
    \u3092\u6C42\u3081\u308B (gcd(a, m) == 1 \u3092\u4EEE\u5B9A)\n * @note \u8A08\u7B97\
    \u91CF: O(log min(a, m))\n */\ninline ll inv_mod(ll a, ll m) {\n    assert(m >\
    \ 0);\n    a %= m;\n    if (a < 0) a += m;\n    ll b = m, u = 1, v = 0;\n    while\
    \ (b) {\n        ll t = a / b;\n        a -= t * b;\n        std::swap(a, b);\n\
    \        u -= t * v;\n        std::swap(u, v);\n    }\n    assert(a == 1);\n \
    \   u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n mod\
    \ m \u3092\u8A08\u7B97\u3059\u308B\n * @note \u8A08\u7B97\u91CF: O(log n)\n */\n\
    inline ll pow_mod(ll a, ll n, ll m) {\n    assert(n >= 0 && m > 0);\n    if (m\
    \ == 1) return 0;\n    ll res = 1;\n    a %= m;\n    if (a < 0) a += m;\n    while\
    \ (n > 0) {\n        if (n & 1) res = (ll)((u128)res * a % m);\n        a = (ll)((u128)a\
    \ * a % m);\n        n >>= 1;\n    }\n    return res;\n}\n\n/**\n * @brief \u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406 (2\u5909\u6570\u7248)\n * @details x = r1 (mod\
    \ m1), x = r2 (mod m2) \u3092\u6E80\u305F\u3059 x = r (mod lcm(m1, m2))\n * \u3092\
    \u6C42\u3081\u308B\n * @return std::pair<ll, ll> {r, lcm(m1, m2)} (\u89E3\u306A\
    \u3057\u306E\u5834\u5408\u306F {0, 0})\n * @note lcm(m1, m2) \u304C ll \u306B\u53CE\
    \u307E\u308B\u3053\u3068\u3092\u524D\u63D0\u3068\u3059\u308B\n */\ninline std::pair<ll,\
    \ ll> crt(ll r1, ll m1, ll r2, ll m2) {\n    assert(m1 >= 1 && m2 >= 1);\n   \
    \ r1 %= m1;\n    if (r1 < 0) r1 += m1;\n    r2 %= m2;\n    if (r2 < 0) r2 += m2;\n\
    \n    auto [g, p, q] = extgcd(m1, m2);\n    if ((r2 - r1) % g != 0) return {0,\
    \ 0};\n\n    ll u = m2 / g;\n    ll t = (ll)((i128)(r2 - r1) / g % u * p % u);\n\
    \    if (t < 0) t += u;\n\n    ll lcm = m1 * u;\n    ll r = r1 + (ll)((i128)t\
    \ * m1 % lcm);\n    if (r >= lcm) r -= lcm;\n    return {r, lcm};\n}\n\n/**\n\
    \ * @brief \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (\u914D\u5217\u7248)\n * @details\
    \ x = r[i] (mod m[i]) \u3092\u3059\u3079\u3066\u6E80\u305F\u3059 x = rem (mod\
    \ lcm) \u3092\u6C42\u3081\u308B\n * @return std::pair<ll, ll> {rem, lcm} (\u89E3\
    \u306A\u3057\u306E\u5834\u5408\u306F {0, 0}, \u7A7A\u914D\u5217\u306E\u5834\u5408\
    \u306F\n * {0, 1})\n */\ninline std::pair<ll, ll> crt(const std::vector<ll>& r,\n\
    \                             const std::vector<ll>& m) {\n    assert(r.size()\
    \ == m.size());\n    ll r0 = 0, m0 = 1;\n    for (size_t i = 0; i < r.size();\
    \ i++) {\n        auto [r1, m1] = crt(r0, m0, r[i], m[i]);\n        if (m1 ==\
    \ 0) return {0, 0};\n        r0 = r1;\n        m0 = m1;\n    }\n    return {r0,\
    \ m0};\n}\n\n}  // namespace nt"
  dependsOn: []
  isVerificationFile: false
  path: lib/nt/modular.hpp
  requiredBy:
  - lib/nt/mod-sqrt.hpp
  - lib/nt/factorize.hpp
  - lib/nt/primitive_root.hpp
  - lib/nt/discrete_log.hpp
  timestamp: '2026-10-17 10:16:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/nt/factorize.test.cpp
documentation_of: lib/nt/modular.hpp
layout: document
redirect_from:
- /library/lib/nt/modular.hpp
- /library/lib/nt/modular.hpp.html
title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u3001\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
  \u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u3001\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (CRT)"
---
