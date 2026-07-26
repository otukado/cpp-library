---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segment-tree.test.cpp
    title: tests/segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/segment-tree.hpp\"\n#include<vector>\n\
    #include <cassert>\n#include <type_traits>\n\nnamespace otukado {\n\n\ntemplate<typename\
    \ T, auto e, auto op>\nclass SegmentTree {\nprivate:\n    int n;\n    int size;\n\
    \    std::vector<T> data;\n\n    static T identity() {\n        if constexpr (std::is_invocable_r_v<T,\
    \ decltype(e)>) {\n            return e();\n        } else {\n            return\
    \ e;\n        }\n    }\n    \npublic:\n    class Proxy {\n    private:\n     \
    \   SegmentTree& seg;\n        int index;\n\n    public:\n        Proxy(SegmentTree&\
    \ seg, int index) : seg(seg), index(index) {}\n        // \u4EE3\u5165\u6642\n\
    \        Proxy& operator=(const T& val) {\n            seg.update(index, val);\n\
    \            return *this;\n        }\n\n        // \u5024\u8AAD\u307F\u53D6\u308A\
    \u6642\n        operator T() const {\n            return seg.at(index);\n    \
    \    }\n\n        Proxy& operator=(const Proxy& other) {\n            return *this\
    \ = static_cast<T>(other);\n        }\n    };\n\n    T at(int p) const {\n   \
    \     assert(0 <= p && p < n);\n        p += size;\n        return data[p];\n\
    \    }\n\n    void update (int p, T x) {\n        assert(0 <= p && p < n);\n \
    \       p += size;\n        data[p] = x;\n        while(p > 1) {\n           \
    \ p /= 2;\n            data[p] = op(data[p * 2], data[p * 2 + 1]);\n        }\n\
    \    }\n\n\n    Proxy operator[](int index) {\n        return Proxy(*this, index);\n\
    \    }\n\n    T operator[](int index) const {\n        return at(index);\n   \
    \ }\n\n\n    SegmentTree(int n) : n(n) {\n        assert(n >= 0);\n        size\
    \ = 1;\n        while(size < n) size *= 2;\n        data.assign(size * 2, identity());\n\
    \    };\n\n    T range(int l, int r) const {\n        assert(0 <= l && l <= r\
    \ && r <= n);\n\n        T left = identity();\n        T right = identity();\n\
    \        int i = 0;\n        while(l != r) {\n            if(l & (1 << i)) {\n\
    \                int target = (size >> i) + (l >> i);\n                l += (1\
    \ << i);\n                left = op(left, data[target]);\n            }\n\n  \
    \          if(r & (1 << i)) {\n                int target = (size >> i) + (r >>\
    \ i) - 1;\n                r -= (1 << i);\n                right = op(data[target],\
    \ right);\n            }\n\n            i++;\n        }\n\n        return op(left,\
    \ right);\n    }\n\n    T all_range() const {\n        return data[1];\n    }\n\
    };\n\n} // namespace otukado\n"
  code: "#pragma once\n#include<vector>\n#include <cassert>\n#include <type_traits>\n\
    \nnamespace otukado {\n\n\ntemplate<typename T, auto e, auto op>\nclass SegmentTree\
    \ {\nprivate:\n    int n;\n    int size;\n    std::vector<T> data;\n\n    static\
    \ T identity() {\n        if constexpr (std::is_invocable_r_v<T, decltype(e)>)\
    \ {\n            return e();\n        } else {\n            return e;\n      \
    \  }\n    }\n    \npublic:\n    class Proxy {\n    private:\n        SegmentTree&\
    \ seg;\n        int index;\n\n    public:\n        Proxy(SegmentTree& seg, int\
    \ index) : seg(seg), index(index) {}\n        // \u4EE3\u5165\u6642\n        Proxy&\
    \ operator=(const T& val) {\n            seg.update(index, val);\n           \
    \ return *this;\n        }\n\n        // \u5024\u8AAD\u307F\u53D6\u308A\u6642\n\
    \        operator T() const {\n            return seg.at(index);\n        }\n\n\
    \        Proxy& operator=(const Proxy& other) {\n            return *this = static_cast<T>(other);\n\
    \        }\n    };\n\n    T at(int p) const {\n        assert(0 <= p && p < n);\n\
    \        p += size;\n        return data[p];\n    }\n\n    void update (int p,\
    \ T x) {\n        assert(0 <= p && p < n);\n        p += size;\n        data[p]\
    \ = x;\n        while(p > 1) {\n            p /= 2;\n            data[p] = op(data[p\
    \ * 2], data[p * 2 + 1]);\n        }\n    }\n\n\n    Proxy operator[](int index)\
    \ {\n        return Proxy(*this, index);\n    }\n\n    T operator[](int index)\
    \ const {\n        return at(index);\n    }\n\n\n    SegmentTree(int n) : n(n)\
    \ {\n        assert(n >= 0);\n        size = 1;\n        while(size < n) size\
    \ *= 2;\n        data.assign(size * 2, identity());\n    };\n\n    T range(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\n        T\
    \ left = identity();\n        T right = identity();\n        int i = 0;\n    \
    \    while(l != r) {\n            if(l & (1 << i)) {\n                int target\
    \ = (size >> i) + (l >> i);\n                l += (1 << i);\n                left\
    \ = op(left, data[target]);\n            }\n\n            if(r & (1 << i)) {\n\
    \                int target = (size >> i) + (r >> i) - 1;\n                r -=\
    \ (1 << i);\n                right = op(data[target], right);\n            }\n\
    \n            i++;\n        }\n\n        return op(left, right);\n    }\n\n  \
    \  T all_range() const {\n        return data[1];\n    }\n};\n\n} // namespace\
    \ otukado\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segment-tree.test.cpp
documentation_of: src/data-structure/segment-tree.hpp
layout: document
title: Segment Tree
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
