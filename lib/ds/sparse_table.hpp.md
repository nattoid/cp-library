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
  bundledCode: "#line 1 \"lib/ds/sparse_table.hpp\"\ntemplate <typename T, typename\
    \ F>\nstruct SparseTable {\n    int n;\n    std::vector<std::vector<T>> st;\n\
    \    F op;\n\n    SparseTable() {}\n    \n    SparseTable(const std::vector<T>&\
    \ v, F f) : n(v.size()), op(f) {\n        int max_k = std::bit_width(unsigned(n))\
    \ - 1;\n        st.assign(max_k + 1, std::vector<T>(n));\n        for (int i =\
    \ 0; i < n; ++i) {\n            st[0][i] = v[i];\n        }\n        for (int\
    \ k = 1; k <= max_k; ++k) {\n            for (int i = 0; i + (1 << k) <= n; ++i)\
    \ {\n                st[k][i] = op(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);\n\
    \            }\n        }\n    }\n\n    // \u533A\u9593 [l, r) \u306E\u6F14\u7B97\
    \u7D50\u679C\u3092\u8FD4\u3059\n    T query(int l, int r) const {\n        assert(0\
    \ <= l && l < r && r <= n);\n        int k = std::bit_width(unsigned(r - l)) -\
    \ 1;\n        return op(st[k][l], st[k][r - (1 << k)]);\n    }\n};\n"
  code: "template <typename T, typename F>\nstruct SparseTable {\n    int n;\n   \
    \ std::vector<std::vector<T>> st;\n    F op;\n\n    SparseTable() {}\n    \n \
    \   SparseTable(const std::vector<T>& v, F f) : n(v.size()), op(f) {\n       \
    \ int max_k = std::bit_width(unsigned(n)) - 1;\n        st.assign(max_k + 1, std::vector<T>(n));\n\
    \        for (int i = 0; i < n; ++i) {\n            st[0][i] = v[i];\n       \
    \ }\n        for (int k = 1; k <= max_k; ++k) {\n            for (int i = 0; i\
    \ + (1 << k) <= n; ++i) {\n                st[k][i] = op(st[k - 1][i], st[k -\
    \ 1][i + (1 << (k - 1))]);\n            }\n        }\n    }\n\n    // \u533A\u9593\
    \ [l, r) \u306E\u6F14\u7B97\u7D50\u679C\u3092\u8FD4\u3059\n    T query(int l,\
    \ int r) const {\n        assert(0 <= l && l < r && r <= n);\n        int k =\
    \ std::bit_width(unsigned(r - l)) - 1;\n        return op(st[k][l], st[k][r -\
    \ (1 << k)]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/ds/sparse_table.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/ds/sparse_table.hpp
layout: document
redirect_from:
- /library/lib/ds/sparse_table.hpp
- /library/lib/ds/sparse_table.hpp.html
title: lib/ds/sparse_table.hpp
---
