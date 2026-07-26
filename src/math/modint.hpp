#pragma once

#include <cassert>
#include <cstdint>

template<std::int64_t MOD>
class modint {
    static_assert(MOD != 0);
private:
    using i64 = std::int64_t;
    using i128 = __int128_t;

    i64 val;

public:
    modint() : val(0) {}

    modint(i64 x) : val(x % MOD) {
        if (val < 0) val += MOD;
    }

    static i64 mod() {
        return MOD;
    }

    i64 value() const {
        return val;
    }

    modint& operator+=(const modint& other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    modint& operator-=(const modint& other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    modint& operator*=(const modint& other) {
        val = static_cast<i64>(
            static_cast<i128>(val) * other.val % MOD
        );
        return *this;
    }

    modint& operator/=(const modint& other) {
        return *this *= other.inv();
    }

    modint operator+() const {
        return *this;
    }

    modint operator-() const {
        return val == 0 ? *this : modint(MOD - val);
    }

    modint pow(std::int64_t exp) const {
        assert(exp >= 0);

        modint res = 1;
        modint base = *this;
        while (exp > 0) {
            if (exp & 1) res *= base;
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    modint inv() const {
        i128 a = val;
        i128 b = MOD;
        i128 x = 1;
        i128 y = 0;

        while (b != 0) {
            const i128 q = a / b;

            const i128 next_a = a - q * b;
            a = b;
            b = next_a;

            const i128 next_x = x - q * y;
            x = y;
            y = next_x;
        }

        assert(a == 1);
        x %= MOD;
        if (x < 0) x += MOD;
        return modint(static_cast<i64>(x));
    }

    friend modint operator+(modint lhs, const modint& rhs) {
        return lhs += rhs;
    }

    friend modint operator-(modint lhs, const modint& rhs) {
        return lhs -= rhs;
    }

    friend modint operator*(modint lhs, const modint& rhs) {
        return lhs *= rhs;
    }

    friend modint operator/(modint lhs, const modint& rhs) {
        return lhs /= rhs;
    }

    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.val == rhs.val;
    }
};
