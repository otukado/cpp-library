---
title: Union-Find
documentation_of: //src/data-structure/union-find.hpp
---

## 概要

要素を互いに素な集合へ分割して管理する Union-Find（Disjoint Set Union）です。
二つの集合の併合、二要素が同じ集合に属するかの判定、集合サイズ、および集合数の取得ができます。

経路圧縮と union by size を使用しています。

```cpp
#include "data-structure/union-find.hpp"
```

## API

### コンストラクタ

```cpp
explicit otukado::UnionFind(int n);
```

`0` から `n - 1` までの各要素が、それぞれ独立した集合に属する状態を構築します。
`n >= 0` が必要です。

### `find`

```cpp
int find(int x);
```

`x` が属する集合の代表元を返します。
代表元の番号は併合によって変わる可能性があるため、永続的な集合IDとしては利用できません。

### `connected`

```cpp
bool connected(int a, int b);
```

`a` と `b` が同じ集合に属していれば `true`、そうでなければ `false` を返します。

### `size`

```cpp
int size(int x);
```

`x` が属する集合の要素数を返します。

### `groups`

```cpp
int groups();
```

現在の集合数を返します。

### `merge`

```cpp
bool merge(int a, int b);
```

`a` と `b` が属する集合を併合します。
異なる集合を実際に併合した場合は `true`、すでに同じ集合だった場合は `false` を返します。

## 使用例

```cpp
#include <iostream>

#include "data-structure/union-find.hpp"

int main() {
    otukado::UnionFind uf(5);

    uf.merge(0, 1);
    uf.merge(1, 2);

    std::cout << uf.connected(0, 2) << '\n'; // 1
    std::cout << uf.connected(0, 3) << '\n'; // 0
    std::cout << uf.size(1) << '\n';         // 3
    std::cout << uf.groups() << '\n';        // 3

    // すでに同じ集合なので併合されない
    std::cout << uf.merge(0, 2) << '\n';     // 0
}
```

## 計算量

要素数を `N` とすると、`find`、`connected`、`size`、`merge` は償却 `O(α(N))` です。
`α` は逆 Ackermann 関数で、実用上はほぼ定数です。
`groups` は `O(1)`、使用領域は `O(N)` です。

## 注意

- すべての要素番号は `0 <= x < n` を満たす必要があります。
- 範囲外アクセスを検査する `assert` はないため、呼び出し側で有効な番号を保証してください。
- 集合の分割や、併合前の状態への巻き戻しには対応していません。
