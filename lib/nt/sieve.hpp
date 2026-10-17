#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace nt {

// 線形篩による高速素因数分解・約数列挙: 前処理 O(N)
struct LinearSieve {
    int max_n;
    std::vector<int> spf;
    std::vector<int> primes;

    LinearSieve(int n) : max_n(n), spf(n + 1, 0) {
        for (int i = 2; i <= n; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p > spf[i] || i * p > n) break;
                spf[i * p] = p;
            }
        }
    }

    // O(1) 素数判定
    bool is_prime(int m) const {
        assert(0 <= m && m <= max_n);
        if (m <= 1) return false;
        return spf[m] == m;
    }

    // O(log m) 素因数分解
    std::vector<std::pair<int, int>> factorize(int m) const {
        assert(0 <= m && m <= max_n);
        std::vector<std::pair<int, int>> res;
        while (m > 1) {
            int p = spf[m];
            int cnt = 0;
            while (m % p == 0) {
                cnt++;
                m /= p;
            }
            res.emplace_back(p, cnt);
        }
        return res;
    }

    // O(log m + D log D) 約数列挙
    std::vector<int> divisors(int m) const {
        assert(0 <= m && m <= max_n);
        if (m == 0) return {};
        std::vector<int> res = {1};
        while (m > 1) {
            int p = spf[m];
            int cnt = 0;
            while (m % p == 0) {
                cnt++;
                m /= p;
            }
            size_t sz = res.size();
            int p_pow = 1;
            for (int i = 0; i < cnt; i++) {
                p_pow *= p;
                for (size_t j = 0; j < sz; j++) {
                    res.push_back(res[j] * p_pow);
                }
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};

// 0 から max_n までのオイラーの φ 関数テーブル: O(N log log N)
inline std::vector<int> phi_table(int max_n) {
    assert(max_n >= 0);
    std::vector<int> res(max_n + 1);
    for (int i = 0; i <= max_n; i++) res[i] = i;
    for (int i = 2; i <= max_n; i++) {
        if (res[i] == i) {
            for (int j = i; j <= max_n; j += i) {
                res[j] -= res[j] / i;
            }
        }
    }
    return res;
}

// 0 から max_n までのメビウス関数 μ(n) テーブル: O(N)
inline std::vector<int> mobius_table(int max_n) {
    assert(max_n >= 0);
    std::vector<int> mu(max_n + 1, 0);
    std::vector<int> primes;
    std::vector<bool> is_comp(max_n + 1, false);
    if (max_n >= 1) mu[1] = 1;
    for (int i = 2; i <= max_n; i++) {
        if (!is_comp[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > max_n) break;
            is_comp[i * p] = true;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }
    return mu;
}

}  // namespace nt