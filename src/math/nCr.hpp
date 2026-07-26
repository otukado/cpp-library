#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

#include "factorial.hpp"

namespace otukado {

template<std::int64_t MOD>
class nCr {
public:
    using mint = typename Factorial<MOD>::mint;

private:
    std::int64_t max_n;
    Factorial<MOD> fact;
    std::vector<mint> inv_fact;

public:
    explicit nCr(std::int64_t max_n) : max_n(max_n), fact(max_n) {
        assert(max_n >= 0);

        inv_fact.resize(max_n + 1);

        inv_fact[max_n] = fact(max_n).inv();
        for (std::int64_t i = max_n; i > 0; --i) {
            inv_fact[i - 1] = inv_fact[i] * mint(i);
        }
    }

    mint operator()(std::int64_t n, std::int64_t r) const {
        if (n < 0 || r < 0 || r > n) return 0;
        assert(n <= max_n);

        return fact(n) * inv_fact[r] * inv_fact[n - r];
    }
};

} // namespace otukado
