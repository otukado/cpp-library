---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/factorial.hpp
    title: Factorial
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/nCr.test.cpp
    title: tests/nCr.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/nCr.hpp\"\n\n#include <cassert>\n#include <cstdint>\n\
    #include <vector>\n\n#line 2 \"src/math/factorial.hpp\"\n\n#line 6 \"src/math/factorial.hpp\"\
    \n\n#line 2 \"src/math/modint.hpp\"\n\n#line 5 \"src/math/modint.hpp\"\n\nnamespace\
    \ otukado{\n\n\ntemplate<std::int64_t MOD>\nclass modint {\n    static_assert(MOD\
    \ != 0);\nprivate:\n    using i64 = std::int64_t;\n    using i128 = __int128_t;\n\
    \n    i64 val;\n\npublic:\n    modint() : val(0) {}\n\n    modint(i64 x) : val(x\
    \ % MOD) {\n        if (val < 0) val += MOD;\n    }\n\n    static i64 mod() {\n\
    \        return MOD;\n    }\n\n    i64 value() const {\n        return val;\n\
    \    }\n\n    modint& operator+=(const modint& other) {\n        val += other.val;\n\
    \        if (val >= MOD) val -= MOD;\n        return *this;\n    }\n\n    modint&\
    \ operator-=(const modint& other) {\n        val -= other.val;\n        if (val\
    \ < 0) val += MOD;\n        return *this;\n    }\n\n    modint& operator*=(const\
    \ modint& other) {\n        val = static_cast<i64>(\n            static_cast<i128>(val)\
    \ * other.val % MOD\n        );\n        return *this;\n    }\n\n    modint& operator/=(const\
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
    \      return lhs.val == rhs.val;\n    }\n};\n\n\n}; //namespace otukado\n#line\
    \ 8 \"src/math/factorial.hpp\"\n\nnamespace otukado {\n\ntemplate<std::int64_t\
    \ MOD>\nclass Factorial {\npublic:\n    using mint = modint<MOD>;\n\nprivate:\n\
    \    std::int64_t max_n;\n    std::vector<mint> fact;\n\npublic:\n    explicit\
    \ Factorial(std::int64_t max_n) : max_n(max_n) {\n        assert(max_n >= 0);\n\
    \n        fact.resize(max_n + 1);\n        fact[0] = 1;\n        for (std::int64_t\
    \ i = 1; i <= max_n; ++i) {\n            fact[i] = fact[i - 1] * mint(i);\n  \
    \      }\n    }\n\n    mint operator()(std::int64_t n) const {\n        assert(0\
    \ <= n && n <= max_n);\n        return fact[n];\n    }\n};\n\n} // namespace otukado\n\
    #line 8 \"src/math/nCr.hpp\"\n\nnamespace otukado {\n\ntemplate<std::int64_t MOD>\n\
    class nCr {\npublic:\n    using mint = typename Factorial<MOD>::mint;\n\nprivate:\n\
    \    std::int64_t max_n;\n    Factorial<MOD> fact;\n    std::vector<mint> inv_fact;\n\
    \npublic:\n    explicit nCr(std::int64_t max_n) : max_n(max_n), fact(max_n) {\n\
    \        assert(max_n >= 0);\n\n        inv_fact.resize(max_n + 1);\n\n      \
    \  inv_fact[max_n] = fact(max_n).inv();\n        for (std::int64_t i = max_n;\
    \ i > 0; --i) {\n            inv_fact[i - 1] = inv_fact[i] * mint(i);\n      \
    \  }\n    }\n\n    mint operator()(std::int64_t n, std::int64_t r) const {\n \
    \       if (n < 0 || r < 0 || r > n) return 0;\n        assert(n <= max_n);\n\n\
    \        return fact(n) * inv_fact[r] * inv_fact[n - r];\n    }\n};\n\n} // namespace\
    \ otukado\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\
    \n#include \"factorial.hpp\"\n\nnamespace otukado {\n\ntemplate<std::int64_t MOD>\n\
    class nCr {\npublic:\n    using mint = typename Factorial<MOD>::mint;\n\nprivate:\n\
    \    std::int64_t max_n;\n    Factorial<MOD> fact;\n    std::vector<mint> inv_fact;\n\
    \npublic:\n    explicit nCr(std::int64_t max_n) : max_n(max_n), fact(max_n) {\n\
    \        assert(max_n >= 0);\n\n        inv_fact.resize(max_n + 1);\n\n      \
    \  inv_fact[max_n] = fact(max_n).inv();\n        for (std::int64_t i = max_n;\
    \ i > 0; --i) {\n            inv_fact[i - 1] = inv_fact[i] * mint(i);\n      \
    \  }\n    }\n\n    mint operator()(std::int64_t n, std::int64_t r) const {\n \
    \       if (n < 0 || r < 0 || r > n) return 0;\n        assert(n <= max_n);\n\n\
    \        return fact(n) * inv_fact[r] * inv_fact[n - r];\n    }\n};\n\n} // namespace\
    \ otukado\n"
  dependsOn:
  - src/math/factorial.hpp
  - src/math/modint.hpp
  isVerificationFile: false
  path: src/math/nCr.hpp
  requiredBy: []
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/nCr.test.cpp
documentation_of: src/math/nCr.hpp
layout: document
title: nCr
---

