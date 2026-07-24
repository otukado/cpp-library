---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/prefix2d.hpp\"\n#include<vector>\n\n\
    namespace otukado {\n\n\ntemplate<typename T>\nclass Prefix2D {\nprivate:\n  \
    \  std::vector<std::vector<T>> data;\n    std::vector<std::vector<T>> prefix_data;\n\
    \    int h;\n    int w;\n    \npublic:\n    Prefix2D() = delete;\n    Prefix2D(std::vector<std::vector<T>>\
    \ _data) : data(_data){\n        assert(!data.empty());\n        h = data.size();\n\
    \        w = data[0].size();\n\n        prefix_data.resize(h + 1, std::vector<T>(w\
    \ + 1));\n        for(int i = 0; i < h; ++i) {\n            assert(w == data[i].size());\n\
    \            for(int j = 0; j < w; ++j) {\n                prefix_data[i + 1][j\
    \ + 1] = data[i][j];\n            }\n        }\n        calculate();\n    };\n\
    \n    void calculate(){\n        for(int i = 1; i <= h; ++i) {\n            for(int\
    \ j = 1; j <= w; ++j) {\n                prefix_data[i][j] += prefix_data[i][j-1];\
    \ // TODO: op\n            }\n        }\n        for(int j = 1; j <= w; ++j) {\n\
    \            for(int i = 1; i <= h; ++i) {\n                prefix_data[i][j]\
    \ += prefix_data[i-1][j];\n            }\n        }\n    }\n\n    // \u9589\u533A\
    \u9593\u3067\u6307\u5B9A\u3059\u308B\n    T get(int a, int b, int c, int d) {\n\
    \        assert(0 <= a && a < h);\n        assert(0 <= c && c < h);\n        assert(0\
    \ <= b && b < w);\n        assert(0 <= d && d < w);\n\n        assert(a <= c &&\
    \ b <= d);\n\n        return prefix_data[c + 1][d + 1] + prefix_data[a][b] - prefix_data[a][d\
    \ + 1] - prefix_data[c + 1][b];\n    }\n\n    auto data(){\n        return prefix_data;\n\
    \    }\n};\n\n\n} // namespace otukado\n"
  code: "#pragma once\n#include<vector>\n\nnamespace otukado {\n\n\ntemplate<typename\
    \ T>\nclass Prefix2D {\nprivate:\n    std::vector<std::vector<T>> data;\n    std::vector<std::vector<T>>\
    \ prefix_data;\n    int h;\n    int w;\n    \npublic:\n    Prefix2D() = delete;\n\
    \    Prefix2D(std::vector<std::vector<T>> _data) : data(_data){\n        assert(!data.empty());\n\
    \        h = data.size();\n        w = data[0].size();\n\n        prefix_data.resize(h\
    \ + 1, std::vector<T>(w + 1));\n        for(int i = 0; i < h; ++i) {\n       \
    \     assert(w == data[i].size());\n            for(int j = 0; j < w; ++j) {\n\
    \                prefix_data[i + 1][j + 1] = data[i][j];\n            }\n    \
    \    }\n        calculate();\n    };\n\n    void calculate(){\n        for(int\
    \ i = 1; i <= h; ++i) {\n            for(int j = 1; j <= w; ++j) {\n         \
    \       prefix_data[i][j] += prefix_data[i][j-1]; // TODO: op\n            }\n\
    \        }\n        for(int j = 1; j <= w; ++j) {\n            for(int i = 1;\
    \ i <= h; ++i) {\n                prefix_data[i][j] += prefix_data[i-1][j];\n\
    \            }\n        }\n    }\n\n    // \u9589\u533A\u9593\u3067\u6307\u5B9A\
    \u3059\u308B\n    T get(int a, int b, int c, int d) {\n        assert(0 <= a &&\
    \ a < h);\n        assert(0 <= c && c < h);\n        assert(0 <= b && b < w);\n\
    \        assert(0 <= d && d < w);\n\n        assert(a <= c && b <= d);\n\n   \
    \     return prefix_data[c + 1][d + 1] + prefix_data[a][b] - prefix_data[a][d\
    \ + 1] - prefix_data[c + 1][b];\n    }\n\n    auto data(){\n        return prefix_data;\n\
    \    }\n};\n\n\n} // namespace otukado\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/prefix2d.hpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/prefix2d.hpp
layout: document
redirect_from:
- /library/src/data-structure/prefix2d.hpp
- /library/src/data-structure/prefix2d.hpp.html
title: src/data-structure/prefix2d.hpp
---
