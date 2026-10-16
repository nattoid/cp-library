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
  bundledCode: "#line 2 \"lib/modulo/binomial.hpp\"\n\n#include <cassert>\n#include\
    \ <type_traits>\n#include <vector>\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u306E MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\
    \u3052\u308B\u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\u500D\
    \u901F\u304F\u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\u524D\
    \u8A08\u7B97\u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\u5BFE\
    \u7B56\u6E08\u307F\ntemplate <typename T>\nstruct Binomial {\n  std::vector<T>\
    \ f, g, h;\n  Binomial(int MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\"\
    );\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n \
    \   if (MAX > 0) extend(MAX + 1);\n  }\n\n  void extend(int m = -1) {\n    int\
    \ n = f.size();\n    if (m == -1) m = n * 2;\n    m = std::min<int>(m, T::get_mod());\n\
    \    if (n >= m) return;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n\
    \    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m -\
    \ 1].inverse();\n    h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2;\
    \ i >= n; i--) {\n      g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i -\
    \ 1];\n    }\n  }\n\n  T fac(int i) {\n    if (i < 0) return T(0);\n    while\
    \ (i >= (int)f.size()) extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n\
    \    if (i < 0) return T(0);\n    while (i >= (int)g.size()) extend();\n    return\
    \ g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i\
    \ >= (int)h.size()) extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n\
    \    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r)\
    \ * finv(r);\n  }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\
    \n  template <typename I>\n  T multinomial(const std::vector<I>& r) {\n    static_assert(std::is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ std::vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n,\
    \ int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n\
    \    r = std::min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) *\
    \ (n--);\n    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n <\
    \ r || r < 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r]\
    \ 1 / (1-x)^n\n  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n \
    \   return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\
    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306E MAX \u306B \u300CC(n, r) \u3084\
    \ fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\u3052\u308B\u6700\u5927\u306E n\
    \ \u300D\n// \u3092\u5165\u308C\u308B\u3068\u500D\u901F\u304F\u3089\u3044\u306B\
    \u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\u524D\u8A08\u7B97\u3057\u3066 0\
    \ \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\u5BFE\u7B56\u6E08\u307F\ntemplate\
    \ <typename T>\nstruct Binomial {\n  std::vector<T> f, g, h;\n  Binomial(int MAX\
    \ = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\");\n    f.resize(1,\
    \ T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n    if (MAX > 0) extend(MAX\
    \ + 1);\n  }\n\n  void extend(int m = -1) {\n    int n = f.size();\n    if (m\
    \ == -1) m = n * 2;\n    m = std::min<int>(m, T::get_mod());\n    if (n >= m)\
    \ return;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n    for (int\
    \ i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m - 1].inverse();\n\
    \    h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2; i >= n; i--) {\n\
    \      g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i - 1];\n    }\n  }\n\
    \n  T fac(int i) {\n    if (i < 0) return T(0);\n    while (i >= (int)f.size())\
    \ extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n    if (i < 0) return\
    \ T(0);\n    while (i >= (int)g.size()) extend();\n    return g[i];\n  }\n\n \
    \ T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i >= (int)h.size())\
    \ extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n    if (n < 0 ||\
    \ n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n \
    \ }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\n  template <typename\
    \ I>\n  T multinomial(const std::vector<I>& r) {\n    static_assert(std::is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ std::vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n,\
    \ int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n\
    \    r = std::min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) *\
    \ (n--);\n    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n <\
    \ r || r < 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r]\
    \ 1 / (1-x)^n\n  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n \
    \   return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/modulo/binomial.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/modulo/binomial.hpp
layout: document
redirect_from:
- /library/lib/modulo/binomial.hpp
- /library/lib/modulo/binomial.hpp.html
title: lib/modulo/binomial.hpp
---
