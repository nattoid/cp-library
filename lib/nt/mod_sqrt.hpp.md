---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/nt/sqrt_mod.test.cpp
    title: verify/nt/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5E73\u65B9\u5270\u4F59 (Tonelli-Shanks algorithm)"
    links:
    - https://nyaannyaan.github.io/library/modulo/mod-sqrt.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/nt/mod_sqrt.hpp: line 7: #pragma once found in a non-first line\n"
  code: "/**\n * @file mod_sqrt.hpp\n * @brief \u5E73\u65B9\u5270\u4F59 (Tonelli-Shanks\
    \ algorithm)\n * @see https://nyaannyaan.github.io/library/modulo/mod-sqrt.hpp\n\
    \ */\n\n#pragma once\n#include <cassert>\n#include <cstdint>\n\n#include \"modular.hpp\"\
    \n\nnamespace nt {\n\n/**\n * @brief x^2 = a (mod p) \u3092\u6E80\u305F\u3059\
    \ x \u30921\u3064\u6C42\u3081\u308B (Tonelli-Shanks)\n * @param a \u771F\u6570\
    \n * @param p \u7D20\u6570 (p >= 2, p < 2^62)\n * @return ll \u89E3 x (0 <= x\
    \ < p, \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1)\n * @note \u8A08\u7B97\
    \u91CF: O(log^2 p) (\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\u306B\u3088\u308A\
    \u5B9A\u6570\u500D\u9AD8\u901F)\n */\ninline ll mod_sqrt(ll a, ll p) {\n    assert(p\
    \ >= 2);\n    a %= p;\n    if (a < 0) a += p;\n    if (a == 0) return 0;\n   \
    \ if (p == 2) return a;\n\n    Montgomery m(p);\n    u64 one = m.one();\n    u64\
    \ minus_one = p - one;\n    u64 r2 = m.r2();\n\n    u64 a_mont = m.mul(a, r2);\n\
    \    if (m.pow(a_mont, (p - 1) >> 1, one) != one) return -1;\n\n    // p == 3\
    \ (mod 4) \u306E\u5834\u5408\u306F a^{(p+1)/4} mod p \u304C\u76F4\u3061\u306B\u89E3\
    \u3068\u306A\u308B\n    if ((p & 3) == 3) {\n        u64 x_mont = m.pow(a_mont,\
    \ (p + 1) >> 2, one);\n        return m.mul(x_mont, 1);\n    }\n\n    // \u975E\
    \u5E73\u65B9\u5270\u4F59 b \u3092\u63A2\u3059\n    u64 b_mont = one;\n    for\
    \ (u64 b = 2;; b++) {\n        b_mont = m.mul(b, r2);\n        if (m.pow(b_mont,\
    \ (p - 1) >> 1, one) == minus_one) break;\n    }\n\n    u64 q = p - 1;\n    int\
    \ e = __builtin_ctzll(q);\n    q >>= e;\n\n    u64 x = m.pow(a_mont, (q + 1) >>\
    \ 1, one);\n    u64 y = m.pow(a_mont, q, one);\n    u64 z = m.pow(b_mont, q, one);\n\
    \n    while (y != one) {\n        int j = 0;\n        u64 t = y;\n        while\
    \ (t != one) {\n            j++;\n            t = m.norm(m.mul(t, t));\n     \
    \   }\n\n        u64 z_pow = z;\n        for (int i = 0; i < e - j - 1; i++) {\n\
    \            z_pow = m.mul(z_pow, z_pow);\n        }\n        z_pow = m.norm(z_pow);\n\
    \n        x = m.norm(m.mul(x, z_pow));\n        z = m.norm(m.mul(z_pow, z_pow));\n\
    \        y = m.norm(m.mul(y, z));\n        e = j;\n    }\n\n    return m.mul(x,\
    \ 1);  // \u30E2\u30F3\u30B4\u30E1\u30EA\u7A7A\u9593\u304B\u3089\u901A\u5E38\u306E\
    \u7A7A\u9593\u3078\u623B\u3059 (\u5E38\u306B [0, p) \u306B\u53CE\u307E\u308B)\n\
    }\n\n}  // namespace nt"
  dependsOn:
  - lib/nt/modular.hpp
  isVerificationFile: false
  path: lib/nt/mod_sqrt.hpp
  requiredBy: []
  timestamp: '2026-10-17 16:01:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/nt/sqrt_mod.test.cpp
documentation_of: lib/nt/mod_sqrt.hpp
layout: document
redirect_from:
- /library/lib/nt/mod_sqrt.hpp
- /library/lib/nt/mod_sqrt.hpp.html
title: "\u5E73\u65B9\u5270\u4F59 (Tonelli-Shanks algorithm)"
---
