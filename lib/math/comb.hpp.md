---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/fps/lagrange-interpolation-point.hpp
    title: lib/fps/lagrange-interpolation-point.hpp
  - icon: ':warning:'
    path: lib/fps/taylor-shift.hpp
    title: "\u5E73\u884C\u79FB\u52D5"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/comb.hpp\"\n#include <algorithm>\r\n#include <cassert>\r\
    \n#include <type_traits>\r\n#include <vector>\r\n\r\ntemplate <class T>\r\nstruct\
    \ Comb {\r\n    std::vector<T> fac, invfac, invs;\r\n\r\n    Comb(int MAX = 0)\
    \ {\r\n        assert(T::mod() != 0 && \"Comb<mint>()\");\r\n        fac.resize(1,\
    \ 1);\r\n        invfac.resize(1, 1);\r\n        invs.resize(1, 1);\r\n      \
    \  if (MAX > 0) extend(MAX + 1);\r\n    }\r\n\r\n    void extend(int n) {\r\n\
    \        int sz = fac.size();\r\n        if (n < sz) return;\r\n        long long\
    \ p = T::mod();\r\n        int new_sz = std::min((long long)std::max(n + 1, sz\
    \ * 2), p);\r\n\r\n        fac.resize(new_sz);\r\n        invfac.resize(new_sz);\r\
    \n        invs.resize(new_sz);\r\n\r\n        for (int i = sz; i < new_sz; i++)\
    \ {\r\n            fac[i] = fac[i - 1] * i;\r\n        }\r\n        invfac[new_sz\
    \ - 1] = fac.back().inv();\r\n        invs[new_sz - 1] = invfac[new_sz - 1] *\
    \ fac[new_sz - 2];\r\n\r\n        for (int i = new_sz - 1; i > sz; i--) {\r\n\
    \            invfac[i - 1] = invfac[i] * i;\r\n            invs[i - 1] = invfac[i\
    \ - 1] * fac[i - 2];\r\n        }\r\n    }\r\n\r\n    T C(int n, int r) {\r\n\
    \        if (r < 0 || n < r) return 0;\r\n        extend(n);\r\n        return\
    \ fac[n] * invfac[r] * invfac[n - r];\r\n    }\r\n\r\n    inline T operator()(int\
    \ n, int r) {\r\n        return C(n, r);\r\n    }\r\n\r\n    T C_large(long long\
    \ n, int r) {\r\n        if (r < 0 || n < r) return 0;\r\n        extend(r);\r\
    \n        T res = 1;\r\n        for (int i = 0; i < r; i++) res = res * T(n -\
    \ i);\r\n        return res * invfac[r];\r\n    }\r\n\r\n    T Lucas(long long\
    \ n, long long r) {\r\n        if (n < 0 || r < 0 || n < r) return 0;\r\n    \
    \    if (r == 0) return 1;\r\n        long long p = T::mod();\r\n        T res\
    \ = 1;\r\n        while (n > 0 || r > 0) {\r\n            long long ni = n % p;\r\
    \n            long long ri = r % p;\r\n            if (ni < ri) return 0;\r\n\
    \            res = res * C(ni, ri);\r\n            n /= p;\r\n            r /=\
    \ p;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    T P(int n, int r)\
    \ {\r\n        if (r < 0 || n < r) return 0;\r\n        extend(n);\r\n       \
    \ return fac[n] * invfac[n - r];\r\n    }\r\n\r\n    T fact(int n) {\r\n     \
    \   if (n < 0) return 0;\r\n        extend(n);\r\n        return fac[n];\r\n \
    \   }\r\n\r\n    T finv(int n) {\r\n        if (n < 0) return 0;\r\n        extend(n);\r\
    \n        return invfac[n];\r\n    }\r\n\r\n    T inv(int n) {\r\n        if (n\
    \ < 0) return -inv(-n);\r\n        extend(n);\r\n        return invs[n];\r\n \
    \   }\r\n\r\n    T S2_single(int n, int k) {\r\n        if (k < 0 || n < k) return\
    \ 0;\r\n        T res = 0;\r\n        for (int i = 0; i <= k; i++) {\r\n     \
    \       T x = i;\r\n            res = C(k, i) * x.pow(n) - res;\r\n        }\r\
    \n        return res * finv(k);\r\n    }\r\n\r\n    T H(int n, int r) {\r\n  \
    \      if (n < 0 || r < 0) return 0;\r\n        return r == 0 ? 1 : C(n + r -\
    \ 1, r);\r\n    }\r\n\r\n    template <typename I>\r\n    T multinomial(const\
    \ std::vector<I>& r) {\r\n        static_assert(std::is_integral<I>::value ==\
    \ true);\r\n        int n = 0;\r\n        for (auto& x : r) {\r\n            if\
    \ (x < 0) return 0;\r\n            n += x;\r\n        }\r\n        T res = fact(n);\r\
    \n        for (auto& x : r) res *= finv(x);\r\n        return res;\r\n    }\r\n\
    \r\n    template <typename I>\r\n    T operator()(const std::vector<I>& r) {\r\
    \n        return multinomial(r);\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <type_traits>\r\
    \n#include <vector>\r\n\r\ntemplate <class T>\r\nstruct Comb {\r\n    std::vector<T>\
    \ fac, invfac, invs;\r\n\r\n    Comb(int MAX = 0) {\r\n        assert(T::mod()\
    \ != 0 && \"Comb<mint>()\");\r\n        fac.resize(1, 1);\r\n        invfac.resize(1,\
    \ 1);\r\n        invs.resize(1, 1);\r\n        if (MAX > 0) extend(MAX + 1);\r\
    \n    }\r\n\r\n    void extend(int n) {\r\n        int sz = fac.size();\r\n  \
    \      if (n < sz) return;\r\n        long long p = T::mod();\r\n        int new_sz\
    \ = std::min((long long)std::max(n + 1, sz * 2), p);\r\n\r\n        fac.resize(new_sz);\r\
    \n        invfac.resize(new_sz);\r\n        invs.resize(new_sz);\r\n\r\n     \
    \   for (int i = sz; i < new_sz; i++) {\r\n            fac[i] = fac[i - 1] * i;\r\
    \n        }\r\n        invfac[new_sz - 1] = fac.back().inv();\r\n        invs[new_sz\
    \ - 1] = invfac[new_sz - 1] * fac[new_sz - 2];\r\n\r\n        for (int i = new_sz\
    \ - 1; i > sz; i--) {\r\n            invfac[i - 1] = invfac[i] * i;\r\n      \
    \      invs[i - 1] = invfac[i - 1] * fac[i - 2];\r\n        }\r\n    }\r\n\r\n\
    \    T C(int n, int r) {\r\n        if (r < 0 || n < r) return 0;\r\n        extend(n);\r\
    \n        return fac[n] * invfac[r] * invfac[n - r];\r\n    }\r\n\r\n    inline\
    \ T operator()(int n, int r) {\r\n        return C(n, r);\r\n    }\r\n\r\n   \
    \ T C_large(long long n, int r) {\r\n        if (r < 0 || n < r) return 0;\r\n\
    \        extend(r);\r\n        T res = 1;\r\n        for (int i = 0; i < r; i++)\
    \ res = res * T(n - i);\r\n        return res * invfac[r];\r\n    }\r\n\r\n  \
    \  T Lucas(long long n, long long r) {\r\n        if (n < 0 || r < 0 || n < r)\
    \ return 0;\r\n        if (r == 0) return 1;\r\n        long long p = T::mod();\r\
    \n        T res = 1;\r\n        while (n > 0 || r > 0) {\r\n            long long\
    \ ni = n % p;\r\n            long long ri = r % p;\r\n            if (ni < ri)\
    \ return 0;\r\n            res = res * C(ni, ri);\r\n            n /= p;\r\n \
    \           r /= p;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    T\
    \ P(int n, int r) {\r\n        if (r < 0 || n < r) return 0;\r\n        extend(n);\r\
    \n        return fac[n] * invfac[n - r];\r\n    }\r\n\r\n    T fact(int n) {\r\
    \n        if (n < 0) return 0;\r\n        extend(n);\r\n        return fac[n];\r\
    \n    }\r\n\r\n    T finv(int n) {\r\n        if (n < 0) return 0;\r\n       \
    \ extend(n);\r\n        return invfac[n];\r\n    }\r\n\r\n    T inv(int n) {\r\
    \n        if (n < 0) return -inv(-n);\r\n        extend(n);\r\n        return\
    \ invs[n];\r\n    }\r\n\r\n    T S2_single(int n, int k) {\r\n        if (k <\
    \ 0 || n < k) return 0;\r\n        T res = 0;\r\n        for (int i = 0; i <=\
    \ k; i++) {\r\n            T x = i;\r\n            res = C(k, i) * x.pow(n) -\
    \ res;\r\n        }\r\n        return res * finv(k);\r\n    }\r\n\r\n    T H(int\
    \ n, int r) {\r\n        if (n < 0 || r < 0) return 0;\r\n        return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\r\n    }\r\n\r\n    template <typename I>\r\n    T\
    \ multinomial(const std::vector<I>& r) {\r\n        static_assert(std::is_integral<I>::value\
    \ == true);\r\n        int n = 0;\r\n        for (auto& x : r) {\r\n         \
    \   if (x < 0) return 0;\r\n            n += x;\r\n        }\r\n        T res\
    \ = fact(n);\r\n        for (auto& x : r) res *= finv(x);\r\n        return res;\r\
    \n    }\r\n\r\n    template <typename I>\r\n    T operator()(const std::vector<I>&\
    \ r) {\r\n        return multinomial(r);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/comb.hpp
  requiredBy:
  - lib/fps/lagrange-interpolation-point.hpp
  - lib/fps/taylor-shift.hpp
  timestamp: '2026-10-17 10:16:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/comb.hpp
layout: document
redirect_from:
- /library/lib/math/comb.hpp
- /library/lib/math/comb.hpp.html
title: lib/math/comb.hpp
---
