---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/example.test.cpp
    title: tests/example.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/binary-search.hpp\"\n\n#include <cassert>\n\
    #include <type_traits>\n\nnamespace otukado {\n\n\ntemplate<typename T, typename\
    \ F>\nT BinarySearch(T ng, T ok, F pred) {\n    assert(ng != ok);\n    T mid;\n\
    \    while(std::abs(ng - ok) > 1) {\n        mid = (ng + ok) / 2;\n\n        if(pred(mid))\
    \ {\n            ok = mid;\n        } else {\n            ng = mid;\n        }\n\
    \    }\n\n    return ok;\n}\n\n\n} // namespace otukado\n"
  code: "#pragma once\n\n#include <cassert>\n#include <type_traits>\n\nnamespace otukado\
    \ {\n\n\ntemplate<typename T, typename F>\nT BinarySearch(T ng, T ok, F pred)\
    \ {\n    assert(ng != ok);\n    T mid;\n    while(std::abs(ng - ok) > 1) {\n \
    \       mid = (ng + ok) / 2;\n\n        if(pred(mid)) {\n            ok = mid;\n\
    \        } else {\n            ng = mid;\n        }\n    }\n\n    return ok;\n\
    }\n\n\n} // namespace otukado\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/binary-search.hpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/example.test.cpp
documentation_of: src/data-structure/binary-search.hpp
layout: document
redirect_from:
- /library/src/data-structure/binary-search.hpp
- /library/src/data-structure/binary-search.hpp.html
title: src/data-structure/binary-search.hpp
---
