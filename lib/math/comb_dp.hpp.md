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
  bundledCode: "#line 2 \"lib/math/comb_dp.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \ntemplate <class T> struct Comb_dp {\n    std::vector<T> s2;\n    int max_n_s2\
    \ = -1;\n\n    void extend_S2(int n) {\n        if (n <= max_n_s2) return;\n \
    \       int new_n = std::max(n, max_n_s2 == -1 ? 1 : max_n_s2 * 2);\n        s2.resize((new_n\
    \ + 1) * (new_n + 2) / 2);\n\n        if (max_n_s2 == -1) {\n            s2[0]\
    \ = 1;\n            max_n_s2 = 0;\n        }\n        for (int i = max_n_s2 +\
    \ 1; i <= new_n; i++) {\n            int row_start = i * (i + 1) / 2;\n      \
    \      int prev_row_start = (i - 1) * i / 2;\n            \n            s2[row_start]\
    \ = 0; // k = 0\n            for (int j = 1; j < i; j++) {\n                s2[row_start\
    \ + j] = s2[prev_row_start + j - 1] + s2[prev_row_start + j] * j;\n          \
    \  }\n            s2[row_start + i] = 1; // k = i\n        }\n        max_n_s2\
    \ = new_n;\n    }\n\n    T S2(int n, int k) {\n        if (k < 0 || n < k) return\
    \ 0;\n        extend_S2(n);\n        return s2[n * (n + 1) / 2 + k];\n    }\n\n\
    \    std::vector<T> s1;\n    int max_n_s1 = -1;\n\n    void extend_S1(int n) {\n\
    \        if (n <= max_n_s1) return;\n        int new_n = std::max(n, max_n_s1\
    \ == -1 ? 1 : max_n_s1 * 2);\n        s1.resize((new_n + 1) * (new_n + 2) / 2);\n\
    \n        if (max_n_s1 == -1) {\n            s1[0] = 1;\n            max_n_s1\
    \ = 0;\n        }\n        for (int i = max_n_s1 + 1; i <= new_n; i++) {\n   \
    \         int row_start = i * (i + 1) / 2;\n            int prev_row_start = (i\
    \ - 1) * i / 2;\n            \n            s1[row_start] = 0; // k = 0\n     \
    \       for (int j = 1; j < i; j++) {\n                s1[row_start + j] = s1[prev_row_start\
    \ + j - 1] + s1[prev_row_start + j] * (i - 1);\n            }\n            s1[row_start\
    \ + i] = 1; // k = i\n        }\n        max_n_s1 = new_n;\n    }\n\n    T S1(int\
    \ n, int k) {\n        if (k < 0 || n < k) return 0;\n        extend_S1(n);\n\
    \        return s1[n * (n + 1) / 2 + k];\n    }\n    \n    std::vector<T> b;\n\
    \    int max_n_b = -1;\n\n    void extend_B(int n){\n        if (n <= max_n_b)\
    \ return;\n        int new_n = std::max(n, max_n_b == -1 ? 1 : max_n_b * 2);\n\
    \        b.resize((new_n + 1) * (new_n + 2) / 2);\n\n        if (max_n_b == -1)\
    \ {\n            b[0] = 1;\n            max_n_b = 0;\n        }\n        for (int\
    \ i = max_n_b + 1; i <= new_n; i++) {\n            int row_start = i * (i + 1)\
    \ / 2;\n            \n            b[row_start] = 0; // k = 0\n            for\
    \ (int j = 1; j <= i; j++) {\n                b[row_start + j] = b[row_start +\
    \ j - 1] + S2(i, j);\n            }\n        }\n        max_n_b = new_n;\n   \
    \ }\n\n    T B(int n, int k){\n        if(k < 0) return 0;\n        extend_B(n);\n\
    \        return b[n * (n + 1) / 2 + std::min(k, n)];\n    }\n\n    T B(int n){\n\
    \        return B(n, n);\n    }\n\n    std::vector<T> part_table;\n    int max_n_part\
    \ = -1;\n\n    void extend_partition(int n){\n        if (n <= max_n_part) return;\n\
    \        int new_n = std::max(n, max_n_part == -1 ? 1 : max_n_part * 2);\n   \
    \     part_table.resize((new_n + 1) * (new_n + 2) / 2);\n\n        if (max_n_part\
    \ == -1) {\n            part_table[0] = 1; // n = 0, k = 0\n            max_n_part\
    \ = 0;\n        }\n        for (int i = max_n_part + 1; i <= new_n; i++) {\n \
    \           int row_start = i * (i + 1) / 2;\n            \n            part_table[row_start]\
    \ = 0; // k = 0\n            for (int j = 1; j <= i; j++) {\n                int\
    \ prev_idx = (i - j) * (i - j + 1) / 2 + std::min(j, i - j);\n               \
    \ part_table[row_start + j] = part_table[row_start + j - 1] + part_table[prev_idx];\n\
    \            }\n        }\n        max_n_part = new_n;\n    }\n\n    T part(int\
    \ n, int k){\n        if(k < 0 || n < 0) return 0;\n        extend_partition(n);\n\
    \        return part_table[n * (n + 1) / 2 + std::min(k, n)];\n    }\n\n    template\
    \ <class F>\n    void enumerate_partition(int n, int max_v, std::vector<int>&\
    \ current, F f) {\n        if (n == 0) {\n            f(current);\n          \
    \  return;\n        }\n        for (int i = std::min(n, max_v); i >= 1; i--) {\n\
    \            current.push_back(i);\n            enumerate_partition(n - i, i,\
    \ current, f);\n            current.pop_back(); \n        }\n    }\n\n    template\
    \ <class F>\n    void each_partition(int n, F f) {\n        if (n < 0) return;\n\
    \        std::vector<int> current;\n        enumerate_partition(n, n, current,\
    \ f);\n    }\n};\n\ntemplate <class T>\nstd::vector<T> partition_array(int n)\
    \ {\n    std::vector<T> p(n + 1, 0);\n    p[0] = 1;\n    for (int i = 1; i <=\
    \ n; i++) {\n        for (int k = 1; ; k++) {\n            int g1 = k * (3 * k\
    \ - 1) / 2;\n            int g2 = k * (3 * k + 1) / 2;\n            \n       \
    \     if (g1 > i) break;\n            \n            if (k % 2 != 0) {\n      \
    \          p[i] += p[i - g1];\n                if (g2 <= i) p[i] += p[i - g2];\n\
    \            } else {\n                p[i] -= p[i - g1];\n                if\
    \ (g2 <= i) p[i] -= p[i - g2];\n            }\n        }\n    }\n    return p;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\ntemplate <class\
    \ T> struct Comb_dp {\n    std::vector<T> s2;\n    int max_n_s2 = -1;\n\n    void\
    \ extend_S2(int n) {\n        if (n <= max_n_s2) return;\n        int new_n =\
    \ std::max(n, max_n_s2 == -1 ? 1 : max_n_s2 * 2);\n        s2.resize((new_n +\
    \ 1) * (new_n + 2) / 2);\n\n        if (max_n_s2 == -1) {\n            s2[0] =\
    \ 1;\n            max_n_s2 = 0;\n        }\n        for (int i = max_n_s2 + 1;\
    \ i <= new_n; i++) {\n            int row_start = i * (i + 1) / 2;\n         \
    \   int prev_row_start = (i - 1) * i / 2;\n            \n            s2[row_start]\
    \ = 0; // k = 0\n            for (int j = 1; j < i; j++) {\n                s2[row_start\
    \ + j] = s2[prev_row_start + j - 1] + s2[prev_row_start + j] * j;\n          \
    \  }\n            s2[row_start + i] = 1; // k = i\n        }\n        max_n_s2\
    \ = new_n;\n    }\n\n    T S2(int n, int k) {\n        if (k < 0 || n < k) return\
    \ 0;\n        extend_S2(n);\n        return s2[n * (n + 1) / 2 + k];\n    }\n\n\
    \    std::vector<T> s1;\n    int max_n_s1 = -1;\n\n    void extend_S1(int n) {\n\
    \        if (n <= max_n_s1) return;\n        int new_n = std::max(n, max_n_s1\
    \ == -1 ? 1 : max_n_s1 * 2);\n        s1.resize((new_n + 1) * (new_n + 2) / 2);\n\
    \n        if (max_n_s1 == -1) {\n            s1[0] = 1;\n            max_n_s1\
    \ = 0;\n        }\n        for (int i = max_n_s1 + 1; i <= new_n; i++) {\n   \
    \         int row_start = i * (i + 1) / 2;\n            int prev_row_start = (i\
    \ - 1) * i / 2;\n            \n            s1[row_start] = 0; // k = 0\n     \
    \       for (int j = 1; j < i; j++) {\n                s1[row_start + j] = s1[prev_row_start\
    \ + j - 1] + s1[prev_row_start + j] * (i - 1);\n            }\n            s1[row_start\
    \ + i] = 1; // k = i\n        }\n        max_n_s1 = new_n;\n    }\n\n    T S1(int\
    \ n, int k) {\n        if (k < 0 || n < k) return 0;\n        extend_S1(n);\n\
    \        return s1[n * (n + 1) / 2 + k];\n    }\n    \n    std::vector<T> b;\n\
    \    int max_n_b = -1;\n\n    void extend_B(int n){\n        if (n <= max_n_b)\
    \ return;\n        int new_n = std::max(n, max_n_b == -1 ? 1 : max_n_b * 2);\n\
    \        b.resize((new_n + 1) * (new_n + 2) / 2);\n\n        if (max_n_b == -1)\
    \ {\n            b[0] = 1;\n            max_n_b = 0;\n        }\n        for (int\
    \ i = max_n_b + 1; i <= new_n; i++) {\n            int row_start = i * (i + 1)\
    \ / 2;\n            \n            b[row_start] = 0; // k = 0\n            for\
    \ (int j = 1; j <= i; j++) {\n                b[row_start + j] = b[row_start +\
    \ j - 1] + S2(i, j);\n            }\n        }\n        max_n_b = new_n;\n   \
    \ }\n\n    T B(int n, int k){\n        if(k < 0) return 0;\n        extend_B(n);\n\
    \        return b[n * (n + 1) / 2 + std::min(k, n)];\n    }\n\n    T B(int n){\n\
    \        return B(n, n);\n    }\n\n    std::vector<T> part_table;\n    int max_n_part\
    \ = -1;\n\n    void extend_partition(int n){\n        if (n <= max_n_part) return;\n\
    \        int new_n = std::max(n, max_n_part == -1 ? 1 : max_n_part * 2);\n   \
    \     part_table.resize((new_n + 1) * (new_n + 2) / 2);\n\n        if (max_n_part\
    \ == -1) {\n            part_table[0] = 1; // n = 0, k = 0\n            max_n_part\
    \ = 0;\n        }\n        for (int i = max_n_part + 1; i <= new_n; i++) {\n \
    \           int row_start = i * (i + 1) / 2;\n            \n            part_table[row_start]\
    \ = 0; // k = 0\n            for (int j = 1; j <= i; j++) {\n                int\
    \ prev_idx = (i - j) * (i - j + 1) / 2 + std::min(j, i - j);\n               \
    \ part_table[row_start + j] = part_table[row_start + j - 1] + part_table[prev_idx];\n\
    \            }\n        }\n        max_n_part = new_n;\n    }\n\n    T part(int\
    \ n, int k){\n        if(k < 0 || n < 0) return 0;\n        extend_partition(n);\n\
    \        return part_table[n * (n + 1) / 2 + std::min(k, n)];\n    }\n\n    template\
    \ <class F>\n    void enumerate_partition(int n, int max_v, std::vector<int>&\
    \ current, F f) {\n        if (n == 0) {\n            f(current);\n          \
    \  return;\n        }\n        for (int i = std::min(n, max_v); i >= 1; i--) {\n\
    \            current.push_back(i);\n            enumerate_partition(n - i, i,\
    \ current, f);\n            current.pop_back(); \n        }\n    }\n\n    template\
    \ <class F>\n    void each_partition(int n, F f) {\n        if (n < 0) return;\n\
    \        std::vector<int> current;\n        enumerate_partition(n, n, current,\
    \ f);\n    }\n};\n\ntemplate <class T>\nstd::vector<T> partition_array(int n)\
    \ {\n    std::vector<T> p(n + 1, 0);\n    p[0] = 1;\n    for (int i = 1; i <=\
    \ n; i++) {\n        for (int k = 1; ; k++) {\n            int g1 = k * (3 * k\
    \ - 1) / 2;\n            int g2 = k * (3 * k + 1) / 2;\n            \n       \
    \     if (g1 > i) break;\n            \n            if (k % 2 != 0) {\n      \
    \          p[i] += p[i - g1];\n                if (g2 <= i) p[i] += p[i - g2];\n\
    \            } else {\n                p[i] -= p[i - g1];\n                if\
    \ (g2 <= i) p[i] -= p[i - g2];\n            }\n        }\n    }\n    return p;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/comb_dp.hpp
  requiredBy: []
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/comb_dp.hpp
layout: document
redirect_from:
- /library/lib/math/comb_dp.hpp
- /library/lib/math/comb_dp.hpp.html
title: lib/math/comb_dp.hpp
---
