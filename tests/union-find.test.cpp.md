---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/union-find.hpp
    title: src/data-structure/union-find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"tests/union-find.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <iostream>\n#line 2 \"src/data-structure/union-find.hpp\"\n#include<vector>\n\
    \nnamespace otukado {\n\n\nclass UnionFind {\nprivate:\n    std::vector<int> parents;\n\
    \    std::vector<int> sizes;\n    int group_num;\n\npublic:\n    UnionFind() =\
    \ delete;\n    UnionFind(int n) : group_num(n) {\n        parents.resize(n);\n\
    \        sizes.resize(n, 1);\n        for(int i = 0; i < n; ++i) parents[i] =\
    \ i;\n    };\n\n    int find (int x) {\n        if(parents[x] == x) return x;\n\
    \        return parents[x] = find(parents[x]); \n    }\n\n    bool connected (int\
    \ a, int b) {\n        return find(a) == find(b);\n    }\n\n    int size (int\
    \ a) {\n        return sizes[find(a)];\n    }\n\n    int groups() {\n        return\
    \ group_num;\n    }\n\n    bool merge (int a, int b) {\n        int root_a = find(a);\n\
    \        int root_b = find(b);\n        if(root_a == root_b) return false;\n\n\
    \        if(size(root_a) < size(root_b)) std::swap(root_a, root_b); // a \u306E\
    \u65B9\u3092\u5927\u304D\u304F\u3059\u308B\n\n        sizes[root_a] += sizes[root_b];\n\
    \        parents[root_b] = root_a;\n        group_num -= 1;\n        return true;\n\
    \    }\n};\n\n\n} // namespace otukado\n#line 5 \"tests/union-find.test.cpp\"\n\
    \nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    otukado::UnionFind uf(n);\n\n\
    \    for(int i=0; i<q; ++i) {\n        int t, u, v;\n        std::cin >> t >>\
    \ u >> v;\n\n        if (t == 0) {\n            uf.merge(u, v);\n        } else\
    \ {\n            std::cout << uf.connected(u, v) << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include \"src/data-structure/union-find.hpp\"\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n, q;\n    std::cin >> n >> q;\n\n    otukado::UnionFind uf(n);\n\n    for(int\
    \ i=0; i<q; ++i) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n\n\
    \        if (t == 0) {\n            uf.merge(u, v);\n        } else {\n      \
    \      std::cout << uf.connected(u, v) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/union-find.hpp
  isVerificationFile: true
  path: tests/union-find.test.cpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/union-find.test.cpp
layout: document
redirect_from:
- /verify/tests/union-find.test.cpp
- /verify/tests/union-find.test.cpp.html
title: tests/union-find.test.cpp
---
