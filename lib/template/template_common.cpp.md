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
  bundledCode: "#line 1 \"lib/template/template_common.cpp\"\n// 10\u884C\u76EE\u304B\
    \u3089\u7D50\u5408\n// clang-format off\n#include <bits/stdc++.h>\n#include <atcoder/all>\n\
    using namespace std;\nusing namespace atcoder;\n\n\n\nusing ll = long long;\n\
    using uint = unsigned int;\nusing pi = pair<int, int>;\nusing pl = pair<ll, ll>;\n\
    using ti = tuple<int, int, int>;\nusing tl = tuple<ll, ll, ll>;\nusing vi = vector<int>;\n\
    using vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\ntemplate<typename T> using vc=vector<T>;\n\
    template<typename T> using vvc=vc<vc<T>>;\nusing mint = atcoder::modint998244353;\n\
    //using mint = atcoder::modint1000000007;\n//using mint = atcoder::modint;\ntemplate<typename\
    \ T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;\n\n\
    const int INF = 1 << 30;\nconst ll LINF = 1LL << 60;\nconst int dx[4] = {-1, 0,\
    \ 1, 0};\nconst int dy[4] = {0, -1, 0, 1};\nconst int dx8[8] = {-1, -1, -1, 0,\
    \ 0, 1, 1, 1};\nconst int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};\n\n#define rep(i,\
    \ l, n) for(int i = (l); i < (int)(n); ++i)\n#define REP(i, n) rep(i, 0, n)\n\
    #define repe(i, l, n) for(int i = (l); i <= (int)(n); i++)\n#define per(i, n,\
    \ l) for(int i = (n); i > (int)(l); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\
    #define sz(A) (ll)(A).size()\n#define LB(A, x) (ll)(lower_bound(all(A), x)-A.begin())\n\
    #define UB(A, x) (ll)(upper_bound(all(A), x)-A.begin())\n#define COU(A,x) (UB(A,x)-LB(A,x))\n\
    #define F first\n#define S second\n#define el \"\\n\"\n#define die(a) {cout<<a<<endl;return\
    \ 0;}\n#define dier(a) {return a;}\ntemplate<typename T1,typename T2>ostream&operator<<(ostream&os,const\
    \ pair<T1,T2>&p){os<<p.F<<\" \"<<p.S;return os;}\ntemplate<typename T1,typename\
    \ T2>istream&operator>>(istream&is,pair<T1,T2>&p){is>>p.F>>p.S;return is;}\ntemplate<typename\
    \ T1,typename T2,typename T3>ostream&operator<<(ostream&os,const tuple<T1,T2,T3>&t){os<<get<0>(t)<<\"\
    \ \"<<get<1>(t)<<\" \"<<get<2>(t);return os;}\ntemplate<typename T1,typename T2,typename\
    \ T3>istream&operator>>(istream&is,tuple<T1,T2,T3>&t){is>>get<0>(t)>>get<1>(t)>>get<2>(t);return\
    \ is;}\ntemplate<typename T>ostream&operator<<(ostream&os,const vector<T>&v){REP(i,sz(v))os<<v[i]<<(i+1!=sz(v)?\"\
    \ \":\"\");return os;}\ntemplate<typename T>istream&operator>>(istream&is,vector<T>&v){for(T&in:v)is>>in;return\
    \ is;}\nstd::istream& operator>>(std::istream& is, __int128_t& v) {\n    std::string\
    \ s;\n    is >> s;\n    v = 0;\n    bool negative = false;\n    for (size_t i\
    \ = 0; i < s.length(); ++i) {\n        if (i == 0 && s[i] == '-') {\n        \
    \    negative = true;\n            continue;\n        }\n        v = v * 10 +\
    \ (s[i] - '0');\n    }\n    if (negative) v = -v;\n    return is;\n}\nstd::ostream&\
    \ operator<<(std::ostream& os, __int128_t v) {\n    if (v == 0) return os << \"\
    0\";\n    bool negative = false;\n    if (v < 0) {\n        negative = true;\n\
    \        v = -v;\n    }\n    std::string s;\n    while (v > 0) {\n        s +=\
    \ (char)('0' + (v % 10));\n        v /= 10;\n    }\n    if (negative) s += '-';\n\
    \    std::reverse(s.begin(), s.end());\n    return os << s;\n}\n\ntemplate<class\
    \ T1, class T2> bool chmax(T1 &a, const T2 &b) { if (a<b) { a=b; return 1; } return\
    \ 0; }\ntemplate<class T1, class T2> bool chmin(T1 &a, const T2 &b) { if (a>b)\
    \ { a=b; return 1; } return 0; }\ntemplate<typename T> T safe_mod(T a, T m) {T\
    \ r = a % m; if (r < 0) r += m; return r;}\ntemplate<typename T> T mod_1_to_d(T\
    \ x, T d) { T r = x % d; if (r <= 0) r += d; return r;}\nll isqrt(ll x){\n   \
    \ ll s = (ll)sqrt(x);\n    while(s * s > x)s--;\n    while((s+1) * (s+1) <= x)s++;\n\
    \    return s;\n}\ntemplate <typename T>\nstd::vector<T> prefix_sum(const std::vector<T>&\
    \ v) {\n    int n = v.size();\n    std::vector<T> res(n + 1, T{0});\n    for (int\
    \ i = 0; i < n; i++) {\n        res[i + 1] = res[i] + v[i];\n    }\n    return\
    \ res;\n}\nvoid Yes(bool f = true, string s1 = \"Yes\", string s2 = \"No\") {\n\
    \    cout << (f ? s1 : s2) << el;\n}\n#define NO { cout << \"No\\n\"; return;\
    \ }\nvoid Alice(bool f = true){\n    cout << (f ? \"Alice\" : \"Bob\") << el;\n\
    }\nvvi read_g(int n, int m, bool directed = false, bool minus_one = true) {\n\
    \    vvi g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n       \
    \ cin >> u >> v;\n        if (minus_one) { --u; --v; }\n        g[u].pb(v);\n\
    \        if (!directed) g[v].pb(u);\n    }\n    return g;\n}\nvvi read_t(int n,\
    \ bool minus_one = true) {\n    return read_g(n, n - 1, false, minus_one);\n}\n\
    vi read_p(int n, bool minus_one = true) {\n    vi p(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> p[i];\n        if (minus_one) p[i]--;\n    }\n \
    \   return p;\n}\n\nconstexpr inline int digit(long long n, int k) { return (n\
    \ >> k) & 1; }\nconstexpr inline ll pow2(int k) { return 1LL << k; }\nconstexpr\
    \ inline int order(int n) {return 31 - __builtin_clz(n);}\n\n#ifdef LOCAL\nvoid\
    \ debug_out() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void debug_out(Head H, Tail... tail) {\ncerr << H << (sizeof...(tail) == 0 ? \"\
    \" : \", \");\ndebug_out(tail...);\n}\n#define debug(...) cerr << \"[L\" << __LINE__\
    \ << \"] \" << #__VA_ARGS__ << \" = \", debug_out(__VA_ARGS__)\n#else\n#define\
    \ debug(...)\n#endif\n\nstruct Setup_io { Setup_io() { ios_base::sync_with_stdio(0);\
    \ cin.tie(0); cout << fixed << setprecision(15); } } setup_io;\n#pragma endregion\n\
    // clang-format on\n"
  code: "// 10\u884C\u76EE\u304B\u3089\u7D50\u5408\n// clang-format off\n#include\
    \ <bits/stdc++.h>\n#include <atcoder/all>\nusing namespace std;\nusing namespace\
    \ atcoder;\n\n\n\nusing ll = long long;\nusing uint = unsigned int;\nusing pi\
    \ = pair<int, int>;\nusing pl = pair<ll, ll>;\nusing ti = tuple<int, int, int>;\n\
    using tl = tuple<ll, ll, ll>;\nusing vi = vector<int>;\nusing vvi = vector<vi>;\n\
    using vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing\
    \ vvvl = vector<vvl>;\ntemplate<typename T> using vc=vector<T>;\ntemplate<typename\
    \ T> using vvc=vc<vc<T>>;\nusing mint = atcoder::modint998244353;\n//using mint\
    \ = atcoder::modint1000000007;\n//using mint = atcoder::modint;\ntemplate<typename\
    \ T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;\n\n\
    const int INF = 1 << 30;\nconst ll LINF = 1LL << 60;\nconst int dx[4] = {-1, 0,\
    \ 1, 0};\nconst int dy[4] = {0, -1, 0, 1};\nconst int dx8[8] = {-1, -1, -1, 0,\
    \ 0, 1, 1, 1};\nconst int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};\n\n#define rep(i,\
    \ l, n) for(int i = (l); i < (int)(n); ++i)\n#define REP(i, n) rep(i, 0, n)\n\
    #define repe(i, l, n) for(int i = (l); i <= (int)(n); i++)\n#define per(i, n,\
    \ l) for(int i = (n); i > (int)(l); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\
    #define sz(A) (ll)(A).size()\n#define LB(A, x) (ll)(lower_bound(all(A), x)-A.begin())\n\
    #define UB(A, x) (ll)(upper_bound(all(A), x)-A.begin())\n#define COU(A,x) (UB(A,x)-LB(A,x))\n\
    #define F first\n#define S second\n#define el \"\\n\"\n#define die(a) {cout<<a<<endl;return\
    \ 0;}\n#define dier(a) {return a;}\ntemplate<typename T1,typename T2>ostream&operator<<(ostream&os,const\
    \ pair<T1,T2>&p){os<<p.F<<\" \"<<p.S;return os;}\ntemplate<typename T1,typename\
    \ T2>istream&operator>>(istream&is,pair<T1,T2>&p){is>>p.F>>p.S;return is;}\ntemplate<typename\
    \ T1,typename T2,typename T3>ostream&operator<<(ostream&os,const tuple<T1,T2,T3>&t){os<<get<0>(t)<<\"\
    \ \"<<get<1>(t)<<\" \"<<get<2>(t);return os;}\ntemplate<typename T1,typename T2,typename\
    \ T3>istream&operator>>(istream&is,tuple<T1,T2,T3>&t){is>>get<0>(t)>>get<1>(t)>>get<2>(t);return\
    \ is;}\ntemplate<typename T>ostream&operator<<(ostream&os,const vector<T>&v){REP(i,sz(v))os<<v[i]<<(i+1!=sz(v)?\"\
    \ \":\"\");return os;}\ntemplate<typename T>istream&operator>>(istream&is,vector<T>&v){for(T&in:v)is>>in;return\
    \ is;}\nstd::istream& operator>>(std::istream& is, __int128_t& v) {\n    std::string\
    \ s;\n    is >> s;\n    v = 0;\n    bool negative = false;\n    for (size_t i\
    \ = 0; i < s.length(); ++i) {\n        if (i == 0 && s[i] == '-') {\n        \
    \    negative = true;\n            continue;\n        }\n        v = v * 10 +\
    \ (s[i] - '0');\n    }\n    if (negative) v = -v;\n    return is;\n}\nstd::ostream&\
    \ operator<<(std::ostream& os, __int128_t v) {\n    if (v == 0) return os << \"\
    0\";\n    bool negative = false;\n    if (v < 0) {\n        negative = true;\n\
    \        v = -v;\n    }\n    std::string s;\n    while (v > 0) {\n        s +=\
    \ (char)('0' + (v % 10));\n        v /= 10;\n    }\n    if (negative) s += '-';\n\
    \    std::reverse(s.begin(), s.end());\n    return os << s;\n}\n\ntemplate<class\
    \ T1, class T2> bool chmax(T1 &a, const T2 &b) { if (a<b) { a=b; return 1; } return\
    \ 0; }\ntemplate<class T1, class T2> bool chmin(T1 &a, const T2 &b) { if (a>b)\
    \ { a=b; return 1; } return 0; }\ntemplate<typename T> T safe_mod(T a, T m) {T\
    \ r = a % m; if (r < 0) r += m; return r;}\ntemplate<typename T> T mod_1_to_d(T\
    \ x, T d) { T r = x % d; if (r <= 0) r += d; return r;}\nll isqrt(ll x){\n   \
    \ ll s = (ll)sqrt(x);\n    while(s * s > x)s--;\n    while((s+1) * (s+1) <= x)s++;\n\
    \    return s;\n}\ntemplate <typename T>\nstd::vector<T> prefix_sum(const std::vector<T>&\
    \ v) {\n    int n = v.size();\n    std::vector<T> res(n + 1, T{0});\n    for (int\
    \ i = 0; i < n; i++) {\n        res[i + 1] = res[i] + v[i];\n    }\n    return\
    \ res;\n}\nvoid Yes(bool f = true, string s1 = \"Yes\", string s2 = \"No\") {\n\
    \    cout << (f ? s1 : s2) << el;\n}\n#define NO { cout << \"No\\n\"; return;\
    \ }\nvoid Alice(bool f = true){\n    cout << (f ? \"Alice\" : \"Bob\") << el;\n\
    }\nvvi read_g(int n, int m, bool directed = false, bool minus_one = true) {\n\
    \    vvi g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n       \
    \ cin >> u >> v;\n        if (minus_one) { --u; --v; }\n        g[u].pb(v);\n\
    \        if (!directed) g[v].pb(u);\n    }\n    return g;\n}\nvvi read_t(int n,\
    \ bool minus_one = true) {\n    return read_g(n, n - 1, false, minus_one);\n}\n\
    vi read_p(int n, bool minus_one = true) {\n    vi p(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> p[i];\n        if (minus_one) p[i]--;\n    }\n \
    \   return p;\n}\n\nconstexpr inline int digit(long long n, int k) { return (n\
    \ >> k) & 1; }\nconstexpr inline ll pow2(int k) { return 1LL << k; }\nconstexpr\
    \ inline int order(int n) {return 31 - __builtin_clz(n);}\n\n#ifdef LOCAL\nvoid\
    \ debug_out() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void debug_out(Head H, Tail... tail) {\ncerr << H << (sizeof...(tail) == 0 ? \"\
    \" : \", \");\ndebug_out(tail...);\n}\n#define debug(...) cerr << \"[L\" << __LINE__\
    \ << \"] \" << #__VA_ARGS__ << \" = \", debug_out(__VA_ARGS__)\n#else\n#define\
    \ debug(...)\n#endif\n\nstruct Setup_io { Setup_io() { ios_base::sync_with_stdio(0);\
    \ cin.tie(0); cout << fixed << setprecision(15); } } setup_io;\n#pragma endregion\n\
    // clang-format on\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/template/template_common.cpp
  requiredBy: []
  timestamp: '2026-10-25 18:55:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/template/template_common.cpp
layout: document
redirect_from:
- /library/lib/template/template_common.cpp
- /library/lib/template/template_common.cpp.html
title: lib/template/template_common.cpp
---
