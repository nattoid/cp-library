#pragma once
#include <vector>
#include <utility>
#include <functional>

template <class Key, class Val, class Op, class Eq = std::equal_to<Key>>
std::vector<std::pair<Key, Val>> monoidal_rle(const std::vector<Key>& keys, const std::vector<Val>& vals, Op op, Eq eq = std::equal_to<Key>()) {
    std::vector<std::pair<Key, Val>> res;
    for (std::size_t i = 0; i < keys.size(); ++i) {
        if (res.empty() || !eq(res.back().first, keys[i])) {
            res.emplace_back(keys[i], vals[i]);
        } else {
            res.back().second = op(res.back().second, vals[i]);
        }
    }
    return res;
}

template <class Container>
auto rle(const Container& c) {
    using T = typename Container::value_type;
    std::vector<std::pair<T, int>> res;
    for (const auto& x : c) {
        if (res.empty() || res.back().first != x) {
            res.emplace_back(x, 1);
        } else {
            res.back().second++;
        }
    }
    return res;
}

template <class Container>
auto circular_rle(const Container& c) {
    auto res = rle(c);
    int offset = 0;
    if (res.size() > 1 && res.front().first == res.back().first) {
        offset = res.back().second;
        res.front().second += res.back().second;
        res.pop_back();
    }
    return std::make_pair(res, offset);
}