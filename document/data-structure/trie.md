---
title: Trie
documentation_of: //src/data-structure/trie.hpp
---

## 概要

英小文字列の集合を管理する Trie です。
単語の追加、完全一致検索、削除、および指定した接頭辞を持つ単語数の取得ができます。

同じ単語を複数回追加しても一つとして扱うため、マルチセットではなくセットとして動作します。

```cpp
#include "data-structure/trie.hpp"
```

## API

### コンストラクタ

```cpp
otukado::Trie trie;
```

空の Trie を構築します。

### `insert`

```cpp
void insert(std::string word);
```

`word` を追加します。
すでに同じ単語が存在する場合は何もしません。

### `search`

```cpp
otukado::Node* search(std::string word);
```

`word` が登録されていれば終端ノードへのポインタを返し、登録されていなければ `nullptr` を返します。
接頭辞として存在するだけで、単語として登録されていない場合も `nullptr` です。

返されたポインタは Trie が所有しています。削除したり、Trie の破棄後や該当単語の `erase` 後に参照したりしないでください。

### `erase`

```cpp
void erase(std::string word);
```

`word` を削除します。
登録されていない場合は何もしません。

### `count_prefix`

```cpp
int count_prefix(std::string prefix);
```

`prefix` から始まる登録済み単語の個数を返します。
空文字列 `""` を渡すと、登録されている全単語数を返します。

## 使用例

```cpp
#include <iostream>

#include "data-structure/trie.hpp"

int main() {
    otukado::Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("apply");
    trie.insert("banana");
    trie.insert("app"); // 重複追加は無視される

    std::cout << (trie.search("app") != nullptr) << '\n';   // 1
    std::cout << (trie.search("ap") != nullptr) << '\n';    // 0
    std::cout << trie.count_prefix("app") << '\n';          // 3
    std::cout << trie.count_prefix("") << '\n';             // 4

    trie.erase("apple");
    std::cout << trie.count_prefix("app") << '\n';          // 2
}
```

## 計算量

対象文字列の長さを `L` とします。

| 操作 | 時間 |
| --- | --- |
| `insert` | `O(L)` |
| `search` | `O(L)` |
| `erase` | `O(L)` |
| `count_prefix` | `O(L)` |

使用領域は、作成されたノード数に比例します。各ノードは英小文字用に `26` 個の子ポインタを保持します。

## 注意

- 使用できる文字は `'a'` から `'z'` までの英小文字だけです。それ以外の文字を渡すと配列範囲外アクセスになります。
- `Trie` と `Node` は生ポインタで所有権を管理しています。`Trie` をコピーまたは代入すると二重解放の原因になるため、コピーしないでください。
- `root` と各 `Node` は実装上公開されていますが、通常は直接変更しないでください。
