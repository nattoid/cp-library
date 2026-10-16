#pragma once
#include <vector>
#include <algorithm>

template <class T> struct Comb_dp {
    std::vector<T> s2;
    int max_n_s2 = -1;

    void extend_S2(int n) {
        if (n <= max_n_s2) return;
        int new_n = std::max(n, max_n_s2 == -1 ? 1 : max_n_s2 * 2);
        s2.resize((new_n + 1) * (new_n + 2) / 2);

        if (max_n_s2 == -1) {
            s2[0] = 1;
            max_n_s2 = 0;
        }
        for (int i = max_n_s2 + 1; i <= new_n; i++) {
            int row_start = i * (i + 1) / 2;
            int prev_row_start = (i - 1) * i / 2;
            
            s2[row_start] = 0; // k = 0
            for (int j = 1; j < i; j++) {
                s2[row_start + j] = s2[prev_row_start + j - 1] + s2[prev_row_start + j] * j;
            }
            s2[row_start + i] = 1; // k = i
        }
        max_n_s2 = new_n;
    }

    T S2(int n, int k) {
        if (k < 0 || n < k) return 0;
        extend_S2(n);
        return s2[n * (n + 1) / 2 + k];
    }

    std::vector<T> s1;
    int max_n_s1 = -1;

    void extend_S1(int n) {
        if (n <= max_n_s1) return;
        int new_n = std::max(n, max_n_s1 == -1 ? 1 : max_n_s1 * 2);
        s1.resize((new_n + 1) * (new_n + 2) / 2);

        if (max_n_s1 == -1) {
            s1[0] = 1;
            max_n_s1 = 0;
        }
        for (int i = max_n_s1 + 1; i <= new_n; i++) {
            int row_start = i * (i + 1) / 2;
            int prev_row_start = (i - 1) * i / 2;
            
            s1[row_start] = 0; // k = 0
            for (int j = 1; j < i; j++) {
                s1[row_start + j] = s1[prev_row_start + j - 1] + s1[prev_row_start + j] * (i - 1);
            }
            s1[row_start + i] = 1; // k = i
        }
        max_n_s1 = new_n;
    }

    T S1(int n, int k) {
        if (k < 0 || n < k) return 0;
        extend_S1(n);
        return s1[n * (n + 1) / 2 + k];
    }
    
    std::vector<T> b;
    int max_n_b = -1;

    void extend_B(int n){
        if (n <= max_n_b) return;
        int new_n = std::max(n, max_n_b == -1 ? 1 : max_n_b * 2);
        b.resize((new_n + 1) * (new_n + 2) / 2);

        if (max_n_b == -1) {
            b[0] = 1;
            max_n_b = 0;
        }
        for (int i = max_n_b + 1; i <= new_n; i++) {
            int row_start = i * (i + 1) / 2;
            
            b[row_start] = 0; // k = 0
            for (int j = 1; j <= i; j++) {
                b[row_start + j] = b[row_start + j - 1] + S2(i, j);
            }
        }
        max_n_b = new_n;
    }

    T B(int n, int k){
        if(k < 0) return 0;
        extend_B(n);
        return b[n * (n + 1) / 2 + std::min(k, n)];
    }

    T B(int n){
        return B(n, n);
    }

    std::vector<T> part_table;
    int max_n_part = -1;

    void extend_partition(int n){
        if (n <= max_n_part) return;
        int new_n = std::max(n, max_n_part == -1 ? 1 : max_n_part * 2);
        part_table.resize((new_n + 1) * (new_n + 2) / 2);

        if (max_n_part == -1) {
            part_table[0] = 1; // n = 0, k = 0
            max_n_part = 0;
        }
        for (int i = max_n_part + 1; i <= new_n; i++) {
            int row_start = i * (i + 1) / 2;
            
            part_table[row_start] = 0; // k = 0
            for (int j = 1; j <= i; j++) {
                int prev_idx = (i - j) * (i - j + 1) / 2 + std::min(j, i - j);
                part_table[row_start + j] = part_table[row_start + j - 1] + part_table[prev_idx];
            }
        }
        max_n_part = new_n;
    }

    T part(int n, int k){
        if(k < 0 || n < 0) return 0;
        extend_partition(n);
        return part_table[n * (n + 1) / 2 + std::min(k, n)];
    }

    template <class F>
    void enumerate_partition(int n, int max_v, std::vector<int>& current, F f) {
        if (n == 0) {
            f(current);
            return;
        }
        for (int i = std::min(n, max_v); i >= 1; i--) {
            current.push_back(i);
            enumerate_partition(n - i, i, current, f);
            current.pop_back(); 
        }
    }

    template <class F>
    void each_partition(int n, F f) {
        if (n < 0) return;
        std::vector<int> current;
        enumerate_partition(n, n, current, f);
    }
};

template <class T>
std::vector<T> partition_array(int n) {
    std::vector<T> p(n + 1, 0);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; ; k++) {
            int g1 = k * (3 * k - 1) / 2;
            int g2 = k * (3 * k + 1) / 2;
            
            if (g1 > i) break;
            
            if (k % 2 != 0) {
                p[i] += p[i - g1];
                if (g2 <= i) p[i] += p[i - g2];
            } else {
                p[i] -= p[i - g1];
                if (g2 <= i) p[i] -= p[i - g2];
            }
        }
    }
    return p;
}