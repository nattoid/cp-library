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
  bundledCode: "#line 2 \"lib/util/rle.hpp\"\n#include <vector>\n#include <utility>\n\
    #include <functional>\n\ntemplate <class Key, class Val, class Op, class Eq =\
    \ std::equal_to<Key>>\nstd::vector<std::pair<Key, Val>> monoidal_rle(const std::vector<Key>&\
    \ keys, const std::vector<Val>& vals, Op op, Eq eq = std::equal_to<Key>()) {\n\
    \    std::vector<std::pair<Key, Val>> res;\n    for (std::size_t i = 0; i < keys.size();\
    \ ++i) {\n        if (res.empty() || !eq(res.back().first, keys[i])) {\n     \
    \       res.emplace_back(keys[i], vals[i]);\n        } else {\n            res.back().second\
    \ = op(res.back().second, vals[i]);\n        }\n    }\n    return res;\n}\n\n\
    template <class Container>\nauto rle(const Container& c) {\n    using T = typename\
    \ Container::value_type;\n    std::vector<std::pair<T, int>> res;\n    for (const\
    \ auto& x : c) {\n        if (res.empty() || res.back().first != x) {\n      \
    \      res.emplace_back(x, 1);\n        } else {\n            res.back().second++;\n\
    \        }\n    }\n    return res;\n}\n\ntemplate <class Container>\nauto circular_rle(const\
    \ Container& c) {\n    auto res = rle(c);\n    int offset = 0;\n    if (res.size()\
    \ > 1 && res.front().first == res.back().first) {\n        offset = res.back().second;\n\
    \        res.front().second += res.back().second;\n        res.pop_back();\n \
    \   }\n    return std::make_pair(res, offset);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <functional>\n\
    \ntemplate <class Key, class Val, class Op, class Eq = std::equal_to<Key>>\nstd::vector<std::pair<Key,\
    \ Val>> monoidal_rle(const std::vector<Key>& keys, const std::vector<Val>& vals,\
    \ Op op, Eq eq = std::equal_to<Key>()) {\n    std::vector<std::pair<Key, Val>>\
    \ res;\n    for (std::size_t i = 0; i < keys.size(); ++i) {\n        if (res.empty()\
    \ || !eq(res.back().first, keys[i])) {\n            res.emplace_back(keys[i],\
    \ vals[i]);\n        } else {\n            res.back().second = op(res.back().second,\
    \ vals[i]);\n        }\n    }\n    return res;\n}\n\ntemplate <class Container>\n\
    auto rle(const Container& c) {\n    using T = typename Container::value_type;\n\
    \    std::vector<std::pair<T, int>> res;\n    for (const auto& x : c) {\n    \
    \    if (res.empty() || res.back().first != x) {\n            res.emplace_back(x,\
    \ 1);\n        } else {\n            res.back().second++;\n        }\n    }\n\
    \    return res;\n}\n\ntemplate <class Container>\nauto circular_rle(const Container&\
    \ c) {\n    auto res = rle(c);\n    int offset = 0;\n    if (res.size() > 1 &&\
    \ res.front().first == res.back().first) {\n        offset = res.back().second;\n\
    \        res.front().second += res.back().second;\n        res.pop_back();\n \
    \   }\n    return std::make_pair(res, offset);\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/rle.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/rle.hpp
layout: document
redirect_from:
- /library/lib/util/rle.hpp
- /library/lib/util/rle.hpp.html
title: lib/util/rle.hpp
---
