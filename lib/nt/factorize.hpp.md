---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/nt/modular.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u6F14\u7B97\u300164bit\u6E1B\u7B97\u578B\u9045\
      \u5EF6\u30E2\u30F3\u30B4\u30E1\u30EA\u6F14\u7B97\u5668\u3001extgcd\u3001CRT"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/nt/primitive_root.hpp
    title: "\u4E57\u6CD5\u4F4D\u6570 (Order) \u3068\u539F\u59CB\u6839 (Primitive Root)\
      \ \u306E\u63A2\u7D22"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/nt/factorize.test.cpp
    title: verify/nt/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Miller-Rabin\u7D20\u6570\u5224\u5B9A\u6CD5 (\u30E2\u30F3\u30B4\
      \u30E1\u30EA\u4E57\u7B97\u7248)"
    links:
    - https://andantesoft.hatenablog.com/entry/2025/05/21/164352
    - https://judge.yosupo.jp/submission/189742
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/nt/factorize.hpp: line 9: #pragma once found in a non-first line\n"
  code: "/**\n * @file factorize.hpp\n * @brief\n * \u7D20\u6570\u5224\u5B9A\u3001\
    \u7D20\u56E0\u6570\u5206\u89E3\u3001\u7D04\u6570\u5217\u6319\u3001\u30AA\u30A4\
    \u30E9\u30FC\u306E\u03C6\u95A2\u6570\u306A\u3069\u3092\u63D0\u4F9B\u3059\u308B\
    \u6574\u6570\u8AD6\u30E9\u30A4\u30D6\u30E9\u30EA\n * @see https://andantesoft.hatenablog.com/entry/2025/05/21/164352\n\
    \ * @see https://judge.yosupo.jp/submission/189742\n */\n\n#pragma once\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"modular.hpp\"\n\nnamespace nt {\n\n/** @cond INTERNAL\
    \ */\nnamespace internal {\n\n// Binary GCD (Stein's algorithm)\ninline u64 gcd_stein(u64\
    \ x, u64 y) {\n    if (x == 0) return y;\n    if (y == 0) return x;\n    int n\
    \ = __builtin_ctzll(x);\n    int m = __builtin_ctzll(y);\n    x >>= n;\n    y\
    \ >>= m;\n    while (x != y) {\n        int s = __builtin_ctzll(x - y);\n    \
    \    bool f = x > y;\n        u64 max_v = f ? x : y;\n        y = f ? y : x;\n\
    \        x = (max_v - y) >> s;\n    }\n    return x << (n < m ? n : m);\n}\n\n\
    }  // namespace internal\n/** @endcond */\n\n/**\n * @brief Miller-Rabin\u7D20\
    \u6570\u5224\u5B9A\u6CD5 (\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97\u7248)\n\
    \ */\ninline bool is_prime(ll n_) {\n    if (n_ <= 1) return false;\n    u64 n\
    \ = n_;\n    if (n == 2 || n == 3 || n == 5 || n == 7) return true;\n    if (n\
    \ % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return false;\n\n    Montgomery\
    \ m(n);\n    u64 d = n - 1;\n    int s = __builtin_ctzll(d);\n    d >>= s;\n\n\
    \    u64 one = m.one();\n    u64 minus_one = n - one;\n    u64 r2 = m.r2();\n\n\
    \    auto check = [&](const auto& bases) {\n        for (u64 a : bases) {\n  \
    \          if (n <= a) break;\n            u64 a_mont = m.mul(a, r2);\n      \
    \      u64 x = m.pow(a_mont, d, one);\n            if (x == one || x == minus_one)\
    \ continue;\n            bool composite = true;\n            for (int r = 1; r\
    \ < s; r++) {\n                x = m.norm(m.mul(x, x));\n                if (x\
    \ == one) return false;\n                if (x == minus_one) {\n             \
    \       composite = false;\n                    break;\n                }\n  \
    \          }\n            if (composite) return false;\n        }\n        return\
    \ true;\n    };\n\n    if (n < 4759123141ULL) {\n        static constexpr u64\
    \ bases_small[] = {2, 7, 61};\n        return check(bases_small);\n    } else\
    \ {\n        static constexpr u64 bases_large[] = {2,      325,     9375,    \
    \  28178,\n                                              450775, 9780504, 1795265022};\n\
    \        return check(bases_large);\n    }\n}\n\n/**\n * @brief Pollard's rho\u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\u306B\u3088\u308B\u7D20\u56E0\u6570\u63A2\u7D22\
    \n */\ninline ll pollard_rho(ll n_) {\n    assert(n_ > 1);\n    u64 n = n_;\n\
    \    if (n % 2 == 0) return 2;\n    if (is_prime(n)) return n;\n\n    using internal::gcd_stein;\n\
    \    const Montgomery m(n);\n\n    constexpr u64 C1 = 1, C2 = 2, M = 512;\n  \
    \  u64 Z1 = 1, Z2 = 2;\n\nretry:\n    u64 z1 = Z1, z2 = Z2;\n    for (size_t k\
    \ = M;; k *= 2) {\n        const u64 x1 = z1 + n;\n        const u64 x2 = z2 +\
    \ n;\n        for (size_t j = 0; j < k; j += M) {\n            const u64 y1 =\
    \ z1;\n            const u64 y2 = z2;\n\n            u64 q1 = 1, q2 = 2;\n   \
    \         z1 = m.fma(z1, z1, C1);\n            z2 = m.fma(z2, z2, C2);\n     \
    \       for (size_t i = 0; i < M; ++i) {\n                u64 t1 = x1 - z1;\n\
    \                u64 t2 = x2 - z2;\n                z1 = m.fma(z1, z1, C1);\n\
    \                z2 = m.fma(z2, z2, C2);\n                q1 = m.mul(q1, t1);\n\
    \                q2 = m.mul(q2, t2);\n            }\n            q1 = m.mul(q1,\
    \ x1 - z1);\n            q2 = m.mul(q2, x2 - z2);\n\n            u64 q3 = m.mul(q1,\
    \ q2);\n            u64 g3 = gcd_stein(n, q3);\n            if (g3 == 1) continue;\n\
    \            if (g3 != n) return g3;\n\n            u64 g1 = gcd_stein(n, q1);\n\
    \            u64 g2 = gcd_stein(n, q2);\n\n            u64 C = g1 != 1 ? C1 :\
    \ C2;\n            u64 x = g1 != 1 ? x1 : x2;\n            u64 z = g1 != 1 ? y1\
    \ : y2;\n            u64 g = g1 != 1 ? g1 : g2;\n\n            if (g == n) {\n\
    \                do {\n                    z = m.fma(z, z, C);\n             \
    \       g = gcd_stein(n, x - z);\n                } while (g == 1);\n        \
    \    }\n            if (g != n) return g;\n\n            Z1 += 2;\n          \
    \  Z2 += 2;\n            goto retry;\n        }\n    }\n}\n\n// factorize, divisors_from_factors,\
    \ divisors, phi\n// \u306F\u5909\u66F4\u306A\u3057\u306E\u305F\u3081\u7701\u7565\
    \u305B\u305A\u305D\u306E\u307E\u307E\u7DAD\u6301\ninline std::vector<std::pair<ll,\
    \ int>> factorize(ll n) {\n    std::vector<std::pair<ll, int>> res;\n    if (n\
    \ <= 1) return res;\n\n    int cnt2 = __builtin_ctzll(n);\n    if (cnt2 > 0) {\n\
    \        res.emplace_back(2, cnt2);\n        n >>= cnt2;\n    }\n    if (n ==\
    \ 1) return res;\n\n    std::vector<ll> primes;\n    auto dfs = [&](auto self,\
    \ ll m) -> void {\n        if (m <= 1) return;\n        if (is_prime(m)) {\n \
    \           primes.push_back(m);\n            return;\n        }\n        ll d\
    \ = pollard_rho(m);\n        self(self, d);\n        self(self, m / d);\n    };\n\
    \    dfs(dfs, n);\n    std::sort(primes.begin(), primes.end());\n\n    ll cur\
    \ = primes[0];\n    int cnt = 1;\n    for (size_t i = 1; i < primes.size(); i++)\
    \ {\n        if (primes[i] == cur) {\n            cnt++;\n        } else {\n \
    \           res.emplace_back(cur, cnt);\n            cur = primes[i];\n      \
    \      cnt = 1;\n        }\n    }\n    res.emplace_back(cur, cnt);\n    return\
    \ res;\n}\n\ntemplate <typename T>\ninline std::vector<T> divisors_from_factors(\n\
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
    \ // namespace nt"
  dependsOn:
  - lib/nt/modular.hpp
  isVerificationFile: false
  path: lib/nt/factorize.hpp
  requiredBy:
  - lib/nt/primitive_root.hpp
  timestamp: '2026-10-17 15:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/nt/factorize.test.cpp
