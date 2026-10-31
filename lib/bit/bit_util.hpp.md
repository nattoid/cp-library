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
  bundledCode: "#line 1 \"lib/bit/bit_util.hpp\"\n#include <bit>\n#include <concepts>\n\
    \n// \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u6570\u304C\u540C\u3058\u3067\
    \u3001\u6B21\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\uFF08Gosper's Hack\uFF09\
    \ntemplate <std::unsigned_integral T>\nconstexpr T next_combination(T v) {\n \
    \   if (v == 0) return 0;\n    T c = v & -v;\n    T r = v + c;\n    return (((r\
    \ ^ v) >> 2) >> std::countr_zero(v)) | r;\n}\n\n// \u6574\u6570\u304B\u3089\u30B0\
    \u30EC\u30A4\u30B3\u30FC\u30C9\u3078\u306E\u5909\u63DB\ntemplate <std::unsigned_integral\
    \ T>\nconstexpr T to_gray(T n) {\n    return n ^ (n >> 1);\n}\n\n// \u30B0\u30EC\
    \u30A4\u30B3\u30FC\u30C9\u304B\u3089\u5143\u306E\u6574\u6570\u3078\u306E\u5FA9\
    \u5143\ntemplate <std::unsigned_integral T>\nconstexpr T from_gray(T g) {\n  \
    \  T n = 0;\n    for (; g; g >>= 1) {\n        n ^= g;\n    }\n    return n;\n\
    }\n"
  code: "#include <bit>\n#include <concepts>\n\n// \u7ACB\u3063\u3066\u3044\u308B\u30D3\
    \u30C3\u30C8\u6570\u304C\u540C\u3058\u3067\u3001\u6B21\u306B\u5927\u304D\u3044\
    \u5024\u3092\u8FD4\u3059\uFF08Gosper's Hack\uFF09\ntemplate <std::unsigned_integral\
    \ T>\nconstexpr T next_combination(T v) {\n    if (v == 0) return 0;\n    T c\
    \ = v & -v;\n    T r = v + c;\n    return (((r ^ v) >> 2) >> std::countr_zero(v))\
    \ | r;\n}\n\n// \u6574\u6570\u304B\u3089\u30B0\u30EC\u30A4\u30B3\u30FC\u30C9\u3078\
    \u306E\u5909\u63DB\ntemplate <std::unsigned_integral T>\nconstexpr T to_gray(T\
    \ n) {\n    return n ^ (n >> 1);\n}\n\n// \u30B0\u30EC\u30A4\u30B3\u30FC\u30C9\
    \u304B\u3089\u5143\u306E\u6574\u6570\u3078\u306E\u5FA9\u5143\ntemplate <std::unsigned_integral\
    \ T>\nconstexpr T from_gray(T g) {\n    T n = 0;\n    for (; g; g >>= 1) {\n \
    \       n ^= g;\n    }\n    return n;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/bit/bit_util.hpp
  requiredBy: []
  timestamp: '2026-10-31 20:37:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/bit/bit_util.hpp
layout: document
redirect_from:
- /library/lib/bit/bit_util.hpp
- /library/lib/bit/bit_util.hpp.html
title: lib/bit/bit_util.hpp
---
