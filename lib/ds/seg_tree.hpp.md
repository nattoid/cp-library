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
  bundledCode: "#line 2 \"lib/ds/seg_tree.hpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate <typename T>\nstruct MultisetSegTree {\n    int n;\n    int sz;\n \
    \   std::vector<T> cnt;\n    std::vector<T> sum;\n    std::vector<T> vals;\n\n\
    \    MultisetSegTree(const std::vector<T>& _vals) : vals(_vals) {\n        n =\
    \ vals.size();\n        sz = 1;\n        while (sz < n) sz *= 2;\n        cnt.assign(2\
    \ * sz, 0);\n        sum.assign(2 * sz, 0);\n    }\n\n    // \u5727\u7E2E\u5F8C\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 p (0-indexed) \u306B\u8981\u7D20\u3092\
    \ c \u500B\u8FFD\u52A0\u3059\u308B\n    void add(int p, T c) {\n        assert(0\
    \ <= p && p < n);\n        T v = vals[p];\n        p += sz;\n        cnt[p] +=\
    \ c;\n        sum[p] += c * v;\n        while (p > 1) {\n            p >>= 1;\n\
    \            cnt[p] = cnt[2 * p] + cnt[2 * p + 1];\n            sum[p] = sum[2\
    \ * p] + sum[2 * p + 1];\n        }\n    }\n\n    // \u5C0F\u3055\u3044\u65B9\u304B\
    \u3089 k \u500B\u306E\u8981\u7D20\u306E\u548C\u3092\u53D6\u5F97\u3059\u308B\n\
    \    T get_sum(T k) {\n        if (k <= 0) return 0;\n        if (cnt[1] <= k)\
    \ return sum[1];\n        return query_rec(1, k);\n    }\n\nprivate:\n    T query_rec(int\
    \ node, T k) {\n        if (node >= sz) {\n            // \u8449\u306B\u5230\u9054\
    \u3057\u305F\u5834\u5408\u3001\u5FC5\u8981\u306A k \u500B\u5206\u3060\u3051\u306E\
    \u5024\u3092\u8FD4\u3059\n            return k * vals[node - sz];\n        }\n\
    \        if (cnt[2 * node] >= k) {\n            return query_rec(2 * node, k);\n\
    \        } else {\n            return sum[2 * node] + query_rec(2 * node + 1,\
    \ k - cnt[2 * node]);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\ntemplate <typename\
    \ T>\nstruct MultisetSegTree {\n    int n;\n    int sz;\n    std::vector<T> cnt;\n\
    \    std::vector<T> sum;\n    std::vector<T> vals;\n\n    MultisetSegTree(const\
    \ std::vector<T>& _vals) : vals(_vals) {\n        n = vals.size();\n        sz\
    \ = 1;\n        while (sz < n) sz *= 2;\n        cnt.assign(2 * sz, 0);\n    \
    \    sum.assign(2 * sz, 0);\n    }\n\n    // \u5727\u7E2E\u5F8C\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9 p (0-indexed) \u306B\u8981\u7D20\u3092 c \u500B\u8FFD\
    \u52A0\u3059\u308B\n    void add(int p, T c) {\n        assert(0 <= p && p < n);\n\
    \        T v = vals[p];\n        p += sz;\n        cnt[p] += c;\n        sum[p]\
    \ += c * v;\n        while (p > 1) {\n            p >>= 1;\n            cnt[p]\
    \ = cnt[2 * p] + cnt[2 * p + 1];\n            sum[p] = sum[2 * p] + sum[2 * p\
    \ + 1];\n        }\n    }\n\n    // \u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u500B\
    \u306E\u8981\u7D20\u306E\u548C\u3092\u53D6\u5F97\u3059\u308B\n    T get_sum(T\
    \ k) {\n        if (k <= 0) return 0;\n        if (cnt[1] <= k) return sum[1];\n\
    \        return query_rec(1, k);\n    }\n\nprivate:\n    T query_rec(int node,\
    \ T k) {\n        if (node >= sz) {\n            // \u8449\u306B\u5230\u9054\u3057\
    \u305F\u5834\u5408\u3001\u5FC5\u8981\u306A k \u500B\u5206\u3060\u3051\u306E\u5024\
    \u3092\u8FD4\u3059\n            return k * vals[node - sz];\n        }\n     \
    \   if (cnt[2 * node] >= k) {\n            return query_rec(2 * node, k);\n  \
    \      } else {\n            return sum[2 * node] + query_rec(2 * node + 1, k\
    \ - cnt[2 * node]);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/ds/seg_tree.hpp
  requiredBy: []
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/ds/seg_tree.hpp
layout: document
redirect_from:
- /library/lib/ds/seg_tree.hpp
- /library/lib/ds/seg_tree.hpp.html
title: lib/ds/seg_tree.hpp
---
