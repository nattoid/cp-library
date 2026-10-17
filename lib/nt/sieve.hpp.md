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
  bundledCode: "#line 2 \"lib/nt/sieve.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace nt {\n\n// \u7DDA\u5F62\u7BE9\
    \u306B\u3088\u308B\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u7D04\u6570\
    \u5217\u6319: \u524D\u51E6\u7406 O(N)\nstruct LinearSieve {\n    int max_n;\n\
    \    std::vector<int> spf;\n    std::vector<int> primes;\n\n    LinearSieve(int\
    \ n) : max_n(n), spf(n + 1, 0) {\n        for (int i = 2; i <= n; i++) {\n   \
    \         if (spf[i] == 0) {\n                spf[i] = i;\n                primes.push_back(i);\n\
    \            }\n            for (int p : primes) {\n                if (p > spf[i]\
    \ || i * p > n) break;\n                spf[i * p] = p;\n            }\n     \
    \   }\n    }\n\n    // O(1) \u7D20\u6570\u5224\u5B9A\n    bool is_prime(int m)\
    \ const {\n        assert(0 <= m && m <= max_n);\n        if (m <= 1) return false;\n\
    \        return spf[m] == m;\n    }\n\n    // O(log m) \u7D20\u56E0\u6570\u5206\
    \u89E3\n    std::vector<std::pair<int, int>> factorize(int m) const {\n      \
    \  assert(0 <= m && m <= max_n);\n        std::vector<std::pair<int, int>> res;\n\
    \        while (m > 1) {\n            int p = spf[m];\n            int cnt = 0;\n\
    \            while (m % p == 0) {\n                cnt++;\n                m /=\
    \ p;\n            }\n            res.emplace_back(p, cnt);\n        }\n      \
    \  return res;\n    }\n\n    // O(log m + D log D) \u7D04\u6570\u5217\u6319\n\
    \    std::vector<int> divisors(int m) const {\n        assert(0 <= m && m <= max_n);\n\
    \        if (m == 0) return {};\n        std::vector<int> res = {1};\n       \
    \ while (m > 1) {\n            int p = spf[m];\n            int cnt = 0;\n   \
    \         while (m % p == 0) {\n                cnt++;\n                m /= p;\n\
    \            }\n            size_t sz = res.size();\n            int p_pow = 1;\n\
    \            for (int i = 0; i < cnt; i++) {\n                p_pow *= p;\n  \
    \              for (size_t j = 0; j < sz; j++) {\n                    res.push_back(res[j]\
    \ * p_pow);\n                }\n            }\n        }\n        std::sort(res.begin(),\
    \ res.end());\n        return res;\n    }\n};\n\n// 0 \u304B\u3089 max_n \u307E\
    \u3067\u306E\u30AA\u30A4\u30E9\u30FC\u306E \u03C6 \u95A2\u6570\u30C6\u30FC\u30D6\
    \u30EB: O(N log log N)\ninline std::vector<int> phi_table(int max_n) {\n    assert(max_n\
    \ >= 0);\n    std::vector<int> res(max_n + 1);\n    for (int i = 0; i <= max_n;\
    \ i++) res[i] = i;\n    for (int i = 2; i <= max_n; i++) {\n        if (res[i]\
    \ == i) {\n            for (int j = i; j <= max_n; j += i) {\n               \
    \ res[j] -= res[j] / i;\n            }\n        }\n    }\n    return res;\n}\n\
    \n// 0 \u304B\u3089 max_n \u307E\u3067\u306E\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\
    \ \u03BC(n) \u30C6\u30FC\u30D6\u30EB: O(N)\ninline std::vector<int> mobius_table(int\
    \ max_n) {\n    assert(max_n >= 0);\n    std::vector<int> mu(max_n + 1, 0);\n\
    \    std::vector<int> primes;\n    std::vector<bool> is_comp(max_n + 1, false);\n\
    \    if (max_n >= 1) mu[1] = 1;\n    for (int i = 2; i <= max_n; i++) {\n    \
    \    if (!is_comp[i]) {\n            primes.push_back(i);\n            mu[i] =\
    \ -1;\n        }\n        for (int p : primes) {\n            if (i * p > max_n)\
    \ break;\n            is_comp[i * p] = true;\n            if (i % p == 0) {\n\
    \                mu[i * p] = 0;\n                break;\n            } else {\n\
    \                mu[i * p] = -mu[i];\n            }\n        }\n    }\n    return\
    \ mu;\n}\n\n}  // namespace nt\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nnamespace nt {\n\n// \u7DDA\u5F62\u7BE9\u306B\u3088\u308B\
    \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u7D04\u6570\u5217\u6319: \u524D\
    \u51E6\u7406 O(N)\nstruct LinearSieve {\n    int max_n;\n    std::vector<int>\
    \ spf;\n    std::vector<int> primes;\n\n    LinearSieve(int n) : max_n(n), spf(n\
    \ + 1, 0) {\n        for (int i = 2; i <= n; i++) {\n            if (spf[i] ==\
    \ 0) {\n                spf[i] = i;\n                primes.push_back(i);\n  \
    \          }\n            for (int p : primes) {\n                if (p > spf[i]\
    \ || i * p > n) break;\n                spf[i * p] = p;\n            }\n     \
    \   }\n    }\n\n    // O(1) \u7D20\u6570\u5224\u5B9A\n    bool is_prime(int m)\
    \ const {\n        assert(0 <= m && m <= max_n);\n        if (m <= 1) return false;\n\
    \        return spf[m] == m;\n    }\n\n    // O(log m) \u7D20\u56E0\u6570\u5206\
    \u89E3\n    std::vector<std::pair<int, int>> factorize(int m) const {\n      \
    \  assert(0 <= m && m <= max_n);\n        std::vector<std::pair<int, int>> res;\n\
    \        while (m > 1) {\n            int p = spf[m];\n            int cnt = 0;\n\
    \            while (m % p == 0) {\n                cnt++;\n                m /=\
    \ p;\n            }\n            res.emplace_back(p, cnt);\n        }\n      \
    \  return res;\n    }\n\n    // O(log m + D log D) \u7D04\u6570\u5217\u6319\n\
    \    std::vector<int> divisors(int m) const {\n        assert(0 <= m && m <= max_n);\n\
    \        if (m == 0) return {};\n        std::vector<int> res = {1};\n       \
    \ while (m > 1) {\n            int p = spf[m];\n            int cnt = 0;\n   \
    \         while (m % p == 0) {\n                cnt++;\n                m /= p;\n\
    \            }\n            size_t sz = res.size();\n            int p_pow = 1;\n\
    \            for (int i = 0; i < cnt; i++) {\n                p_pow *= p;\n  \
    \              for (size_t j = 0; j < sz; j++) {\n                    res.push_back(res[j]\
    \ * p_pow);\n                }\n            }\n        }\n        std::sort(res.begin(),\
    \ res.end());\n        return res;\n    }\n};\n\n// 0 \u304B\u3089 max_n \u307E\
    \u3067\u306E\u30AA\u30A4\u30E9\u30FC\u306E \u03C6 \u95A2\u6570\u30C6\u30FC\u30D6\
    \u30EB: O(N log log N)\ninline std::vector<int> phi_table(int max_n) {\n    assert(max_n\
    \ >= 0);\n    std::vector<int> res(max_n + 1);\n    for (int i = 0; i <= max_n;\
    \ i++) res[i] = i;\n    for (int i = 2; i <= max_n; i++) {\n        if (res[i]\
    \ == i) {\n            for (int j = i; j <= max_n; j += i) {\n               \
    \ res[j] -= res[j] / i;\n            }\n        }\n    }\n    return res;\n}\n\
    \n// 0 \u304B\u3089 max_n \u307E\u3067\u306E\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\
    \ \u03BC(n) \u30C6\u30FC\u30D6\u30EB: O(N)\ninline std::vector<int> mobius_table(int\
    \ max_n) {\n    assert(max_n >= 0);\n    std::vector<int> mu(max_n + 1, 0);\n\
    \    std::vector<int> primes;\n    std::vector<bool> is_comp(max_n + 1, false);\n\
    \    if (max_n >= 1) mu[1] = 1;\n    for (int i = 2; i <= max_n; i++) {\n    \
    \    if (!is_comp[i]) {\n            primes.push_back(i);\n            mu[i] =\
    \ -1;\n        }\n        for (int p : primes) {\n            if (i * p > max_n)\
    \ break;\n            is_comp[i * p] = true;\n            if (i % p == 0) {\n\
    \                mu[i * p] = 0;\n                break;\n            } else {\n\
    \                mu[i * p] = -mu[i];\n            }\n        }\n    }\n    return\
    \ mu;\n}\n\n}  // namespace nt"
  dependsOn: []
  isVerificationFile: false
  path: lib/nt/sieve.hpp
  requiredBy: []
  timestamp: '2026-10-17 10:16:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/nt/sieve.hpp
layout: document
redirect_from:
- /library/lib/nt/sieve.hpp
- /library/lib/nt/sieve.hpp.html
title: lib/nt/sieve.hpp
---
