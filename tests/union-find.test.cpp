#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "src/data-structure/union-find.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    otukado::UnionFind uf(n);

    for(int i=0; i<q; ++i) {
        int t, u, v;
        std::cin >> t >> u >> v;

        if (t == 0) {
            uf.merge(u, v);
        } else {
            std::cout << uf.connected(u, v) << '\n';
        }
    }
}