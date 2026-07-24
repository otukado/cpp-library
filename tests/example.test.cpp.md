---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/binary-search.hpp
    title: src/data-structure/binary-search.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"tests/example.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"src/data-structure/binary-search.hpp\"\
    \n\n#include <cassert>\n#include <type_traits>\n\nnamespace otukado {\n\n\ntemplate<typename\
    \ T, typename F>\nT BinarySearch(T ng, T ok, F pred) {\n    assert(ng != ok);\n\
    \    T mid;\n    while(std::abs(ng - ok) > 1) {\n        mid = (ng + ok) / 2;\n\
    \n        if(pred(mid)) {\n            ok = mid;\n        } else {\n         \
    \   ng = mid;\n        }\n    }\n\n    return ok;\n}\n\n\n} // namespace otukado\n\
    #line 5 \"tests/example.test.cpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\nusing namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int>\
    \ s(n);\n    REP (i, n) {\n        cin >> s[i];\n    }\n    int q; cin >> q;\n\
    \    int cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        int\
    \ index = otukado::BinarySearch(-1, n, [&](int i) {\n            return s[i] >=\
    \ t_i;\n        });\n        cnt += index < n && s[index] == t_i;\n    }\n   \
    \ cout << cnt << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/data-structure/binary-search.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\nusing namespace std;\n\
    \nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n    REP (i, n) {\n\
    \        cin >> s[i];\n    }\n    int q; cin >> q;\n    int cnt = 0;\n    while\
    \ (q --) {\n        int t_i; cin >> t_i;\n        int index = otukado::BinarySearch(-1,\
    \ n, [&](int i) {\n            return s[i] >= t_i;\n        });\n        cnt +=\
    \ index < n && s[index] == t_i;\n    }\n    cout << cnt << endl;\n    return 0;\n\
    }\n"
  dependsOn:
  - src/data-structure/binary-search.hpp
  isVerificationFile: true
  path: tests/example.test.cpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/example.test.cpp
layout: document
redirect_from:
- /verify/tests/example.test.cpp
- /verify/tests/example.test.cpp.html
title: tests/example.test.cpp
---
