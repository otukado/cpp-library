---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/modint.test.cpp
    title: tests/modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modint.hpp\"\n\n#include <cassert>\n#include <cstdint>\n\
    \ntemplate<std::int64_t MOD>\nclass modint {\n    static_assert(MOD != 0);\nprivate:\n\
    \    using i64 = std::int64_t;\n    using i128 = __int128_t;\n\n    i64 val;\n\
    \npublic:\n    modint() : val(0) {}\n\n    modint(i64 x) : val(x % MOD) {\n  \
    \      if (val < 0) val += MOD;\n    }\n\n    static i64 mod() {\n        return\
    \ MOD;\n    }\n\n    i64 value() const {\n        return val;\n    }\n\n    modint&\
    \ operator+=(const modint& other) {\n        val += other.val;\n        if (val\
    \ >= MOD) val -= MOD;\n        return *this;\n    }\n\n    modint& operator-=(const\
    \ modint& other) {\n        val -= other.val;\n        if (val < 0) val += MOD;\n\
    \        return *this;\n    }\n\n    modint& operator*=(const modint& other) {\n\
    \        val = static_cast<i64>(\n            static_cast<i128>(val) * other.val\
    \ % MOD\n        );\n        return *this;\n    }\n\n    modint& operator/=(const\
    \ modint& other) {\n        return *this *= other.inv();\n    }\n\n    modint\
    \ operator+() const {\n        return *this;\n    }\n\n    modint operator-()\
    \ const {\n        return val == 0 ? *this : modint(MOD - val);\n    }\n\n   \
    \ modint pow(std::int64_t exp) const {\n        assert(exp >= 0);\n\n        modint\
    \ res = 1;\n        modint base = *this;\n        while (exp > 0) {\n        \
    \    if (exp & 1) res *= base;\n            base *= base;\n            exp >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    modint inv() const {\n    \
    \    i128 a = val;\n        i128 b = MOD;\n        i128 x = 1;\n        i128 y\
    \ = 0;\n\n        while (b != 0) {\n            const i128 q = a / b;\n\n    \
    \        const i128 next_a = a - q * b;\n            a = b;\n            b = next_a;\n\
    \n            const i128 next_x = x - q * y;\n            x = y;\n           \
    \ y = next_x;\n        }\n\n        assert(a == 1);\n        x %= MOD;\n     \
    \   if (x < 0) x += MOD;\n        return modint(static_cast<i64>(x));\n    }\n\
    \n    friend modint operator+(modint lhs, const modint& rhs) {\n        return\
    \ lhs += rhs;\n    }\n\n    friend modint operator-(modint lhs, const modint&\
    \ rhs) {\n        return lhs -= rhs;\n    }\n\n    friend modint operator*(modint\
    \ lhs, const modint& rhs) {\n        return lhs *= rhs;\n    }\n\n    friend modint\
    \ operator/(modint lhs, const modint& rhs) {\n        return lhs /= rhs;\n   \
    \ }\n\n    friend bool operator==(const modint& lhs, const modint& rhs) {\n  \
    \      return lhs.val == rhs.val;\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n\ntemplate<std::int64_t\
    \ MOD>\nclass modint {\n    static_assert(MOD != 0);\nprivate:\n    using i64\
    \ = std::int64_t;\n    using i128 = __int128_t;\n\n    i64 val;\n\npublic:\n \
    \   modint() : val(0) {}\n\n    modint(i64 x) : val(x % MOD) {\n        if (val\
    \ < 0) val += MOD;\n    }\n\n    static i64 mod() {\n        return MOD;\n   \
    \ }\n\n    i64 value() const {\n        return val;\n    }\n\n    modint& operator+=(const\
    \ modint& other) {\n        val += other.val;\n        if (val >= MOD) val -=\
    \ MOD;\n        return *this;\n    }\n\n    modint& operator-=(const modint& other)\
    \ {\n        val -= other.val;\n        if (val < 0) val += MOD;\n        return\
    \ *this;\n    }\n\n    modint& operator*=(const modint& other) {\n        val\
    \ = static_cast<i64>(\n            static_cast<i128>(val) * other.val % MOD\n\
    \        );\n        return *this;\n    }\n\n    modint& operator/=(const modint&\
    \ other) {\n        return *this *= other.inv();\n    }\n\n    modint operator+()\
    \ const {\n        return *this;\n    }\n\n    modint operator-() const {\n  \
    \      return val == 0 ? *this : modint(MOD - val);\n    }\n\n    modint pow(std::int64_t\
    \ exp) const {\n        assert(exp >= 0);\n\n        modint res = 1;\n       \
    \ modint base = *this;\n        while (exp > 0) {\n            if (exp & 1) res\
    \ *= base;\n            base *= base;\n            exp >>= 1;\n        }\n   \
    \     return res;\n    }\n\n    modint inv() const {\n        i128 a = val;\n\
    \        i128 b = MOD;\n        i128 x = 1;\n        i128 y = 0;\n\n        while\
    \ (b != 0) {\n            const i128 q = a / b;\n\n            const i128 next_a\
    \ = a - q * b;\n            a = b;\n            b = next_a;\n\n            const\
    \ i128 next_x = x - q * y;\n            x = y;\n            y = next_x;\n    \
    \    }\n\n        assert(a == 1);\n        x %= MOD;\n        if (x < 0) x +=\
    \ MOD;\n        return modint(static_cast<i64>(x));\n    }\n\n    friend modint\
    \ operator+(modint lhs, const modint& rhs) {\n        return lhs += rhs;\n   \
    \ }\n\n    friend modint operator-(modint lhs, const modint& rhs) {\n        return\
    \ lhs -= rhs;\n    }\n\n    friend modint operator*(modint lhs, const modint&\
    \ rhs) {\n        return lhs *= rhs;\n    }\n\n    friend modint operator/(modint\
    \ lhs, const modint& rhs) {\n        return lhs /= rhs;\n    }\n\n    friend bool\
    \ operator==(const modint& lhs, const modint& rhs) {\n        return lhs.val ==\
    \ rhs.val;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modint.hpp
  requiredBy: []
  timestamp: '2026-07-25 11:44:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/modint.test.cpp
documentation_of: src/math/modint.hpp
layout: document
redirect_from:
- /library/src/math/modint.hpp
- /library/src/math/modint.hpp.html
title: src/math/modint.hpp
---
