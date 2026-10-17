---
data:
  _extendedDependsOn:
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
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/nt/modular.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\n#include \"modular.hpp\"\
    \  // pow_mod\u3092\u4F7F\u7528\n\nnamespace nt {\n\n// a \u306E\u5E73\u65B9\u5270\
    \u4F59 mod p \u3092\u6C42\u3081\u308B (Tonelli-Shanks algorithm)\n// \u5B58\u5728\
    \u3057\u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\u3059\u3002p \u306F\u7D20\
    \u6570\u3092\u4EEE\u5B9A\u3002\ninline long long mod_sqrt(long long a, long long\
    \ p) {\n    assert(0 <= a && a < p);\n    if (a == 0) return 0;\n    if (p ==\
    \ 2) return a;\n\n    if (pow_mod(a, (p - 1) >> 1, p) != 1) return -1;\n\n   \
    \ long long b = 1;\n    while (pow_mod(b, (p - 1) >> 1, p) == 1) {\n        b++;\n\
    \    }\n\n    long long m = p - 1, e = 0;\n    while (m % 2 == 0) {\n        m\
    \ >>= 1;\n        e++;\n    }\n\n    long long x = pow_mod(a, (m + 1) >> 1, p);\n\
    \    long long y = pow_mod(a, m, p);\n    long long z = pow_mod(b, m, p);\n\n\
    \    while (y != 1) {\n        long long j = 0;\n        long long t = y;\n  \
    \      while (t != 1) {\n            j++;\n            t = (long long)((__uint128_t)t\
    \ * t % p);\n        }\n\n        long long z_pow = z;\n        for (long long\
    \ i = 0; i < e - j - 1; i++) {\n            z_pow = (long long)((__uint128_t)z_pow\
    \ * z_pow % p);\n        }\n\n        x = (long long)((__uint128_t)x * z_pow %\
    \ p);\n        z = (long long)((__uint128_t)z_pow * z_pow % p);\n        y = (long\
    \ long)((__uint128_t)y * z % p);\n        e = j;\n    }\n    return x;\n}\n\n\
    }  // namespace nt"
  dependsOn:
  - lib/nt/modular.hpp
  isVerificationFile: false
  path: lib/nt/mod-sqrt.hpp
  requiredBy: []
  timestamp: '2026-10-17 10:16:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/nt/mod-sqrt.hpp
layout: document
redirect_from:
- /library/lib/nt/mod-sqrt.hpp
- /library/lib/nt/mod-sqrt.hpp.html
title: lib/nt/mod-sqrt.hpp
---
