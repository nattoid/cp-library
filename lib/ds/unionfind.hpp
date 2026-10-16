#pragma once
#include <vector>
#include <map>
#include <utility>

struct UnionFind {
    std::vector<int> parent_or_size;
    
    UnionFind(int n = 0) : parent_or_size(n, -1) {}
    
    int add_node() {
        int id = parent_or_size.size();
        parent_or_size.push_back(-1);
        return id;
    }
    
    int leader(int x) {
        if (parent_or_size[x] < 0) return x;
        return parent_or_size[x] = leader(parent_or_size[x]);
    }

    bool merge(int x, int y) {
        int root_x = leader(x);
        int root_y = leader(y);
        if (root_x == root_y) return false;
        if (-parent_or_size[root_x] < -parent_or_size[root_y]) {
            std::swap(root_x, root_y);
        }
        parent_or_size[root_x] += parent_or_size[root_y];
        parent_or_size[root_y] = root_x;
        return true;
    }
    
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    int size(int x) {
        return -parent_or_size[leader(x)];
    }
};

template <class T>
struct WeightedUnionFind {
    std::vector<int> parent_or_size;
    std::vector<T> diff_weight;
    
    WeightedUnionFind(int n = 0) : parent_or_size(n, -1), diff_weight(n, 0) {}
    
    int add_node() {
        int id = parent_or_size.size();
        parent_or_size.push_back(-1);
        diff_weight.push_back(0);
        return id;
    }
    
    int leader(int x) {
        if (parent_or_size[x] < 0) return x;
        int r = leader(parent_or_size[x]);
        diff_weight[x] += diff_weight[parent_or_size[x]];
        return parent_or_size[x] = r;
    }

    T weight(int x) {
        leader(x);
        return diff_weight[x];
    }

    bool merge(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        int root_x = leader(x);
        int root_y = leader(y);
        if (root_x == root_y) return false;
        if (-parent_or_size[root_x] < -parent_or_size[root_y]) {
            std::swap(root_x, root_y);
            w = -w;
        }
        parent_or_size[root_x] += parent_or_size[root_y];
        parent_or_size[root_y] = root_x;
        diff_weight[root_y] = w;
        return true;
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    int size(int x) {
        return -parent_or_size[leader(x)];
    }
};

// ID管理用のユーティリティ
template <class T>
struct IDManager {
    std::map<T, int> id_map;
    
    int get_id(const T& key) {
        auto it = id_map.leader(key);
        if (it != id_map.end()) return it->second;
        int new_id = id_map.size();
        id_map[key] = new_id;
        return new_id;
    }
};