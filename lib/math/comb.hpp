#pragma once
#include <vector>
#include <algorithm>

template <class T> struct Comb {
    std::vector<T> fac, invfac, invs;

    Comb() : fac(1, 1), invfac(1, 1), invs(1, 1) {}

    void extend(int n) {
        int sz = fac.size();
        if (n < sz) return;
        long long p = T::mod();
        int new_sz = std::min((long long)std::max(n + 1, sz * 2), p);
        
        fac.resize(new_sz);
        invfac.resize(new_sz);
        invs.resize(new_sz);
        
        for (int i = sz; i < new_sz; i++) {
            fac[i] = fac[i - 1] * i;
        }
        invfac[new_sz - 1] = fac.back().inv();
        invs[new_sz - 1] = invfac[new_sz - 1] * fac[new_sz - 2];
        
        for (int i = new_sz - 1; i > sz; i--) {
            invfac[i - 1] = invfac[i] * i;
            invs[i - 1] = invfac[i - 1] * fac[i - 2];
        }
    }

    T C(int n, int r) {
        if (r < 0 || n < r) return 0;
        extend(n);
        return fac[n] * invfac[r] * invfac[n - r];
    }
    
    //単一O(r)
    T C_large(long long n, int r) {
        if (r < 0 || n < r) return 0;
        extend(r);
        T res = 1;
        for (int i = 0; i < r; i++) res = res * T(n - i);
        return res * invfac[r];
    }

    T Lucas(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        if (r == 0) return 1;
        long long p = T::mod();
        T res = 1;
        while (n > 0 || r > 0) {
            long long ni = n % p;
            long long ri = r % p;
            if (ni < ri) return 0;
            res = res * C(ni, ri);
            n /= p;
            r /= p;
        }
        return res;
    }

    T P(int n, int r) {
        if (r < 0 || n < r) return 0;
        extend(n);
        return fac[n] * invfac[n - r];
    }

    T fact(int n){
        if(n < 0) return 0;
        extend(n);
        return fac[n];
    }

    T finv(int n){
        if(n < 0) return 0;
        extend(n);
        return invfac[n];
    }

    T inv(int n) {
        if (n < 0) return -inv(-n);
        extend(n);
        return invs[n];
    }

    T S2_single(int n, int k){
        if (k < 0 || n < k) return 0;
        T res = 0;
        for (int i = 0; i <= k; i++) {
            T x = i;
            res = C(k, i) * x.pow(n) - res;
        }
        return res * finv(k);
    }
    
    // 重複組合せ: [x^r] 1 / (1-x)^n
    T H(int n, int r) {
        if (n < 0 || r < 0) return 0;
        return r == 0 ? 1 : C(n + r - 1, r);
    }

    // 多項係数
    template <typename I>
    T multinomial(const std::vector<I>& r) {
        static_assert(std::is_integral<I>::value == true);
        int n = 0;
        for (auto& x : r) {
            if (x < 0) return 0;
            n += x;
        }
        T res = fact(n);
        for (auto& x : r) res *= finv(x);
        return res;
    }
};