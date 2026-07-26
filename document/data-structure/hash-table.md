---
title: Hash Table
documentation_of: //src/data-structure/hash-table.hpp
---

## 概要

Separate Chaining 法で衝突を処理する連想配列です。
キーと値の追加・更新・検索・削除ができ、要素数に応じてバケット数を自動調整します。

現在のハッシュ関数は `std::string` 用に実装されているため、キー型には `std::string` を使用します。
このライブラリの `HashTable` はグローバル名前空間に定義されています。

```cpp
#include "data-structure/hash-table.hpp"
```

## API

### コンストラクタ

```cpp
HashTable<std::string, V> table;
```

空のハッシュテーブルを構築します。初期バケット数は `3` です。

### `put`

```cpp
bool put(K key, V value);
```

`key` に対応する値を `value` にします。
新しいキーを追加した場合は `true`、既存のキーの値を更新した場合は `false` を返します。

### `get`

```cpp
std::optional<V> get(K key);
```

`key` に対応する値のコピーを返します。
キーが存在しない場合は `std::nullopt` を返します。

### `erase`

```cpp
bool erase(K key);
```

`key` とその値を削除します。
削除した場合は `true`、キーが存在しなかった場合は `false` を返します。

### `size`

```cpp
int size();
```

登録されているキーの個数を返します。

### `bucket_size`

```cpp
int bucket_size();
```

現在確保されているバケットの個数を返します。

## 使用例

```cpp
#include <iostream>
#include <string>

#include "data-structure/hash-table.hpp"

int main() {
    HashTable<std::string, int> scores;

    std::cout << scores.put("alice", 80) << '\n'; // 1: 新規追加
    scores.put("bob", 72);
    std::cout << scores.put("alice", 95) << '\n'; // 0: 値を更新

    if (const auto score = scores.get("alice")) {
        std::cout << *score << '\n'; // 95
    }

    std::cout << scores.get("carol").value_or(-1) << '\n'; // -1
    scores.erase("bob");
    std::cout << scores.size() << '\n'; // 1
}
```

## 計算量

要素数を `N`、キーの長さを `L` とします。

| 操作 | 平均 | 最悪 |
| --- | --- | --- |
| `put` | 償却 `O(L)` | `O(NL)` |
| `get` | `O(L)` | `O(NL)` |
| `erase` | 償却 `O(L)` | `O(NL)` |
| `size` | `O(1)` | `O(1)` |
| `bucket_size` | `O(1)` | `O(1)` |

最悪計算量は、多数のキーが同じバケットへ衝突する場合や、バケットの再構築が行われる場合のものです。
使用領域は、キーと値自体を除いて `O(N + B)` です。`B` はバケット数です。

## 注意

- 対応するキー型は現在 `std::string` です。
- `get` は値への参照ではなくコピーを返します。
- `table`、`_size`、`primes`、`is_prime`、`resize`、`expand_prime`、`calculate_hash`、`get_bucket` も実装上は公開されていますが、内部処理用です。通常は直接操作しないでください。
- 独自の暗号学的ハッシュではないため、敵対的に作られた入力に対する衝突耐性は保証しません。
