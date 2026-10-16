#pragma once
#include <vector>
#include <algorithm>

template <class T>
struct Compressor {
    std::vector<T> xs;

    Compressor() = default;

    Compressor(const std::vector<T>& v) {
        xs = v;
        build();
    }

    void add(T x) {
        xs.push_back(x);
    }

    void build() {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    }

    int operator()(T x) const {
        return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }

    T operator[](int id) const {
        return xs[id];
    }

    // 圧縮後の要素数(種類数)を取得
    int size() const {
        return xs.size();
    }
};