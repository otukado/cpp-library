# cpp-library

競技プログラミングで使用する C++ ライブラリです。  
各ライブラリはヘッダー単体で利用でき、[online-judge-verify-helper](https://github.com/online-judge-tools/verification-helper) で実際の問題を使って検証しています。

## 必要環境

- C++23 に対応したコンパイラ
- Python 3 と `pipx`
- [online-judge-verify-helper](https://github.com/online-judge-tools/verification-helper)
- [online-judge-tools](https://github.com/online-judge-tools/oj)

依存ツールは次のコマンドでインストールできます。

```bash
pipx install online-judge-verify-helper
pipx install online-judge-tools
```

## セットアップ

このリポジトリを任意のディレクトリにクローンします。次の `/path/to/cpp-library` は、使用したい配置先に置き換えてください。

```bash
git clone https://github.com/otukado/cpp-library.git /path/to/cpp-library
```

クローン先の絶対パスを `CP_LIBRARY_DIR` に設定し、次の内容を `~/.bashrc` に追加します。

```bash
export CP_LIBRARY_DIR="/path/to/cpp-library"
export CPLUS_INCLUDE_PATH="$CP_LIBRARY_DIR/src${CPLUS_INCLUDE_PATH:+:$CPLUS_INCLUDE_PATH}"
```

設定を反映します。

```bash
source ~/.bashrc
```

## 使い方

使用するヘッダーを解答コードからインクルードします。

```cpp
#include <iostream>
#include "data-structure/union-find.hpp"

int main() {
    otukado::UnionFind uf(5);
    uf.merge(0, 1);
    std::cout << uf.connected(0, 1) << '\n';
}
```

コンパイル時にインクルード先を直接指定する場合は、次のようにします。

```bash
g++ -std=gnu++23 -O2 -Wall -Wextra \
  -I "$CP_LIBRARY_DIR/src" main.cpp
```

### 提出コードを一つのファイルへ展開

`oj-bundle` を使うと、インクルードしたライブラリを解答コードへ展開できます。

```bash
oj-bundle -I "$CP_LIBRARY_DIR/src" main.cpp > bundle.cpp
```

生成された `bundle.cpp` の内容を提出してください。

WSL を使用している場合は、展開したコードを Windows のクリップボードへ直接コピーできます。

```bash
oj-bundle -I "$CP_LIBRARY_DIR/src" main.cpp \
  | iconv -f UTF-8 -t CP932 \
  | clip.exe
```

実行後、提出画面のエディタへそのまま貼り付けられます。この方法には `iconv` と Windows の `clip.exe` が必要です。

## ライブラリ一覧

### データ構造・アルゴリズム

| ライブラリ | 概要 | ソース | 検証コード |
| --- | --- | --- | --- |
| Binary Search | `ng` と `ok` を指定する二分探索 | [binary-search.hpp](src/data-structure/binary-search.hpp) | [example.test.cpp](tests/example.test.cpp) |
| Hash Table | Separate Chaining 法による連想配列 | [hash-table.hpp](src/data-structure/hash-table.hpp) | [hash-table.test.cpp](tests/hash-table.test.cpp) |
| Prefix Sum 2D | 二次元累積和と矩形和 | [prefix2d.hpp](src/data-structure/prefix2d.hpp) | [prefix2d.test.cpp](tests/prefix2d.test.cpp) |
| Segment Tree | 一点更新・区間取得 | [segment-tree.hpp](src/data-structure/segment-tree.hpp) | [segment-tree.test.cpp](tests/segment-tree.test.cpp) |
| Trie | 英小文字列の追加・検索・削除・接頭辞数え上げ | [trie.hpp](src/data-structure/trie.hpp) | [trie.test.cpp](tests/trie.test.cpp) |
| Union-Find | 素集合データ構造 | [union-find.hpp](src/data-structure/union-find.hpp) | [union-find.test.cpp](tests/union-find.test.cpp) |

### 数学

| ライブラリ | 概要 | ソース | 検証コード |
| --- | --- | --- | --- |
| Factorial | 階乗の前計算 | [factorial.hpp](src/math/factorial.hpp) | [factorial.test.cpp](tests/factorial.test.cpp) |
| ModInt | コンパイル時法による剰余演算 | [modint.hpp](src/math/modint.hpp) | [modint.test.cpp](tests/modint.test.cpp) |
| nCr | 二項係数の前計算 | [nCr.hpp](src/math/nCr.hpp) | [nCr.test.cpp](tests/nCr.test.cpp) |

多くのクラスと関数は `otukado` 名前空間に定義されています。利用可能な操作や境界条件の詳細は、各ヘッダーと検証コードを参照してください。

## 検証

すべてのライブラリを検証するには、リポジトリのルートで次を実行します。

```bash
oj-verify all
```

検証環境では GCC と Clang を使用し、いずれも `-std=gnu++23 -O2 -Wall -Wextra` を指定しています。`main` ブランチへの push と pull request では、GitHub Actions でも同じ検証を実行します。

## ディレクトリ構成

```text
.
├── src/                  # ライブラリ本体
│   ├── data-structure/
│   └── math/
├── tests/                # オンラインジャッジを使った検証コード
└── .verify-helper/
    └── config.toml       # 検証用コンパイラ設定
```

## ライセンス

このリポジトリは [CC0 1.0 Universal](LICENSE) のもとで公開されています。
