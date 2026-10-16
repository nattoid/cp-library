#pragma once
#include <vector>
#include <stack>
#include <functional>

template <typename T, typename Compare = std::less<T>>
struct CartesianTree {
    int root;
        std::vector<int> lc, rc;

        CartesianTree(const std::vector<T>& a, Compare comp = Compare()) {
        int n = a.size();
        lc.assign(n, -1);
        rc.assign(n, -1);
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            // a[i] が a[st.top()] よりも「親になるべき条件」を満たすなら pop して左の子にする
            while (!st.empty() && comp(a[i], a[st.top()])) {
                lc[i] = st.top();
                st.pop();
            }
            if (!st.empty()) {
                rc[st.top()] = i;
            }
            st.push(i);
        }
        while (!st.empty()) {
            root = st.top();
            st.pop();
        }
    }
};