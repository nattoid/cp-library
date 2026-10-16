---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':warning:'
    path: lib/modint/arbitrary-montgomery-modint.hpp
    title: lib/modint/arbitrary-montgomery-modint.hpp
  - icon: ':warning:'
    path: lib/modulo/mod-sqrt.hpp
    title: mod sqrt(Tonelli-Shanks algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5E73\u65B9\u6839"
    links: []
  bundledCode: "#line 2 \"lib/fps/formal-power-series.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cstdint>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename mint>\nstruct FormalPowerSeries : std::vector<mint> {\n \
    \   using std::vector<mint>::std::vector;\n    using FPS = FormalPowerSeries;\n\
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
    \n */\n#line 3 \"lib/modulo/mod-sqrt.hpp\"\n\n#line 2 \"lib/modint/arbitrary-montgomery-modint.hpp\"\
    \n\n#include <iostream>\n\ntemplate <typename Int, typename UInt, typename Long,\
    \ typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n  using\
    \ mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt mod;\n  inline\
    \ static UInt r;\n  inline static UInt n2;\n  static constexpr int bit_length\
    \ = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret = mod;\n    while\
    \ (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n  }\n  static\
    \ void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length - 2)));\n  \
    \  assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n  }\n\
    \  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ mint &b) {\n    return os << b.get();\n  }\n\n  friend std::istream &operator>>(std::istream\
    \ &is, mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      std::swap(x\
    \ -= t * y, y);\n      std::swap(u -= t * v, v);\n    }\n    return mint{u};\n\
    \  }\n\n  UInt get() const {\n    UInt ret = reduce(a);\n    return ret >= mod\
    \ ? ret - mod : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n//\
    \ id \u306B\u9069\u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\
    \u3046\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;\n#line 5 \"lib/modulo/mod-sqrt.hpp\"\
    \n\nint64_t mod_sqrt(const int64_t& a, const int64_t& p) {\n    assert(0 <= a\
    \ && a < p);\n    if (a < 2) return a;\n    using Mint = ArbitraryLazyMontgomeryModInt<409075245>;\n\
    \    Mint::set_mod(p);\n    if (Mint(a).pow((p - 1) >> 1) != 1) return -1;\n \
    \   Mint b = 1, one = 1;\n    while (b.pow((p - 1) >> 1) == 1) b += one;\n   \
    \ int64_t m = p - 1, e = 0;\n    while (m % 2 == 0) m >>= 1, e += 1;\n    Mint\
    \ x = Mint(a).pow((m - 1) >> 1);\n    Mint y = Mint(a) * x * x;\n    x *= a;\n\
    \    Mint z = Mint(b).pow(m);\n    while (y != 1) {\n        int64_t j = 0;\n\
    \        Mint t = y;\n        while (t != one) {\n            j += 1;\n      \
    \      t *= t;\n        }\n        z = z.pow(int64_t(1) << (e - j - 1));\n   \
    \     x *= z;\n        z *= z;\n        y *= z;\n        e = j;\n    }\n    return\
    \ x.get();\n}\n\n/**\n * @brief mod sqrt(Tonelli-Shanks algorithm)\n */\n#line\
    \ 4 \"lib/fps/fps-sqrt.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ sqrt(const FormalPowerSeries<mint>& f, int deg = -1) {\n    if (deg == -1) deg\
    \ = (int)f.size();\n    if ((int)f.size() == 0) return FormalPowerSeries<mint>(deg,\
    \ 0);\n    if (f[0] == mint(0)) {\n        for (int i = 1; i < (int)f.size();\
    \ i++) {\n            if (f[i] != mint(0)) {\n                if (i & 1) return\
    \ {};\n                if (deg - i / 2 <= 0) break;\n                auto ret\
    \ = sqrt(f >> i, deg - i / 2);\n                if (ret.empty()) return {};\n\
    \                ret = ret << (i / 2);\n                if ((int)ret.size() <\
    \ deg) ret.resize(deg, mint(0));\n                return ret;\n            }\n\
    \        }\n        return FormalPowerSeries<mint>(deg, 0);\n    }\n\n    int64_t\
    \ sqr = mod_sqrt(f[0].val(), mint::mod());\n    if (sqr == -1) return {};\n  \
    \  assert(sqr * sqr % mint::mod() == f[0].val());\n    FormalPowerSeries<mint>\
    \ ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n    for (int i = 1; i <\
    \ deg; i <<= 1) {\n        ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\n\
    \    }\n    return ret.pre(deg);\n}\n\n/**\n * @brief \u5E73\u65B9\u6839\n */\n"
  code: "#pragma once\n#include \"../fps/formal-power-series.hpp\"\n#include \"../modulo/mod-sqrt.hpp\"\
    \n\ntemplate <typename mint>\nFormalPowerSeries<mint> sqrt(const FormalPowerSeries<mint>&\
    \ f, int deg = -1) {\n    if (deg == -1) deg = (int)f.size();\n    if ((int)f.size()\
    \ == 0) return FormalPowerSeries<mint>(deg, 0);\n    if (f[0] == mint(0)) {\n\
    \        for (int i = 1; i < (int)f.size(); i++) {\n            if (f[i] != mint(0))\
    \ {\n                if (i & 1) return {};\n                if (deg - i / 2 <=\
    \ 0) break;\n                auto ret = sqrt(f >> i, deg - i / 2);\n         \
    \       if (ret.empty()) return {};\n                ret = ret << (i / 2);\n \
    \               if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n       \
    \         return ret;\n            }\n        }\n        return FormalPowerSeries<mint>(deg,\
    \ 0);\n    }\n\n    int64_t sqr = mod_sqrt(f[0].val(), mint::mod());\n    if (sqr\
    \ == -1) return {};\n    assert(sqr * sqr % mint::mod() == f[0].val());\n    FormalPowerSeries<mint>\
    \ ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n    for (int i = 1; i <\
    \ deg; i <<= 1) {\n        ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\n\
    \    }\n    return ret.pre(deg);\n}\n\n/**\n * @brief \u5E73\u65B9\u6839\n */"
  dependsOn:
  - lib/fps/formal-power-series.hpp
  - lib/modulo/mod-sqrt.hpp
  - lib/modint/arbitrary-montgomery-modint.hpp
  isVerificationFile: false
  path: lib/fps/fps-sqrt.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/fps/fps-sqrt.hpp
layout: document
redirect_from:
- /library/lib/fps/fps-sqrt.hpp
- /library/lib/fps/fps-sqrt.hpp.html
title: "\u5E73\u65B9\u6839"
---
