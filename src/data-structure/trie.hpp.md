---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/trie.test.cpp
    title: tests/trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/trie.hpp\"\n#include <array>\n#include\
    \ <vector>\n#include <string>\n\nnamespace otukado {\n\n\nstruct Node {\n    Node*\
    \ parent = nullptr;\n    std::array<Node*, 26> children{};\n\n    char alphabet\
    \ = '$';\n    int num = 0;\n    bool is_end = false;\n\n    Node() = default;\n\
    \    Node(Node* par, char alp) : parent(par), alphabet(alp) {}\n\n    ~Node()\
    \ {\n        for(auto& child : this->children) {\n            delete child;\n\
    \        }\n    }\n};\n\nstruct Trie {\n    Node* root = new Node();\n\n    ~Trie()\
    \ {\n        delete this->root;\n    }\n\n    void insert (std::string word) {\n\
    \        auto curr = this->root;\n        for(const auto& c: word) {\n       \
    \     if(curr->children[c-'a'] == nullptr) {\n                curr->children[c-'a']\
    \ = new Node(curr, c);\n            }\n            curr = curr->children[c-'a'];\n\
    \        }\n        if(curr->is_end) return;\n        curr->is_end = true;\n \
    \       while(curr != this->root) {\n            ++curr->num;\n            curr\
    \ = curr->parent;\n        }\n        ++curr->num;\n    }\n\n    // \u898B\u3064\
    \u304B\u3089\u306A\u3051\u308C\u3070 nullptr \u3092\u8FD4\u3059\n    Node* search(std::string\
    \ word) {\n        auto curr = this->root;\n        for(const char& c : word)\
    \ {\n            if(curr->children[c-'a'] == nullptr) return nullptr;\n      \
    \      curr = curr->children[c - 'a'];\n        }\n        return curr->is_end\
    \ ? curr : nullptr;\n    }\n\n    // \u6307\u5B9A\u3057\u305F word \u3092\u524A\
    \u9664\n    void erase (std::string word) {\n        auto end = search(word);\n\
    \        if(end == nullptr) return;\n        auto curr = end;\n        curr->is_end\
    \ = false;\n        while(curr != this->root) {\n            if(curr->num == 1)\
    \ {\n                auto parent = curr->parent;\n                parent->children[curr->alphabet\
    \ - 'a'] = nullptr;\n                delete curr;\n                curr = parent;\n\
    \            } else {\n                --curr->num;\n                curr = curr->parent;\n\
    \            } \n        }\n        --curr->num;\n    };\n\n    int count_prefix(std::string\
    \ perfix) {\n        auto curr = this->root;\n        for(const char& c : perfix)\
    \ {\n            if(curr->children[c-'a'] == nullptr) return 0;\n            curr\
    \ = curr->children[c - 'a'];\n        }\n        return curr->num;\n    }\n};\n\
    \n\n} // namespace otukado\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include <string>\n\n\
    namespace otukado {\n\n\nstruct Node {\n    Node* parent = nullptr;\n    std::array<Node*,\
    \ 26> children{};\n\n    char alphabet = '$';\n    int num = 0;\n    bool is_end\
    \ = false;\n\n    Node() = default;\n    Node(Node* par, char alp) : parent(par),\
    \ alphabet(alp) {}\n\n    ~Node() {\n        for(auto& child : this->children)\
    \ {\n            delete child;\n        }\n    }\n};\n\nstruct Trie {\n    Node*\
    \ root = new Node();\n\n    ~Trie() {\n        delete this->root;\n    }\n\n \
    \   void insert (std::string word) {\n        auto curr = this->root;\n      \
    \  for(const auto& c: word) {\n            if(curr->children[c-'a'] == nullptr)\
    \ {\n                curr->children[c-'a'] = new Node(curr, c);\n            }\n\
    \            curr = curr->children[c-'a'];\n        }\n        if(curr->is_end)\
    \ return;\n        curr->is_end = true;\n        while(curr != this->root) {\n\
    \            ++curr->num;\n            curr = curr->parent;\n        }\n     \
    \   ++curr->num;\n    }\n\n    // \u898B\u3064\u304B\u3089\u306A\u3051\u308C\u3070\
    \ nullptr \u3092\u8FD4\u3059\n    Node* search(std::string word) {\n        auto\
    \ curr = this->root;\n        for(const char& c : word) {\n            if(curr->children[c-'a']\
    \ == nullptr) return nullptr;\n            curr = curr->children[c - 'a'];\n \
    \       }\n        return curr->is_end ? curr : nullptr;\n    }\n\n    // \u6307\
    \u5B9A\u3057\u305F word \u3092\u524A\u9664\n    void erase (std::string word)\
    \ {\n        auto end = search(word);\n        if(end == nullptr) return;\n  \
    \      auto curr = end;\n        curr->is_end = false;\n        while(curr !=\
    \ this->root) {\n            if(curr->num == 1) {\n                auto parent\
    \ = curr->parent;\n                parent->children[curr->alphabet - 'a'] = nullptr;\n\
    \                delete curr;\n                curr = parent;\n            } else\
    \ {\n                --curr->num;\n                curr = curr->parent;\n    \
    \        } \n        }\n        --curr->num;\n    };\n\n    int count_prefix(std::string\
    \ perfix) {\n        auto curr = this->root;\n        for(const char& c : perfix)\
    \ {\n            if(curr->children[c-'a'] == nullptr) return 0;\n            curr\
    \ = curr->children[c - 'a'];\n        }\n        return curr->num;\n    }\n};\n\
    \n\n} // namespace otukado\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/trie.hpp
  requiredBy: []
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/trie.test.cpp
documentation_of: src/data-structure/trie.hpp
layout: document
title: Trie
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
