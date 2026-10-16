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
    - https://github.com/nattoid/cp-library
  bundledCode: "#line 1 \"lib/template/template_atcoder.cpp\"\n// Library: https://github.com/nattoid/cp-library\r\
    \n// clang-format off\r\n#include <bits/stdc++.h>\r\n#include <atcoder/all>\r\n\
    \r\n#pragma region Template\r\nusing namespace std;\r\nusing namespace atcoder;\r\
    \n\r\nusing ll = long long;\r\nusing uint = unsigned int;\r\nusing pi = pair<int,\
    \ int>;\r\nusing pl = pair<ll, ll>;\r\nusing ti = tuple<int, int, int>;\r\nusing\
    \ tl = tuple<ll, ll, ll>;\r\nusing vi = vector<int>;\r\nusing vvi = vector<vi>;\r\
    \nusing vvvi = vector<vvi>;\r\nusing vl = vector<ll>;\r\nusing vvl = vector<vl>;\r\
    \nusing vvvl = vector<vvl>;\r\ntemplate<typename T> using vc=vector<T>;\r\ntemplate<typename\
    \ T> using vvc=vc<vc<T>>;\r\nusing mint = atcoder::modint998244353;\r\n//using\
    \ mint = atcoder::modint1000000007;\r\n//using mint = atcoder::modint;\r\ntemplate<typename\
    \ T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;\r\n\r\
    \nconst int INF = 1 << 30;\r\nconst ll LINF = 1LL << 60;\r\nconst int dx[4] =\
    \ {-1, 0, 1, 0};\r\nconst int dy[4] = {0, -1, 0, 1};\r\nconst int dx8[8] = {-1,\
    \ -1, -1, 0, 0, 1, 1, 1};\r\nconst int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};\r\
    \n\r\n#define rep(i, l, n) for(int i = (l); i < (int)(n); ++i)\r\n#define REP(i,\
    \ n) rep(i, 0, n)\r\n#define repe(i, l, n) for(int i = (l); i <= (int)(n); i++)\r\
    \n#define per(i, n, l) for(int i = (n); i > (int)(l); i--)\r\n#define pb push_back\r\
    \n#define eb emplace_back\r\n#define all(v) (v).begin(), (v).end()\r\n#define\
    \ rall(v) (v).rbegin(), (v).rend()\r\n#define sz(A) (ll)(A).size()\r\n#define\
    \ LB(A, x) (ll)(lower_bound(all(A), x)-A.begin())\r\n#define UB(A, x) (ll)(upper_bound(all(A),\
    \ x)-A.begin())\r\n#define COU(A,x) (UB(A,x)-LB(A,x))\r\n#define F first\r\n#define\
    \ S second\r\n#define el \"\\n\"\r\n#define die(a) {cout<<a<<endl;return 0;}\r\
    \n#define dier(a) {return a;}\r\ntemplate<typename T1,typename T2>ostream&operator<<(ostream&os,const\
    \ pair<T1,T2>&p){os<<p.F<<\" \"<<p.S;return os;}\r\ntemplate<typename T1,typename\
    \ T2>istream&operator>>(istream&is,pair<T1,T2>&p){is>>p.F>>p.S;return is;}\r\n\
    template<typename T1,typename T2,typename T3>ostream&operator<<(ostream&os,const\
    \ tuple<T1,T2,T3>&t){os<<get<0>(t)<<\" \"<<get<1>(t)<<\" \"<<get<2>(t);return\
    \ os;}\r\ntemplate<typename T1,typename T2,typename T3>istream&operator>>(istream&is,tuple<T1,T2,T3>&t){is>>get<0>(t)>>get<1>(t)>>get<2>(t);return\
    \ is;}\r\ntemplate<typename T>ostream&operator<<(ostream&os,const vector<T>&v){REP(i,sz(v))os<<v[i]<<(i+1!=sz(v)?\"\
    \ \":\"\");return os;}\r\ntemplate<typename T>istream&operator>>(istream&is,vector<T>&v){for(T&in:v)is>>in;return\
    \ is;}\r\nstd::istream& operator>>(std::istream& is, __int128_t& v) {\r\n    std::string\
    \ s;\r\n    is >> s;\r\n    v = 0;\r\n    bool negative = false;\r\n    for (size_t\
    \ i = 0; i < s.length(); ++i) {\r\n        if (i == 0 && s[i] == '-') {\r\n  \
    \          negative = true;\r\n            continue;\r\n        }\r\n        v\
    \ = v * 10 + (s[i] - '0');\r\n    }\r\n    if (negative) v = -v;\r\n    return\
    \ is;\r\n}\r\nstd::ostream& operator<<(std::ostream& os, __int128_t v) {\r\n \
    \   if (v == 0) return os << \"0\";\r\n    bool negative = false;\r\n    if (v\
    \ < 0) {\r\n        negative = true;\r\n        v = -v;\r\n    }\r\n    std::string\
    \ s;\r\n    while (v > 0) {\r\n        s += (char)('0' + (v % 10));\r\n      \
    \  v /= 10;\r\n    }\r\n    if (negative) s += '-';\r\n    std::reverse(s.begin(),\
    \ s.end());\r\n    return os << s;\r\n}\r\n\r\ntemplate<class T1, class T2> bool\
    \ chmax(T1 &a, const T2 &b) { if (a<b) { a=b; return 1; } return 0; }\r\ntemplate<class\
    \ T1, class T2> bool chmin(T1 &a, const T2 &b) { if (a>b) { a=b; return 1; } return\
    \ 0; }\r\ntemplate<typename T> T safe_mod(T a, T m) {T r = a % m; if (r < 0) r\
    \ += m; return r;}\r\ntemplate<typename T> T mod_1_to_d(T x, T d) { T r = x %\
    \ d; if (r <= 0) r += d; return r;}\r\nll isqrt(ll x){\r\n    ll s = (ll)sqrt(x);\r\
    \n    while(s * s > x)s--;\r\n    while((s+1) * (s+1) <= x)s++;\r\n    return\
    \ s;\r\n}\r\ntemplate <typename T>\r\nstd::vector<T> prefix_sum(const std::vector<T>&\
    \ v) {\r\n    int n = v.size();\r\n    std::vector<T> res(n + 1, T{0});\r\n  \
    \  for (int i = 0; i < n; i++) {\r\n        res[i + 1] = res[i] + v[i];\r\n  \
    \  }\r\n    return res;\r\n}\r\nvoid Yes(bool f = true, string s1 = \"Yes\", string\
    \ s2 = \"No\") {\r\n    cout << (f ? s1 : s2) << el;\r\n}\r\n#define NO { cout\
    \ << \"No\\n\"; return; }\r\nvoid Alice(bool f = true){\r\n    cout << (f ? \"\
    Alice\" : \"Bob\") << el;\r\n}\r\n\r\nconstexpr inline int digit(long long n,\
    \ int k) { return (n >> k) & 1; }\r\nconstexpr inline ll pow2(int k) { return\
    \ 1LL << k; }\r\nconstexpr inline int order(int n) {return 31 - __builtin_clz(n);}\r\
    \n\r\n#ifdef LOCAL\r\nvoid debug_out() { cerr << endl; }\r\ntemplate <typename\
    \ Head, typename... Tail>\r\nvoid debug_out(Head H, Tail... tail) {\r\ncerr <<\
    \ H << (sizeof...(tail) == 0 ? \"\" : \", \");\r\ndebug_out(tail...);\r\n}\r\n\
    #define debug(...) cerr << \"[L\" << __LINE__ << \"] \" << #__VA_ARGS__ << \"\
    \ = \", debug_out(__VA_ARGS__)\r\n#else\r\n#define debug(...)\r\n#endif\r\n\r\n\
    struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0); cin.tie(0); cout\
    \ << fixed << setprecision(15); } } setup_io;\r\n#pragma endregion\r\n// clang-format\
    \ on\r\n\r\nvoid solve() {\r\n\r\n    return;\r\n}\r\n\r\nint main() {\r\n   \
    \ int t = 1;\r\n#ifdef LOCAL\r\n    cin >> t;\r\n#else\r\n    // cin >> t;\r\n\
    #endif\r\n    while (t--) {\r\n        solve();\r\n    }\r\n    return 0;\r\n\
    }\r\n"
  code: "// Library: https://github.com/nattoid/cp-library\r\n// clang-format off\r\
    \n#include <bits/stdc++.h>\r\n#include <atcoder/all>\r\n\r\n#pragma region Template\r\
    \nusing namespace std;\r\nusing namespace atcoder;\r\n\r\nusing ll = long long;\r\
    \nusing uint = unsigned int;\r\nusing pi = pair<int, int>;\r\nusing pl = pair<ll,\
    \ ll>;\r\nusing ti = tuple<int, int, int>;\r\nusing tl = tuple<ll, ll, ll>;\r\n\
    using vi = vector<int>;\r\nusing vvi = vector<vi>;\r\nusing vvvi = vector<vvi>;\r\
    \nusing vl = vector<ll>;\r\nusing vvl = vector<vl>;\r\nusing vvvl = vector<vvl>;\r\
    \ntemplate<typename T> using vc=vector<T>;\r\ntemplate<typename T> using vvc=vc<vc<T>>;\r\
    \nusing mint = atcoder::modint998244353;\r\n//using mint = atcoder::modint1000000007;\r\
    \n//using mint = atcoder::modint;\r\ntemplate<typename T> using min_priority_queue\
    \ = priority_queue<T, vector<T>, greater<T>>;\r\n\r\nconst int INF = 1 << 30;\r\
    \nconst ll LINF = 1LL << 60;\r\nconst int dx[4] = {-1, 0, 1, 0};\r\nconst int\
    \ dy[4] = {0, -1, 0, 1};\r\nconst int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};\r\n\
    const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};\r\n\r\n#define rep(i, l, n) for(int\
    \ i = (l); i < (int)(n); ++i)\r\n#define REP(i, n) rep(i, 0, n)\r\n#define repe(i,\
    \ l, n) for(int i = (l); i <= (int)(n); i++)\r\n#define per(i, n, l) for(int i\
    \ = (n); i > (int)(l); i--)\r\n#define pb push_back\r\n#define eb emplace_back\r\
    \n#define all(v) (v).begin(), (v).end()\r\n#define rall(v) (v).rbegin(), (v).rend()\r\
    \n#define sz(A) (ll)(A).size()\r\n#define LB(A, x) (ll)(lower_bound(all(A), x)-A.begin())\r\
    \n#define UB(A, x) (ll)(upper_bound(all(A), x)-A.begin())\r\n#define COU(A,x)\
    \ (UB(A,x)-LB(A,x))\r\n#define F first\r\n#define S second\r\n#define el \"\\\
    n\"\r\n#define die(a) {cout<<a<<endl;return 0;}\r\n#define dier(a) {return a;}\r\
    \ntemplate<typename T1,typename T2>ostream&operator<<(ostream&os,const pair<T1,T2>&p){os<<p.F<<\"\
    \ \"<<p.S;return os;}\r\ntemplate<typename T1,typename T2>istream&operator>>(istream&is,pair<T1,T2>&p){is>>p.F>>p.S;return\
    \ is;}\r\ntemplate<typename T1,typename T2,typename T3>ostream&operator<<(ostream&os,const\
    \ tuple<T1,T2,T3>&t){os<<get<0>(t)<<\" \"<<get<1>(t)<<\" \"<<get<2>(t);return\
    \ os;}\r\ntemplate<typename T1,typename T2,typename T3>istream&operator>>(istream&is,tuple<T1,T2,T3>&t){is>>get<0>(t)>>get<1>(t)>>get<2>(t);return\
    \ is;}\r\ntemplate<typename T>ostream&operator<<(ostream&os,const vector<T>&v){REP(i,sz(v))os<<v[i]<<(i+1!=sz(v)?\"\
    \ \":\"\");return os;}\r\ntemplate<typename T>istream&operator>>(istream&is,vector<T>&v){for(T&in:v)is>>in;return\
    \ is;}\r\nstd::istream& operator>>(std::istream& is, __int128_t& v) {\r\n    std::string\
    \ s;\r\n    is >> s;\r\n    v = 0;\r\n    bool negative = false;\r\n    for (size_t\
    \ i = 0; i < s.length(); ++i) {\r\n        if (i == 0 && s[i] == '-') {\r\n  \
    \          negative = true;\r\n            continue;\r\n        }\r\n        v\
    \ = v * 10 + (s[i] - '0');\r\n    }\r\n    if (negative) v = -v;\r\n    return\
    \ is;\r\n}\r\nstd::ostream& operator<<(std::ostream& os, __int128_t v) {\r\n \
    \   if (v == 0) return os << \"0\";\r\n    bool negative = false;\r\n    if (v\
    \ < 0) {\r\n        negative = true;\r\n        v = -v;\r\n    }\r\n    std::string\
    \ s;\r\n    while (v > 0) {\r\n        s += (char)('0' + (v % 10));\r\n      \
    \  v /= 10;\r\n    }\r\n    if (negative) s += '-';\r\n    std::reverse(s.begin(),\
    \ s.end());\r\n    return os << s;\r\n}\r\n\r\ntemplate<class T1, class T2> bool\
    \ chmax(T1 &a, const T2 &b) { if (a<b) { a=b; return 1; } return 0; }\r\ntemplate<class\
    \ T1, class T2> bool chmin(T1 &a, const T2 &b) { if (a>b) { a=b; return 1; } return\
    \ 0; }\r\ntemplate<typename T> T safe_mod(T a, T m) {T r = a % m; if (r < 0) r\
    \ += m; return r;}\r\ntemplate<typename T> T mod_1_to_d(T x, T d) { T r = x %\
    \ d; if (r <= 0) r += d; return r;}\r\nll isqrt(ll x){\r\n    ll s = (ll)sqrt(x);\r\
    \n    while(s * s > x)s--;\r\n    while((s+1) * (s+1) <= x)s++;\r\n    return\
    \ s;\r\n}\r\ntemplate <typename T>\r\nstd::vector<T> prefix_sum(const std::vector<T>&\
    \ v) {\r\n    int n = v.size();\r\n    std::vector<T> res(n + 1, T{0});\r\n  \
    \  for (int i = 0; i < n; i++) {\r\n        res[i + 1] = res[i] + v[i];\r\n  \
    \  }\r\n    return res;\r\n}\r\nvoid Yes(bool f = true, string s1 = \"Yes\", string\
    \ s2 = \"No\") {\r\n    cout << (f ? s1 : s2) << el;\r\n}\r\n#define NO { cout\
    \ << \"No\\n\"; return; }\r\nvoid Alice(bool f = true){\r\n    cout << (f ? \"\
    Alice\" : \"Bob\") << el;\r\n}\r\n\r\nconstexpr inline int digit(long long n,\
    \ int k) { return (n >> k) & 1; }\r\nconstexpr inline ll pow2(int k) { return\
    \ 1LL << k; }\r\nconstexpr inline int order(int n) {return 31 - __builtin_clz(n);}\r\
    \n\r\n#ifdef LOCAL\r\nvoid debug_out() { cerr << endl; }\r\ntemplate <typename\
    \ Head, typename... Tail>\r\nvoid debug_out(Head H, Tail... tail) {\r\ncerr <<\
    \ H << (sizeof...(tail) == 0 ? \"\" : \", \");\r\ndebug_out(tail...);\r\n}\r\n\
    #define debug(...) cerr << \"[L\" << __LINE__ << \"] \" << #__VA_ARGS__ << \"\
    \ = \", debug_out(__VA_ARGS__)\r\n#else\r\n#define debug(...)\r\n#endif\r\n\r\n\
    struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0); cin.tie(0); cout\
    \ << fixed << setprecision(15); } } setup_io;\r\n#pragma endregion\r\n// clang-format\
    \ on\r\n\r\nvoid solve() {\r\n\r\n    return;\r\n}\r\n\r\nint main() {\r\n   \
    \ int t = 1;\r\n#ifdef LOCAL\r\n    cin >> t;\r\n#else\r\n    // cin >> t;\r\n\
    #endif\r\n    while (t--) {\r\n        solve();\r\n    }\r\n    return 0;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/template/template_atcoder.cpp
  requiredBy: []
  timestamp: '2026-10-16 14:51:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/template/template_atcoder.cpp
layout: document
redirect_from:
- /library/lib/template/template_atcoder.cpp
- /library/lib/template/template_atcoder.cpp.html
title: lib/template/template_atcoder.cpp
---