documentation_of: lib/nt/factorize.hpp
layout: document
---

# 整数論ライブラリ (素因数分解・素数判定)

素数判定、素因数分解、約数列挙、オイラーの $\phi$ 関数などを提供するライブラリです。
内部的にモンゴメリ乗算を用いた Miller-Rabin 素数判定法と、Pollard's rho アルゴリズムを使用しており、$O(N^{1/4})$ ベースで高速に動作します。

## 提供する関数

### `is_prime(ll n)`
`n` が素数かどうかを判定します。
- **計算量:** $O(\log N)$
- 内部仕様: 64bit整数の範囲で確定的に判定するため、底として特定の素数の集合を用いています。

### `factorize(ll n)`
`n` を素因数分解し、`(素因数, 指数)` のペアの配列を素因数の昇順にソートして返します。
- **計算量:** 期待値 $O(N^{1/4})$
- $n \le 1$ の場合は空の配列を返します。

### `divisors(ll n)`
`n` のすべての約数を昇順に列挙して返します。
- **計算量:** 期待値 $O(N^{1/4} + D \log D)$ （$D$ は約数の個数）
- 内部で `factorize` を呼び出し、得られた素因数からDFS的に約数を構築してソートします。

### `phi(ll n)`
オイラーの $\phi$ 関数（$n$ と互いに素な $1$ 以上 $n$ 以下の整数の個数）の値を返します。
- **計算量:** 期待値 $O(N^{1/4})$

## 参考文献
- [https://andantesoft.hatenablog.com/entry/2025/05/21/164352](https://andantesoft.hatenablog.com/entry/2025/05/21/164352)
- [https://judge.yosupo.jp/submission/189742](https://judge.yosupo.jp/submission/189742)