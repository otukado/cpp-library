#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0019"

#include <cstdint>
#include <iostream>

#include "src/math/factorial.hpp"

int main() {
    std::int64_t n;
    std::cin >> n;

    constexpr std::int64_t mod = 9'000'000'000'000'000'000;
    const otukado::Factorial<mod> factorial(n);
    std::cout << factorial(n).value() << '\n';
}
