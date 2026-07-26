---
title: Prefix Sum 2D
documentation_of: //src/data-structure/prefix2d.hpp
---

## 概要

二次元配列の累積和を前計算し、軸に平行な矩形領域の総和を高速に求めます。
矩形は行と列の両方を **0-indexed の閉区間** で指定します。

```cpp
#include "data-structure/prefix2d.hpp"
```

## API

### コンストラクタ

```cpp
explicit Prefix2D(std::vector<std::vector<T>> data);
```

`data` から二次元累積和を構築します。
`data` は一行以上あり、全行の列数が等しい必要があります。

要素型 `T` にはデフォルト構築、コピー、`+=`、`+`、`-` が必要です。

### `get`

```cpp
T get(int a, int b, int c, int d);
```

左上を `(a, b)`、右下を `(c, d)` とする矩形内の総和を返します。
行区間は `[a, c]`、列区間は `[b, d]` で、端点をどちらも含みます。

次の条件を満たす必要があります。

```text
0 <= a <= c < 行数
0 <= b <= d < 列数
```

### `data`

```cpp
auto data() const;
```

内部の累積和配列のコピーを返します。
返される配列の大きさは `(行数 + 1) × (列数 + 1)` で、先頭行と先頭列は番兵の `0` です。

### `calculate`

```cpp
void calculate();
```

内部の累積和を計算するためのメソッドです。コンストラクタから自動的に呼ばれます。
構築後にもう一度呼ぶと既存の累積値へ再加算されるため、利用者が直接呼び出すことは想定していません。

## 使用例

```cpp
#include <iostream>
#include <vector>

#include "data-structure/prefix2d.hpp"

int main() {
    const std::vector<std::vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    otukado::Prefix2D<int> prefix(grid);

    // 行 [0, 1]、列 [1, 2]: 2 + 3 + 5 + 6
    std::cout << prefix.get(0, 1, 1, 2) << '\n'; // 16

    // 全要素の和
    std::cout << prefix.get(0, 0, 2, 2) << '\n'; // 45
}
```

## 計算量

配列の高さを `H`、幅を `W` とします。

| 操作 | 時間 | 追加領域 |
| --- | --- | --- |
| 構築 | `O(HW)` | `O(HW)` |
| `get` | `O(1)` | `O(1)` |
| `data` | `O(HW)` | `O(HW)` |

`data()` は累積和配列をコピーして返すため、定数時間ではありません。

## 注意

- `get` の範囲は半開区間ではなく閉区間です。
- 構築後に元の `data` を変更しても、このオブジェクトの累積和には反映されません。
- 動的な一点更新には対応していません。更新が必要な場合は二次元 Fenwick Tree などを使用してください。
