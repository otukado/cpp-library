---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/prefix2d.hpp
    title: src/data-structure/prefix2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B
  bundledCode: "#line 1 \"tests/prefix2d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 2 \"\
    src/data-structure/prefix2d.hpp\"\n\n#include <cassert>\n#line 5 \"src/data-structure/prefix2d.hpp\"\
    \n\nnamespace otukado {\n\n\ntemplate<typename T>\nclass Prefix2D {\nprivate:\n\
    \    std::vector<std::vector<T>> raw_data;\n    std::vector<std::vector<T>> prefix_data;\n\
    \    int h;\n    int w;\n    \npublic:\n    Prefix2D() = delete;\n    Prefix2D(std::vector<std::vector<T>>\
    \ _data) : raw_data(_data){\n        assert(!raw_data.empty());\n        h = raw_data.size();\n\
    \        w = raw_data[0].size();\n\n        prefix_data.resize(h + 1, std::vector<T>(w\
    \ + 1));\n        for(int i = 0; i < h; ++i) {\n            assert(w == static_cast<int>(raw_data[i].size()));\n\
    \            for(int j = 0; j < w; ++j) {\n                prefix_data[i + 1][j\
    \ + 1] = raw_data[i][j];\n            }\n        }\n        calculate();\n   \
    \ };\n\n    void calculate(){\n        for(int i = 1; i <= h; ++i) {\n       \
    \     for(int j = 1; j <= w; ++j) {\n                prefix_data[i][j] += prefix_data[i][j-1];\
    \ // TODO: op\n            }\n        }\n        for(int j = 1; j <= w; ++j) {\n\
    \            for(int i = 1; i <= h; ++i) {\n                prefix_data[i][j]\
    \ += prefix_data[i-1][j];\n            }\n        }\n    }\n\n    // \u9589\u533A\
    \u9593\u3067\u6307\u5B9A\u3059\u308B\n    T get(int a, int b, int c, int d) {\n\
    \        assert(0 <= a && a < h);\n        assert(0 <= c && c < h);\n        assert(0\
    \ <= b && b < w);\n        assert(0 <= d && d < w);\n\n        assert(a <= c &&\
    \ b <= d);\n\n        return prefix_data[c + 1][d + 1] + prefix_data[a][b] - prefix_data[a][d\
    \ + 1] - prefix_data[c + 1][b];\n    }\n\n    auto data() const {\n        return\
    \ prefix_data;\n    }\n};\n\n\n} // namespace otukado\n#line 8 \"tests/prefix2d.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    constexpr int coordinate_limit = 1000;\n    std::vector<std::vector<int>>\
    \ difference(\n        coordinate_limit + 1,\n        std::vector<int>(coordinate_limit\
    \ + 1)\n    );\n\n    int n;\n    std::cin >> n;\n    while (n--) {\n        int\
    \ x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >> y2;\n\n        ++difference[x1][y1];\n\
    \        --difference[x2][y1];\n        --difference[x1][y2];\n        ++difference[x2][y2];\n\
    \    }\n\n    otukado::Prefix2D<int> prefix(difference);\n\n    int answer = 0;\n\
    \    for (int x = 0; x < coordinate_limit; ++x) {\n        for (int y = 0; y <\
    \ coordinate_limit; ++y) {\n            answer = std::max(answer, prefix.get(0,\
    \ 0, x, y));\n        }\n    }\n    std::cout << answer << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B\"\n\n\
    #include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"src/data-structure/prefix2d.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    constexpr int coordinate_limit = 1000;\n    std::vector<std::vector<int>>\
    \ difference(\n        coordinate_limit + 1,\n        std::vector<int>(coordinate_limit\
    \ + 1)\n    );\n\n    int n;\n    std::cin >> n;\n    while (n--) {\n        int\
    \ x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >> y2;\n\n        ++difference[x1][y1];\n\
    \        --difference[x2][y1];\n        --difference[x1][y2];\n        ++difference[x2][y2];\n\
    \    }\n\n    otukado::Prefix2D<int> prefix(difference);\n\n    int answer = 0;\n\
    \    for (int x = 0; x < coordinate_limit; ++x) {\n        for (int y = 0; y <\
    \ coordinate_limit; ++y) {\n            answer = std::max(answer, prefix.get(0,\
    \ 0, x, y));\n        }\n    }\n    std::cout << answer << '\\n';\n}\n"
  dependsOn:
  - src/data-structure/prefix2d.hpp
  isVerificationFile: true
  path: tests/prefix2d.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/prefix2d.test.cpp
layout: document
redirect_from:
- /verify/tests/prefix2d.test.cpp
- /verify/tests/prefix2d.test.cpp.html
title: tests/prefix2d.test.cpp
---
