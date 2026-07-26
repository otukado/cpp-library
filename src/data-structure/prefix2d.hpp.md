---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/prefix2d.test.cpp
    title: tests/prefix2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/prefix2d.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace otukado {\n\n\ntemplate<typename T>\nclass Prefix2D\
    \ {\nprivate:\n    std::vector<std::vector<T>> raw_data;\n    std::vector<std::vector<T>>\
    \ prefix_data;\n    int h;\n    int w;\n    \npublic:\n    Prefix2D() = delete;\n\
    \    Prefix2D(std::vector<std::vector<T>> _data) : raw_data(_data){\n        assert(!raw_data.empty());\n\
    \        h = raw_data.size();\n        w = raw_data[0].size();\n\n        prefix_data.resize(h\
    \ + 1, std::vector<T>(w + 1));\n        for(int i = 0; i < h; ++i) {\n       \
    \     assert(w == static_cast<int>(raw_data[i].size()));\n            for(int\
    \ j = 0; j < w; ++j) {\n                prefix_data[i + 1][j + 1] = raw_data[i][j];\n\
    \            }\n        }\n        calculate();\n    };\n\n    void calculate(){\n\
    \        for(int i = 1; i <= h; ++i) {\n            for(int j = 1; j <= w; ++j)\
    \ {\n                prefix_data[i][j] += prefix_data[i][j-1]; // TODO: op\n \
    \           }\n        }\n        for(int j = 1; j <= w; ++j) {\n            for(int\
    \ i = 1; i <= h; ++i) {\n                prefix_data[i][j] += prefix_data[i-1][j];\n\
    \            }\n        }\n    }\n\n    // \u9589\u533A\u9593\u3067\u6307\u5B9A\
    \u3059\u308B\n    T get(int a, int b, int c, int d) {\n        assert(0 <= a &&\
    \ a < h);\n        assert(0 <= c && c < h);\n        assert(0 <= b && b < w);\n\
    \        assert(0 <= d && d < w);\n\n        assert(a <= c && b <= d);\n\n   \
    \     return prefix_data[c + 1][d + 1] + prefix_data[a][b] - prefix_data[a][d\
    \ + 1] - prefix_data[c + 1][b];\n    }\n\n    auto data() const {\n        return\
    \ prefix_data;\n    }\n};\n\n\n} // namespace otukado\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace otukado\
    \ {\n\n\ntemplate<typename T>\nclass Prefix2D {\nprivate:\n    std::vector<std::vector<T>>\
    \ raw_data;\n    std::vector<std::vector<T>> prefix_data;\n    int h;\n    int\
    \ w;\n    \npublic:\n    Prefix2D() = delete;\n    Prefix2D(std::vector<std::vector<T>>\
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
    \ prefix_data;\n    }\n};\n\n\n} // namespace otukado\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/prefix2d.hpp
  requiredBy: []
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/prefix2d.test.cpp
documentation_of: src/data-structure/prefix2d.hpp
layout: document
redirect_from:
- /library/src/data-structure/prefix2d.hpp
- /library/src/data-structure/prefix2d.hpp.html
title: src/data-structure/prefix2d.hpp
---
