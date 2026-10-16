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
  bundledCode: "#line 2 \"lib/ds/cartesiantree.hpp\"\n#include <vector>\n#include\
    \ <stack>\n#include <functional>\n\ntemplate <typename T, typename Compare = std::less<T>>\n\
    struct CartesianTree {\n    int root;\n        std::vector<int> lc, rc;\n\n  \
    \      CartesianTree(const std::vector<T>& a, Compare comp = Compare()) {\n  \
    \      int n = a.size();\n        lc.assign(n, -1);\n        rc.assign(n, -1);\n\
    \        std::stack<int> st;\n        for (int i = 0; i < n; i++) {\n        \
    \    // a[i] \u304C a[st.top()] \u3088\u308A\u3082\u300C\u89AA\u306B\u306A\u308B\
    \u3079\u304D\u6761\u4EF6\u300D\u3092\u6E80\u305F\u3059\u306A\u3089 pop \u3057\u3066\
    \u5DE6\u306E\u5B50\u306B\u3059\u308B\n            while (!st.empty() && comp(a[i],\
    \ a[st.top()])) {\n                lc[i] = st.top();\n                st.pop();\n\
    \            }\n            if (!st.empty()) {\n                rc[st.top()] =\
    \ i;\n            }\n            st.push(i);\n        }\n        while (!st.empty())\
    \ {\n            root = st.top();\n            st.pop();\n        }\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <stack>\n#include <functional>\n\
    \ntemplate <typename T, typename Compare = std::less<T>>\nstruct CartesianTree\
    \ {\n    int root;\n        std::vector<int> lc, rc;\n\n        CartesianTree(const\
    \ std::vector<T>& a, Compare comp = Compare()) {\n        int n = a.size();\n\
    \        lc.assign(n, -1);\n        rc.assign(n, -1);\n        std::stack<int>\
    \ st;\n        for (int i = 0; i < n; i++) {\n            // a[i] \u304C a[st.top()]\
    \ \u3088\u308A\u3082\u300C\u89AA\u306B\u306A\u308B\u3079\u304D\u6761\u4EF6\u300D\
    \u3092\u6E80\u305F\u3059\u306A\u3089 pop \u3057\u3066\u5DE6\u306E\u5B50\u306B\u3059\
    \u308B\n            while (!st.empty() && comp(a[i], a[st.top()])) {\n       \
    \         lc[i] = st.top();\n                st.pop();\n            }\n      \
    \      if (!st.empty()) {\n                rc[st.top()] = i;\n            }\n\
    \            st.push(i);\n        }\n        while (!st.empty()) {\n         \
    \   root = st.top();\n            st.pop();\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/ds/cartesiantree.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/ds/cartesiantree.hpp
layout: document
redirect_from:
- /library/lib/ds/cartesiantree.hpp
- /library/lib/ds/cartesiantree.hpp.html
title: lib/ds/cartesiantree.hpp
---
