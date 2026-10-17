---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5E73\u65B9\u6839"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../modulo/mod-sqrt.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../fps/formal-power-series.hpp\"\n#include \"../modulo/mod-sqrt.hpp\"\
    \n\ntemplate <typename mint>\nFormalPowerSeries<mint> sqrt(const FormalPowerSeries<mint>&\
    \ f, int deg = -1) {\n    if (deg == -1) deg = (int)f.size();\n    if ((int)f.size()\
    \ == 0) return FormalPowerSeries<mint>(deg, 0);\n    if (f[0] == mint(0)) {\n\
    \        for (int i = 1; i < (int)f.size(); i++) {\n            if (f[i] != mint(0))\
    \ {\n                if (i & 1) return {};\n                if (deg - i / 2 <=\
    \ 0) break;\n                auto ret = sqrt(f >> i, deg - i / 2);\n         \
    \       if (ret.empty()) return {};\n                ret = ret << (i / 2);\n \
    \               if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n       \
    \         return ret;\n            }\n        }\n        return FormalPowerSeries<mint>(deg,\
    \ 0);\n    }\n\n    int64_t sqr = mod_sqrt(f[0].val(), mint::mod());\n    if (sqr\
    \ == -1) return {};\n    assert(sqr * sqr % mint::mod() == f[0].val());\n    FormalPowerSeries<mint>\
    \ ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n    for (int i = 1; i <\
    \ deg; i <<= 1) {\n        ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\n\
    \    }\n    return ret.pre(deg);\n}\n\n/**\n * @brief \u5E73\u65B9\u6839\n */"
  dependsOn: []
  isVerificationFile: false
  path: lib/fps/fps-sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/fps/fps-sqrt.hpp
layout: document
redirect_from:
- /library/lib/fps/fps-sqrt.hpp
- /library/lib/fps/fps-sqrt.hpp.html
title: "\u5E73\u65B9\u6839"
---
