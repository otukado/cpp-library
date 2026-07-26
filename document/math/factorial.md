---
title: Factorial
documentation_of: //src/math/factorial.hpp
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
