---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Zeta Transform / Moebius Transform
    links: []
  bundledCode: "#line 2 \"lib/set-function/zeta-mobius-transform.hpp\"\n\ntemplate\
    \ <typename T>\nvoid superset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n\
    \  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] += f[j | i];\n\
    \      }\n    }\n  }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n &\
    \ (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j\
    \ < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] -= f[j];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void multiple_zeta_transform(std::vector<T>& f, const std::vector<int>& primes)\
    \ {\n    int n = f.size() - 1;\n    for (int p : primes) {\n        for (int i\
    \ = n / p; i >= 1; --i) {\n            f[i] += f[i * p];\n        }\n    }\n}\n\
    \ntemplate <typename T>\nvoid multiple_mobius_transform(std::vector<T>& f, const\
    \ std::vector<int>& primes) {\n    int n = f.size() - 1;\n    for (int p : primes)\
    \ {\n        for (int i = 1; i * p <= n; ++i) {\n            f[i] -= f[i * p];\n\
    \        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_zeta_transform(std::vector<T>&\
    \ f, const std::vector<int>& primes) {\n    int n = f.size() - 1;\n    for (int\
    \ p : primes) {\n        for (int i = 1; i * p <= n; ++i) {\n            f[i *\
    \ p] += f[i];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_mobius_transform(std::vector<T>&\
    \ f, const std::vector<int>& primes) {\n    int n = f.size() - 1;\n    for (int\
    \ p : primes) {\n        for (int i = n / p; i >= 1; --i) {\n            f[i *\
    \ p] -= f[i];\n        }\n    }\n}\n\n/**\n * @brief Zeta Transform / Moebius\
    \ Transform\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] += f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void superset_mobius_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] -= f[j | i];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_zeta_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] += f[j];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_mobius_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] -= f[j];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid multiple_zeta_transform(std::vector<T>&\
    \ f, const std::vector<int>& primes) {\n    int n = f.size() - 1;\n    for (int\
    \ p : primes) {\n        for (int i = n / p; i >= 1; --i) {\n            f[i]\
    \ += f[i * p];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid multiple_mobius_transform(std::vector<T>&\
    \ f, const std::vector<int>& primes) {\n    int n = f.size() - 1;\n    for (int\
    \ p : primes) {\n        for (int i = 1; i * p <= n; ++i) {\n            f[i]\
    \ -= f[i * p];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_zeta_transform(std::vector<T>&\
    \ f, const std::vector<int>& primes) {\n    int n = f.size() - 1;\n    for (int\
    \ p : primes) {\n        for (int i = 1; i * p <= n; ++i) {\n            f[i *\
    \ p] += f[i];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_mobius_transform(std::vector<T>&\
    \ f, const std::vector<int>& primes) {\n    int n = f.size() - 1;\n    for (int\
    \ p : primes) {\n        for (int i = n / p; i >= 1; --i) {\n            f[i *\
    \ p] -= f[i];\n        }\n    }\n}\n\n/**\n * @brief Zeta Transform / Moebius\
    \ Transform\n */"
  dependsOn: []
  isVerificationFile: false
  path: lib/set-function/zeta-mobius-transform.hpp
  requiredBy: []
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/set-function/zeta-mobius-transform.hpp
layout: document
redirect_from:
- /library/lib/set-function/zeta-mobius-transform.hpp
- /library/lib/set-function/zeta-mobius-transform.hpp.html
title: Zeta Transform / Moebius Transform
---
