#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include <iostream>
#include "../../lib/nt/factorize.hpp" 

using namespace std;
using ll = long long;
int main(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll a;
        cin >> a;
        auto f = nt::factorize(a);
        int sum{};
        for(auto [p, e] : f){
            sum += e;
        }
        cout << sum << " ";
        for(auto [p, e] : f){
            for(int j = 0; j < e; j++){
                cout << p << " ";
            }
        }
        cout << "\n";
    }
}