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
  bundledCode: "#line 2 \"lib/misc/mo.hpp\"\n#include <vector>\n#include <numeric>\n\
    #include <cmath>\n#include <algorithm>\n#include <cassert>\n\nstruct Mo {\n  int\
    \ width;\n  std::vector<int> left, right, order;\n\n  Mo(int N, int Q) : order(Q)\
    \ {\n    width = std::max<int>(1, 1.0 * N / std::max<double>(1.0, std::sqrt(Q\
    \ * 2.0 / 3.0)));\n    std::iota(std::begin(order), std::end(order), 0);\n  }\n\
    \n  void insert(int l, int r) { /* [l, r) */\n    left.emplace_back(l);\n    right.emplace_back(r);\n\
    \  }\n\n  template <typename AL, typename AR, typename DL, typename DR, typename\
    \ REM>\n  void run(const AL &add_left, const AR &add_right, const DL &delete_left,\n\
    \           const DR &delete_right, const REM &rem) {\n    assert(left.size()\
    \ == order.size());\n    std::sort(std::begin(order), std::end(order), [&](int\
    \ a, int b) {\n      int ablock = left[a] / width, bblock = left[b] / width;\n\
    \      if (ablock != bblock) return ablock < bblock;\n      if (ablock & 1) return\
    \ right[a] < right[b];\n      return right[a] > right[b];\n    });\n    int nl\
    \ = 0, nr = 0;\n    for (auto idx : order) {\n      while (nl > left[idx]) add_left(--nl);\n\
    \      while (nr < right[idx]) add_right(nr++);\n      while (nl < left[idx])\
    \ delete_left(nl++);\n      while (nr > right[idx]) delete_right(--nr);\n    \
    \  rem(idx);\n    }\n  }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n#include <cmath>\n#include\
    \ <algorithm>\n#include <cassert>\n\nstruct Mo {\n  int width;\n  std::vector<int>\
    \ left, right, order;\n\n  Mo(int N, int Q) : order(Q) {\n    width = std::max<int>(1,\
    \ 1.0 * N / std::max<double>(1.0, std::sqrt(Q * 2.0 / 3.0)));\n    std::iota(std::begin(order),\
    \ std::end(order), 0);\n  }\n\n  void insert(int l, int r) { /* [l, r) */\n  \
    \  left.emplace_back(l);\n    right.emplace_back(r);\n  }\n\n  template <typename\
    \ AL, typename AR, typename DL, typename DR, typename REM>\n  void run(const AL\
    \ &add_left, const AR &add_right, const DL &delete_left,\n           const DR\
    \ &delete_right, const REM &rem) {\n    assert(left.size() == order.size());\n\
    \    std::sort(std::begin(order), std::end(order), [&](int a, int b) {\n     \
    \ int ablock = left[a] / width, bblock = left[b] / width;\n      if (ablock !=\
    \ bblock) return ablock < bblock;\n      if (ablock & 1) return right[a] < right[b];\n\
    \      return right[a] > right[b];\n    });\n    int nl = 0, nr = 0;\n    for\
    \ (auto idx : order) {\n      while (nl > left[idx]) add_left(--nl);\n      while\
    \ (nr < right[idx]) add_right(nr++);\n      while (nl < left[idx]) delete_left(nl++);\n\
    \      while (nr > right[idx]) delete_right(--nr);\n      rem(idx);\n    }\n \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/misc/mo.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/mo.hpp
layout: document
redirect_from:
- /library/lib/misc/mo.hpp
- /library/lib/misc/mo.hpp.html
title: lib/misc/mo.hpp
---
