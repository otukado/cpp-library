---
title: Segment Tree
documentation_of: //src/data-structure/segment-tree.hpp
---

## 概要

一点更新と区間積の取得を行うセグメント木です。
演算 `op` と単位元 `e` をテンプレート引数として指定するため、区間和、区間最小値、区間最大値などに利用できます。

```cpp
#include "data-structure/segment-tree.hpp"
```

## テンプレート引数

```cpp
template<typename T, auto e, auto op>
class otukado::SegmentTree;
```

| 引数 | 説明 |
| --- | --- |
| `T` | 格納する値と演算結果の型 |
| `e` | 単位元そのもの、または引数なしで `T` を返す関数 |
| `op` | `T` を二つ受け取り `T` を返す二項演算 |

`op` は結合則を満たし、`e` は左右両方の単位元である必要があります。
可換である必要はありません。

## API

### コンストラクタ

```cpp
explicit SegmentTree(int n);
```

長さ `n` の列を構築し、すべての要素を単位元で初期化します。
`n >= 0` が必要です。

### `update`

```cpp
void update(int p, T x);
```

位置 `p` の値を `x` に置き換えます。
`0 <= p < n` が必要です。

### `at`

```cpp
T at(int p) const;
```

位置 `p` の値を返します。
`0 <= p < n` が必要です。

### `operator[]`

```cpp
Proxy operator[](int p);
T operator[](int p) const;
```

非 `const` オブジェクトでは読み書き用のプロキシ、`const` オブジェクトでは値を返します。
次のように通常の配列に近い記法で一点更新できます。

```cpp
seg[p] = x;
seg[p] = seg[p] + delta;
```

### `range`

```cpp
T range(int l, int r) const;
```

半開区間 `[l, r)` の要素を左から `op` でまとめた値を返します。
`0 <= l <= r <= n` が必要です。空区間では単位元を返します。

### `all_range`

```cpp
T all_range() const;
```

全区間 `[0, n)` の値を返します。

## 使用例

一点加算と区間和を処理します。

```cpp
#include <iostream>

#include "data-structure/segment-tree.hpp"

long long add(long long a, long long b) {
    return a + b;
}

int main() {
    otukado::SegmentTree<long long, 0LL, add> seg(5);

    seg[0] = 2;
    seg[1] = 4;
    seg[2] = 1;
    seg[3] = 8;
    seg[4] = 3;

    std::cout << seg.range(1, 4) << '\n'; // 4 + 1 + 8 = 13

    seg[2] = seg[2] + 10;
    std::cout << seg.all_range() << '\n'; // 28
}
```

単位元は値の代わりに関数でも指定できます。

```cpp
#include <limits>

int inf() {
    return std::numeric_limits<int>::max();
}

int minimum(int a, int b) {
    return a < b ? a : b;
}

otukado::SegmentTree<int, inf, minimum> range_minimum(100);
```

## 計算量

| 操作 | 時間 |
| --- | --- |
| 構築 | `O(n)` |
| `update`、`operator[]` への代入 | `O(log n)` |
| `at`、`operator[]` からの読み取り | `O(1)` |
| `range` | `O(log n)` |
| `all_range` | `O(1)` |

使用領域は `O(n)` です。

## 注意

- `range(l, r)` の右端 `r` は範囲に含まれません。
- `seg[p] += x` はプロキシに `operator+=` がないため使用できません。`seg[p] = seg[p] + x` と書いてください。
- `op` が結合則を満たさない場合、結果は期待する値になりません。
