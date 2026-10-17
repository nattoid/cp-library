#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include <iostream>

#include "../../lib/nt/factorize.hpp"

using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        cout << nt::is_prime(n) << "\n";
    }
}