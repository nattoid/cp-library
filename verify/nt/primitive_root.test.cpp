#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../lib/nt/primitive_root.hpp"

#include <iostream>

using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    while (q--) {
        ll p;
        cin >> p;
        cout << nt::primitive_root_prime(p) << "\n";
    }
}