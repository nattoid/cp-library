---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/nt/discrete_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (Extended Baby-step Giant-step)"
  - icon: ':question:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/nt/discrete_logarithm_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n#include <iostream>\n\
    \n#line 2 \"lib/nt/discrete_log.hpp\"\n\n/**\n * @file discrete_log.hpp\n * @brief\
    \ \u96E2\u6563\u5BFE\u6570\u554F\u984C (Extended Baby-step Giant-step)\n */\n\n\
    #include <cassert>\n#include <cmath>\n#include <cstdint>\n#include <numeric>\n\
    #include <vector>\n\n#line 2 \"lib/nt/modular.hpp\"\n\n/**\n * @file modular.hpp\n\
    \ * @brief \u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
    \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT\n\
    \ */\n\n#line 10 \"lib/nt/modular.hpp\"\n#include <tuple>\n#include <utility>\n\
    #line 13 \"lib/nt/modular.hpp\"\n\nnamespace nt {\n\nusing ll = long long;\nusing\
    \ u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\n/**\n\
    \ * @brief 64bit \u6E1B\u7B97\u578B\u9045\u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\
    \u7B97\u5668 (mod < 2^62 \u304B\u3064\u5947\u6570)\n * @details \u5024\u57DF [0,\
    \ 2*mod)\n * \u3067\u9045\u5EF6\u8A55\u4FA1\u3092\u884C\u3046\u3002\u30B3\u30F3\
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
    \ }\n    return {r0, m0};\n}\n\n}  // namespace nt\n#line 15 \"lib/nt/discrete_log.hpp\"\
    \n\nnamespace nt {\n\n/** @cond INTERNAL */\nnamespace internal {\n\n// BSGS\u7528\
    \u306E\u9AD8\u901F\u30AA\u30FC\u30D7\u30F3\u30A2\u30C9\u30EC\u30B9\u30CF\u30C3\
    \u30B7\u30E5\u30C6\u30FC\u30D6\u30EB (\u5024\u306E\u4E0A\u66F8\u304D\u5BFE\u5FDC\
    )\nstruct FastHashMap {\n    int cap, mask;\n    std::vector<u64> keys;\n    std::vector<int>\
    \ vals;\n    std::vector<bool> used;\n\n    FastHashMap(int max_elements) {\n\
    \        cap = 8;\n        while (cap < max_elements * 2) cap <<= 1;\n       \
    \ mask = cap - 1;\n        keys.resize(cap);\n        vals.resize(cap);\n    \
    \    used.assign(cap, false);\n    }\n\n    static inline u64 hash(u64 x) {\n\
    \        x += 0x9e3779b97f4a7c15ULL;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;\n        return x ^ (x >>\
    \ 31);\n    }\n\n    inline void insert(u64 k, int v) {\n        int i = hash(k)\
    \ & mask;\n        while (used[i] && keys[i] != k) {\n            i = (i + 1)\
    \ & mask;\n        }\n        keys[i] = k;\n        vals[i] = v;  // \u3088\u308A\
    \u5927\u304D\u3044 j \u3067\u4E0A\u66F8\u304D\u3059\u308B\u3053\u3068\u3067 i*step\
    \ - j \u3092\u6700\u5C0F\u5316\n        used[i] = true;\n    }\n\n    inline int\
    \ find(u64 k) const {\n        int i = hash(k) & mask;\n        while (used[i])\
    \ {\n            if (keys[i] == k) return vals[i];\n            i = (i + 1) &\
    \ mask;\n        }\n        return -1;\n    }\n};\n\n}  // namespace internal\n\
    /** @endcond */\n\n/**\n * @brief \u96E2\u6563\u5BFE\u6570\u554F\u984C a^x = b\
    \ (mod m) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E x \u3092\u6C42\u3081\u308B\
    \ (exBSGS)\n * @param a \u5E95\n * @param b \u771F\u6570\n * @param m \u6CD5 (m\
    \ >= 1)\n * @param allow_zero x = 0 \u3092\u89E3\u3068\u3057\u3066\u8A31\u5BB9\
    \u3059\u308B\u304B (\u30C7\u30D5\u30A9\u30EB\u30C8: true, 0^0 = 1\n * \u3068\u5B9A\
    \u7FA9)\n * @return ll \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\
    \ x (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1)\n * @note \u8A08\u7B97\
    \u91CF: \u6642\u9593\u30FB\u7A7A\u9593\u3068\u3082\u306B O(sqrt(m))\n */\ninline\
    \ ll discrete_log(ll a, ll b, ll m, bool allow_zero = true) {\n    assert(m >=\
    \ 1);\n    if (m == 1) return allow_zero ? 0 : 1;\n\n    a %= m;\n    if (a <\
    \ 0) a += m;\n    b %= m;\n    if (b < 0) b += m;\n\n    if (allow_zero && b ==\
    \ 1) return 0;\n    if (a == 0) {\n        if (b == 0) return 1;\n        return\
    \ -1;\n    }\n\n    // 1. gcd(a, m) > 1 \u306E\u9593\u3001\u56E0\u5B50\u3092\u62EC\
    \u308A\u51FA\u3057\u3066\u4E92\u3044\u306B\u7D20\u306A\u554F\u984C\u306B\u5E30\
    \u7740\u3055\u305B\u308B\n    ll k = 0, c = 1 % m;\n    while (true) {\n     \
    \   if ((allow_zero || k > 0) && c == b) return k;\n        ll g = std::gcd(a,\
    \ m);\n        if (g == 1) break;\n        if (b % g != 0) return -1;\n      \
    \  b /= g;\n        m /= g;\n        c = (ll)((u128)c * (a / g) % m);\n      \
    \  k++;\n    }\n\n    // 2. c * a^{x - k} = b (mod m) \u3092 BSGS \u3067\u89E3\
    \u304F (gcd(a, m) == 1)\n    // x - k = i * step - j (1 <= i <= step, 0 <= j <\
    \ step) \u3068\u304A\u304F\n    // c * (a^step)^i = b * a^j (mod m)\n    ll step\
    \ = std::sqrtl(m) + 1;\n    internal::FastHashMap mp(step);\n\n    ll cur = b;\n\
    \    for (int j = 0; j < step; j++) {\n        mp.insert(cur, j);\n        cur\
    \ = (ll)((u128)cur * a % m);\n    }\n\n    ll a_step = pow_mod(a, step, m);\n\
    \    cur = c;\n    for (ll i = 1; i <= step; i++) {\n        cur = (ll)((u128)cur\
    \ * a_step % m);\n        int j = mp.find(cur);\n        if (j != -1) {\n    \
    \        return i * step - j + k;\n        }\n    }\n\n    return -1;\n}\n\n}\
    \  // namespace nt\n#line 5 \"verify/nt/discrete_logarithm_mod.test.cpp\"\n\n\
    using namespace std;\nusing ll = long long;\nint main() {\n    int q;\n    cin\
    \ >> q;\n    while (q--) {\n        int x, y, m;\n        cin >> x >> y >> m;\n\
    \        cout << nt::discrete_log(x, y, m) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include <iostream>\n\n#include \"../../lib/nt/discrete_log.hpp\"\n\nusing namespace\
    \ std;\nusing ll = long long;\nint main() {\n    int q;\n    cin >> q;\n    while\
    \ (q--) {\n        int x, y, m;\n        cin >> x >> y >> m;\n        cout <<\
    \ nt::discrete_log(x, y, m) << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/nt/discrete_log.hpp
  - lib/nt/modular.hpp
  isVerificationFile: true
  path: verify/nt/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 16:44:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/nt/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/nt/discrete_logarithm_mod.test.cpp
- /verify/verify/nt/discrete_logarithm_mod.test.cpp.html
title: verify/nt/discrete_logarithm_mod.test.cpp
---
