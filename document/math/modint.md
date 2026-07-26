---
title: ModInt
documentation_of: //src/math/modint.hpp
---

## 概要

コンパイル時に法を指定する剰余整数型です。
加算、減算、乗算、除算、累乗、逆元、および等値比較を通常の整数に近い記法で扱えます。

```cpp
#include "math/modint.hpp"
```

## API

### 型

```cpp
template<std::int64_t MOD>
class otukado::modint;
```

`MOD` は `0` 以外であることがコンパイル時に検査されます。通常は正の整数を指定します。

### コンストラクタ

```cpp
modint();
modint(std::int64_t x);
```

デフォルトコンストラクタは `0` を生成します。
整数を渡した場合は `x mod MOD` を `0` 以上 `MOD` 未満へ正規化して保持します。負の整数も指定できます。

### `mod`

```cpp
static std::int64_t mod();
```

法 `MOD` を返します。

### `value`

```cpp
std::int64_t value() const;
```

正規化された内部値を返します。

### 算術演算

```cpp
modint& operator+=(const modint& rhs);
modint& operator-=(const modint& rhs);
modint& operator*=(const modint& rhs);
modint& operator/=(const modint& rhs);

modint operator+() const;
modint operator-() const;

friend modint operator+(modint lhs, const modint& rhs);
friend modint operator-(modint lhs, const modint& rhs);
friend modint operator*(modint lhs, const modint& rhs);
friend modint operator/(modint lhs, const modint& rhs);
```

同じ `MOD` を持つ値同士で四則演算を行います。
整数は暗黙に `modint` へ変換できるため、`x + 3` や `x *= 2` のようにも書けます。

除算は右辺の逆元を乗算します。右辺と `MOD` が互いに素である必要があります。

### `pow`

```cpp
modint pow(std::int64_t exp) const;
```

自身の `exp` 乗を返します。`exp >= 0` が必要です。
`pow(0)` は底が `0` の場合も `1` を返します。

### `inv`

```cpp
modint inv() const;
```

拡張 Euclid の互除法で乗法逆元を返します。
内部値と `MOD` の最大公約数が `1` である必要があります。

### 比較

```cpp
friend bool operator==(const modint& lhs, const modint& rhs);
```

二つの正規化済みの値が等しければ `true` を返します。

## 使用例

```cpp
#include <cstdint>
#include <iostream>

#include "math/modint.hpp"

int main() {
    using mint = otukado::modint<1'000'000'007>;

    const mint a = 1'000'000'008; // 1 に正規化
    const mint b = -2;            // 1000000005 に正規化

    std::cout << a.value() << '\n';             // 1
    std::cout << (a + b).value() << '\n';       // 1000000006
    std::cout << (mint(3) * 4).value() << '\n'; // 12
    std::cout << mint(2).pow(10).value() << '\n'; // 1024
    std::cout << (mint(10) / 2).value() << '\n';  // 5
}
```

## 計算量

| 操作 | 時間 |
| --- | --- |
| 構築、`mod`、`value`、加減乗算、比較 | `O(1)` |
| `pow(exp)` | `O(log exp)` |
| `inv`、除算 | `O(log MOD)` |

各オブジェクトの使用領域は `O(1)` です。
乗算の中間値には `__int128_t` を使用します。

## 注意

- `MOD` には正の整数を指定してください。
- `inv()` と除算では、対象の値と `MOD` が互いに素でなければなりません。条件を満たさない場合は `assert` に失敗します。
- `MOD` が素数であっても `0` に逆元はありません。
- 異なる `MOD` の `modint` 同士は異なる型なので、直接演算できません。
- `assert` を無効にしたビルドでも、逆元の存在条件は呼び出し側で必ず保証してください。
