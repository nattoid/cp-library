---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/others/GraphTemplate.cpp\"\n\nstruct WeightedEdge{\n\
    \    ll to, cost;\n    WeightedEdge(){}\n    WeightedEdge(ll to, ll cost): to(to),\
    \ cost(cost){}\n    operator ll() const { return to; }\n};\nstruct WeightedGraph{\n\
    \    using E = WeightedEdge;\n    std::vector<std::vector<E>> g;\n    WeightedGraph(){}\n\
    \    WeightedGraph(ll n): g(n){}\n    std::vector<E>& operator[](ll at){ return\
    \ g[at]; }\n    operator std::vector<std::vector<E>>&(){ return g; }\n    auto\
    \ begin() const { return g.cbegin(); }\n    auto end() const { return g.cend();\
    \ }\n    ll size() const { return g.size(); }\n    const std::vector<E>& operator[](ll\
    \ at) const { return g[at]; }\n    operator const std::vector<std::vector<E>>&()\
    \ const { return g; }\n    void resize(ll a){ g.resize(a); }\n    void add_edge(ll\
    \ a, ll b, ll cost){\n        g[a].emplace_back(b, cost);\n        g[b].emplace_back(a,\
    \ cost);\n    }\n    void add_directed_edge(ll from, ll to, ll cost){\n      \
    \  g[from].emplace_back(to, cost);\n    }\n    template<ll start_index = 1, bool\
    \ directed = false> void input_graph(ll m){\n        while(m--){\n           \
    \ ll a, b, c;\n            scanf(\"%lld%lld%lld\", &a, &b, &c);\n            a\
    \ -= start_index;\n            b -= start_index;\n            g[a].emplace_back(b,\
    \ c);\n            if(!directed) g[b].emplace_back(a, c);\n        }\n    }\n\
    \    template<ll start_index = 1> void input_tree(ll n){ input_graph<start_index>(n\
    \ - 1); }\n};\n\nstruct UnWeightedEdge{\n    ll to;\n    static constexpr ll cost\
    \ = 1;\n    UnWeightedEdge(){}\n    UnWeightedEdge(ll to): to(to){}\n    operator\
    \ ll() const { return to; }\n};\nstruct UnWeightedGraph{\n    using E = UnWeightedEdge;\n\
    \    std::vector<std::vector<E>> g;\n    UnWeightedGraph(){}\n    UnWeightedGraph(ll\
    \ n): g(n){}\n    std::vector<E>& operator[](ll at){ return g[at]; }\n    operator\
    \ std::vector<std::vector<E>>&(){ return g; }\n    auto begin() const { return\
    \ g.cbegin(); }\n    auto end() const { return g.cend(); }\n    ll size() const\
    \ { return g.size(); }\n    const std::vector<E>& operator[](ll at) const { return\
    \ g[at]; }\n    operator const std::vector<std::vector<E>>&() const { return g;\
    \ }\n    void resize(ll a){ g.resize(a); }\n    void add_edge(ll a, ll b){\n \
    \       g[a].emplace_back(b);\n        g[b].emplace_back(a);\n    }\n    void\
    \ add_directed_edge(ll from, ll to){\n        g[from].emplace_back(to);\n    }\n\
    \    template<ll start_index = 1, bool directed = false> void input_graph(ll m){\n\
    \        while(m--){\n            ll a, b;\n            scanf(\"%lld%lld\", &a,\
    \ &b);\n            a -= start_index;\n            b -= start_index;\n       \
    \     g[a].emplace_back(b);\n            if(!directed) g[b].emplace_back(a);\n\
    \        }\n    }\n    template<ll start_index = 1> void input_tree(ll n){ input_graph<start_index>(n\
    \ - 1); }\n};\n\ntemplate<class Graph> std::vector<ll> Dijkstra(const Graph& g,\
    \ ll start){\n    std::vector<ll> cost(g.size(), LINF);\n    std::vector<bool>\
    \ used(g.size());\n    pq<pll> q;\n    cost[start] = 0;\n    q.emplace(0, start);\n\
    \    while(q.size()){\n        ll at = q.top().second;\n        q.pop();\n   \
    \     if(used[at]) continue;\n        used[at] = 1;\n        each(i, g[at]) if(chmin(cost[i],\
    \ cost[at] + i.cost)) q.emplace(cost[i], i);\n    }\n    return cost;\n}\n\nstd::vector<ll>\
    \ BFS(const UnWeightedGraph& g, ll start){\n    std::vector<ll> cost(g.size(),\
    \ LINF);\n    std::queue<ll> q;\n    cost[start] = 0;\n    q.push(start);\n  \
    \  while(q.size()){\n        ll at = q.front();\n        q.pop();\n        each(i,\
    \ g[at]) if(chmin(cost[i], cost[at] + i.cost)) q.push(i);\n    }\n    return cost;\n\
    }\n\ntemplate<class Graph> std::vector<std::vector<ll>> WarshallFloyd(const Graph&\
    \ g){\n    ll n = g.size();\n    std::vector<std::vector<ll>> cost(n, std::vector<ll>(n,\
    \ LINF));\n    std::queue<ll> q;\n    for(ll i = 0; i < n; i++) cost[i][i] = 0;\n\
    \    for(ll i = 0; i < n; i++) for(auto& j : g[i]) cost[i][j] = j.cost;\n    for(ll\
    \ k = 0; k < n; k++) for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) chmin(cost[i][j],\
    \ cost[i][k] + cost[k][j]);\n    return cost;\n}\n"
  code: "\nstruct WeightedEdge{\n    ll to, cost;\n    WeightedEdge(){}\n    WeightedEdge(ll\
    \ to, ll cost): to(to), cost(cost){}\n    operator ll() const { return to; }\n\
    };\nstruct WeightedGraph{\n    using E = WeightedEdge;\n    std::vector<std::vector<E>>\
    \ g;\n    WeightedGraph(){}\n    WeightedGraph(ll n): g(n){}\n    std::vector<E>&\
    \ operator[](ll at){ return g[at]; }\n    operator std::vector<std::vector<E>>&(){\
    \ return g; }\n    auto begin() const { return g.cbegin(); }\n    auto end() const\
    \ { return g.cend(); }\n    ll size() const { return g.size(); }\n    const std::vector<E>&\
    \ operator[](ll at) const { return g[at]; }\n    operator const std::vector<std::vector<E>>&()\
    \ const { return g; }\n    void resize(ll a){ g.resize(a); }\n    void add_edge(ll\
    \ a, ll b, ll cost){\n        g[a].emplace_back(b, cost);\n        g[b].emplace_back(a,\
    \ cost);\n    }\n    void add_directed_edge(ll from, ll to, ll cost){\n      \
    \  g[from].emplace_back(to, cost);\n    }\n    template<ll start_index = 1, bool\
    \ directed = false> void input_graph(ll m){\n        while(m--){\n           \
    \ ll a, b, c;\n            scanf(\"%lld%lld%lld\", &a, &b, &c);\n            a\
    \ -= start_index;\n            b -= start_index;\n            g[a].emplace_back(b,\
    \ c);\n            if(!directed) g[b].emplace_back(a, c);\n        }\n    }\n\
    \    template<ll start_index = 1> void input_tree(ll n){ input_graph<start_index>(n\
    \ - 1); }\n};\n\nstruct UnWeightedEdge{\n    ll to;\n    static constexpr ll cost\
    \ = 1;\n    UnWeightedEdge(){}\n    UnWeightedEdge(ll to): to(to){}\n    operator\
    \ ll() const { return to; }\n};\nstruct UnWeightedGraph{\n    using E = UnWeightedEdge;\n\
    \    std::vector<std::vector<E>> g;\n    UnWeightedGraph(){}\n    UnWeightedGraph(ll\
    \ n): g(n){}\n    std::vector<E>& operator[](ll at){ return g[at]; }\n    operator\
    \ std::vector<std::vector<E>>&(){ return g; }\n    auto begin() const { return\
    \ g.cbegin(); }\n    auto end() const { return g.cend(); }\n    ll size() const\
    \ { return g.size(); }\n    const std::vector<E>& operator[](ll at) const { return\
    \ g[at]; }\n    operator const std::vector<std::vector<E>>&() const { return g;\
    \ }\n    void resize(ll a){ g.resize(a); }\n    void add_edge(ll a, ll b){\n \
    \       g[a].emplace_back(b);\n        g[b].emplace_back(a);\n    }\n    void\
    \ add_directed_edge(ll from, ll to){\n        g[from].emplace_back(to);\n    }\n\
    \    template<ll start_index = 1, bool directed = false> void input_graph(ll m){\n\
    \        while(m--){\n            ll a, b;\n            scanf(\"%lld%lld\", &a,\
    \ &b);\n            a -= start_index;\n            b -= start_index;\n       \
    \     g[a].emplace_back(b);\n            if(!directed) g[b].emplace_back(a);\n\
    \        }\n    }\n    template<ll start_index = 1> void input_tree(ll n){ input_graph<start_index>(n\
    \ - 1); }\n};\n\ntemplate<class Graph> std::vector<ll> Dijkstra(const Graph& g,\
    \ ll start){\n    std::vector<ll> cost(g.size(), LINF);\n    std::vector<bool>\
    \ used(g.size());\n    pq<pll> q;\n    cost[start] = 0;\n    q.emplace(0, start);\n\
    \    while(q.size()){\n        ll at = q.top().second;\n        q.pop();\n   \
    \     if(used[at]) continue;\n        used[at] = 1;\n        each(i, g[at]) if(chmin(cost[i],\
    \ cost[at] + i.cost)) q.emplace(cost[i], i);\n    }\n    return cost;\n}\n\nstd::vector<ll>\
    \ BFS(const UnWeightedGraph& g, ll start){\n    std::vector<ll> cost(g.size(),\
    \ LINF);\n    std::queue<ll> q;\n    cost[start] = 0;\n    q.push(start);\n  \
    \  while(q.size()){\n        ll at = q.front();\n        q.pop();\n        each(i,\
    \ g[at]) if(chmin(cost[i], cost[at] + i.cost)) q.push(i);\n    }\n    return cost;\n\
    }\n\ntemplate<class Graph> std::vector<std::vector<ll>> WarshallFloyd(const Graph&\
    \ g){\n    ll n = g.size();\n    std::vector<std::vector<ll>> cost(n, std::vector<ll>(n,\
    \ LINF));\n    std::queue<ll> q;\n    for(ll i = 0; i < n; i++) cost[i][i] = 0;\n\
    \    for(ll i = 0; i < n; i++) for(auto& j : g[i]) cost[i][j] = j.cost;\n    for(ll\
    \ k = 0; k < n; k++) for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) chmin(cost[i][j],\
    \ cost[i][k] + cost[k][j]);\n    return cost;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/GraphTemplate.cpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/GraphTemplate.cpp
layout: document
redirect_from:
- /library/lib/others/GraphTemplate.cpp
- /library/lib/others/GraphTemplate.cpp.html
title: lib/others/GraphTemplate.cpp
---
