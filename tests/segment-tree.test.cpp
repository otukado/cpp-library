#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include "src/data-structure/segment-tree.hpp"

long long add(long long a, long long b) {
    return a + b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    otukado::SegmentTree<long long, 0LL, add> seg(n);

    for (int i = 0; i < n; ++i) {
        long long x;
        std::cin >> x;
        seg[i] = x;
    }

    while (q--) {
        int type;
        std::cin >> type;

        if (type == 0) {
            int p;
            long long x;
            std::cin >> p >> x;
            seg[p] = seg[p] + x;
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.range(l, r) << '\n';
        }
    }
}