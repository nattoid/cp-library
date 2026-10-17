---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/nt/discrete_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (Extended Baby-step Giant-step)"
  - icon: ':question:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm
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
    \ lib/nt/discrete_log.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm\"\n\
    #include <iostream>\n\n#include \"../../lib/nt/discrete_log.hpp\"\n\nusing namespace\
    \ std;\nusing ll = long long;\nint main() {\n    int q;\n    cin >> q;\n    while\
    \ (q--) {\n        int x, y, m;\n        cin >> x >> y >> m;\n        cout <<\
    \ nt::discrete_log(x, y, m) << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/nt/discrete_log.hpp
  - lib/nt/modular.hpp
  isVerificationFile: true
  path: verify/nt/discrete_logarithm.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 16:08:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/nt/discrete_logarithm.test.cpp
layout: document
redirect_from:
- /verify/verify/nt/discrete_logarithm.test.cpp
- /verify/verify/nt/discrete_logarithm.test.cpp.html
title: verify/nt/discrete_logarithm.test.cpp
---
