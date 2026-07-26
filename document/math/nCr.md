---
title: nCr
documentation_of: //src/math/nCr.hpp
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
