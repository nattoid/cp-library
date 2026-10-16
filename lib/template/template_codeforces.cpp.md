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
  bundledCode: "#line 1 \"lib/template/template_codeforces.cpp\"\n#include <bits/stdc++.h>\n\
    //clang-format off\n// #include <atcoder/convolution.hpp>\n// #include <atcoder/modint.hpp>\n\
    \n#pragma region Template\nusing namespace std;\n// using namespace atcoder;\n\
    \nusing ll = long long;\nusing uint = unsigned int;\nusing pi = pair<int, int>;\n\
    using ti = tuple<int, int, int>;\nusing vi = vector<int>;\nusing vvi = vector<vi>;\n\
    using vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing\
    \ vvvl = vector<vvl>;\ntemplate <typename T>\nusing vc = vector<T>;\ntemplate\
    \ <typename T>\nusing vvc = vc<vc<T>>;\n// using mint = atcoder::modint998244353;\n\
    // using mint = atcoder::modint1000000007;\n// using mint = atcoder::modint;\n\
    template <typename T>\nusing min_priority_queue = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\nconst int INF = 1 << 30;\nconst ll LINF = 1LL << 60;\nconst\
    \ int dx[4] = {-1, 0, 1, 0};\nconst int dy[4] = {0, -1, 0, 1};\nconst int dx8[8]\
    \ = {-1, -1, -1, 0, 0, 1, 1, 1};\nconst int dy8[8] = {-1, 0, 1, -1, 1, -1, 0,\
    \ 1};\n\n#define rep(i, l, n) for (int i = (l); i < (int)(n); ++i)\n#define REP(i,\
    \ n) rep(i, 0, n)\n#define pb push_back\n#define eb emplace_back\n#define all(v)\
    \ (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n#define sz(A)\
    \ (ll)(A).size()\n#define LB(A, x) (ll)(lower_bound(all(A), x) - A.begin())\n\
    #define UB(A, x) (ll)(upper_bound(all(A), x) - A.begin())\n#define COU(A, x) (UB(A,\
    \ x) - LB(A, x))\n#define F first\n#define S second\n#define el \"\\n\"\n\ntemplate\
    \ <typename T1, typename T2>\nostream& operator<<(ostream& os, const pair<T1,\
    \ T2>& p) {\n    os << p.F << \" \" << p.S;\n    return os;\n}\ntemplate <typename\
    \ T1, typename T2>\nistream& operator>>(istream& is, pair<T1, T2>& p) {\n    is\
    \ >> p.F >> p.S;\n    return is;\n}\ntemplate <typename T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    REP(i, sz(v)) os << v[i] << (i + 1 != sz(v) ?\
    \ \" \" : \"\");\n    return os;\n}\ntemplate <typename T>\nistream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& in : v) is >> in;\n    return is;\n}\nstd::istream&\
    \ operator>>(std::istream& is, __int128_t& v) {\n    std::string s;\n    is >>\
    \ s;\n    v = 0;\n    bool negative = false;\n    for (size_t i = 0; i < s.length();\
    \ ++i) {\n        if (i == 0 && s[i] == '-') {\n            negative = true;\n\
    \            continue;\n        }\n        v = v * 10 + (s[i] - '0');\n    }\n\
    \    if (negative) v = -v;\n    return is;\n}\nstd::ostream& operator<<(std::ostream&\
    \ os, __int128_t v) {\n    if (v == 0) return os << \"0\";\n    bool negative\
    \ = false;\n    if (v < 0) {\n        negative = true;\n        v = -v;\n    }\n\
    \    std::string s;\n    while (v > 0) {\n        s += (char)('0' + (v % 10));\n\
    \        v /= 10;\n    }\n    if (negative) s += '-';\n    std::reverse(s.begin(),\
    \ s.end());\n    return os << s;\n}\n\ntemplate <class T1, class T2>\nbool chmax(T1&\
    \ a, const T2& b) {\n    if (a < b) {\n        a = b;\n        return 1;\n   \
    \ }\n    return 0;\n}\ntemplate <class T1, class T2>\nbool chmin(T1& a, const\
    \ T2& b) {\n    if (a > b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\ntemplate <typename T>\nT safe_mod(T a, T m) {\n    T r = a % m;\n   \
    \ if (r < 0) r += m;\n    return r;\n}\ntemplate <typename T>\nT mod_1_to_d(T\
    \ x, T d) {\n    T r = x % d;\n    if (r <= 0) r += d;\n    return r;\n}\nll isqrt(ll\
    \ x) {\n    ll s = (ll)sqrt(x);\n    while (s * s > x) s--;\n    while ((s + 1)\
    \ * (s + 1) <= x) s++;\n    return s;\n}\nvoid Yes(bool f = true, string s1 =\
    \ \"Yes\", string s2 = \"No\") {\n    cout << (f ? s1 : s2) << el;\n}\n#define\
    \ NO              \\\n    {                   \\\n        cout << \"No\\n\"; \\\
    \n        return;         \\\n    }\n\n#ifdef LOCAL\nvoid debug_out() {\n    cerr\
    \ << endl;\n}\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... tail) {\n    cerr << H << (sizeof...(tail) == 0 ? \"\" : \", \");\n\
    \    debug_out(tail...);\n}\n#define debug(...)                              \
    \               \\\n    cerr << \"[L\" << __LINE__ << \"] \" << #__VA_ARGS__ <<\
    \ \" = \", \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\
    \nstruct Setup_io {\n    Setup_io() {\n        ios_base::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(15);\n    }\n} setup_io;\n\
    #pragma endregion\n// clang-format on\nvoid solve() {\n\n    return;\n}\n\nint\
    \ main() {\n    int t;\n    cin >> t;\n    while (t--) {\n        solve();\n \
    \   }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n//clang-format off\n// #include <atcoder/convolution.hpp>\n\
    // #include <atcoder/modint.hpp>\n\n#pragma region Template\nusing namespace std;\n\
    // using namespace atcoder;\n\nusing ll = long long;\nusing uint = unsigned int;\n\
    using pi = pair<int, int>;\nusing ti = tuple<int, int, int>;\nusing vi = vector<int>;\n\
    using vvi = vector<vi>;\nusing vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing\
    \ vvl = vector<vl>;\nusing vvvl = vector<vvl>;\ntemplate <typename T>\nusing vc\
    \ = vector<T>;\ntemplate <typename T>\nusing vvc = vc<vc<T>>;\n// using mint =\
    \ atcoder::modint998244353;\n// using mint = atcoder::modint1000000007;\n// using\
    \ mint = atcoder::modint;\ntemplate <typename T>\nusing min_priority_queue = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\nconst int INF = 1 << 30;\nconst ll LINF = 1LL <<\
    \ 60;\nconst int dx[4] = {-1, 0, 1, 0};\nconst int dy[4] = {0, -1, 0, 1};\nconst\
    \ int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};\nconst int dy8[8] = {-1, 0, 1, -1,\
    \ 1, -1, 0, 1};\n\n#define rep(i, l, n) for (int i = (l); i < (int)(n); ++i)\n\
    #define REP(i, n) rep(i, 0, n)\n#define pb push_back\n#define eb emplace_back\n\
    #define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\
    #define sz(A) (ll)(A).size()\n#define LB(A, x) (ll)(lower_bound(all(A), x) - A.begin())\n\
    #define UB(A, x) (ll)(upper_bound(all(A), x) - A.begin())\n#define COU(A, x) (UB(A,\
    \ x) - LB(A, x))\n#define F first\n#define S second\n#define el \"\\n\"\n\ntemplate\
    \ <typename T1, typename T2>\nostream& operator<<(ostream& os, const pair<T1,\
    \ T2>& p) {\n    os << p.F << \" \" << p.S;\n    return os;\n}\ntemplate <typename\
    \ T1, typename T2>\nistream& operator>>(istream& is, pair<T1, T2>& p) {\n    is\
    \ >> p.F >> p.S;\n    return is;\n}\ntemplate <typename T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    REP(i, sz(v)) os << v[i] << (i + 1 != sz(v) ?\
    \ \" \" : \"\");\n    return os;\n}\ntemplate <typename T>\nistream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& in : v) is >> in;\n    return is;\n}\nstd::istream&\
    \ operator>>(std::istream& is, __int128_t& v) {\n    std::string s;\n    is >>\
    \ s;\n    v = 0;\n    bool negative = false;\n    for (size_t i = 0; i < s.length();\
    \ ++i) {\n        if (i == 0 && s[i] == '-') {\n            negative = true;\n\
    \            continue;\n        }\n        v = v * 10 + (s[i] - '0');\n    }\n\
    \    if (negative) v = -v;\n    return is;\n}\nstd::ostream& operator<<(std::ostream&\
    \ os, __int128_t v) {\n    if (v == 0) return os << \"0\";\n    bool negative\
    \ = false;\n    if (v < 0) {\n        negative = true;\n        v = -v;\n    }\n\
    \    std::string s;\n    while (v > 0) {\n        s += (char)('0' + (v % 10));\n\
    \        v /= 10;\n    }\n    if (negative) s += '-';\n    std::reverse(s.begin(),\
    \ s.end());\n    return os << s;\n}\n\ntemplate <class T1, class T2>\nbool chmax(T1&\
    \ a, const T2& b) {\n    if (a < b) {\n        a = b;\n        return 1;\n   \
    \ }\n    return 0;\n}\ntemplate <class T1, class T2>\nbool chmin(T1& a, const\
    \ T2& b) {\n    if (a > b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\ntemplate <typename T>\nT safe_mod(T a, T m) {\n    T r = a % m;\n   \
    \ if (r < 0) r += m;\n    return r;\n}\ntemplate <typename T>\nT mod_1_to_d(T\
    \ x, T d) {\n    T r = x % d;\n    if (r <= 0) r += d;\n    return r;\n}\nll isqrt(ll\
    \ x) {\n    ll s = (ll)sqrt(x);\n    while (s * s > x) s--;\n    while ((s + 1)\
    \ * (s + 1) <= x) s++;\n    return s;\n}\nvoid Yes(bool f = true, string s1 =\
    \ \"Yes\", string s2 = \"No\") {\n    cout << (f ? s1 : s2) << el;\n}\n#define\
    \ NO              \\\n    {                   \\\n        cout << \"No\\n\"; \\\
    \n        return;         \\\n    }\n\n#ifdef LOCAL\nvoid debug_out() {\n    cerr\
    \ << endl;\n}\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... tail) {\n    cerr << H << (sizeof...(tail) == 0 ? \"\" : \", \");\n\
    \    debug_out(tail...);\n}\n#define debug(...)                              \
    \               \\\n    cerr << \"[L\" << __LINE__ << \"] \" << #__VA_ARGS__ <<\
    \ \" = \", \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\
    \nstruct Setup_io {\n    Setup_io() {\n        ios_base::sync_with_stdio(0);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(15);\n    }\n} setup_io;\n\
    #pragma endregion\n// clang-format on\nvoid solve() {\n\n    return;\n}\n\nint\
    \ main() {\n    int t;\n    cin >> t;\n    while (t--) {\n        solve();\n \
    \   }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/template/template_codeforces.cpp
  requiredBy: []
  timestamp: '2026-10-16 14:51:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/template/template_codeforces.cpp
layout: document
redirect_from:
- /library/lib/template/template_codeforces.cpp
- /library/lib/template/template_codeforces.cpp.html
title: lib/template/template_codeforces.cpp
---
