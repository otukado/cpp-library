#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"

#include <cstdint>
#include <iostream>

#include "src/math/modint.hpp"

int main() {
    std::int64_t m;
    std::int64_t n;
    std::cin >> m >> n;
    std::cout << modint<1'000'000'007>(m).pow(n).value() << '\n';
}
