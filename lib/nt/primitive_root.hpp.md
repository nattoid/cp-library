---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/nt/factorize.hpp
    title: lib/nt/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/nt/primitive_root.test.cpp
    title: verify/nt/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive\
      \ Root) \u306E\u63A2\u7D22"
    links: []
  bundledCode: "#line 2 \"lib/nt/primitive_root.hpp\"\n\n/**\n * @file primitive_root.hpp\n\
    \ * @brief \u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive\
    \ Root) \u306E\u63A2\u7D22\n */\n\n#include <cassert>\n#include <cstdint>\n#include\
    \ <numeric>\n#include <utility>\n#include <vector>\n\n#line 2 \"lib/nt/factorize.hpp\"\
    \n\n/**\n * @file factorize.hpp\n * @brief\n * \u7D20\u6570\u5224\u5B9A\u3001\u7D20\
    \u56E0\u6570\u5206\u89E3\u3001\u7D04\u6570\u5217\u6319\u3001\u30AA\u30A4\u30E9\
    \u30FC\u306E\u03C6\u95A2\u6570\u306A\u3069\u3092\u63D0\u4F9B\u3059\u308B\u6574\
    \u6570\u8AD6\u30E9\u30A4\u30D6\u30E9\u30EA\n * @see https://andantesoft.hatenablog.com/entry/2025/05/21/164352\n\
    \ * @see https://judge.yosupo.jp/submission/189742\n */\n\n#include <algorithm>\n\
    #line 16 \"lib/nt/factorize.hpp\"\n\n#line 2 \"lib/nt/modular.hpp\"\n\n/**\n *\
    \ @file modular.hpp\n * @brief \u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\
    \u7B97\u578B\u9045\u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001\
    extgcd\u3001CRT\n */\n\n#line 10 \"lib/nt/modular.hpp\"\n#include <tuple>\n#line\
    \ 13 \"lib/nt/modular.hpp\"\n\nnamespace nt {\n\nusing ll = long long;\nusing\
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
    \ }\n    return {r0, m0};\n}\n\n}  // namespace nt\n#line 18 \"lib/nt/factorize.hpp\"\
    \n\nnamespace nt {\n\n/** @cond INTERNAL */\nnamespace internal {\n\n// Binary\
    \ GCD (Stein's algorithm)\ninline u64 gcd_stein(u64 x, u64 y) {\n    if (x ==\
    \ 0) return y;\n    if (y == 0) return x;\n    int n = __builtin_ctzll(x);\n \
    \   int m = __builtin_ctzll(y);\n    x >>= n;\n    y >>= m;\n    while (x != y)\
    \ {\n        int s = __builtin_ctzll(x - y);\n        bool f = x > y;\n      \
    \  u64 max_v = f ? x : y;\n        y = f ? y : x;\n        x = (max_v - y) >>\
    \ s;\n    }\n    return x << (n < m ? n : m);\n}\n\n}  // namespace internal\n\
    /** @endcond */\n\n/**\n * @brief Miller-Rabin\u7D20\u6570\u5224\u5B9A\u6CD5 (\u30E2\
    \u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\u7248)\n */\ninline bool is_prime(ll n_)\
    \ {\n    if (n_ <= 1) return false;\n    u64 n = n_;\n    if (n == 2 || n == 3\
    \ || n == 5 || n == 7) return true;\n    if (n % 2 == 0 || n % 3 == 0 || n % 5\
    \ == 0 || n % 7 == 0) return false;\n\n    Montgomery m(n);\n    u64 d = n - 1;\n\
    \    int s = __builtin_ctzll(d);\n    d >>= s;\n\n    u64 one = m.one();\n   \
    \ u64 minus_one = n - one;\n    u64 r2 = m.r2();\n\n    auto check = [&](const\
    \ auto& bases) {\n        for (u64 a : bases) {\n            if (n <= a) break;\n\
    \            u64 a_mont = m.mul(a, r2);\n            u64 x = m.pow(a_mont, d,\
    \ one);\n            if (x == one || x == minus_one) continue;\n            bool\
    \ composite = true;\n            for (int r = 1; r < s; r++) {\n             \
    \   x = m.norm(m.mul(x, x));\n                if (x == one) return false;\n  \
    \              if (x == minus_one) {\n                    composite = false;\n\
    \                    break;\n                }\n            }\n            if\
    \ (composite) return false;\n        }\n        return true;\n    };\n\n    if\
    \ (n < 4759123141ULL) {\n        static constexpr u64 bases_small[] = {2, 7, 61};\n\
    \        return check(bases_small);\n    } else {\n        static constexpr u64\
    \ bases_large[] = {2, 325, 9375, 28178,\n                                    \
    \          450775, 9780504, 1795265022};\n        return check(bases_large);\n\
    \    }\n}\n\n/**\n * @brief Pollard's rho\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306B\
    \u3088\u308B\u7D20\u56E0\u6570\u63A2\u7D22\n */\ninline ll pollard_rho(ll n_)\
    \ {\n    assert(n_ > 1);\n    u64 n = n_;\n    if (n % 2 == 0) return 2;\n   \
    \ if (is_prime(n)) return n;\n\n    using internal::gcd_stein;\n    const Montgomery\
    \ m(n);\n\n    constexpr u64 C1 = 1, C2 = 2, M = 512;\n    u64 Z1 = 1, Z2 = 2;\n\
    \nretry:\n    u64 z1 = Z1, z2 = Z2;\n    for (size_t k = M;; k *= 2) {\n     \
    \   const u64 x1 = z1 + n;\n        const u64 x2 = z2 + n;\n        for (size_t\
    \ j = 0; j < k; j += M) {\n            const u64 y1 = z1;\n            const u64\
    \ y2 = z2;\n\n            u64 q1 = 1, q2 = 2;\n            z1 = m.fma(z1, z1,\
    \ C1);\n            z2 = m.fma(z2, z2, C2);\n            for (size_t i = 0; i\
    \ < M; ++i) {\n                u64 t1 = x1 - z1;\n                u64 t2 = x2\
    \ - z2;\n                z1 = m.fma(z1, z1, C1);\n                z2 = m.fma(z2,\
    \ z2, C2);\n                q1 = m.mul(q1, t1);\n                q2 = m.mul(q2,\
    \ t2);\n            }\n            q1 = m.mul(q1, x1 - z1);\n            q2 =\
    \ m.mul(q2, x2 - z2);\n\n            u64 q3 = m.mul(q1, q2);\n            u64\
    \ g3 = gcd_stein(n, q3);\n            if (g3 == 1) continue;\n            if (g3\
    \ != n) return g3;\n\n            u64 g1 = gcd_stein(n, q1);\n            u64\
    \ g2 = gcd_stein(n, q2);\n\n            u64 C = g1 != 1 ? C1 : C2;\n         \
    \   u64 x = g1 != 1 ? x1 : x2;\n            u64 z = g1 != 1 ? y1 : y2;\n     \
    \       u64 g = g1 != 1 ? g1 : g2;\n\n            if (g == n) {\n            \
    \    do {\n                    z = m.fma(z, z, C);\n                    g = gcd_stein(n,\
    \ x - z);\n                } while (g == 1);\n            }\n            if (g\
    \ != n) return g;\n\n            Z1 += 2;\n            Z2 += 2;\n            goto\
    \ retry;\n        }\n    }\n}\n\n// factorize, divisors_from_factors, divisors,\
    \ phi\n// \u306F\u5909\u66F4\u306A\u3057\u306E\u305F\u3081\u7701\u7565\u305B\u305A\
    \u305D\u306E\u307E\u307E\u7DAD\u6301\ninline std::vector<std::pair<ll, int>> factorize(ll\
    \ n) {\n    std::vector<std::pair<ll, int>> res;\n    if (n <= 1) return res;\n\
    \n    int cnt2 = __builtin_ctzll(n);\n    if (cnt2 > 0) {\n        res.emplace_back(2,\
    \ cnt2);\n        n >>= cnt2;\n    }\n    if (n == 1) return res;\n\n    std::vector<ll>\
    \ primes;\n    auto dfs = [&](auto self, ll m) -> void {\n        if (m <= 1)\
    \ return;\n        if (is_prime(m)) {\n            primes.push_back(m);\n    \
    \        return;\n        }\n        ll d = pollard_rho(m);\n        self(self,\
    \ d);\n        self(self, m / d);\n    };\n    dfs(dfs, n);\n    std::sort(primes.begin(),\
    \ primes.end());\n\n    ll cur = primes[0];\n    int cnt = 1;\n    for (size_t\
    \ i = 1; i < primes.size(); i++) {\n        if (primes[i] == cur) {\n        \
    \    cnt++;\n        } else {\n            res.emplace_back(cur, cnt);\n     \
    \       cur = primes[i];\n            cnt = 1;\n        }\n    }\n    res.emplace_back(cur,\
    \ cnt);\n    return res;\n}\n\ntemplate <typename T>\ninline std::vector<T> divisors_from_factors(\n\
    \    const std::vector<std::pair<T, int>>& factors) {\n    size_t sz = 1;\n  \
    \  for (const auto& [p, e] : factors) sz *= (e + 1);\n    std::vector<T> res;\n\
    \    res.reserve(sz);\n    res.push_back(1);\n\n    for (const auto& [p, e] :\
    \ factors) {\n        size_t cur_sz = res.size();\n        T p_pow = 1;\n    \
    \    for (int i = 1; i <= e; i++) {\n            p_pow *= p;\n            for\
    \ (size_t j = 0; j < cur_sz; j++) {\n                res.push_back(res[j] * p_pow);\n\
    \            }\n        }\n    }\n    std::sort(res.begin(), res.end());\n   \
    \ return res;\n}\n\ninline std::vector<ll> divisors(ll n) {\n    if (n <= 0) return\
    \ {};\n    return divisors_from_factors(factorize(n));\n}\n\ninline ll phi(ll\
    \ n) {\n    if (n <= 0) return 0;\n    ll res = n;\n    for (const auto& [p, e]\
    \ : factorize(n)) {\n        res -= res / p;\n    }\n    return res;\n}\n\n} \
    \ // namespace nt\n#line 16 \"lib/nt/primitive_root.hpp\"\n\nnamespace nt {\n\n\
    /**\n * @brief \u6CD5 m \u306B\u304A\u3051\u308B a \u306E\u4E57\u6CD5\u4F4D\u6570\
    \ ord_m(a) \u3092\u6C42\u3081\u308B (\u524D\u8A08\u7B97\u5229\u7528\u7248)\n *\
    \ @param a \u5E95\n * @param m \u6CD5 (m >= 1)\n * @param phi_m \u30AA\u30A4\u30E9\
    \u30FC\u306E\u03C6\u95A2\u6570\u5024 phi(m)\n * @param phi_factors phi(m) \u306E\
    \u7D20\u56E0\u6570\u5206\u89E3\u30EA\u30B9\u30C8\n * @return ll a^k = 1 (mod m)\
    \ \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u6B63\u6574\u6570 k (gcd(a, m) !=\
    \ 1 \u306E\u5834\u5408\u306F 0)\n */\ninline ll order(ll a, ll m, ll phi_m,\n\
    \                const std::vector<std::pair<ll, int>>& phi_factors) {\n    assert(m\
    \ >= 1);\n    if (m == 1) return 1;\n    a %= m;\n    if (a < 0) a += m;\n   \
    \ if (std::gcd(a, m) != 1) return 0;\n\n    ll res = phi_m;\n    if (m & 1) {\n\
    \        Montgomery mont(m);\n        u64 one = mont.one();\n        u64 a_mont\
    \ = mont.mul(a, mont.r2());\n        for (const auto& [p, e] : phi_factors) {\n\
    \            while (res % p == 0 && mont.pow(a_mont, res / p, one) == one) {\n\
    \                res /= p;\n            }\n        }\n    } else {\n        for\
    \ (const auto& [p, e] : phi_factors) {\n            while (res % p == 0 && pow_mod(a,\
    \ res / p, m) == 1) {\n                res /= p;\n            }\n        }\n \
    \   }\n    return res;\n}\n\n/**\n * @brief \u6CD5 m \u306B\u304A\u3051\u308B\
    \ a \u306E\u4E57\u6CD5\u4F4D\u6570 ord_m(a) \u3092\u6C42\u3081\u308B\n * @param\
    \ a \u5E95 (gcd(a, m) == 1 \u3067\u306A\u3044\u5834\u5408\u306F 0 \u3092\u8FD4\
    \u3059)\n * @param m \u6CD5 (m >= 1)\n * @return ll a^k = 1 (mod m) \u3092\u6E80\
    \u305F\u3059\u6700\u5C0F\u306E\u6B63\u6574\u6570 k (\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F 0)\n * @note \u8A08\u7B97\u91CF: \u671F\u5F85\u5024 O(m^{1/4})\n\
    \ */\ninline ll order(ll a, ll m) {\n    assert(m >= 1);\n    if (m == 1) return\
    \ 1;\n    a %= m;\n    if (a < 0) a += m;\n    if (std::gcd(a, m) != 1) return\
    \ 0;\n\n    ll phi_m = phi(m);\n    auto phi_factors = factorize(phi_m);\n   \
    \ return order(a, m, phi_m, phi_factors);\n}\n\n/**\n * @brief \u7D20\u6570 p\
    \ \u306B\u5BFE\u3059\u308B\u6700\u5C0F\u306E\u539F\u59CB\u6839\u3092\u6C42\u3081\
    \u308B\n * (\u6E1B\u7B97\u578B\u9045\u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\
    \u7B97\u306B\u3088\u308B\u9AD8\u901F\u7248)\n * @param p \u7D20\u6570 (p >= 2)\n\
    \ * @return ll \u6700\u5C0F\u306E\u539F\u59CB\u6839\n * @note \u8A08\u7B97\u91CF\
    : \u671F\u5F85\u5024 O((p - 1)^{1/4})\n */\ninline ll primitive_root_prime(ll\
    \ p) {\n    assert(p >= 2);\n    if (p == 2) return 1;\n    if (p == 998244353)\
    \ return 3;\n\n    auto factors = factorize(p - 1);\n    std::vector<u64> exps;\n\
    \    exps.reserve(factors.size());\n    for (const auto& [q, e] : factors) {\n\
    \        exps.push_back((p - 1) / q);\n    }\n\n    Montgomery m(p);\n    u64\
    \ one = m.one();\n    u64 r2 = m.r2();\n\n    for (u64 g = 2;; g++) {\n      \
    \  u64 g_mont = m.mul(g, r2);\n        bool ok = true;\n        for (u64 exp :\
    \ exps) {\n            if (m.pow(g_mont, exp, one) == one) {\n               \
    \ ok = false;\n                break;\n            }\n        }\n        if (ok)\
    \ return g;\n    }\n}\n\n/**\n * @brief \u4E00\u822C\u306E\u6B63\u6574\u6570 n\
    \ \u306B\u5BFE\u3059\u308B\u6700\u5C0F\u306E\u539F\u59CB\u6839\u3092\u6C42\u3081\
    \u308B\n * @details \u539F\u59CB\u6839\u304C\u5B58\u5728\u3059\u308B n (n = 1,\
    \ 2, 4, p^k, 2p^k (p\u306F\u5947\u7D20\u6570))\n * \u306B\u5BFE\u3057\u3066\u6700\
    \u5C0F\u306E\u539F\u59CB\u6839\u3092\u8FD4\u3059\n * @param n \u5BFE\u8C61\u306E\
    \u6B63\u6574\u6570 (n >= 1)\n * @return ll \u6700\u5C0F\u306E\u539F\u59CB\u6839\
    \ (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1)\n * @note \u8A08\u7B97\
    \u91CF: \u671F\u5F85\u5024 O(n^{1/4})\n */\ninline ll primitive_root(ll n) {\n\
    \    assert(n >= 1);\n    if (n == 1) return 0;\n    if (n == 2) return 1;\n \
    \   if (n == 4) return 3;\n    if (is_prime(n)) return primitive_root_prime(n);\n\
    \n    // \u539F\u59CB\u6839\u306E\u5B58\u5728\u5224\u5B9A: n = p^k \u307E\u305F\
    \u306F 2*p^k (p\u306F\u5947\u7D20\u6570)\n    ll m = n;\n    if ((m & 1) == 0)\
    \ {\n        m >>= 1;\n        if ((m & 1) == 0) return -1;  // 4\u3088\u308A\u5927\
    \u304D\u30444\u306E\u500D\u6570\u306F\u539F\u59CB\u6839\u3092\u6301\u305F\u306A\
    \u3044\n    }\n\n    auto factors_m = factorize(m);\n    if (factors_m.size()\
    \ != 1) {\n        return -1;  // \u7570\u306A\u308B2\u3064\u4EE5\u4E0A\u306E\u5947\
    \u7D20\u6570\u3067\u5272\u308C\u308B\u5834\u5408\u306F\u5B58\u5728\u3057\u306A\
    \u3044\n    }\n\n    ll p = factors_m[0].first;\n    ll phi_n = (m / p) * (p -\
    \ 1);\n\n    // phi(n) \u306E\u7D20\u56E0\u6570\u30EA\u30B9\u30C8\u3092\u4F5C\u6210\
    \ (p \u3068 p-1 \u306E\u7D20\u56E0\u6570)\n    auto factors_phi = factorize(p\
    \ - 1);\n    std::vector<u64> exps;\n    exps.reserve(factors_phi.size() + 1);\n\
    \    if (factors_m[0].second >= 2) {\n        exps.push_back(phi_n / p);\n   \
    \ }\n    for (const auto& [q, e] : factors_phi) {\n        exps.push_back(phi_n\
    \ / q);\n    }\n\n    // n = p^k \u307E\u305F\u306F n = 2*p^k \u306E\u3044\u305A\
    \u308C\u3067\u3042\u3063\u3066\u3082\u3001\n    // \u5947\u6570\u306E\u6CD5 m\
    \ = p^k \u4E0A\u3067\u306E\u4F4D\u6570\u304C phi(n) == phi(m) \u306B\u4E00\u81F4\
    \u3059\u308B\u304B\u3092\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\u3067\u5224\
    \u5B9A\u3067\u304D\u308B\uFF01\n    Montgomery mont(m);\n    u64 one = mont.one();\n\
    \    u64 r2 = mont.r2();\n    u64 step = (n & 1) ? 1 : 2;\n    u64 start = (n\
    \ & 1) ? 2 : 3;\n\n    for (u64 g = start;; g += step) {\n        if (g % p ==\
    \ 0) continue;\n        u64 g_mont = mont.mul(g % m, r2);\n        bool ok = true;\n\
    \        for (u64 exp : exps) {\n            if (mont.pow(g_mont, exp, one) ==\
    \ one) {\n                ok = false;\n                break;\n            }\n\
    \        }\n        if (ok) return g;\n    }\n}\n\n}  // namespace nt\n"
  code: "#pragma once\n\n/**\n * @file primitive_root.hpp\n * @brief \u4E57\u6CD5\u4F4D\
    \u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive Root) \u306E\u63A2\u7D22\n\
    \ */\n\n#include <cassert>\n#include <cstdint>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n\n#include \"factorize.hpp\"\n#include \"modular.hpp\"\n\n\
    namespace nt {\n\n/**\n * @brief \u6CD5 m \u306B\u304A\u3051\u308B a \u306E\u4E57\
    \u6CD5\u4F4D\u6570 ord_m(a) \u3092\u6C42\u3081\u308B (\u524D\u8A08\u7B97\u5229\
    \u7528\u7248)\n * @param a \u5E95\n * @param m \u6CD5 (m >= 1)\n * @param phi_m\
    \ \u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\u5024 phi(m)\n * @param phi_factors\
    \ phi(m) \u306E\u7D20\u56E0\u6570\u5206\u89E3\u30EA\u30B9\u30C8\n * @return ll\
    \ a^k = 1 (mod m) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u6B63\u6574\u6570\
    \ k (gcd(a, m) != 1 \u306E\u5834\u5408\u306F 0)\n */\ninline ll order(ll a, ll\
    \ m, ll phi_m,\n                const std::vector<std::pair<ll, int>>& phi_factors)\
    \ {\n    assert(m >= 1);\n    if (m == 1) return 1;\n    a %= m;\n    if (a <\
    \ 0) a += m;\n    if (std::gcd(a, m) != 1) return 0;\n\n    ll res = phi_m;\n\
    \    if (m & 1) {\n        Montgomery mont(m);\n        u64 one = mont.one();\n\
    \        u64 a_mont = mont.mul(a, mont.r2());\n        for (const auto& [p, e]\
    \ : phi_factors) {\n            while (res % p == 0 && mont.pow(a_mont, res /\
    \ p, one) == one) {\n                res /= p;\n            }\n        }\n   \
    \ } else {\n        for (const auto& [p, e] : phi_factors) {\n            while\
    \ (res % p == 0 && pow_mod(a, res / p, m) == 1) {\n                res /= p;\n\
    \            }\n        }\n    }\n    return res;\n}\n\n/**\n * @brief \u6CD5\
    \ m \u306B\u304A\u3051\u308B a \u306E\u4E57\u6CD5\u4F4D\u6570 ord_m(a) \u3092\u6C42\
    \u3081\u308B\n * @param a \u5E95 (gcd(a, m) == 1 \u3067\u306A\u3044\u5834\u5408\
    \u306F 0 \u3092\u8FD4\u3059)\n * @param m \u6CD5 (m >= 1)\n * @return ll a^k =\
    \ 1 (mod m) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u6B63\u6574\u6570 k (\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306F 0)\n * @note \u8A08\u7B97\u91CF: \u671F\
    \u5F85\u5024 O(m^{1/4})\n */\ninline ll order(ll a, ll m) {\n    assert(m >= 1);\n\
    \    if (m == 1) return 1;\n    a %= m;\n    if (a < 0) a += m;\n    if (std::gcd(a,\
    \ m) != 1) return 0;\n\n    ll phi_m = phi(m);\n    auto phi_factors = factorize(phi_m);\n\
    \    return order(a, m, phi_m, phi_factors);\n}\n\n/**\n * @brief \u7D20\u6570\
    \ p \u306B\u5BFE\u3059\u308B\u6700\u5C0F\u306E\u539F\u59CB\u6839\u3092\u6C42\u3081\
    \u308B\n * (\u6E1B\u7B97\u578B\u9045\u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\
    \u7B97\u306B\u3088\u308B\u9AD8\u901F\u7248)\n * @param p \u7D20\u6570 (p >= 2)\n\
    \ * @return ll \u6700\u5C0F\u306E\u539F\u59CB\u6839\n * @note \u8A08\u7B97\u91CF\
    : \u671F\u5F85\u5024 O((p - 1)^{1/4})\n */\ninline ll primitive_root_prime(ll\
    \ p) {\n    assert(p >= 2);\n    if (p == 2) return 1;\n    if (p == 998244353)\
    \ return 3;\n\n    auto factors = factorize(p - 1);\n    std::vector<u64> exps;\n\
    \    exps.reserve(factors.size());\n    for (const auto& [q, e] : factors) {\n\
    \        exps.push_back((p - 1) / q);\n    }\n\n    Montgomery m(p);\n    u64\
    \ one = m.one();\n    u64 r2 = m.r2();\n\n    for (u64 g = 2;; g++) {\n      \
    \  u64 g_mont = m.mul(g, r2);\n        bool ok = true;\n        for (u64 exp :\
    \ exps) {\n            if (m.pow(g_mont, exp, one) == one) {\n               \
    \ ok = false;\n                break;\n            }\n        }\n        if (ok)\
    \ return g;\n    }\n}\n\n/**\n * @brief \u4E00\u822C\u306E\u6B63\u6574\u6570 n\
    \ \u306B\u5BFE\u3059\u308B\u6700\u5C0F\u306E\u539F\u59CB\u6839\u3092\u6C42\u3081\
    \u308B\n * @details \u539F\u59CB\u6839\u304C\u5B58\u5728\u3059\u308B n (n = 1,\
    \ 2, 4, p^k, 2p^k (p\u306F\u5947\u7D20\u6570))\n * \u306B\u5BFE\u3057\u3066\u6700\
    \u5C0F\u306E\u539F\u59CB\u6839\u3092\u8FD4\u3059\n * @param n \u5BFE\u8C61\u306E\
    \u6B63\u6574\u6570 (n >= 1)\n * @return ll \u6700\u5C0F\u306E\u539F\u59CB\u6839\
    \ (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1)\n * @note \u8A08\u7B97\
    \u91CF: \u671F\u5F85\u5024 O(n^{1/4})\n */\ninline ll primitive_root(ll n) {\n\
    \    assert(n >= 1);\n    if (n == 1) return 0;\n    if (n == 2) return 1;\n \
    \   if (n == 4) return 3;\n    if (is_prime(n)) return primitive_root_prime(n);\n\
    \n    // \u539F\u59CB\u6839\u306E\u5B58\u5728\u5224\u5B9A: n = p^k \u307E\u305F\
    \u306F 2*p^k (p\u306F\u5947\u7D20\u6570)\n    ll m = n;\n    if ((m & 1) == 0)\
    \ {\n        m >>= 1;\n        if ((m & 1) == 0) return -1;  // 4\u3088\u308A\u5927\
    \u304D\u30444\u306E\u500D\u6570\u306F\u539F\u59CB\u6839\u3092\u6301\u305F\u306A\
    \u3044\n    }\n\n    auto factors_m = factorize(m);\n    if (factors_m.size()\
    \ != 1) {\n        return -1;  // \u7570\u306A\u308B2\u3064\u4EE5\u4E0A\u306E\u5947\
    \u7D20\u6570\u3067\u5272\u308C\u308B\u5834\u5408\u306F\u5B58\u5728\u3057\u306A\
    \u3044\n    }\n\n    ll p = factors_m[0].first;\n    ll phi_n = (m / p) * (p -\
    \ 1);\n\n    // phi(n) \u306E\u7D20\u56E0\u6570\u30EA\u30B9\u30C8\u3092\u4F5C\u6210\
    \ (p \u3068 p-1 \u306E\u7D20\u56E0\u6570)\n    auto factors_phi = factorize(p\
    \ - 1);\n    std::vector<u64> exps;\n    exps.reserve(factors_phi.size() + 1);\n\
    \    if (factors_m[0].second >= 2) {\n        exps.push_back(phi_n / p);\n   \
    \ }\n    for (const auto& [q, e] : factors_phi) {\n        exps.push_back(phi_n\
    \ / q);\n    }\n\n    // n = p^k \u307E\u305F\u306F n = 2*p^k \u306E\u3044\u305A\
    \u308C\u3067\u3042\u3063\u3066\u3082\u3001\n    // \u5947\u6570\u306E\u6CD5 m\
    \ = p^k \u4E0A\u3067\u306E\u4F4D\u6570\u304C phi(n) == phi(m) \u306B\u4E00\u81F4\
    \u3059\u308B\u304B\u3092\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\u3067\u5224\
    \u5B9A\u3067\u304D\u308B\uFF01\n    Montgomery mont(m);\n    u64 one = mont.one();\n\
    \    u64 r2 = mont.r2();\n    u64 step = (n & 1) ? 1 : 2;\n    u64 start = (n\
    \ & 1) ? 2 : 3;\n\n    for (u64 g = start;; g += step) {\n        if (g % p ==\
    \ 0) continue;\n        u64 g_mont = mont.mul(g % m, r2);\n        bool ok = true;\n\
    \        for (u64 exp : exps) {\n            if (mont.pow(g_mont, exp, one) ==\
    \ one) {\n                ok = false;\n                break;\n            }\n\
    \        }\n        if (ok) return g;\n    }\n}\n\n}  // namespace nt"
  dependsOn:
  - lib/nt/factorize.hpp
  - lib/nt/modular.hpp
  isVerificationFile: false
  path: lib/nt/primitive_root.hpp
  requiredBy: []
  timestamp: '2026-10-17 16:39:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/nt/primitive_root.test.cpp
documentation_of: lib/nt/primitive_root.hpp
layout: document
redirect_from:
- /library/lib/nt/primitive_root.hpp
- /library/lib/nt/primitive_root.hpp.html
title: "\u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive Root)\
  \ \u306E\u63A2\u7D22"
---
