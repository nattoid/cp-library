---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/nt/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59 (Tonelli-Shanks algorithm)"
  - icon: ':heavy_check_mark:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"verify/nt/sqrt_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n#include <iostream>\n\n#line 2 \"lib/nt/mod_sqrt.hpp\"\n\n/**\n * @file mod_sqrt.hpp\n\
    \ * @brief \u5E73\u65B9\u5270\u4F59 (Tonelli-Shanks algorithm)\n * @see https://nyaannyaan.github.io/library/modulo/mod-sqrt.hpp\n\
    \ */\n\n#include <cassert>\n#include <cstdint>\n\n#line 2 \"lib/nt/modular.hpp\"\
    \n\n/**\n * @file modular.hpp\n * @brief \u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u3001\
    64bit\u6E1B\u7B97\u578B\u9045\u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\
    \u3001extgcd\u3001CRT\n */\n\n#line 10 \"lib/nt/modular.hpp\"\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace nt {\n\nusing ll = long long;\n\
    using u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\n\
    /**\n * @brief 64bit \u6E1B\u7B97\u578B\u9045\u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\
    \u6F14\u7B97\u5668 (mod < 2^62 \u304B\u3064\u5947\u6570)\n * @details \u5024\u57DF\
    \ [0, 2*mod)\n * \u3067\u9045\u5EF6\u8A55\u4FA1\u3092\u884C\u3046\u3002\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u306F\u9664\u7B97\u3092\u542B\u307E\u305A\u6975\
    \u3081\u3066\u9AD8\u901F\u3002\n */\nstruct Montgomery {\n    u64 mod;\n    u64\
    \ minv;  // mod * minv == 1 (mod 2^64)\n\n    constexpr Montgomery(u64 n) : mod(n),\
    \ minv(n) {\n        assert((n & 1) == 1);\n        for (int i = 0; i < 5; i++)\
    \ minv *= 2 - mod * minv;\n    }\n\n    // \u30E2\u30F3\u30B4\u30E1\u30EA\u7A7A\
    \u9593\u306B\u304A\u3051\u308B 1 (R mod n)\n    inline u64 one() const {\n   \
    \     return (-mod) % mod;\n    }\n\n    // \u30E2\u30F3\u30B4\u30E1\u30EA\u5909\
    \u63DB\u7528\u5B9A\u6570 R^2 mod n\n    inline u64 r2() const {\n        return\
    \ (-u128(mod)) % mod;\n    }\n\n    // (a * b + c) * R^{-1} mod n (\u51FA\u529B\
    \u306F [0, 2*mod))\n    inline u64 fma(u64 a, u64 b, u64 c) const {\n        u128\
    \ d = u128(a) * b;\n        u64 e = c + mod + (d >> 64);\n        u64 f = u64(d)\
    \ * minv;\n        u64 g = (u128(f) * mod) >> 64;\n        return e - g;\n   \
    \ }\n\n    // a * b * R^{-1} mod n (\u51FA\u529B\u306F [0, 2*mod))\n    inline\
    \ u64 mul(u64 a, u64 b) const {\n        return fma(a, b, 0);\n    }\n\n    //\
    \ [0, 2*mod) -> [0, mod) \u3078\u306E\u6B63\u898F\u5316\n    inline u64 norm(u64\
    \ a) const {\n        return a >= mod ? a - mod : a;\n    }\n\n    // \u30E2\u30F3\
    \u30B4\u30E1\u30EA\u7A7A\u9593\u4E0A\u3067\u306E\u3079\u304D\u4E57 a_mont^exp\
    \ (\u51FA\u529B\u306F\u6B63\u898F\u5316\u6E08\u307F [0, mod))\n    inline u64\
    \ pow(u64 a_mont, u64 exp, u64 one_mont) const {\n        u64 res = one_mont;\n\
    \        while (exp > 0) {\n            if (exp & 1) res = mul(res, a_mont);\n\
    \            a_mont = mul(a_mont, a_mont);\n            exp >>= 1;\n        }\n\
    \        return norm(res);\n    }\n};\n\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\
    \u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5 (\u975E\u518D\u5E30)\n * @details\
    \ a*x + b*y = g = gcd(|a|, |b|) \u3068\u306A\u308B (g, x, y) \u3092\u6C42\u3081\
    \u308B\n */\ninline std::tuple<ll, ll, ll> extgcd(ll a, ll b) {\n    ll x = 1,\
    \ y = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n        ll q = a / b;\n      \
    \  ll a2 = a - q * b;\n        a = b;\n        b = a2;\n        ll x2 = x - q\
    \ * x1;\n        x = x1;\n        x1 = x2;\n        ll y2 = y - q * y1;\n    \
    \    y = y1;\n        y1 = y2;\n    }\n    if (a < 0) {\n        a = -a;\n   \
    \     x = -x;\n        y = -y;\n    }\n    return {a, x, y};\n}\n\ninline ll extgcd(ll\
    \ a, ll b, ll& x, ll& y) {\n    auto [g, u, v] = extgcd(a, b);\n    x = u;\n \
    \   y = v;\n    return g;\n}\n\n/**\n * @brief \u30E2\u30B8\u30E5\u30E9\u9006\u5143\
    \u3092\u6C42\u3081\u308B (gcd(a, m) == 1 \u3092\u4EEE\u5B9A)\n */\ninline ll inv_mod(ll\
    \ a, ll m) {\n    assert(m > 0);\n    auto [g, x, y] = extgcd(a, m);\n    assert(g\
    \ == 1);\n    return x < 0 ? x + m : x;\n}\n\n/**\n * @brief a^n mod m \u3092\u8A08\
    \u7B97\u3059\u308B\n */\ninline ll pow_mod(ll a, ll n, ll m) {\n    assert(n >=\
    \ 0 && m > 0);\n    if (m == 1) return 0;\n    ll res = 1;\n    a %= m;\n    if\
    \ (a < 0) a += m;\n    while (n > 0) {\n        if (n & 1) res = (ll)((u128)res\
    \ * a % m);\n        a = (ll)((u128)a * a % m);\n        n >>= 1;\n    }\n   \
    \ return res;\n}\n\n/**\n * @brief \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (2\u5909\
    \u6570\u7248)\n */\ninline std::pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {\n\
    \    assert(m1 >= 1 && m2 >= 1);\n    r1 %= m1;\n    if (r1 < 0) r1 += m1;\n \
    \   r2 %= m2;\n    if (r2 < 0) r2 += m2;\n\n    auto [g, p, q] = extgcd(m1, m2);\n\
    \    if ((r2 - r1) % g != 0) return {0, 0};\n\n    ll u = m2 / g;\n    ll t =\
    \ (ll)((i128)(r2 - r1) / g % u * p % u);\n    if (t < 0) t += u;\n\n    ll lcm\
    \ = m1 * u;\n    ll r = r1 + t * m1;\n    return {r, lcm};\n}\n\n/**\n * @brief\
    \ \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (\u914D\u5217\u7248)\n */\ninline std::pair<ll,\
    \ ll> crt(const std::vector<ll>& r,\n                             const std::vector<ll>&\
    \ m) {\n    assert(r.size() == m.size());\n    ll r0 = 0, m0 = 1;\n    for (size_t\
    \ i = 0; i < r.size(); i++) {\n        auto [r1, m1] = crt(r0, m0, r[i], m[i]);\n\
    \        if (m1 == 0) return {0, 0};\n        r0 = r1;\n        m0 = m1;\n   \
    \ }\n    return {r0, m0};\n}\n\n}  // namespace nt\n#line 13 \"lib/nt/mod_sqrt.hpp\"\
    \n\nnamespace nt {\n\n/**\n * @brief x^2 = a (mod p) \u3092\u6E80\u305F\u3059\
    \ x \u30921\u3064\u6C42\u3081\u308B (Tonelli-Shanks)\n * @param a \u771F\u6570\
    \n * @param p \u7D20\u6570 (p >= 2, p < 2^62)\n * @return ll \u89E3 x (0 <= x\
    \ < p, \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1)\n * @note \u8A08\u7B97\
    \u91CF: O(log^2 p) (\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\u306B\u3088\u308A\
    \u5B9A\u6570\u500D\u9AD8\u901F)\n */\ninline ll mod_sqrt(ll a, ll p) {\n    assert(p\
    \ >= 2);\n    a %= p;\n    if (a < 0) a += p;\n    if (a == 0) return 0;\n   \
    \ if (p == 2) return a;\n\n    Montgomery m(p);\n    u64 one = m.one();\n    u64\
    \ minus_one = p - one;\n    u64 r2 = m.r2();\n\n    u64 a_mont = m.mul(a, r2);\n\
    \    if (m.pow(a_mont, (p - 1) >> 1, one) != one) return -1;\n\n    // p == 3\
    \ (mod 4) \u306E\u5834\u5408\u306F a^{(p+1)/4} mod p \u304C\u76F4\u3061\u306B\u89E3\
    \u3068\u306A\u308B\n    if ((p & 3) == 3) {\n        u64 x_mont = m.pow(a_mont,\
    \ (p + 1) >> 2, one);\n        return m.mul(x_mont, 1);\n    }\n\n    // \u975E\
    \u5E73\u65B9\u5270\u4F59 b \u3092\u63A2\u3059\n    u64 b_mont = one;\n    for\
    \ (u64 b = 2;; b++) {\n        b_mont = m.mul(b, r2);\n        if (m.pow(b_mont,\
    \ (p - 1) >> 1, one) == minus_one) break;\n    }\n\n    u64 q = p - 1;\n    int\
    \ e = __builtin_ctzll(q);\n    q >>= e;\n\n    u64 x = m.pow(a_mont, (q + 1) >>\
    \ 1, one);\n    u64 y = m.pow(a_mont, q, one);\n    u64 z = m.pow(b_mont, q, one);\n\
    \n    while (y != one) {\n        int j = 0;\n        u64 t = y;\n        while\
    \ (t != one) {\n            j++;\n            t = m.norm(m.mul(t, t));\n     \
    \   }\n\n        u64 z_pow = z;\n        for (int i = 0; i < e - j - 1; i++) {\n\
    \            z_pow = m.mul(z_pow, z_pow);\n        }\n        z_pow = m.norm(z_pow);\n\
    \n        x = m.norm(m.mul(x, z_pow));\n        z = m.norm(m.mul(z_pow, z_pow));\n\
    \        y = m.norm(m.mul(y, z));\n        e = j;\n    }\n\n    return m.mul(x,\
    \ 1);  // \u30E2\u30F3\u30B4\u30E1\u30EA\u7A7A\u9593\u304B\u3089\u901A\u5E38\u306E\
    \u7A7A\u9593\u3078\u623B\u3059 (\u5E38\u306B [0, p) \u306B\u53CE\u307E\u308B)\n\
    }\n\n}  // namespace nt\n#line 5 \"verify/nt/sqrt_mod.test.cpp\"\n\nusing namespace\
    \ std;\nusing ll = long long;\nint main() {\n    int q;\n    cin >> q;\n    while\
    \ (q--) {\n        int p, y;\n        cin >> y >> p;\n        cout << nt::mod_sqrt(y,\
    \ p) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include <iostream>\n\
    \n#include \"../../lib/nt/mod_sqrt.hpp\"\n\nusing namespace std;\nusing ll = long\
    \ long;\nint main() {\n    int q;\n    cin >> q;\n    while (q--) {\n        int\
    \ p, y;\n        cin >> y >> p;\n        cout << nt::mod_sqrt(y, p) << \"\\n\"\
    ;\n    }\n}"
  dependsOn:
  - lib/nt/mod_sqrt.hpp
  - lib/nt/modular.hpp
  isVerificationFile: true
  path: verify/nt/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 16:39:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/nt/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/nt/sqrt_mod.test.cpp
- /verify/verify/nt/sqrt_mod.test.cpp.html
title: verify/nt/sqrt_mod.test.cpp
---
