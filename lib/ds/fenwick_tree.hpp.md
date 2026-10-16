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
  bundledCode: "#line 2 \"lib/ds/fenwick_tree.hpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate <typename T>\nstruct FenwickTree {\n    int n;\n    std::vector<T>\
    \ data;\n    \n    FenwickTree(int n_) : n(n_), data(n_ + 1, 0) {}\n    \n   \
    \ void add(int p, T x) {\n        p++; // 0-indexed\u306E\u5165\u529B\u30921-indexed\u306B\
    \u5909\u63DB\n        for (int i = p; i <= n; i += i & -i) {\n            data[i]\
    \ += x;\n        }\n    }\n    \n    T sum(int p) {\n        T s = 0;\n      \
    \  for (int i = p; i > 0; i -= i & -i) {\n            s += data[i];\n        }\n\
    \        return s;\n    }\n    \n    T sum(int l, int r){\n        return sum(r)\
    \ - sum(l);\n    }\n    \n    // \u7D2F\u7A4D\u548C\u304Cw\u4EE5\u4E0A\u306B\u306A\
    \u308B\u6700\u5C0F\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\u3092\u8FD4\
    \u3059\n    int lower_bound(T w) {\n        if (w <= 0) return 0;\n        int\
    \ x = 0;\n        int k = 1;\n        while (k * 2 <= n) k *= 2;\n        \n \
    \       for (; k > 0; k /= 2) {\n            if (x + k <= n && data[x + k] < w)\
    \ {\n                w -= data[x + k];\n                x += k;\n            }\n\
    \        }\n        return x; \n    }\n};\n\ntemplate <typename T>\nstruct ExtendedFenwickTree\
    \ {\n    int n;\n    int log_n;\n    std::vector<T> cnt_tree;\n    std::vector<T>\
    \ sum_tree;\n    std::vector<T> vals;\n\n    // \u5EA7\u6A19\u5727\u7E2E\u6E08\
    \u307F\u306E\u5024\u306E\u914D\u5217\u3092\u6E21\u3057\u3066\u521D\u671F\u5316\
    \n    ExtendedFenwickTree(const std::vector<T>& _vals) : vals(_vals) {\n     \
    \   n = vals.size();\n        log_n = 0;\n        while ((1 << log_n) <= n) log_n++;\n\
    \        cnt_tree.assign(n + 1, 0);\n        sum_tree.assign(n + 1, 0);\n    }\n\
    \n    // \u5727\u7E2E\u5F8C\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 p (0-indexed)\
    \ \u306B\u8981\u7D20\u3092 c \u500B\u8FFD\u52A0\n    // \u524A\u9664\u3059\u308B\
    \u5834\u5408\u306Fc\u306B\u8CA0\u306E\u5024\u3092\u6E21\u3059\n    void add(int\
    \ p, T c) {\n        assert(0 <= p && p < n);\n        T v = vals[p];\n      \
    \  for (int i = p + 1; i <= n; i += i & -i) {\n            cnt_tree[i] += c;\n\
    \            sum_tree[i] += c * v;\n        }\n    }\n    // \u5C0F\u3055\u3044\
    \u65B9\u304B\u3089 k \u500B\u76EE (1-indexed) \u306E\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n    T get_kth(T k) {\n        if (k <= 0) return vals[0];\n        T cnt\
    \ = 0;\n        int i = 0;\n        \n        for (int b = log_n; b >= 0; --b)\
    \ {\n            int j = i | (1 << b);\n            // \u7D2F\u7A4D\u500B\u6570\
    \u304C k \"\u672A\u6E80\" \u3067\u3042\u308B\u9650\u308A\u9032\u3080\n       \
    \     if (j <= n && cnt + cnt_tree[j] < k) {\n                cnt += cnt_tree[j];\n\
    \                i = j;\n            }\n        }\n        \n        // i \u306F\
    \ k \u756A\u76EE\u306E\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n\
    \        return vals[i];\n    }\n\n    // \u5C0F\u3055\u3044\u65B9\u304B\u3089\
    \ k \u500B\u306E\u8981\u7D20\u306E\u548C\u3092\u53D6\u5F97\u3059\u308B\n    T\
    \ get_sum(T k) {\n        if (k <= 0) return 0;\n        T cnt = 0;\n        T\
    \ sum = 0;\n        int i = 0;\n        \n        // Binary Lifting \u3067\u7D2F\
    \u7A4D\u500B\u6570\u304C k \u4EE5\u4E0B\u306B\u306A\u308B\u6700\u5927\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u63A2\u7D22\n        for (int b = log_n;\
    \ b >= 0; --b) {\n            int j = i | (1 << b);\n            if (j <= n &&\
    \ cnt + cnt_tree[j] <= k) {\n                cnt += cnt_tree[j];\n           \
    \     sum += sum_tree[j];\n                i = j;\n            }\n        }\n\
    \        \n        if (cnt < k && i < n) {\n            sum += (k - cnt) * vals[i];\n\
    \        }\n        \n        return sum;\n    }\n\n    // \u5727\u7E2E\u524D\u306E\
    \u5024 x \u672A\u6E80\u306E\u8981\u7D20\u306E\u500B\u6570\u3092\u53D6\u5F97\n\
    \    T count_less_than(T x) {\n        int p = std::lower_bound(vals.begin(),\
    \ vals.end(), x) - vals.begin();\n        T cnt = 0;\n        for (int i = p;\
    \ i > 0; i -= i & -i) {\n            cnt += cnt_tree[i];\n        }\n        return\
    \ cnt;\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\ntemplate <typename\
    \ T>\nstruct FenwickTree {\n    int n;\n    std::vector<T> data;\n    \n    FenwickTree(int\
    \ n_) : n(n_), data(n_ + 1, 0) {}\n    \n    void add(int p, T x) {\n        p++;\
    \ // 0-indexed\u306E\u5165\u529B\u30921-indexed\u306B\u5909\u63DB\n        for\
    \ (int i = p; i <= n; i += i & -i) {\n            data[i] += x;\n        }\n \
    \   }\n    \n    T sum(int p) {\n        T s = 0;\n        for (int i = p; i >\
    \ 0; i -= i & -i) {\n            s += data[i];\n        }\n        return s;\n\
    \    }\n    \n    T sum(int l, int r){\n        return sum(r) - sum(l);\n    }\n\
    \    \n    // \u7D2F\u7A4D\u548C\u304Cw\u4EE5\u4E0A\u306B\u306A\u308B\u6700\u5C0F\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9(0-indexed)\u3092\u8FD4\u3059\n    int\
    \ lower_bound(T w) {\n        if (w <= 0) return 0;\n        int x = 0;\n    \
    \    int k = 1;\n        while (k * 2 <= n) k *= 2;\n        \n        for (;\
    \ k > 0; k /= 2) {\n            if (x + k <= n && data[x + k] < w) {\n       \
    \         w -= data[x + k];\n                x += k;\n            }\n        }\n\
    \        return x; \n    }\n};\n\ntemplate <typename T>\nstruct ExtendedFenwickTree\
    \ {\n    int n;\n    int log_n;\n    std::vector<T> cnt_tree;\n    std::vector<T>\
    \ sum_tree;\n    std::vector<T> vals;\n\n    // \u5EA7\u6A19\u5727\u7E2E\u6E08\
    \u307F\u306E\u5024\u306E\u914D\u5217\u3092\u6E21\u3057\u3066\u521D\u671F\u5316\
    \n    ExtendedFenwickTree(const std::vector<T>& _vals) : vals(_vals) {\n     \
    \   n = vals.size();\n        log_n = 0;\n        while ((1 << log_n) <= n) log_n++;\n\
    \        cnt_tree.assign(n + 1, 0);\n        sum_tree.assign(n + 1, 0);\n    }\n\
    \n    // \u5727\u7E2E\u5F8C\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 p (0-indexed)\
    \ \u306B\u8981\u7D20\u3092 c \u500B\u8FFD\u52A0\n    // \u524A\u9664\u3059\u308B\
    \u5834\u5408\u306Fc\u306B\u8CA0\u306E\u5024\u3092\u6E21\u3059\n    void add(int\
    \ p, T c) {\n        assert(0 <= p && p < n);\n        T v = vals[p];\n      \
    \  for (int i = p + 1; i <= n; i += i & -i) {\n            cnt_tree[i] += c;\n\
    \            sum_tree[i] += c * v;\n        }\n    }\n    // \u5C0F\u3055\u3044\
    \u65B9\u304B\u3089 k \u500B\u76EE (1-indexed) \u306E\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n    T get_kth(T k) {\n        if (k <= 0) return vals[0];\n        T cnt\
    \ = 0;\n        int i = 0;\n        \n        for (int b = log_n; b >= 0; --b)\
    \ {\n            int j = i | (1 << b);\n            // \u7D2F\u7A4D\u500B\u6570\
    \u304C k \"\u672A\u6E80\" \u3067\u3042\u308B\u9650\u308A\u9032\u3080\n       \
    \     if (j <= n && cnt + cnt_tree[j] < k) {\n                cnt += cnt_tree[j];\n\
    \                i = j;\n            }\n        }\n        \n        // i \u306F\
    \ k \u756A\u76EE\u306E\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n\
    \        return vals[i];\n    }\n\n    // \u5C0F\u3055\u3044\u65B9\u304B\u3089\
    \ k \u500B\u306E\u8981\u7D20\u306E\u548C\u3092\u53D6\u5F97\u3059\u308B\n    T\
    \ get_sum(T k) {\n        if (k <= 0) return 0;\n        T cnt = 0;\n        T\
    \ sum = 0;\n        int i = 0;\n        \n        // Binary Lifting \u3067\u7D2F\
    \u7A4D\u500B\u6570\u304C k \u4EE5\u4E0B\u306B\u306A\u308B\u6700\u5927\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u63A2\u7D22\n        for (int b = log_n;\
    \ b >= 0; --b) {\n            int j = i | (1 << b);\n            if (j <= n &&\
    \ cnt + cnt_tree[j] <= k) {\n                cnt += cnt_tree[j];\n           \
    \     sum += sum_tree[j];\n                i = j;\n            }\n        }\n\
    \        \n        if (cnt < k && i < n) {\n            sum += (k - cnt) * vals[i];\n\
    \        }\n        \n        return sum;\n    }\n\n    // \u5727\u7E2E\u524D\u306E\
    \u5024 x \u672A\u6E80\u306E\u8981\u7D20\u306E\u500B\u6570\u3092\u53D6\u5F97\n\
    \    T count_less_than(T x) {\n        int p = std::lower_bound(vals.begin(),\
    \ vals.end(), x) - vals.begin();\n        T cnt = 0;\n        for (int i = p;\
    \ i > 0; i -= i & -i) {\n            cnt += cnt_tree[i];\n        }\n        return\
    \ cnt;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/ds/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/ds/fenwick_tree.hpp
layout: document
redirect_from:
- /library/lib/ds/fenwick_tree.hpp
- /library/lib/ds/fenwick_tree.hpp.html
title: lib/ds/fenwick_tree.hpp
---
