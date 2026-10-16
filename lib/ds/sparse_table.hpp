template <typename T, typename F>
struct SparseTable {
    int n;
    std::vector<std::vector<T>> st;
    F op;

    SparseTable() {}
    
    SparseTable(const std::vector<T>& v, F f) : n(v.size()), op(f) {
        int max_k = std::bit_width(unsigned(n)) - 1;
        st.assign(max_k + 1, std::vector<T>(n));
        for (int i = 0; i < n; ++i) {
            st[0][i] = v[i];
        }
        for (int k = 1; k <= max_k; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                st[k][i] = op(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    // 区間 [l, r) の演算結果を返す
    T query(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        int k = std::bit_width(unsigned(r - l)) - 1;
        return op(st[k][l], st[k][r - (1 << k)]);
    }
};