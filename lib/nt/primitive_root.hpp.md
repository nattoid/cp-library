---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/nt/factorize.hpp
    title: lib/nt/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u3001\u62E1\u5F35\u30E6\u30FC\u30AF\
      \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u3001\u4E2D\u56FD\u5270\u4F59\u5B9A\
      \u7406 (CRT)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive\
      \ Root) \u306E\u63A2\u7D22"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/nt/primitive_root.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @file primitive_root.hpp\n * @brief \u4E57\u6CD5\u4F4D\u6570 (Order)\
    \ \u3068\u539F\u59CB\u6839 (Primitive Root) \u306E\u63A2\u7D22\n */\n\n#pragma\
    \ once\n#include <cassert>\n#include <cstdint>\n#include <numeric>\n#include <vector>\n\
    \n#include \"factorize.hpp\"\n#include \"modular.hpp\"\n\nnamespace nt {\n\n/**\n\
    \ * @brief \u6CD5 m \u306B\u304A\u3051\u308B a \u306E\u4E57\u6CD5\u4F4D\u6570\
    \ ord_m(a) \u3092\u6C42\u3081\u308B\n * @param a \u5E95 (gcd(a, m) == 1 \u3067\
    \u306A\u3044\u5834\u5408\u306F 0 \u3092\u8FD4\u3059)\n * @param m \u6CD5 (m >=\
    \ 1)\n * @return ll a^k = 1 (mod m) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\
    \u6B63\u6574\u6570 k (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F 0)\n *\
    \ @note \u8A08\u7B97\u91CF: \u671F\u5F85\u5024 O(m^{1/4})\n */\ninline ll order(ll\
    \ a, ll m) {\n    assert(m >= 1);\n    if (m == 1) return 1;\n    a %= m;\n  \
    \  if (a < 0) a += m;\n    if (std::gcd(a, m) != 1) return 0;\n\n    ll phi_m\
    \ = phi(m);\n    auto factors = factorize(phi_m);\n    ll res = phi_m;\n    for\
    \ (const auto& [p, e] : factors) {\n        while (res % p == 0 && pow_mod(a,\
    \ res / p, m) == 1) {\n            res /= p;\n        }\n    }\n    return res;\n\
    }\n\n/**\n * @brief \u7D20\u6570 p \u306B\u5BFE\u3059\u308B\u6700\u5C0F\u306E\u539F\
    \u59CB\u6839\u3092\u6C42\u3081\u308B\n * (\u6E1B\u7B97\u578B\u9045\u5EF6\u30E2\
    \u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\u306B\u3088\u308B\u9AD8\u901F\u7248)\n *\
    \ @param p \u7D20\u6570 (p >= 2)\n * @return ll \u6700\u5C0F\u306E\u539F\u59CB\
    \u6839\n * @note \u8A08\u7B97\u91CF: \u671F\u5F85\u5024 O((p - 1)^{1/4})\n */\n\
    inline ll primitive_root_prime(ll p) {\n    assert(p >= 2);\n    if (p == 2) return\
    \ 1;\n    if (p == 998244353) return 3;\n\n    auto factors = factorize(p - 1);\n\
    \    std::vector<u64> exps;\n    exps.reserve(factors.size());\n    for (const\
    \ auto& [q, e] : factors) {\n        exps.push_back((p - 1) / q);\n    }\n\n \
    \   internal::u64 n = p;\n    internal::Montgomery m(n);\n    internal::u64 one\
    \ = (-n) % n;\n    internal::u64 r2 = (-internal::u128(n)) % n;\n\n    auto mod_pow_mont\
    \ = [&](internal::u64 a_mont, internal::u64 exp) {\n        internal::u64 res\
    \ = one;\n        while (exp > 0) {\n            if (exp & 1) res = m.mul(res,\
    \ a_mont);\n            a_mont = m.mul(a_mont, a_mont);\n            exp >>= 1;\n\
    \        }\n        return res >= n ? res - n : res;\n    };\n\n    for (internal::u64\
    \ g = 2;; g++) {\n        internal::u64 g_mont = m.mul(g, r2);\n        bool ok\
    \ = true;\n        for (internal::u64 exp : exps) {\n            if (mod_pow_mont(g_mont,\
    \ exp) == one) {\n                ok = false;\n                break;\n      \
    \      }\n        }\n        if (ok) return g;\n    }\n}\n\n/**\n * @brief \u4E00\
    \u822C\u306E\u6B63\u6574\u6570 n \u306B\u5BFE\u3059\u308B\u6700\u5C0F\u306E\u539F\
    \u59CB\u6839\u3092\u6C42\u3081\u308B\n * @details \u539F\u59CB\u6839\u304C\u5B58\
    \u5728\u3059\u308B n (n = 1, 2, 4, p^k, 2p^k (p\u306F\u5947\u7D20\u6570))\n *\
    \ \u306B\u5BFE\u3057\u3066\u6700\u5C0F\u306E\u539F\u59CB\u6839\u3092\u8FD4\u3059\
    \n * @param n \u5BFE\u8C61\u306E\u6B63\u6574\u6570 (n >= 1)\n * @return ll \u6700\
    \u5C0F\u306E\u539F\u59CB\u6839 (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\
    \ -1)\n * @note \u8A08\u7B97\u91CF: \u671F\u5F85\u5024 O(n^{1/4})\n */\ninline\
    \ ll primitive_root(ll n) {\n    assert(n >= 1);\n    if (n == 1) return 0;\n\
    \    if (n == 2) return 1;\n    if (n == 4) return 3;\n    if (is_prime(n)) return\
    \ primitive_root_prime(n);\n\n    // \u539F\u59CB\u6839\u306E\u5B58\u5728\u5224\
    \u5B9A: n = p^k \u307E\u305F\u306F 2*p^k (p\u306F\u5947\u7D20\u6570)\n    ll m\
    \ = n;\n    if (m % 2 == 0) {\n        m /= 2;\n        if (m % 2 == 0) return\
    \ -1;  // 4\u3088\u308A\u5927\u304D\u30444\u306E\u500D\u6570\u306F\u539F\u59CB\
    \u6839\u3092\u6301\u305F\u306A\u3044\n    }\n\n    auto factors_m = factorize(m);\n\
    \    if (factors_m.size() != 1)\n        return -1;  // \u7570\u306A\u308B2\u3064\
    \u4EE5\u4E0A\u306E\u5947\u7D20\u6570\u3067\u5272\u308C\u308B\u5834\u5408\u306F\
    \u5B58\u5728\u3057\u306A\u3044\n\n    ll p = factors_m[0].first;\n    ll phi_n\
    \ = (m / p) * (p - 1);\n\n    // phi(n) \u306E\u7D20\u56E0\u6570\u30EA\u30B9\u30C8\
    \u3092\u4F5C\u6210 (p \u3068 p-1 \u306E\u7D20\u56E0\u6570)\n    auto factors_phi\
    \ = factorize(p - 1);\n    std::vector<ll> exps;\n    exps.reserve(factors_phi.size()\
    \ + 1);\n    if (factors_m[0].second >= 2) {\n        exps.push_back(phi_n / p);\n\
    \    }\n    for (const auto& [q, e] : factors_phi) {\n        exps.push_back(phi_n\
    \ / q);\n    }\n\n    for (ll g = 2;; g++) {\n        if (std::gcd(g, n) != 1)\
    \ continue;\n        bool ok = true;\n        for (ll exp : exps) {\n        \
    \    if (pow_mod(g, exp, n) == 1) {\n                ok = false;\n           \
    \     break;\n            }\n        }\n        if (ok) return g;\n    }\n}\n\n\
    }  // namespace nt"
  dependsOn:
  - lib/nt/factorize.hpp
  - lib/nt/modular.hpp
  isVerificationFile: false
  path: lib/nt/primitive_root.hpp
  requiredBy: []
  timestamp: '2026-10-17 10:16:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/nt/primitive_root.hpp
layout: document
redirect_from:
- /library/lib/nt/primitive_root.hpp
- /library/lib/nt/primitive_root.hpp.html
title: "\u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive Root)\
  \ \u306E\u63A2\u7D22"
---
