---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: src/math/modint.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/nCr.hpp
    title: src/math/nCr.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/factorial.test.cpp
    title: tests/factorial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/nCr.test.cpp
    title: tests/nCr.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/factorial.hpp\"\n\n#include <cassert>\n#include\
    \ <cstdint>\n#include <vector>\n\n#line 2 \"src/math/modint.hpp\"\n\n#line 5 \"\
    src/math/modint.hpp\"\n\nnamespace otukado{\n\n\ntemplate<std::int64_t MOD>\n\
    class modint {\n    static_assert(MOD != 0);\nprivate:\n    using i64 = std::int64_t;\n\
    \    using i128 = __int128_t;\n\n    i64 val;\n\npublic:\n    modint() : val(0)\
    \ {}\n\n    modint(i64 x) : val(x % MOD) {\n        if (val < 0) val += MOD;\n\
    \    }\n\n    static i64 mod() {\n        return MOD;\n    }\n\n    i64 value()\
    \ const {\n        return val;\n    }\n\n    modint& operator+=(const modint&\
    \ other) {\n        val += other.val;\n        if (val >= MOD) val -= MOD;\n \
    \       return *this;\n    }\n\n    modint& operator-=(const modint& other) {\n\
    \        val -= other.val;\n        if (val < 0) val += MOD;\n        return *this;\n\
    \    }\n\n    modint& operator*=(const modint& other) {\n        val = static_cast<i64>(\n\
    \            static_cast<i128>(val) * other.val % MOD\n        );\n        return\
    \ *this;\n    }\n\n    modint& operator/=(const modint& other) {\n        return\
    \ *this *= other.inv();\n    }\n\n    modint operator+() const {\n        return\
    \ *this;\n    }\n\n    modint operator-() const {\n        return val == 0 ? *this\
    \ : modint(MOD - val);\n    }\n\n    modint pow(std::int64_t exp) const {\n  \
    \      assert(exp >= 0);\n\n        modint res = 1;\n        modint base = *this;\n\
    \        while (exp > 0) {\n            if (exp & 1) res *= base;\n          \
    \  base *= base;\n            exp >>= 1;\n        }\n        return res;\n   \
    \ }\n\n    modint inv() const {\n        i128 a = val;\n        i128 b = MOD;\n\
    \        i128 x = 1;\n        i128 y = 0;\n\n        while (b != 0) {\n      \
    \      const i128 q = a / b;\n\n            const i128 next_a = a - q * b;\n \
    \           a = b;\n            b = next_a;\n\n            const i128 next_x =\
    \ x - q * y;\n            x = y;\n            y = next_x;\n        }\n\n     \
    \   assert(a == 1);\n        x %= MOD;\n        if (x < 0) x += MOD;\n       \
    \ return modint(static_cast<i64>(x));\n    }\n\n    friend modint operator+(modint\
    \ lhs, const modint& rhs) {\n        return lhs += rhs;\n    }\n\n    friend modint\
    \ operator-(modint lhs, const modint& rhs) {\n        return lhs -= rhs;\n   \
    \ }\n\n    friend modint operator*(modint lhs, const modint& rhs) {\n        return\
    \ lhs *= rhs;\n    }\n\n    friend modint operator/(modint lhs, const modint&\
    \ rhs) {\n        return lhs /= rhs;\n    }\n\n    friend bool operator==(const\
    \ modint& lhs, const modint& rhs) {\n        return lhs.val == rhs.val;\n    }\n\
    };\n\n\n}; //namespace otukado\n#line 8 \"src/math/factorial.hpp\"\n\nnamespace\
    \ otukado {\n\ntemplate<std::int64_t MOD>\nclass Factorial {\npublic:\n    using\
    \ mint = modint<MOD>;\n\nprivate:\n    std::int64_t max_n;\n    std::vector<mint>\
    \ fact;\n\npublic:\n    explicit Factorial(std::int64_t max_n) : max_n(max_n)\
    \ {\n        assert(max_n >= 0);\n\n        fact.resize(max_n + 1);\n        fact[0]\
    \ = 1;\n        for (std::int64_t i = 1; i <= max_n; ++i) {\n            fact[i]\
    \ = fact[i - 1] * mint(i);\n        }\n    }\n\n    mint operator()(std::int64_t\
    \ n) const {\n        assert(0 <= n && n <= max_n);\n        return fact[n];\n\
    \    }\n};\n\n} // namespace otukado\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\
    \n#include \"modint.hpp\"\n\nnamespace otukado {\n\ntemplate<std::int64_t MOD>\n\
    class Factorial {\npublic:\n    using mint = modint<MOD>;\n\nprivate:\n    std::int64_t\
    \ max_n;\n    std::vector<mint> fact;\n\npublic:\n    explicit Factorial(std::int64_t\
    \ max_n) : max_n(max_n) {\n        assert(max_n >= 0);\n\n        fact.resize(max_n\
    \ + 1);\n        fact[0] = 1;\n        for (std::int64_t i = 1; i <= max_n; ++i)\
    \ {\n            fact[i] = fact[i - 1] * mint(i);\n        }\n    }\n\n    mint\
    \ operator()(std::int64_t n) const {\n        assert(0 <= n && n <= max_n);\n\
    \        return fact[n];\n    }\n};\n\n} // namespace otukado\n"
  dependsOn:
  - src/math/modint.hpp
  isVerificationFile: false
  path: src/math/factorial.hpp
  requiredBy:
  - src/math/nCr.hpp
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/nCr.test.cpp
  - tests/factorial.test.cpp
documentation_of: src/math/factorial.hpp
layout: document
redirect_from:
- /library/src/math/factorial.hpp
- /library/src/math/factorial.hpp.html
title: src/math/factorial.hpp
---
