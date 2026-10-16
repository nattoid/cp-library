---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.hackerrank.com/contests/yfkpo3-1/challenges/bananas-multiplier-hard/problem
  bundledCode: "#line 1 \"lib/others/HLD_EulerTour.cpp\"\n\ntemplate<class Graph>\
    \ struct HLDecomposition{\n    ll n;\n    const Graph& g;\n    std::vector<ll>\
    \ index, invex, light_root, heavy_root, siz;\n    HLDecomposition(const Graph&\
    \ g, ll root = 0): n(g.size()), g(g), index(n), invex(n), light_root(n), heavy_root(n),\
    \ siz(n, 1){\n        dfs(-1, root);\n        n = 0;\n        dfs2(-1, root, -1,\
    \ 0);\n        std::vector<ll> siz2(n);\n        for(ll i = 0; i < n; i++) siz2[index[i]]\
    \ = siz[i];\n        std::swap(siz, siz2);\n    }\n    void dfs(ll from, ll at){\n\
    \        for(auto& i : g[at]) if(i != from){\n            dfs(at, i);\n      \
    \      siz[at] += siz[i];\n        }\n    }\n    void dfs2(ll from, ll at, ll\
    \ light, ll heavy){\n        invex[n] = at;\n        light_root[n] = light;\n\
    \        heavy_root[n] = heavy;\n        index[at] = n++;\n        ll max = -1,\
    \ maxdex = -1;\n        for(auto& i : g[at]) if(i != from && chmax(max, siz[i]))\
    \ maxdex = i;\n        if(maxdex == -1) return;\n        dfs2(at, maxdex, light,\
    \ heavy);\n        for(auto& i : g[at]) if(i != from && i != maxdex) dfs2(at,\
    \ i, index[at], n);\n    }\n    ll lca(ll a, ll b){\n        a = index[a]; b =\
    \ index[b];\n        while(true){\n            if(a > b) std::swap(a, b);\n  \
    \          if(heavy_root[a] == heavy_root[b]) return invex[a];\n            b\
    \ = light_root[b];\n        }\n    }\n    template<class T> void path_node(ll\
    \ a, ll b, const T& f){\n        a = index[a]; b = index[b];\n        while(true){\n\
    \            if(a > b) std::swap(a, b);\n            if(heavy_root[a] == heavy_root[b]){\n\
    \                f(a, b + 1);\n                return;\n            }\n      \
    \      f(heavy_root[b], b + 1);\n            b = light_root[b];\n        }\n \
    \   }\n    template<class T> void path_edge(ll a, ll b, const T& f){\n       \
    \ a = index[a]; b = index[b];\n        while(true){\n            if(a > b) std::swap(a,\
    \ b);\n            if(a == b) return;\n            if(heavy_root[a] == heavy_root[b]){\n\
    \                f(a, b);\n                return;\n            }\n          \
    \  f(heavy_root[b] - 1, b);\n            b = light_root[b];\n        }\n    }\n\
    \    template<class T> void subtree_node(ll a, const T& f){\n        a = index[a];\n\
    \        f(a, a + siz[a]);\n    }\n    template<class T> void subtree_edge(ll\
    \ a, const T& f){\n        a = index[a];\n        f(a, a + siz[a] - 1);\n    }\n\
    };\n\n\n\n// https://www.hackerrank.com/contests/yfkpo3-1/challenges/bananas-multiplier-hard/problem\n\
    \nint main(){\n    ll n;\n    std::cin >> n;\n    std::vector<std::array<ll, 3>>\
    \ edge(n - 1);\n    for(auto& i : edge) std::cin >> i[0] >> i[1] >> i[2];\n  \
    \  UnWeightedGraph g(n);\n    for(auto& i : edge) g.add_edge(--i[0], --i[1]);\n\
    \    HLDecomposition<UnWeightedGraph> hld(g);\n    SegmentTree<Modint> seg(n);\n\
    \    for(auto& i : edge) hld.path_edge(i[0], i[1], [&](ll l, ll r){ seg.set(l,\
    \ i[2]); });\n    ll q;\n    std::cin >> q;\n    for(ll i = 0; i < q; i++){\n\
    \        ll a, b, c;\n        std::cin >> a >> b >> c;\n        a--; b--;\n  \
    \      Modint ans = c;\n        hld.path_edge(a, b, [&](ll l, ll r){ ans *= seg.get(l,\
    \ r); });\n        std::cout << ans << '\\n';\n    }\n}\n"
  code: "\ntemplate<class Graph> struct HLDecomposition{\n    ll n;\n    const Graph&\
    \ g;\n    std::vector<ll> index, invex, light_root, heavy_root, siz;\n    HLDecomposition(const\
    \ Graph& g, ll root = 0): n(g.size()), g(g), index(n), invex(n), light_root(n),\
    \ heavy_root(n), siz(n, 1){\n        dfs(-1, root);\n        n = 0;\n        dfs2(-1,\
    \ root, -1, 0);\n        std::vector<ll> siz2(n);\n        for(ll i = 0; i < n;\
    \ i++) siz2[index[i]] = siz[i];\n        std::swap(siz, siz2);\n    }\n    void\
    \ dfs(ll from, ll at){\n        for(auto& i : g[at]) if(i != from){\n        \
    \    dfs(at, i);\n            siz[at] += siz[i];\n        }\n    }\n    void dfs2(ll\
    \ from, ll at, ll light, ll heavy){\n        invex[n] = at;\n        light_root[n]\
    \ = light;\n        heavy_root[n] = heavy;\n        index[at] = n++;\n       \
    \ ll max = -1, maxdex = -1;\n        for(auto& i : g[at]) if(i != from && chmax(max,\
    \ siz[i])) maxdex = i;\n        if(maxdex == -1) return;\n        dfs2(at, maxdex,\
    \ light, heavy);\n        for(auto& i : g[at]) if(i != from && i != maxdex) dfs2(at,\
    \ i, index[at], n);\n    }\n    ll lca(ll a, ll b){\n        a = index[a]; b =\
    \ index[b];\n        while(true){\n            if(a > b) std::swap(a, b);\n  \
    \          if(heavy_root[a] == heavy_root[b]) return invex[a];\n            b\
    \ = light_root[b];\n        }\n    }\n    template<class T> void path_node(ll\
    \ a, ll b, const T& f){\n        a = index[a]; b = index[b];\n        while(true){\n\
    \            if(a > b) std::swap(a, b);\n            if(heavy_root[a] == heavy_root[b]){\n\
    \                f(a, b + 1);\n                return;\n            }\n      \
    \      f(heavy_root[b], b + 1);\n            b = light_root[b];\n        }\n \
    \   }\n    template<class T> void path_edge(ll a, ll b, const T& f){\n       \
    \ a = index[a]; b = index[b];\n        while(true){\n            if(a > b) std::swap(a,\
    \ b);\n            if(a == b) return;\n            if(heavy_root[a] == heavy_root[b]){\n\
    \                f(a, b);\n                return;\n            }\n          \
    \  f(heavy_root[b] - 1, b);\n            b = light_root[b];\n        }\n    }\n\
    \    template<class T> void subtree_node(ll a, const T& f){\n        a = index[a];\n\
    \        f(a, a + siz[a]);\n    }\n    template<class T> void subtree_edge(ll\
    \ a, const T& f){\n        a = index[a];\n        f(a, a + siz[a] - 1);\n    }\n\
    };\n\n\n\n// https://www.hackerrank.com/contests/yfkpo3-1/challenges/bananas-multiplier-hard/problem\n\
    \nint main(){\n    ll n;\n    std::cin >> n;\n    std::vector<std::array<ll, 3>>\
    \ edge(n - 1);\n    for(auto& i : edge) std::cin >> i[0] >> i[1] >> i[2];\n  \
    \  UnWeightedGraph g(n);\n    for(auto& i : edge) g.add_edge(--i[0], --i[1]);\n\
    \    HLDecomposition<UnWeightedGraph> hld(g);\n    SegmentTree<Modint> seg(n);\n\
    \    for(auto& i : edge) hld.path_edge(i[0], i[1], [&](ll l, ll r){ seg.set(l,\
    \ i[2]); });\n    ll q;\n    std::cin >> q;\n    for(ll i = 0; i < q; i++){\n\
    \        ll a, b, c;\n        std::cin >> a >> b >> c;\n        a--; b--;\n  \
    \      Modint ans = c;\n        hld.path_edge(a, b, [&](ll l, ll r){ ans *= seg.get(l,\
    \ r); });\n        std::cout << ans << '\\n';\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/HLD_EulerTour.cpp
  requiredBy: []
  timestamp: '2026-10-16 16:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/HLD_EulerTour.cpp
layout: document
redirect_from:
- /library/lib/others/HLD_EulerTour.cpp
- /library/lib/others/HLD_EulerTour.cpp.html
title: lib/others/HLD_EulerTour.cpp
---
