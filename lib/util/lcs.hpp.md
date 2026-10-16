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
  bundledCode: "#line 2 \"lib/util/lcs.hpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cstdint>\n\ntemplate <typename T>\nint fast_lcs(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    int n = a.size();\n    int m = b.size();\n\
    \    if (n == 0 || m == 0) return 0;\n\n    std::vector<T> vals = b;\n    std::sort(vals.begin(),\
    \ vals.end());\n    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());\n\
    \n    int k = vals.size();\n    int blocks = (m + 63) / 64;\n    std::vector<std::vector<uint64_t>>\
    \ pos(k, std::vector<uint64_t>(blocks, 0));\n\n    for (int i = 0; i < m; ++i)\
    \ {\n        int idx = std::lower_bound(vals.begin(), vals.end(), b[i]) - vals.begin();\n\
    \        pos[idx][i / 64] |= (1ULL << (i % 64));\n    }\n\n    std::vector<uint64_t>\
    \ dp(blocks, 0);\n\n    for (int i = 0; i < n; ++i) {\n        auto it = std::lower_bound(vals.begin(),\
    \ vals.end(), a[i]);\n        if (it == vals.end() || *it != a[i]) continue;\n\
    \        \n        int idx = it - vals.begin();\n        const auto& p = pos[idx];\n\
    \n        uint64_t carry = 1;\n        uint64_t borrow = 0;\n\n        for (int\
    \ j = 0; j < blocks; ++j) {\n            uint64_t u = dp[j] | p[j];\n        \
    \    uint64_t v = (dp[j] << 1) | carry;\n            carry = dp[j] >> 63;\n\n\
    \            uint64_t diff = u - v - borrow;\n            if (u < v || (u == v\
    \ && borrow == 1)) {\n                borrow = 1;\n            } else {\n    \
    \            borrow = 0;\n            }\n            \n            dp[j] = u &\
    \ (u ^ diff);\n        }\n    }\n\n    int lcs_len = 0;\n    for (int i = 0; i\
    \ < blocks; ++i) {\n        lcs_len += __builtin_popcountll(dp[i]);\n    }\n \
    \   return lcs_len;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cstdint>\n\
    \ntemplate <typename T>\nint fast_lcs(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = a.size();\n    int m = b.size();\n    if (n == 0 || m == 0)\
    \ return 0;\n\n    std::vector<T> vals = b;\n    std::sort(vals.begin(), vals.end());\n\
    \    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());\n\n    int\
    \ k = vals.size();\n    int blocks = (m + 63) / 64;\n    std::vector<std::vector<uint64_t>>\
    \ pos(k, std::vector<uint64_t>(blocks, 0));\n\n    for (int i = 0; i < m; ++i)\
    \ {\n        int idx = std::lower_bound(vals.begin(), vals.end(), b[i]) - vals.begin();\n\
    \        pos[idx][i / 64] |= (1ULL << (i % 64));\n    }\n\n    std::vector<uint64_t>\
    \ dp(blocks, 0);\n\n    for (int i = 0; i < n; ++i) {\n        auto it = std::lower_bound(vals.begin(),\
    \ vals.end(), a[i]);\n        if (it == vals.end() || *it != a[i]) continue;\n\
    \        \n        int idx = it - vals.begin();\n        const auto& p = pos[idx];\n\
    \n        uint64_t carry = 1;\n        uint64_t borrow = 0;\n\n        for (int\
    \ j = 0; j < blocks; ++j) {\n            uint64_t u = dp[j] | p[j];\n        \
    \    uint64_t v = (dp[j] << 1) | carry;\n            carry = dp[j] >> 63;\n\n\
    \            uint64_t diff = u - v - borrow;\n            if (u < v || (u == v\
    \ && borrow == 1)) {\n                borrow = 1;\n            } else {\n    \
    \            borrow = 0;\n            }\n            \n            dp[j] = u &\
    \ (u ^ diff);\n        }\n    }\n\n    int lcs_len = 0;\n    for (int i = 0; i\
    \ < blocks; ++i) {\n        lcs_len += __builtin_popcountll(dp[i]);\n    }\n \
    \   return lcs_len;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/lcs.hpp
  requiredBy: []
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/lcs.hpp
layout: document
redirect_from:
- /library/lib/util/lcs.hpp
- /library/lib/util/lcs.hpp.html
title: lib/util/lcs.hpp
---
