---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: ModInt
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/nCr.hpp
    title: nCr
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
title: Factorial
---

## 概要

`0!` から `max_n!` までを前計算し、指定した階乗を定数時間で返します。
値は `otukado::modint<MOD>` として、コンパイル時に指定した法 `MOD` で計算されます。

```cpp
#include "math/factorial.hpp"
```

`factorial.hpp` は内部で `modint.hpp` をインクルードします。

## API

### 型

```cpp
template<std::int64_t MOD>
class otukado::Factorial;

using mint = otukado::modint<MOD>;
```

### コンストラクタ

```cpp
explicit Factorial(std::int64_t max_n);
```

`0!` から `max_n!` までを法 `MOD` で前計算します。
`max_n >= 0` が必要です。

### `operator()`

```cpp
mint operator()(std::int64_t n) const;
```

`n! mod MOD` を返します。
`0 <= n <= max_n` が必要です。

## 使用例

```cpp
#include <cstdint>
#include <iostream>

#include "math/factorial.hpp"

int main() {
    constexpr std::int64_t mod = 1'000'000'007;
    const otukado::Factorial<mod> factorial(100);

    std::cout << factorial(0).value() << '\n'; // 1
    std::cout << factorial(5).value() << '\n'; // 120
    std::cout << factorial(10).value() << '\n'; // 3628800
}
```

返り値は `modint` なので、そのまま剰余演算に利用できます。

```cpp
constexpr std::int64_t mod = 1'000'000'007;
const otukado::Factorial<mod> factorial(20);
using mint = otukado::modint<mod>;

const mint result = factorial(10) * mint(3) + factorial(5);
```

## 計算量

| 操作 | 時間 | 追加領域 |
| --- | --- | --- |
| 構築 | `O(max_n)` | `O(max_n)` |
| `operator()` | `O(1)` | `O(1)` |

## 注意

- `MOD` には正の整数を指定してください。
- `max_n` を超える階乗は取得できません。
- 保持される値は常に法 `MOD` での剰余です。通常の整数としての階乗そのものが必要な場合には適しません。
