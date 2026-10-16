---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/graph/graph-template.hpp
    title: lib/graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Doubling-Lowest-Common-Ancestor(\u6700\u5C0F\u5171\u901A\u7956\
      \u5148)"
    links: []
  bundledCode: "#line 2 \"lib/graph/tree/doubling-lowest-common-ancestor.hpp\"\n\n\
    #line 2 \"lib/graph/graph-template.hpp\"\n\ntemplate <typename T = int>\nstruct\
    \ Edge {\n  int from, to;\n  T cost;\n  int idx;\n\n  Edge() = default;\n\n  Edge(int\
    \ from, int to, T cost = 1, int idx = -1)\n      : from(from), to(to), cost(cost),\
    \ idx(idx) {}\n\n  operator int() const { return to; }\n};\n\ntemplate <typename\
    \ T = int>\nstruct Graph {\n  std::vector<std::vector<Edge<T> > > g;\n  int es;\n\
    \n  Graph() = default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t\
    \ size() const { return g.size(); }\n\n  void add_directed_edge(int from, int\
    \ to, T cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\n\
    \  void add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void\
    \ read(int M, int padding = -1, bool weighted = false,\n            bool directed\
    \ = false) {\n    for (int i = 0; i < M; i++) {\n      int a, b;\n      std::cin\
    \ >> a >> b;\n      a += padding;\n      b += padding;\n      T c = T(1);\n  \
    \    if (weighted) std::cin >> c;\n      if (directed)\n        add_directed_edge(a,\
    \ b, c);\n      else\n        add_edge(a, b, c);\n    }\n  }\n\n  inline std::vector<Edge<T>\
    \ >& operator[](const int& k) { return g[k]; }\n\n  inline const std::vector<Edge<T>\
    \ >& operator[](const int& k) const { return g[k]; }\n};\n\ntemplate <typename\
    \ T = int>\nusing Edges = std::vector<Edge<T> >;\n#line 4 \"lib/graph/tree/doubling-lowest-common-ancestor.hpp\"\
    \n\n/**\n * @brief Doubling-Lowest-Common-Ancestor(\u6700\u5C0F\u5171\u901A\u7956\
    \u5148)\n *\n */\ntemplate <typename T>\nstruct DoublingLowestCommonAncestor :\
    \ Graph<T> {\n public:\n  using Graph<T>::g;\n  std::vector<int> dep;\n  std::vector<T>\
    \ sum;\n  std::vector<std::vector<int> > table;\n  const int LOG;\n\n  explicit\
    \ DoublingLowestCommonAncestor(int n)\n      : Graph<T>(n), LOG(32 - __builtin_clz(g.size()))\
    \ {}\n\n  explicit DoublingLowestCommonAncestor(const Graph<T>& g)\n      : LOG(32\
    \ - __builtin_clz(g.size())), Graph<T>(g) {}\n\n  void build(int root = 0) {\n\
    \    dep.assign(g.size(), 0);\n    sum.assign(g.size(), 0);\n    table.assign(LOG,\
    \ std::vector<int>(g.size(), -1));\n    dfs(root, -1, 0);\n    for (int k = 0;\
    \ k + 1 < LOG; k++) {\n      for (int i = 0; i < (int)table[k].size(); i++) {\n\
    \        if (table[k][i] == -1)\n          table[k + 1][i] = -1;\n        else\n\
    \          table[k + 1][i] = table[k][table[k][i]];\n      }\n    }\n  }\n\n \
    \ int lca(int u, int v) {\n    if (dep[u] > dep[v]) std::swap(u, v);\n    v =\
    \ climb(v, dep[v] - dep[u]);\n    if (u == v) return u;\n    for (int i = LOG\
    \ - 1; i >= 0; i--) {\n      if (table[i][u] != table[i][v]) {\n        u = table[i][u];\n\
    \        v = table[i][v];\n      }\n    }\n    return table[0][u];\n  }\n\n  int\
    \ climb(int u, int k) {\n    if (dep[u] < k) return -1;\n    for (int i = LOG\
    \ - 1; i >= 0; i--) {\n      if ((k >> i) & 1) u = table[i][u];\n    }\n    return\
    \ u;\n  }\n\n  T dist(int u, int v) { return sum[u] + sum[v] - 2 * sum[lca(u,\
    \ v)]; }\n\n private:\n  void dfs(int idx, int par, int d) {\n    table[0][idx]\
    \ = par;\n    dep[idx] = d;\n    for (auto& to : g[idx]) {\n      if (to != par)\
    \ {\n        sum[to] = sum[idx] + to.cost;\n        dfs(to, idx, d + 1);\n   \
    \   }\n    }\n  }\n};\n"
  code: "#pragma once\n\n#include \"../graph-template.hpp\"\n\n/**\n * @brief Doubling-Lowest-Common-Ancestor(\u6700\
    \u5C0F\u5171\u901A\u7956\u5148)\n *\n */\ntemplate <typename T>\nstruct DoublingLowestCommonAncestor\
    \ : Graph<T> {\n public:\n  using Graph<T>::g;\n  std::vector<int> dep;\n  std::vector<T>\
    \ sum;\n  std::vector<std::vector<int> > table;\n  const int LOG;\n\n  explicit\
    \ DoublingLowestCommonAncestor(int n)\n      : Graph<T>(n), LOG(32 - __builtin_clz(g.size()))\
    \ {}\n\n  explicit DoublingLowestCommonAncestor(const Graph<T>& g)\n      : LOG(32\
    \ - __builtin_clz(g.size())), Graph<T>(g) {}\n\n  void build(int root = 0) {\n\
    \    dep.assign(g.size(), 0);\n    sum.assign(g.size(), 0);\n    table.assign(LOG,\
    \ std::vector<int>(g.size(), -1));\n    dfs(root, -1, 0);\n    for (int k = 0;\
    \ k + 1 < LOG; k++) {\n      for (int i = 0; i < (int)table[k].size(); i++) {\n\
    \        if (table[k][i] == -1)\n          table[k + 1][i] = -1;\n        else\n\
    \          table[k + 1][i] = table[k][table[k][i]];\n      }\n    }\n  }\n\n \
    \ int lca(int u, int v) {\n    if (dep[u] > dep[v]) std::swap(u, v);\n    v =\
    \ climb(v, dep[v] - dep[u]);\n    if (u == v) return u;\n    for (int i = LOG\
    \ - 1; i >= 0; i--) {\n      if (table[i][u] != table[i][v]) {\n        u = table[i][u];\n\
    \        v = table[i][v];\n      }\n    }\n    return table[0][u];\n  }\n\n  int\
    \ climb(int u, int k) {\n    if (dep[u] < k) return -1;\n    for (int i = LOG\
    \ - 1; i >= 0; i--) {\n      if ((k >> i) & 1) u = table[i][u];\n    }\n    return\
    \ u;\n  }\n\n  T dist(int u, int v) { return sum[u] + sum[v] - 2 * sum[lca(u,\
    \ v)]; }\n\n private:\n  void dfs(int idx, int par, int d) {\n    table[0][idx]\
    \ = par;\n    dep[idx] = d;\n    for (auto& to : g[idx]) {\n      if (to != par)\
    \ {\n        sum[to] = sum[idx] + to.cost;\n        dfs(to, idx, d + 1);\n   \
    \   }\n    }\n  }\n};\n"
  dependsOn:
  - lib/graph/graph-template.hpp
  isVerificationFile: false
  path: lib/graph/tree/doubling-lowest-common-ancestor.hpp
  requiredBy: []
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/tree/doubling-lowest-common-ancestor.hpp
layout: document
redirect_from:
- /library/lib/graph/tree/doubling-lowest-common-ancestor.hpp
- /library/lib/graph/tree/doubling-lowest-common-ancestor.hpp.html
title: "Doubling-Lowest-Common-Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---
