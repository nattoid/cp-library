#pragma once
#include <vector>
#include <cassert>

template <typename T>
struct FenwickTree {
    int n;
    std::vector<T> data;
    
    FenwickTree(int n_) : n(n_), data(n_ + 1, 0) {}
    
    void add(int p, T x) {
        p++; // 0-indexedの入力を1-indexedに変換
        for (int i = p; i <= n; i += i & -i) {
            data[i] += x;
        }
    }
    
    T sum(int p) {
        T s = 0;
        for (int i = p; i > 0; i -= i & -i) {
            s += data[i];
        }
        return s;
    }
    
    T sum(int l, int r){
        return sum(r) - sum(l);
    }
    
    // 累積和がw以上になる最小のインデックス(0-indexed)を返す
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int x = 0;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        
        for (; k > 0; k /= 2) {
            if (x + k <= n && data[x + k] < w) {
                w -= data[x + k];
                x += k;
            }
        }
        return x; 
    }
};

template <typename T>
struct ExtendedFenwickTree {
    int n;
    int log_n;
    std::vector<T> cnt_tree;
    std::vector<T> sum_tree;
    std::vector<T> vals;

    // 座標圧縮済みの値の配列を渡して初期化
    ExtendedFenwickTree(const std::vector<T>& _vals) : vals(_vals) {
        n = vals.size();
        log_n = 0;
        while ((1 << log_n) <= n) log_n++;
        cnt_tree.assign(n + 1, 0);
        sum_tree.assign(n + 1, 0);
    }

    // 圧縮後のインデックス p (0-indexed) に要素を c 個追加
    // 削除する場合はcに負の値を渡す
    void add(int p, T c) {
        assert(0 <= p && p < n);
        T v = vals[p];
        for (int i = p + 1; i <= n; i += i & -i) {
            cnt_tree[i] += c;
            sum_tree[i] += c * v;
        }
    }
    // 小さい方から k 個目 (1-indexed) の値を取得する
    T get_kth(T k) {
        if (k <= 0) return vals[0];
        T cnt = 0;
        int i = 0;
        
        for (int b = log_n; b >= 0; --b) {
            int j = i | (1 << b);
            // 累積個数が k "未満" である限り進む
            if (j <= n && cnt + cnt_tree[j] < k) {
                cnt += cnt_tree[j];
                i = j;
            }
        }
        
        // i は k 番目の要素のインデックス (0-indexed)
        return vals[i];
    }

    // 小さい方から k 個の要素の和を取得する
    T get_sum(T k) {
        if (k <= 0) return 0;
        T cnt = 0;
        T sum = 0;
        int i = 0;
        
        // Binary Lifting で累積個数が k 以下になる最大のインデックスを探索
        for (int b = log_n; b >= 0; --b) {
            int j = i | (1 << b);
            if (j <= n && cnt + cnt_tree[j] <= k) {
                cnt += cnt_tree[j];
                sum += sum_tree[j];
                i = j;
            }
        }
        
        if (cnt < k && i < n) {
            sum += (k - cnt) * vals[i];
        }
        
        return sum;
    }

    // 圧縮前の値 x 未満の要素の個数を取得
    T count_less_than(T x) {
        int p = std::lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        T cnt = 0;
        for (int i = p; i > 0; i -= i & -i) {
            cnt += cnt_tree[i];
        }
        return cnt;
    }
};