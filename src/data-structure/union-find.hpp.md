---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/union-find.test.cpp
    title: tests/union-find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/union-find.hpp\"\n#include<vector>\n\n\
    namespace otukado {\n\n\nclass UnionFind {\nprivate:\n    std::vector<int> parents;\n\
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
    \    }\n};\n\n\n} // namespace otukado\n"
  code: "#pragma once\n#include<vector>\n\nnamespace otukado {\n\n\nclass UnionFind\
    \ {\nprivate:\n    std::vector<int> parents;\n    std::vector<int> sizes;\n  \
    \  int group_num;\n\npublic:\n    UnionFind() = delete;\n    UnionFind(int n)\
    \ : group_num(n) {\n        parents.resize(n);\n        sizes.resize(n, 1);\n\
    \        for(int i = 0; i < n; ++i) parents[i] = i;\n    };\n\n    int find (int\
    \ x) {\n        if(parents[x] == x) return x;\n        return parents[x] = find(parents[x]);\
    \ \n    }\n\n    bool connected (int a, int b) {\n        return find(a) == find(b);\n\
    \    }\n\n    int size (int a) {\n        return sizes[find(a)];\n    }\n\n  \
    \  int groups() {\n        return group_num;\n    }\n\n    bool merge (int a,\
    \ int b) {\n        int root_a = find(a);\n        int root_b = find(b);\n   \
    \     if(root_a == root_b) return false;\n\n        if(size(root_a) < size(root_b))\
    \ std::swap(root_a, root_b); // a \u306E\u65B9\u3092\u5927\u304D\u304F\u3059\u308B\
    \n\n        sizes[root_a] += sizes[root_b];\n        parents[root_b] = root_a;\n\
    \        group_num -= 1;\n        return true;\n    }\n};\n\n\n} // namespace\
    \ otukado"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/union-find.hpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/union-find.test.cpp
documentation_of: src/data-structure/union-find.hpp
layout: document
redirect_from:
- /library/src/data-structure/union-find.hpp
- /library/src/data-structure/union-find.hpp.html
title: src/data-structure/union-find.hpp
---
