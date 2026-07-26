---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"tests/segment-tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#include <iostream>\n#line 2 \"src/data-structure/segment-tree.hpp\"\n#include<vector>\n\
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
    };\n\n} // namespace otukado\n#line 5 \"tests/segment-tree.test.cpp\"\n\nlong\
    \ long add(long long a, long long b) {\n    return a + b;\n}\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n, q;\n    std::cin >> n >> q;\n\n    otukado::SegmentTree<long long, 0LL, add>\
    \ seg(n);\n\n    for (int i = 0; i < n; ++i) {\n        long long x;\n       \
    \ std::cin >> x;\n        seg[i] = x;\n    }\n\n    while (q--) {\n        int\
    \ type;\n        std::cin >> type;\n\n        if (type == 0) {\n            int\
    \ p;\n            long long x;\n            std::cin >> p >> x;\n            seg[p]\
    \ = seg[p] + x;\n        } else {\n            int l, r;\n            std::cin\
    \ >> l >> r;\n            std::cout << seg.range(l, r) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include \"src/data-structure/segment-tree.hpp\"\n\nlong\
    \ long add(long long a, long long b) {\n    return a + b;\n}\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n, q;\n    std::cin >> n >> q;\n\n    otukado::SegmentTree<long long, 0LL, add>\
    \ seg(n);\n\n    for (int i = 0; i < n; ++i) {\n        long long x;\n       \
    \ std::cin >> x;\n        seg[i] = x;\n    }\n\n    while (q--) {\n        int\
    \ type;\n        std::cin >> type;\n\n        if (type == 0) {\n            int\
    \ p;\n            long long x;\n            std::cin >> p >> x;\n            seg[p]\
    \ = seg[p] + x;\n        } else {\n            int l, r;\n            std::cin\
    \ >> l >> r;\n            std::cout << seg.range(l, r) << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - src/data-structure/segment-tree.hpp
  isVerificationFile: true
  path: tests/segment-tree.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/segment-tree.test.cpp
layout: document
redirect_from:
- /verify/tests/segment-tree.test.cpp
- /verify/tests/segment-tree.test.cpp.html
title: tests/segment-tree.test.cpp
---
