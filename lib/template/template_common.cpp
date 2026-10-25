// 10行目から結合
// clang-format off
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;



using ll = long long;
using uint = unsigned int;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
template<typename T> using vc=vector<T>;
template<typename T> using vvc=vc<vc<T>>;
using mint = atcoder::modint998244353;
//using mint = atcoder::modint1000000007;
//using mint = atcoder::modint;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

#define rep(i, l, n) for(int i = (l); i < (int)(n); ++i)
#define REP(i, n) rep(i, 0, n)
#define repe(i, l, n) for(int i = (l); i <= (int)(n); i++)
#define per(i, n, l) for(int i = (n); i > (int)(l); i--)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(A) (ll)(A).size()
#define LB(A, x) (ll)(lower_bound(all(A), x)-A.begin())
#define UB(A, x) (ll)(upper_bound(all(A), x)-A.begin())
#define COU(A,x) (UB(A,x)-LB(A,x))
#define F first
#define S second
#define el "\n"
#define die(a) {cout<<a<<endl;return 0;}
#define dier(a) {return a;}
template<typename T1,typename T2>ostream&operator<<(ostream&os,const pair<T1,T2>&p){os<<p.F<<" "<<p.S;return os;}
template<typename T1,typename T2>istream&operator>>(istream&is,pair<T1,T2>&p){is>>p.F>>p.S;return is;}
template<typename T1,typename T2,typename T3>ostream&operator<<(ostream&os,const tuple<T1,T2,T3>&t){os<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);return os;}
template<typename T1,typename T2,typename T3>istream&operator>>(istream&is,tuple<T1,T2,T3>&t){is>>get<0>(t)>>get<1>(t)>>get<2>(t);return is;}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){REP(i,sz(v))os<<v[i]<<(i+1!=sz(v)?" ":"");return os;}
template<typename T>istream&operator>>(istream&is,vector<T>&v){for(T&in:v)is>>in;return is;}
std::istream& operator>>(std::istream& is, __int128_t& v) {
    std::string s;
    is >> s;
    v = 0;
    bool negative = false;
    for (size_t i = 0; i < s.length(); ++i) {
        if (i == 0 && s[i] == '-') {
            negative = true;
            continue;
        }
        v = v * 10 + (s[i] - '0');
    }
    if (negative) v = -v;
    return is;
}
std::ostream& operator<<(std::ostream& os, __int128_t v) {
    if (v == 0) return os << "0";
    bool negative = false;
    if (v < 0) {
        negative = true;
        v = -v;
    }
    std::string s;
    while (v > 0) {
        s += (char)('0' + (v % 10));
        v /= 10;
    }
    if (negative) s += '-';
    std::reverse(s.begin(), s.end());
    return os << s;
}

template<class T1, class T2> bool chmax(T1 &a, const T2 &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T1, class T2> bool chmin(T1 &a, const T2 &b) { if (a>b) { a=b; return 1; } return 0; }
template<typename T> T safe_mod(T a, T m) {T r = a % m; if (r < 0) r += m; return r;}
template<typename T> T mod_1_to_d(T x, T d) { T r = x % d; if (r <= 0) r += d; return r;}
ll isqrt(ll x){
    ll s = (ll)sqrt(x);
    while(s * s > x)s--;
    while((s+1) * (s+1) <= x)s++;
    return s;
}
template <typename T>
std::vector<T> prefix_sum(const std::vector<T>& v) {
    int n = v.size();
    std::vector<T> res(n + 1, T{0});
    for (int i = 0; i < n; i++) {
        res[i + 1] = res[i] + v[i];
    }
    return res;
}
void Yes(bool f = true, string s1 = "Yes", string s2 = "No") {
    cout << (f ? s1 : s2) << el;
}
#define NO { cout << "No\n"; return; }
void Alice(bool f = true){
    cout << (f ? "Alice" : "Bob") << el;
}
vvi read_g(int n, int m, bool directed = false, bool minus_one = true) {
    vvi g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (minus_one) { --u; --v; }
        g[u].pb(v);
        if (!directed) g[v].pb(u);
    }
    return g;
}
vvi read_t(int n, bool minus_one = true) {
    return read_g(n, n - 1, false, minus_one);
}
vi read_p(int n, bool minus_one = true) {
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (minus_one) p[i]--;
    }
    return p;
}

constexpr inline int digit(long long n, int k) { return (n >> k) & 1; }
constexpr inline ll pow2(int k) { return 1LL << k; }
constexpr inline int order(int n) {return 31 - __builtin_clz(n);}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... tail) {
cerr << H << (sizeof...(tail) == 0 ? "" : ", ");
debug_out(tail...);
}
#define debug(...) cerr << "[L" << __LINE__ << "] " << #__VA_ARGS__ << " = ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(15); } } setup_io;
#pragma endregion
// clang-format on
