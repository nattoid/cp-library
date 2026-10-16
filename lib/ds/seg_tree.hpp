#pragma once
#include <vector>
#include <cassert>

template <typename T>
struct MultisetSegTree {
    int n;
    int sz;
    std::vector<T> cnt;
    std::vector<T> sum;
    std::vector<T> vals;

    MultisetSegTree(const std::vector<T>& _vals) : vals(_vals) {
        n = vals.size();
        sz = 1;
        while (sz < n) sz *= 2;
        cnt.assign(2 * sz, 0);
        sum.assign(2 * sz, 0);
    }

    // 圧縮後のインデックス p (0-indexed) に要素を c 個追加する
    void add(int p, T c) {
        assert(0 <= p && p < n);
        T v = vals[p];
        p += sz;
        cnt[p] += c;
        sum[p] += c * v;
        while (p > 1) {
            p >>= 1;
            cnt[p] = cnt[2 * p] + cnt[2 * p + 1];
            sum[p] = sum[2 * p] + sum[2 * p + 1];
        }
    }

    // 小さい方から k 個の要素の和を取得する
    T get_sum(T k) {
        if (k <= 0) return 0;
        if (cnt[1] <= k) return sum[1];
        return query_rec(1, k);
    }

private:
    T query_rec(int node, T k) {
        if (node >= sz) {
            // 葉に到達した場合、必要な k 個分だけの値を返す
            return k * vals[node - sz];
        }
        if (cnt[2 * node] >= k) {
            return query_rec(2 * node, k);
        } else {
            return sum[2 * node] + query_rec(2 * node + 1, k - cnt[2 * node]);
        }
    }
};