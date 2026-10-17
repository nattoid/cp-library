---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (Extended Baby-step Giant-step)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/nt/discrete_log.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @file discrete_log.hpp\n * @brief \u96E2\u6563\u5BFE\u6570\u554F\u984C\
    \ (Extended Baby-step Giant-step)\n */\n\n#pragma once\n#include <cassert>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <numeric>\n#include <vector>\n\n#include\
    \ \"modular.hpp\"\n\nnamespace nt {\n\n/** @cond INTERNAL */\nnamespace internal\
    \ {\n\n// BSGS\u7528\u306E\u9AD8\u901F\u30AA\u30FC\u30D7\u30F3\u30A2\u30C9\u30EC\
    \u30B9\u30CF\u30C3\u30B7\u30E5\u30C6\u30FC\u30D6\u30EB (\u5024\u306E\u4E0A\u66F8\
    \u304D\u5BFE\u5FDC)\nstruct FastHashMap {\n    int cap, mask;\n    std::vector<u64>\
    \ keys;\n    std::vector<int> vals;\n    std::vector<bool> used;\n\n    FastHashMap(int\
    \ max_elements) {\n        cap = 8;\n        while (cap < max_elements * 2) cap\
    \ <<= 1;\n        mask = cap - 1;\n        keys.resize(cap);\n        vals.resize(cap);\n\
    \        used.assign(cap, false);\n    }\n\n    static inline u64 hash(u64 x)\
    \ {\n        x += 0x9e3779b97f4a7c15ULL;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;\n        return x ^ (x >>\
    \ 31);\n    }\n\n    inline void insert(u64 k, int v) {\n        int i = hash(k)\
    \ & mask;\n        while (used[i] && keys[i] != k) {\n            i = (i + 1)\
    \ & mask;\n        }\n        keys[i] = k;\n        vals[i] = v;  // \u3088\u308A\
    \u5927\u304D\u3044 j \u3067\u4E0A\u66F8\u304D\u3059\u308B\u3053\u3068\u3067 i*step\
    \ - j \u3092\u6700\u5C0F\u5316\n        used[i] = true;\n    }\n\n    inline int\
    \ find(u64 k) const {\n        int i = hash(k) & mask;\n        while (used[i])\
    \ {\n            if (keys[i] == k) return vals[i];\n            i = (i + 1) &\
    \ mask;\n        }\n        return -1;\n    }\n};\n\n}  // namespace internal\n\
    /** @endcond */\n\n/**\n * @brief \u96E2\u6563\u5BFE\u6570\u554F\u984C a^x = b\
    \ (mod m) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E x \u3092\u6C42\u3081\u308B\
    \ (exBSGS)\n * @param a \u5E95\n * @param b \u771F\u6570\n * @param m \u6CD5 (m\
    \ >= 1)\n * @param allow_zero x = 0 \u3092\u89E3\u3068\u3057\u3066\u8A31\u5BB9\
    \u3059\u308B\u304B (\u30C7\u30D5\u30A9\u30EB\u30C8: true, 0^0 = 1\n * \u3068\u5B9A\
    \u7FA9)\n * @return ll \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\
    \ x (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1)\n * @note \u8A08\u7B97\
    \u91CF: \u6642\u9593\u30FB\u7A7A\u9593\u3068\u3082\u306B O(sqrt(m))\n */\ninline\
    \ ll discrete_log(ll a, ll b, ll m, bool allow_zero = true) {\n    assert(m >=\
    \ 1);\n    if (m == 1) return allow_zero ? 0 : 1;\n\n    a %= m;\n    if (a <\
    \ 0) a += m;\n    b %= m;\n    if (b < 0) b += m;\n\n    if (allow_zero && b ==\
    \ 1) return 0;\n    if (a == 0) {\n        if (b == 0) return 1;\n        return\
    \ -1;\n    }\n\n    // 1. gcd(a, m) > 1 \u306E\u9593\u3001\u56E0\u5B50\u3092\u62EC\
    \u308A\u51FA\u3057\u3066\u4E92\u3044\u306B\u7D20\u306A\u554F\u984C\u306B\u5E30\
    \u7740\u3055\u305B\u308B\n    ll k = 0, c = 1 % m;\n    while (true) {\n     \
    \   if ((allow_zero || k > 0) && c == b) return k;\n        ll g = std::gcd(a,\
    \ m);\n        if (g == 1) break;\n        if (b % g != 0) return -1;\n      \
    \  b /= g;\n        m /= g;\n        c = (ll)((u128)c * (a / g) % m);\n      \
    \  k++;\n    }\n\n    // 2. c * a^{x - k} = b (mod m) \u3092 BSGS \u3067\u89E3\
    \u304F (gcd(a, m) == 1)\n    // x - k = i * step - j (1 <= i <= step, 0 <= j <\
    \ step) \u3068\u304A\u304F\n    // c * (a^step)^i = b * a^j (mod m)\n    ll step\
    \ = std::sqrtl(m) + 1;\n    internal::FastHashMap mp(step);\n\n    ll cur = b;\n\
    \    for (int j = 0; j < step; j++) {\n        mp.insert(cur, j);\n        cur\
    \ = (ll)((u128)cur * a % m);\n    }\n\n    ll a_step = pow_mod(a, step, m);\n\
    \    cur = c;\n    for (ll i = 1; i <= step; i++) {\n        cur = (ll)((u128)cur\
    \ * a_step % m);\n        int j = mp.find(cur);\n        if (j != -1) {\n    \
    \        ll ans = i * step - j + k;\n            if (ans > 0 || allow_zero) return\
    \ ans;\n        }\n    }\n\n    return -1;\n}\n\n}  // namespace nt"
  dependsOn:
  - lib/nt/modular.hpp
  isVerificationFile: false
  path: lib/nt/discrete_log.hpp
  requiredBy: []
  timestamp: '2026-10-17 15:06:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/nt/discrete_log.hpp
layout: document
redirect_from:
- /library/lib/nt/discrete_log.hpp
- /library/lib/nt/discrete_log.hpp.html
title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (Extended Baby-step Giant-step)"
---
