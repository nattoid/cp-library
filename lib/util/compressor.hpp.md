---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/util/compressor.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \ntemplate <class T>\nstruct Compressor {\n    std::vector<T> xs;\n\n    Compressor()\
    \ = default;\n\n    Compressor(const std::vector<T>& v) {\n        xs = v;\n \
    \       build();\n    }\n\n    void add(T x) {\n        xs.push_back(x);\n   \
    \ }\n\n    void build() {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n\n    int operator()(T x) const {\n        return\
    \ std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\n    T operator[](int\
    \ id) const {\n        return xs[id];\n    }\n\n    // \u5727\u7E2E\u5F8C\u306E\
    \u8981\u7D20\u6570(\u7A2E\u985E\u6570)\u3092\u53D6\u5F97\n    int size() const\
    \ {\n        return xs.size();\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\ntemplate <class\
    \ T>\nstruct Compressor {\n    std::vector<T> xs;\n\n    Compressor() = default;\n\
    \n    Compressor(const std::vector<T>& v) {\n        xs = v;\n        build();\n\
    \    }\n\n    void add(T x) {\n        xs.push_back(x);\n    }\n\n    void build()\
    \ {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n\n    int operator()(T x) const {\n        return\
    \ std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\n    T operator[](int\
    \ id) const {\n        return xs[id];\n    }\n\n    // \u5727\u7E2E\u5F8C\u306E\
    \u8981\u7D20\u6570(\u7A2E\u985E\u6570)\u3092\u53D6\u5F97\n    int size() const\
    \ {\n        return xs.size();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/compressor.hpp
  requiredBy: []
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/compressor.hpp
layout: document
redirect_from:
- /library/lib/util/compressor.hpp
- /library/lib/util/compressor.hpp.html
title: lib/util/compressor.hpp
---