## 概要

階乗と逆階乗を前計算し、二項係数

```text
nCr = n! / (r! (n-r)!)
```

を法 `MOD` で定数時間に求めます。

```cpp
#include "math/nCr.hpp"
```

`nCr.hpp` は内部で `factorial.hpp` と `modint.hpp` をインクルードします。

## API

### 型

```cpp
template<std::int64_t MOD>
class otukado::nCr;

using mint = otukado::modint<MOD>;
```

### コンストラクタ

```cpp
explicit nCr(std::int64_t max_n);
```

`0` から `max_n` までの二項係数を計算するため、階乗と逆階乗を前計算します。
`max_n >= 0` が必要です。

構築には `max_n!` の逆元が必要です。したがって、`gcd(max_n!, MOD) == 1` を満たす必要があります。
典型的には素数 `MOD` を使い、`max_n < MOD` とします。

### `operator()`

```cpp
mint operator()(std::int64_t n, std::int64_t r) const;
```

`nCr mod MOD` を返します。

`n < 0`、`r < 0`、または `r > n` の場合は `0` を返します。
それ以外の場合は `n <= max_n` が必要です。

## 使用例

```cpp
#include <cstdint>
#include <iostream>

#include "math/nCr.hpp"

int main() {
    constexpr std::int64_t mod = 1'000'000'007;
    const otukado::nCr<mod> combination(100);

    std::cout << combination(5, 2).value() << '\n';  // 10
    std::cout << combination(10, 3).value() << '\n'; // 120
    std::cout << combination(4, 5).value() << '\n';  // 0
}
```

返り値は `modint` なので、複数の二項係数を使った式もそのまま計算できます。

```cpp
constexpr std::int64_t mod = 1'000'000'007;
const otukado::nCr<mod> combination(1000);

const auto answer = combination(20, 5) * combination(30, 7);
```

## 計算量

| 操作 | 時間 | 追加領域 |
| --- | --- | --- |
| 構築 | `O(max_n + log MOD)` | `O(max_n)` |
| `operator()` | `O(1)` | `O(1)` |

構築時に階乗を `O(max_n)` で計算し、逆元を一度 `O(log MOD)` で求めた後、残りの逆階乗を `O(max_n)` で計算します。

## 注意

- `MOD` には正の整数を指定してください。
- 素数 `MOD` を利用する場合も、現在の実装では通常 `max_n < MOD` が必要です。`max_n >= MOD` では `max_n!` が `0 mod MOD` となり、逆元を作れません。
- `n > max_n` は `assert` に失敗します。必要となる最大の `n` をコンストラクタへ渡してください。
- Lucas の定理や合成数を法とする一般的な二項係数には対応していません。
