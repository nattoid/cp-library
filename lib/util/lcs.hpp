#pragma once
#include <vector>
#include <algorithm>
#include <cstdint>

template <typename T>
int fast_lcs(const std::vector<T>& a, const std::vector<T>& b) {
    int n = a.size();
    int m = b.size();
    if (n == 0 || m == 0) return 0;

    std::vector<T> vals = b;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

    int k = vals.size();
    int blocks = (m + 63) / 64;
    std::vector<std::vector<uint64_t>> pos(k, std::vector<uint64_t>(blocks, 0));

    for (int i = 0; i < m; ++i) {
        int idx = std::lower_bound(vals.begin(), vals.end(), b[i]) - vals.begin();
        pos[idx][i / 64] |= (1ULL << (i % 64));
    }

    std::vector<uint64_t> dp(blocks, 0);

    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(vals.begin(), vals.end(), a[i]);
        if (it == vals.end() || *it != a[i]) continue;
        
        int idx = it - vals.begin();
        const auto& p = pos[idx];

        uint64_t carry = 1;
        uint64_t borrow = 0;

        for (int j = 0; j < blocks; ++j) {
            uint64_t u = dp[j] | p[j];
            uint64_t v = (dp[j] << 1) | carry;
            carry = dp[j] >> 63;

            uint64_t diff = u - v - borrow;
            if (u < v || (u == v && borrow == 1)) {
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            dp[j] = u & (u ^ diff);
        }
    }

    int lcs_len = 0;
    for (int i = 0; i < blocks; ++i) {
        lcs_len += __builtin_popcountll(dp[i]);
    }
    return lcs_len;
}