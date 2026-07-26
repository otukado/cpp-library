---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/example.test.cpp
    title: tests/example.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/binary-search.hpp\"\n\n#include <cassert>\n\
    #include <type_traits>\n\nnamespace otukado {\n\n\ntemplate<typename T, typename\
    \ F>\nT BinarySearch(T ng, T ok, F pred) {\n    assert(ng != ok);\n    T mid;\n\
    \    while(std::abs(ng - ok) > 1) {\n        mid = (ng + ok) / 2;\n\n        if(pred(mid))\
    \ {\n            ok = mid;\n        } else {\n            ng = mid;\n        }\n\
    \    }\n\n    return ok;\n}\n\n\n} // namespace otukado\n"
  code: "#pragma once\n\n#include <cassert>\n#include <type_traits>\n\nnamespace otukado\
    \ {\n\n\ntemplate<typename T, typename F>\nT BinarySearch(T ng, T ok, F pred)\
    \ {\n    assert(ng != ok);\n    T mid;\n    while(std::abs(ng - ok) > 1) {\n \
    \       mid = (ng + ok) / 2;\n\n        if(pred(mid)) {\n            ok = mid;\n\
    \        } else {\n            ng = mid;\n        }\n    }\n\n    return ok;\n\
    }\n\n\n} // namespace otukado\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/binary-search.hpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/example.test.cpp
documentation_of: src/data-structure/binary-search.hpp
layout: document
title: Binary Search
---

## 概要

単調な判定関数に対して二分探索を行い、条件を満たす側の境界を返します。
探索区間の左右は `ng`（条件を満たさない値）と `ok`（条件を満たす値）で指定します。
`ng < ok` の探索だけでなく、`ok < ng` の探索にも利用できます。

```cpp
#include "data-structure/binary-search.hpp"
```

## API

### `BinarySearch`

```cpp
template<typename T, typename F>
T otukado::BinarySearch(T ng, T ok, F pred);
```

`pred(ng) == false`、`pred(ok) == true` となる二つの値を受け取り、`ok` 側にある境界を返します。
探索中は次の不変条件が保たれます。

- `ng` は条件を満たさない
- `ok` は条件を満たす

`ng` と `ok` の差の絶対値が `1` になった時点の `ok` が返ります。

| 引数 | 説明 |
| --- | --- |
| `ng` | 条件を満たさないことが分かっている番兵 |
| `ok` | 条件を満たすことが分かっている番兵 |
| `pred` | `T` を受け取り、真偽値へ変換可能な値を返す単調な関数 |

`T` には、減算、加算、`2` による除算、および `std::abs` が利用できる符号付き整数型を想定しています。

## 使用例

昇順の配列から `x` 以上となる最初の位置を求めます。

```cpp
#include <iostream>
#include <vector>

#include "data-structure/binary-search.hpp"

int main() {
    const std::vector<int> values = {1, 3, 3, 7, 10};
    const int x = 4;

    const int index = otukado::BinarySearch(-1, static_cast<int>(values.size()),
        [&](int i) {
            return values[i] >= x;
        }
    );

    if (index == static_cast<int>(values.size())) {
        std::cout << "not found\n";
    } else {
        std::cout << index << ' ' << values[index] << '\n'; // 3 7
    }
}
```

この例では `-1` と `values.size()` を番兵として使用しています。判定関数が呼ばれるのは両番兵の間の値だけなので、番兵による配列外参照は発生しません。

## 計算量

`D = |ok - ng|` とすると、判定関数の呼び出し回数は `O(log D)` です。
判定関数一回の計算量を `P` とした全体の計算量は `O(P log D)`、追加領域は `O(1)` です。

## 注意

- `ng != ok` が必要です。
- 判定結果は `ng` から `ok` へ進む間に `false` から `true` へ一度だけ変化する必要があります。
- `pred(ng)` と `pred(ok)` は関数内では検査されません。呼び出し側で条件を保証してください。
- 非常に大きい整数では `(ng + ok) / 2` の加算がオーバーフローしない範囲を使用してください。
