---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/trie.hpp
    title: src/data-structure/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP2_7_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP2_7_B
  bundledCode: "#line 1 \"tests/trie.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP2_7_B\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"src/data-structure/trie.hpp\"\
    \n#include <array>\n#include <vector>\n#line 5 \"src/data-structure/trie.hpp\"\
    \n\nnamespace otukado {\n\n\nstruct Node {\n    Node* parent = nullptr;\n    std::array<Node*,\
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
    \n\n} // namespace otukado\n#line 7 \"tests/trie.test.cpp\"\n\nstd::string encode(int\
    \ value) {\n    std::string result;\n    do {\n        result += static_cast<char>('a'\
    \ + value % 26);\n        value /= 26;\n    } while (value > 0);\n    return result;\n\
    }\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    std::cin >> n;\n\n    otukado::Trie trie;\n    while (n--) {\n\
    \        int type;\n        int value;\n        std::cin >> type >> value;\n \
    \       const std::string word = encode(value);\n\n        if (type == 0) {\n\
    \            trie.insert(word);\n            std::cout << trie.count_prefix(\"\
    \") << '\\n';\n        } else if (type == 1) {\n            std::cout << (trie.search(word)\
    \ == nullptr ? 0 : 1) << '\\n';\n        } else {\n            trie.erase(word);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP2_7_B\"\n\n\
    #include <iostream>\n#include <string>\n\n#include \"src/data-structure/trie.hpp\"\
    \n\nstd::string encode(int value) {\n    std::string result;\n    do {\n     \
    \   result += static_cast<char>('a' + value % 26);\n        value /= 26;\n   \
    \ } while (value > 0);\n    return result;\n}\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n\n    otukado::Trie\
    \ trie;\n    while (n--) {\n        int type;\n        int value;\n        std::cin\
    \ >> type >> value;\n        const std::string word = encode(value);\n\n     \
    \   if (type == 0) {\n            trie.insert(word);\n            std::cout <<\
    \ trie.count_prefix(\"\") << '\\n';\n        } else if (type == 1) {\n       \
    \     std::cout << (trie.search(word) == nullptr ? 0 : 1) << '\\n';\n        }\
    \ else {\n            trie.erase(word);\n        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/trie.hpp
  isVerificationFile: true
  path: tests/trie.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 10:31:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/trie.test.cpp
layout: document
redirect_from:
- /verify/tests/trie.test.cpp
- /verify/tests/trie.test.cpp.html
title: tests/trie.test.cpp
---
