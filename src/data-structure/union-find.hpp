#pragma once
#include<vector>

namespace otukado {


class UnionFind {
private:
    std::vector<int> parents;
    std::vector<int> sizes;
    int group_num;

public:
    UnionFind() = delete;
    UnionFind(int n) : group_num(n) {
        parents.resize(n);
        sizes.resize(n, 1);
        for(int i = 0; i < n; ++i) parents[i] = i;
    };

    int find (int x) {
        if(parents[x] == x) return x;
        return parents[x] = find(parents[x]); 
    }

    bool connected (int a, int b) {
        return find(a) == find(b);
    }

    int size (int a) {
        return sizes[find(a)];
    }

    int groups() {
        return group_num;
    }

    bool merge (int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) return false;

        if(size(root_a) < size(root_b)) std::swap(root_a, root_b); // a の方を大きくする

        sizes[root_a] += sizes[root_b];
        parents[root_b] = root_a;
        group_num -= 1;
        return true;
    }
};


} // namespace otukado