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
  bundledCode: "#line 2 \"lib/util/lis.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \ntemplate <class T>\nstruct LIS {\n    std::vector<T> v;\n    std::vector<int>\
    \ p;\n    int n, max_len, last_idx;\n\n    LIS(const std::vector<T>& _v) : v(_v),\
    \ p(_v.size(), -1), n(_v.size()), max_len(0), last_idx(-1) {}\n\n    // strict\
    \ = true : \u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 (\u30C7\u30D5\u30A9\u30EB\u30C8\
    )\n    // strict = false: \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\n    int lis(bool\
    \ strict = true) {\n        if (n == 0) return 0;\n        \n        std::vector<T>\
    \ dp_val;\n        std::vector<int> dp_idx;\n        \n        for (int i = 0;\
    \ i < n; i++) {\n            T x = v[i];\n            auto it = strict \n    \
    \            ? std::lower_bound(dp_val.begin(), dp_val.end(), x)\n           \
    \     : std::upper_bound(dp_val.begin(), dp_val.end(), x);\n            \n   \
    \         int pos = it - dp_val.begin();\n            \n            if (pos >\
    \ 0) {\n                p[i] = dp_idx[pos - 1];\n            }\n            \n\
    \            if (it == dp_val.end()) {\n                dp_val.push_back(x);\n\
    \                dp_idx.push_back(i);\n            } else {\n                dp_val[pos]\
    \ = x;\n                dp_idx[pos] = i;\n            }\n        }\n        \n\
    \        max_len = dp_val.size();\n        last_idx = dp_idx.back();\n       \
    \ return max_len;\n    }\n\n    std::vector<int> restore(bool strict = true) {\n\
    \        lis(strict);\n        std::vector<int> res(max_len);\n        int curr\
    \ = last_idx;\n        for (int i = max_len - 1; i >= 0; i--) {\n            res[i]\
    \ = curr;\n            curr = p[curr];\n        }\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\ntemplate <class\
    \ T>\nstruct LIS {\n    std::vector<T> v;\n    std::vector<int> p;\n    int n,\
    \ max_len, last_idx;\n\n    LIS(const std::vector<T>& _v) : v(_v), p(_v.size(),\
    \ -1), n(_v.size()), max_len(0), last_idx(-1) {}\n\n    // strict = true : \u72ED\
    \u7FA9\u5358\u8ABF\u5897\u52A0 (\u30C7\u30D5\u30A9\u30EB\u30C8)\n    // strict\
    \ = false: \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\n    int lis(bool strict = true)\
    \ {\n        if (n == 0) return 0;\n        \n        std::vector<T> dp_val;\n\
    \        std::vector<int> dp_idx;\n        \n        for (int i = 0; i < n; i++)\
    \ {\n            T x = v[i];\n            auto it = strict \n                ?\
    \ std::lower_bound(dp_val.begin(), dp_val.end(), x)\n                : std::upper_bound(dp_val.begin(),\
    \ dp_val.end(), x);\n            \n            int pos = it - dp_val.begin();\n\
    \            \n            if (pos > 0) {\n                p[i] = dp_idx[pos -\
    \ 1];\n            }\n            \n            if (it == dp_val.end()) {\n  \
    \              dp_val.push_back(x);\n                dp_idx.push_back(i);\n  \
    \          } else {\n                dp_val[pos] = x;\n                dp_idx[pos]\
    \ = i;\n            }\n        }\n        \n        max_len = dp_val.size();\n\
    \        last_idx = dp_idx.back();\n        return max_len;\n    }\n\n    std::vector<int>\
    \ restore(bool strict = true) {\n        lis(strict);\n        std::vector<int>\
    \ res(max_len);\n        int curr = last_idx;\n        for (int i = max_len -\
    \ 1; i >= 0; i--) {\n            res[i] = curr;\n            curr = p[curr];\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/lis.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/lis.hpp
layout: document
redirect_from:
- /library/lib/util/lis.hpp
- /library/lib/util/lis.hpp.html
title: lib/util/lis.hpp
---
