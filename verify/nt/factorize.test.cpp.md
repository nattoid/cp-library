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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
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
    \ lib/nt/factorize.hpp: line 9: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include <iostream>\n\
    #include \"../../lib/nt/factorize.hpp\" \n\nusing namespace std;\nusing ll = long\
    \ long;\nint main(){\n    int q;\n    cin >> q;\n    for(int i = 0; i < q; i++){\n\
    \        ll a;\n        cin >> a;\n        auto f = nt::factorize(a);\n      \
    \  int sum{};\n        for(auto [p, e] : f){\n            sum += e;\n        }\n\
    \        cout << sum << \" \";\n        for(auto [p, e] : f){\n            for(int\
    \ j = 0; j < e; j++){\n                cout << p << \" \";\n            }\n  \
    \      }\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/nt/factorize.hpp
  - lib/nt/modular.hpp
  isVerificationFile: true
  path: verify/nt/factorize.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 15:06:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/nt/factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/nt/factorize.test.cpp
- /verify/verify/nt/factorize.test.cpp.html
title: verify/nt/factorize.test.cpp
---
