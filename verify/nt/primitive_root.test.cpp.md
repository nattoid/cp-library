---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/nt/factorize.hpp
    title: lib/nt/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  - icon: ':heavy_check_mark:'
    path: lib/nt/primitive_root.hpp
    title: "\u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive Root)\
      \ \u306E\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primitive_root
    links:
    - https://judge.yosupo.jp/problem/primitive_root
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
    \ lib/nt/primitive_root.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\n#include\
    \ \"../../lib/nt/primitive_root.hpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\nusing ll = long long;\nint main() {\n    int q;\n    cin >> q;\n    while\
    \ (q--) {\n        ll p;\n        cin >> p;\n        cout << nt::primitive_root_prime(p)\
    \ << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/nt/primitive_root.hpp
  - lib/nt/factorize.hpp
  - lib/nt/modular.hpp
  isVerificationFile: true
  path: verify/nt/primitive_root.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 16:01:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/nt/primitive_root.test.cpp
layout: document
redirect_from:
- /verify/verify/nt/primitive_root.test.cpp
- /verify/verify/nt/primitive_root.test.cpp.html
title: verify/nt/primitive_root.test.cpp
---
