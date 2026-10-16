---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/graph/tree/doubling-lowest-common-ancestor.hpp
    title: "Doubling-Lowest-Common-Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/graph-template.hpp\"\n\ntemplate <typename T =\
    \ int>\nstruct Edge {\n  int from, to;\n  T cost;\n  int idx;\n\n  Edge() = default;\n\
    \n  Edge(int from, int to, T cost = 1, int idx = -1)\n      : from(from), to(to),\
    \ cost(cost), idx(idx) {}\n\n  operator int() const { return to; }\n};\n\ntemplate\
    \ <typename T = int>\nstruct Graph {\n  std::vector<std::vector<Edge<T> > > g;\n\
    \  int es;\n\n  Graph() = default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\
    \n  size_t size() const { return g.size(); }\n\n  void add_directed_edge(int from,\
    \ int to, T cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\
    \n  void add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void\
    \ read(int M, int padding = -1, bool weighted = false,\n            bool directed\
    \ = false) {\n    for (int i = 0; i < M; i++) {\n      int a, b;\n      std::cin\
    \ >> a >> b;\n      a += padding;\n      b += padding;\n      T c = T(1);\n  \
    \    if (weighted) std::cin >> c;\n      if (directed)\n        add_directed_edge(a,\
    \ b, c);\n      else\n        add_edge(a, b, c);\n    }\n  }\n\n  inline std::vector<Edge<T>\
    \ >& operator[](const int& k) { return g[k]; }\n\n  inline const std::vector<Edge<T>\
    \ >& operator[](const int& k) const { return g[k]; }\n};\n\ntemplate <typename\
    \ T = int>\nusing Edges = std::vector<Edge<T> >;\n"
  code: "#pragma once\n\ntemplate <typename T = int>\nstruct Edge {\n  int from, to;\n\
    \  T cost;\n  int idx;\n\n  Edge() = default;\n\n  Edge(int from, int to, T cost\
    \ = 1, int idx = -1)\n      : from(from), to(to), cost(cost), idx(idx) {}\n\n\
    \  operator int() const { return to; }\n};\n\ntemplate <typename T = int>\nstruct\
    \ Graph {\n  std::vector<std::vector<Edge<T> > > g;\n  int es;\n\n  Graph() =\
    \ default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t size() const\
    \ { return g.size(); }\n\n  void add_directed_edge(int from, int to, T cost =\
    \ 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\n  void add_edge(int\
    \ from, int to, T cost = 1) {\n    g[from].emplace_back(from, to, cost, es);\n\
    \    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void read(int M, int\
    \ padding = -1, bool weighted = false,\n            bool directed = false) {\n\
    \    for (int i = 0; i < M; i++) {\n      int a, b;\n      std::cin >> a >> b;\n\
    \      a += padding;\n      b += padding;\n      T c = T(1);\n      if (weighted)\
    \ std::cin >> c;\n      if (directed)\n        add_directed_edge(a, b, c);\n \
    \     else\n        add_edge(a, b, c);\n    }\n  }\n\n  inline std::vector<Edge<T>\
    \ >& operator[](const int& k) { return g[k]; }\n\n  inline const std::vector<Edge<T>\
    \ >& operator[](const int& k) const { return g[k]; }\n};\n\ntemplate <typename\
    \ T = int>\nusing Edges = std::vector<Edge<T> >;"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph-template.hpp
  requiredBy:
  - lib/graph/tree/doubling-lowest-common-ancestor.hpp
  timestamp: '2026-10-16 11:43:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/graph-template.hpp
layout: document
redirect_from:
- /library/lib/graph/graph-template.hpp
- /library/lib/graph/graph-template.hpp.html
title: lib/graph/graph-template.hpp
---
