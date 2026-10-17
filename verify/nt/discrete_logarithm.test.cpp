#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm"
#include <iostream>

#include "../../lib/nt/discrete_log.hpp"

using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    while (q--) {
        int x, y, m;
        cin >> x >> y >> m;
        cout << nt::discrete_log(x, y, m) << "\n";
    }
}