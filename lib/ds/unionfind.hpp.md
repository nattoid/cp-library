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
  bundledCode: "#line 2 \"lib/ds/unionfind.hpp\"\n#include <vector>\n#include <map>\n\
    #include <utility>\n\nstruct UnionFind {\n    std::vector<int> parent_or_size;\n\
    \    \n    UnionFind(int n = 0) : parent_or_size(n, -1) {}\n    \n    int add_node()\
    \ {\n        int id = parent_or_size.size();\n        parent_or_size.push_back(-1);\n\
    \        return id;\n    }\n    \n    int leader(int x) {\n        if (parent_or_size[x]\
    \ < 0) return x;\n        return parent_or_size[x] = leader(parent_or_size[x]);\n\
    \    }\n\n    bool merge(int x, int y) {\n        int root_x = leader(x);\n  \
    \      int root_y = leader(y);\n        if (root_x == root_y) return false;\n\
    \        if (-parent_or_size[root_x] < -parent_or_size[root_y]) {\n          \
    \  std::swap(root_x, root_y);\n        }\n        parent_or_size[root_x] += parent_or_size[root_y];\n\
    \        parent_or_size[root_y] = root_x;\n        return true;\n    }\n    \n\
    \    bool same(int x, int y) {\n        return leader(x) == leader(y);\n    }\n\
    \n    int size(int x) {\n        return -parent_or_size[leader(x)];\n    }\n};\n\
    \ntemplate <class T>\nstruct WeightedUnionFind {\n    std::vector<int> parent_or_size;\n\
    \    std::vector<T> diff_weight;\n    \n    WeightedUnionFind(int n = 0) : parent_or_size(n,\
    \ -1), diff_weight(n, 0) {}\n    \n    int add_node() {\n        int id = parent_or_size.size();\n\
    \        parent_or_size.push_back(-1);\n        diff_weight.push_back(0);\n  \
    \      return id;\n    }\n    \n    int leader(int x) {\n        if (parent_or_size[x]\
    \ < 0) return x;\n        int r = leader(parent_or_size[x]);\n        diff_weight[x]\
    \ += diff_weight[parent_or_size[x]];\n        return parent_or_size[x] = r;\n\
    \    }\n\n    T weight(int x) {\n        leader(x);\n        return diff_weight[x];\n\
    \    }\n\n    bool merge(int x, int y, T w) {\n        w += weight(x);\n     \
    \   w -= weight(y);\n        int root_x = leader(x);\n        int root_y = leader(y);\n\
    \        if (root_x == root_y) return false;\n        if (-parent_or_size[root_x]\
    \ < -parent_or_size[root_y]) {\n            std::swap(root_x, root_y);\n     \
    \       w = -w;\n        }\n        parent_or_size[root_x] += parent_or_size[root_y];\n\
    \        parent_or_size[root_y] = root_x;\n        diff_weight[root_y] = w;\n\
    \        return true;\n    }\n\n    T diff(int x, int y) {\n        return weight(y)\
    \ - weight(x);\n    }\n\n    bool same(int x, int y) {\n        return leader(x)\
    \ == leader(y);\n    }\n\n    int size(int x) {\n        return -parent_or_size[leader(x)];\n\
    \    }\n};\n\n// ID\u7BA1\u7406\u7528\u306E\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\
    \u30A3\ntemplate <class T>\nstruct IDManager {\n    std::map<T, int> id_map;\n\
    \    \n    int get_id(const T& key) {\n        auto it = id_map.leader(key);\n\
    \        if (it != id_map.end()) return it->second;\n        int new_id = id_map.size();\n\
    \        id_map[key] = new_id;\n        return new_id;\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <utility>\n\nstruct\
    \ UnionFind {\n    std::vector<int> parent_or_size;\n    \n    UnionFind(int n\
    \ = 0) : parent_or_size(n, -1) {}\n    \n    int add_node() {\n        int id\
    \ = parent_or_size.size();\n        parent_or_size.push_back(-1);\n        return\
    \ id;\n    }\n    \n    int leader(int x) {\n        if (parent_or_size[x] < 0)\
    \ return x;\n        return parent_or_size[x] = leader(parent_or_size[x]);\n \
    \   }\n\n    bool merge(int x, int y) {\n        int root_x = leader(x);\n   \
    \     int root_y = leader(y);\n        if (root_x == root_y) return false;\n \
    \       if (-parent_or_size[root_x] < -parent_or_size[root_y]) {\n           \
    \ std::swap(root_x, root_y);\n        }\n        parent_or_size[root_x] += parent_or_size[root_y];\n\
    \        parent_or_size[root_y] = root_x;\n        return true;\n    }\n    \n\
    \    bool same(int x, int y) {\n        return leader(x) == leader(y);\n    }\n\
    \n    int size(int x) {\n        return -parent_or_size[leader(x)];\n    }\n};\n\
    \ntemplate <class T>\nstruct WeightedUnionFind {\n    std::vector<int> parent_or_size;\n\
    \    std::vector<T> diff_weight;\n    \n    WeightedUnionFind(int n = 0) : parent_or_size(n,\
    \ -1), diff_weight(n, 0) {}\n    \n    int add_node() {\n        int id = parent_or_size.size();\n\
    \        parent_or_size.push_back(-1);\n        diff_weight.push_back(0);\n  \
    \      return id;\n    }\n    \n    int leader(int x) {\n        if (parent_or_size[x]\
    \ < 0) return x;\n        int r = leader(parent_or_size[x]);\n        diff_weight[x]\
    \ += diff_weight[parent_or_size[x]];\n        return parent_or_size[x] = r;\n\
    \    }\n\n    T weight(int x) {\n        leader(x);\n        return diff_weight[x];\n\
    \    }\n\n    bool merge(int x, int y, T w) {\n        w += weight(x);\n     \
    \   w -= weight(y);\n        int root_x = leader(x);\n        int root_y = leader(y);\n\
    \        if (root_x == root_y) return false;\n        if (-parent_or_size[root_x]\
    \ < -parent_or_size[root_y]) {\n            std::swap(root_x, root_y);\n     \
    \       w = -w;\n        }\n        parent_or_size[root_x] += parent_or_size[root_y];\n\
    \        parent_or_size[root_y] = root_x;\n        diff_weight[root_y] = w;\n\
    \        return true;\n    }\n\n    T diff(int x, int y) {\n        return weight(y)\
    \ - weight(x);\n    }\n\n    bool same(int x, int y) {\n        return leader(x)\
    \ == leader(y);\n    }\n\n    int size(int x) {\n        return -parent_or_size[leader(x)];\n\
    \    }\n};\n\n// ID\u7BA1\u7406\u7528\u306E\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\
    \u30A3\ntemplate <class T>\nstruct IDManager {\n    std::map<T, int> id_map;\n\
    \    \n    int get_id(const T& key) {\n        auto it = id_map.leader(key);\n\
    \        if (it != id_map.end()) return it->second;\n        int new_id = id_map.size();\n\
    \        id_map[key] = new_id;\n        return new_id;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/ds/unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/ds/unionfind.hpp
layout: document
redirect_from:
- /library/lib/ds/unionfind.hpp
- /library/lib/ds/unionfind.hpp.html
title: lib/ds/unionfind.hpp
---
