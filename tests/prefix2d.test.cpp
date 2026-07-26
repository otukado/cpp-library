#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B"

#include <algorithm>
#include <iostream>
#include <vector>

#include "src/data-structure/prefix2d.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int coordinate_limit = 1000;
    std::vector<std::vector<int>> difference(
        coordinate_limit + 1,
        std::vector<int>(coordinate_limit + 1)
    );

    int n;
    std::cin >> n;
    while (n--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        ++difference[x1][y1];
        --difference[x2][y1];
        --difference[x1][y2];
        ++difference[x2][y2];
    }

    otukado::Prefix2D<int> prefix(difference);

    int answer = 0;
    for (int x = 0; x < coordinate_limit; ++x) {
        for (int y = 0; y < coordinate_limit; ++y) {
            answer = std::max(answer, prefix.get(0, 0, x, y));
        }
    }
    std::cout << answer << '\n';
}
