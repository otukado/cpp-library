#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_E"

#include <cstdint>
#include <iostream>

#include "src/math/nCr.hpp"

int main() {
    std::int64_t n;
    std::int64_t k;
    std::cin >> n >> k;

    const otukado::nCr<1'000'000'007> combination(k);
    std::cout << combination(k, n).value() << '\n';
}
