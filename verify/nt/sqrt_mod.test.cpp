#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include <iostream>

#include "../../lib/nt/mod_sqrt.hpp"

using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    while (q--) {
        int p, y;
        cin >> y >> p;
        cout << nt::mod_sqrt(y, p) << "\n";
    }
}