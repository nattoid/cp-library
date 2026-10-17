---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':warning:'
    path: lib/math/comb.hpp
    title: lib/math/comb.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5E73\u884C\u79FB\u52D5"
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
    \n        return multinomial(r);\r\n    }\r\n};\n#line 4 \"lib/fps/formal-power-series.hpp\"\
    \n#include <cstdint>\n#include <utility>\n#line 7 \"lib/fps/formal-power-series.hpp\"\
    \n\ntemplate <typename mint>\nstruct FormalPowerSeries : std::vector<mint> {\n\
    \    using std::vector<mint>::std::vector;\n    using FPS = FormalPowerSeries;\n\
    \n    FPS& operator+=(const FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n       \
    \ return *this;\n    }\n\n    FPS& operator+=(const mint& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n\n\
    \    FPS& operator-=(const FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n       \
    \ return *this;\n    }\n\n    FPS& operator-=(const mint& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return *this;\n    }\n\n\
    \    FPS& operator*=(const mint& v) {\n        for (int k = 0; k < (int)this->size();\
    \ k++) (*this)[k] *= v;\n        return *this;\n    }\n\n    FPS& operator/=(const\
    \ FPS& r) {\n        if (this->size() < r.size()) {\n            this->clear();\n\
    \            return *this;\n        }\n        int n = this->size() - r.size()\
    \ + 1;\n        if ((int)r.size() <= 64) {\n            FPS f(*this), g(r);\n\
    \            g.shrink();\n            mint coeff = g.back().inv();\n         \
    \   for (auto& x : g) x *= coeff;\n            int deg = (int)f.size() - (int)g.size()\
    \ + 1;\n            int gs = g.size();\n            FPS quo(deg);\n          \
    \  for (int i = deg - 1; i >= 0; i--) {\n                quo[i] = f[i + gs - 1];\n\
    \                for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\n   \
    \         }\n            *this = quo * coeff;\n            this->resize(n, mint(0));\n\
    \            return *this;\n        }\n        return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n    }\n\n    FPS& operator%=(const FPS& r)\
    \ {\n        *this -= *this / r * r;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS operator+(const FPS& r) const {\n        return FPS(*this) +=\
    \ r;\n    }\n    FPS operator+(const mint& v) const {\n        return FPS(*this)\
    \ += v;\n    }\n    FPS operator-(const FPS& r) const {\n        return FPS(*this)\
    \ -= r;\n    }\n    FPS operator-(const mint& v) const {\n        return FPS(*this)\
    \ -= v;\n    }\n    FPS operator*(const FPS& r) const {\n        return FPS(*this)\
    \ *= r;\n    }\n    FPS operator*(const mint& v) const {\n        return FPS(*this)\
    \ *= v;\n    }\n    FPS operator/(const FPS& r) const {\n        return FPS(*this)\
    \ /= r;\n    }\n    FPS operator%(const FPS& r) const {\n        return FPS(*this)\
    \ %= r;\n    }\n    FPS operator-() const {\n        FPS ret(this->size());\n\
    \        for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n \
    \       return ret;\n    }\n\n    void shrink() {\n        while (this->size()\
    \ && this->back() == mint(0)) this->pop_back();\n    }\n\n    FPS rev() const\
    \ {\n        FPS ret(*this);\n        std::reverse(std::begin(ret), std::end(ret));\n\
    \        return ret;\n    }\n\n    FPS dot(FPS r) const {\n        FPS ret(std::min(this->size(),\
    \ r.size()));\n        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n        return ret;\n    }\n\n    // \u524D sz \u9805\u3092\u53D6\u3063\
    \u3066\u304F\u308B\u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\
    \u3081\u3059\u308B\n    FPS pre(int sz) const {\n        FPS ret(std::begin(*this),\n\
    \                std::begin(*this) + std::min((int)this->size(), sz));\n     \
    \   if ((int)ret.size() < sz) ret.resize(sz);\n        return ret;\n    }\n\n\
    \    FPS operator>>(int sz) const {\n        if ((int)this->size() <= sz) return\
    \ {};\n        FPS ret(*this);\n        ret.erase(ret.begin(), ret.begin() + sz);\n\
    \        return ret;\n    }\n\n    FPS operator<<(int sz) const {\n        FPS\
    \ ret(*this);\n        ret.insert(ret.begin(), sz, mint(0));\n        return ret;\n\
    \    }\n\n    FPS diff() const {\n        const int n = (int)this->size();\n \
    \       FPS ret(std::max(0, n - 1));\n        mint one(1), coeff(1);\n       \
    \ for (int i = 1; i < n; i++) {\n            ret[i - 1] = (*this)[i] * coeff;\n\
    \            coeff += one;\n        }\n        return ret;\n    }\n\n    FPS integral()\
    \ const {\n        const int n = (int)this->size();\n        FPS ret(n + 1);\n\
    \        ret[0] = mint(0);\n        if (n > 0) ret[1] = mint(1);\n        auto\
    \ mod = mint::mod();\n        for (int i = 2; i <= n; i++) ret[i] = (-ret[mod\
    \ % i]) * (mod / i);\n        for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n\
    \        return ret;\n    }\n\n    mint eval(mint x) const {\n        mint r =\
    \ 0, w = 1;\n        for (auto& v : *this) r += w * v, w *= x;\n        return\
    \ r;\n    }\n\n    FPS log(int deg = -1) const {\n        assert(!(*this).empty()\
    \ && (*this)[0] == mint(1));\n        if (deg == -1) deg = (int)this->size();\n\
    \        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n   \
    \ }\n\n    FPS pow(int64_t k, int deg = -1) const {\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        if (k == 0) {\n            FPS ret(deg);\n\
    \            if (deg) ret[0] = 1;\n            return ret;\n        }\n      \
    \  for (int i = 0; i < n; i++) {\n            if ((*this)[i] != mint(0)) {\n \
    \               mint rev = mint(1) / (*this)[i];\n                FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n\
    \                ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n                return ret;\n            }\n\
    \            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \     }\n        return FPS(deg, mint(0));\n    }\n\n    static void* ntt_ptr;\n\
    \    static void set_fft();\n    FPS& operator*=(const FPS& r);\n    void ntt();\n\
    \    void intt();\n    void ntt_doubling();\n    static int ntt_pr();\n    FPS\
    \ inv(int deg = -1) const;\n    FPS exp(int deg = -1) const;\n};\ntemplate <typename\
    \ mint>\nvoid* FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\
    \u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\
    \n */\n#line 4 \"lib/fps/taylor-shift.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ TaylorShift(FormalPowerSeries<mint> f, mint a,\n                           \
    \         Comb<mint>& C) {\n    using fps = FormalPowerSeries<mint>;\n    int\
    \ N = f.size();\n    for (int i = 0; i < N; i++) f[i] *= C.fact(i);\n    std::reverse(f.begin(),\
    \ f.end());\n    fps g(N, mint(1));\n    for (int i = 1; i < N; i++) g[i] = g[i\
    \ - 1] * a * C.inv(i);\n    f = (f * g).pre(N);\n    std::reverse(f.begin(), f.end());\n\
    \    for (int i = 0; i < N; i++) f[i] *= C.finv(i);\n    return f;\n}\n\n/**\n\
    \ * @brief \u5E73\u884C\u79FB\u52D5\n */\n"
  code: "#pragma once\n#include \"../math/comb.hpp\"\n#include \"./formal-power-series.hpp\"\
    \n\ntemplate <typename mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint>\
    \ f, mint a,\n                                    Comb<mint>& C) {\n    using\
    \ fps = FormalPowerSeries<mint>;\n    int N = f.size();\n    for (int i = 0; i\
    \ < N; i++) f[i] *= C.fact(i);\n    std::reverse(f.begin(), f.end());\n    fps\
    \ g(N, mint(1));\n    for (int i = 1; i < N; i++) g[i] = g[i - 1] * a * C.inv(i);\n\
    \    f = (f * g).pre(N);\n    std::reverse(f.begin(), f.end());\n    for (int\
    \ i = 0; i < N; i++) f[i] *= C.finv(i);\n    return f;\n}\n\n/**\n * @brief \u5E73\
    \u884C\u79FB\u52D5\n */"
  dependsOn:
  - lib/math/comb.hpp
  - lib/fps/formal-power-series.hpp
  isVerificationFile: false
  path: lib/fps/taylor-shift.hpp
  requiredBy: []
  timestamp: '2026-10-17 10:16:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/fps/taylor-shift.hpp
layout: document
redirect_from:
- /library/lib/fps/taylor-shift.hpp
- /library/lib/fps/taylor-shift.hpp.html
title: "\u5E73\u884C\u79FB\u52D5"
---
