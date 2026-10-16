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
  bundledCode: "#line 2 \"lib/math/comb.hpp\"\n#include <vector>\r\n#include <algorithm>\r\
    \n\r\ntemplate <class T> struct Comb {\r\n    std::vector<T> fac, invfac, invs;\r\
    \n\r\n    Comb() : fac(1, 1), invfac(1, 1), invs(1, 1) {}\r\n\r\n    void extend(int\
    \ n) {\r\n        int sz = fac.size();\r\n        if (n < sz) return;\r\n    \
    \    long long p = T::mod();\r\n        int new_sz = std::min((long long)std::max(n\
    \ + 1, sz * 2), p);\r\n        \r\n        fac.resize(new_sz);\r\n        invfac.resize(new_sz);\r\
    \n        invs.resize(new_sz);\r\n        \r\n        for (int i = sz; i < new_sz;\
    \ i++) {\r\n            fac[i] = fac[i - 1] * i;\r\n        }\r\n        invfac[new_sz\
    \ - 1] = fac.back().inv();\r\n        invs[new_sz - 1] = invfac[new_sz - 1] *\
    \ fac[new_sz - 2];\r\n        \r\n        for (int i = new_sz - 1; i > sz; i--)\
    \ {\r\n            invfac[i - 1] = invfac[i] * i;\r\n            invs[i - 1] =\
    \ invfac[i - 1] * fac[i - 2];\r\n        }\r\n    }\r\n\r\n    T C(int n, int\
    \ r) {\r\n        if (r < 0 || n < r) return 0;\r\n        extend(n);\r\n    \
    \    return fac[n] * invfac[r] * invfac[n - r];\r\n    }\r\n    \r\n    //\u5358\
    \u4E00O(r)\r\n    T C_large(long long n, int r) {\r\n        if (r < 0 || n <\
    \ r) return 0;\r\n        extend(r);\r\n        T res = 1;\r\n        for (int\
    \ i = 0; i < r; i++) res = res * T(n - i);\r\n        return res * invfac[r];\r\
    \n    }\r\n\r\n    T Lucas(long long n, long long r) {\r\n        if (n < 0 ||\
    \ r < 0 || n < r) return 0;\r\n        if (r == 0) return 1;\r\n        long long\
    \ p = T::mod();\r\n        T res = 1;\r\n        while (n > 0 || r > 0) {\r\n\
    \            long long ni = n % p;\r\n            long long ri = r % p;\r\n  \
    \          if (ni < ri) return 0;\r\n            res = res * C(ni, ri);\r\n  \
    \          n /= p;\r\n            r /= p;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    T P(int n, int r) {\r\n        if (r < 0 || n < r) return 0;\r\
    \n        extend(n);\r\n        return fac[n] * invfac[n - r];\r\n    }\r\n\r\n\
    \    T fact(int n){\r\n        if(n < 0) return 0;\r\n        extend(n);\r\n \
    \       return fac[n];\r\n    }\r\n\r\n    T finv(int n){\r\n        if(n < 0)\
    \ return 0;\r\n        extend(n);\r\n        return invfac[n];\r\n    }\r\n\r\n\
    \    T inv(int n) {\r\n        if (n < 0) return -inv(-n);\r\n        extend(n);\r\
    \n        return invs[n];\r\n    }\r\n\r\n    T S2_single(int n, int k){\r\n \
    \       if (k < 0 || n < k) return 0;\r\n        T res = 0;\r\n        for (int\
    \ i = 0; i <= k; i++) {\r\n            T x = i;\r\n            res = C(k, i) *\
    \ x.pow(n) - res;\r\n        }\r\n        return res * finv(k);\r\n    }\r\n \
    \   \r\n    // \u91CD\u8907\u7D44\u5408\u305B: [x^r] 1 / (1-x)^n\r\n    T H(int\
    \ n, int r) {\r\n        if (n < 0 || r < 0) return 0;\r\n        return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\r\n    }\r\n\r\n    // \u591A\u9805\u4FC2\u6570\r\n\
    \    template <typename I>\r\n    T multinomial(const std::vector<I>& r) {\r\n\
    \        static_assert(std::is_integral<I>::value == true);\r\n        int n =\
    \ 0;\r\n        for (auto& x : r) {\r\n            if (x < 0) return 0;\r\n  \
    \          n += x;\r\n        }\r\n        T res = fact(n);\r\n        for (auto&\
    \ x : r) res *= finv(x);\r\n        return res;\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n\r\ntemplate\
    \ <class T> struct Comb {\r\n    std::vector<T> fac, invfac, invs;\r\n\r\n   \
    \ Comb() : fac(1, 1), invfac(1, 1), invs(1, 1) {}\r\n\r\n    void extend(int n)\
    \ {\r\n        int sz = fac.size();\r\n        if (n < sz) return;\r\n       \
    \ long long p = T::mod();\r\n        int new_sz = std::min((long long)std::max(n\
    \ + 1, sz * 2), p);\r\n        \r\n        fac.resize(new_sz);\r\n        invfac.resize(new_sz);\r\
    \n        invs.resize(new_sz);\r\n        \r\n        for (int i = sz; i < new_sz;\
    \ i++) {\r\n            fac[i] = fac[i - 1] * i;\r\n        }\r\n        invfac[new_sz\
    \ - 1] = fac.back().inv();\r\n        invs[new_sz - 1] = invfac[new_sz - 1] *\
    \ fac[new_sz - 2];\r\n        \r\n        for (int i = new_sz - 1; i > sz; i--)\
    \ {\r\n            invfac[i - 1] = invfac[i] * i;\r\n            invs[i - 1] =\
    \ invfac[i - 1] * fac[i - 2];\r\n        }\r\n    }\r\n\r\n    T C(int n, int\
    \ r) {\r\n        if (r < 0 || n < r) return 0;\r\n        extend(n);\r\n    \
    \    return fac[n] * invfac[r] * invfac[n - r];\r\n    }\r\n    \r\n    //\u5358\
    \u4E00O(r)\r\n    T C_large(long long n, int r) {\r\n        if (r < 0 || n <\
    \ r) return 0;\r\n        extend(r);\r\n        T res = 1;\r\n        for (int\
    \ i = 0; i < r; i++) res = res * T(n - i);\r\n        return res * invfac[r];\r\
    \n    }\r\n\r\n    T Lucas(long long n, long long r) {\r\n        if (n < 0 ||\
    \ r < 0 || n < r) return 0;\r\n        if (r == 0) return 1;\r\n        long long\
    \ p = T::mod();\r\n        T res = 1;\r\n        while (n > 0 || r > 0) {\r\n\
    \            long long ni = n % p;\r\n            long long ri = r % p;\r\n  \
    \          if (ni < ri) return 0;\r\n            res = res * C(ni, ri);\r\n  \
    \          n /= p;\r\n            r /= p;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    T P(int n, int r) {\r\n        if (r < 0 || n < r) return 0;\r\
    \n        extend(n);\r\n        return fac[n] * invfac[n - r];\r\n    }\r\n\r\n\
    \    T fact(int n){\r\n        if(n < 0) return 0;\r\n        extend(n);\r\n \
    \       return fac[n];\r\n    }\r\n\r\n    T finv(int n){\r\n        if(n < 0)\
    \ return 0;\r\n        extend(n);\r\n        return invfac[n];\r\n    }\r\n\r\n\
    \    T inv(int n) {\r\n        if (n < 0) return -inv(-n);\r\n        extend(n);\r\
    \n        return invs[n];\r\n    }\r\n\r\n    T S2_single(int n, int k){\r\n \
    \       if (k < 0 || n < k) return 0;\r\n        T res = 0;\r\n        for (int\
    \ i = 0; i <= k; i++) {\r\n            T x = i;\r\n            res = C(k, i) *\
    \ x.pow(n) - res;\r\n        }\r\n        return res * finv(k);\r\n    }\r\n \
    \   \r\n    // \u91CD\u8907\u7D44\u5408\u305B: [x^r] 1 / (1-x)^n\r\n    T H(int\
    \ n, int r) {\r\n        if (n < 0 || r < 0) return 0;\r\n        return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\r\n    }\r\n\r\n    // \u591A\u9805\u4FC2\u6570\r\n\
    \    template <typename I>\r\n    T multinomial(const std::vector<I>& r) {\r\n\
    \        static_assert(std::is_integral<I>::value == true);\r\n        int n =\
    \ 0;\r\n        for (auto& x : r) {\r\n            if (x < 0) return 0;\r\n  \
    \          n += x;\r\n        }\r\n        T res = fact(n);\r\n        for (auto&\
    \ x : r) res *= finv(x);\r\n        return res;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/comb.hpp
  requiredBy:
  - lib/fps/taylor-shift.hpp
  - lib/fps/lagrange-interpolation-point.hpp
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/comb.hpp
layout: document
redirect_from:
- /library/lib/math/comb.hpp
- /library/lib/math/comb.hpp.html
title: lib/math/comb.hpp
---
