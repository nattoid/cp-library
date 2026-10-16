#pragma once
#include <vector>
#include <algorithm>

template <class T>
struct LIS {
    std::vector<T> v;
    std::vector<int> p;
    int n, max_len, last_idx;

    LIS(const std::vector<T>& _v) : v(_v), p(_v.size(), -1), n(_v.size()), max_len(0), last_idx(-1) {}

    // strict = true : 狭義単調増加 (デフォルト)
    // strict = false: 広義単調増加
    int lis(bool strict = true) {
        if (n == 0) return 0;
        
        std::vector<T> dp_val;
        std::vector<int> dp_idx;
        
        for (int i = 0; i < n; i++) {
            T x = v[i];
            auto it = strict 
                ? std::lower_bound(dp_val.begin(), dp_val.end(), x)
                : std::upper_bound(dp_val.begin(), dp_val.end(), x);
            
            int pos = it - dp_val.begin();
            
            if (pos > 0) {
                p[i] = dp_idx[pos - 1];
            }
            
            if (it == dp_val.end()) {
                dp_val.push_back(x);
                dp_idx.push_back(i);
            } else {
                dp_val[pos] = x;
                dp_idx[pos] = i;
            }
        }
        
        max_len = dp_val.size();
        last_idx = dp_idx.back();
        return max_len;
    }

    std::vector<int> restore(bool strict = true) {
        lis(strict);
        std::vector<int> res(max_len);
        int curr = last_idx;
        for (int i = max_len - 1; i >= 0; i--) {
            res[i] = curr;
            curr = p[curr];
        }
        return res;
    }
};