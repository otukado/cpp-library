#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

#include "modint.hpp"

namespace otukado {

template<std::int64_t MOD>
class Factorial {
public:
    using mint = modint<MOD>;

private:
    std::int64_t max_n;
    std::vector<mint> fact;

public:
    explicit Factorial(std::int64_t max_n) : max_n(max_n) {
        assert(max_n >= 0);

        fact.resize(max_n + 1);
        fact[0] = 1;
        for (std::int64_t i = 1; i <= max_n; ++i) {
            fact[i] = fact[i - 1] * mint(i);
        }
    }

    mint operator()(std::int64_t n) const {
        assert(0 <= n && n <= max_n);
        return fact[n];
    }
};

} // namespace otukado
