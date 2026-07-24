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
  bundledCode: "#line 2 \"src/data-structure/trie.hpp\"\n#include <array>\n#include\
    \ <vector>\n#include <string>\n\nnamespace otukado {\n\n\nstruct Node {\n    Node*\
    \ parent = nullptr;\n    std::array<Node*, 26> children{};\n\n    char alphabet\
    \ = '$';\n    char num = 0;\n    bool is_end = false;\n\n    Node() = default;\n\
    \    Node(Node* par, char alp) : parent(par), alphabet(alp) {}\n\n    ~Node()\
    \ {\n        for(auto& child : this->children) {\n            delete child;\n\
    \        }\n    }\n};\n\nstruct Trie {\n    Node* root = new Node();\n\n    ~Trie()\
    \ {\n        delete this->root;\n    }\n\n    void insert (std::string word) {\n\
    \        auto curr = this->root;\n        for(const auto& c: word) {\n       \
    \     if(curr->children[c-'a'] == nullptr) {\n                curr->children[c-'a']\
    \ = new Node(curr, c);\n            }\n            curr = curr->children[c-'a'];\n\
    \        }\n        if(curr->is_end) return;\n        curr->is_end = true;\n \
    \       while(curr != this->root) {\n            ++curr->num;\n            curr\
    \ = curr->parent;\n        }\n        ++curr->num;\n    }\n\n    // \u898B\u3064\
    \u304B\u3089\u306A\u3051\u308C\u3070 nullptr \u3092\u8FD4\u3059\n    Node* search(std::string\
    \ word) {\n        auto curr = this->root;\n        for(const char& c : word)\
    \ {\n            if(curr->children[c-'a'] == nullptr) return nullptr;\n      \
    \      curr = curr->children[c - 'a'];\n        }\n        return curr->is_end\
    \ ? curr : nullptr;\n    }\n\n    // \u6307\u5B9A\u3057\u305F word \u3092\u524A\
    \u9664\n    void erase (std::string word) {\n        auto end = search(word);\n\
    \        if(end == nullptr) return;\n        auto curr = end;\n        curr->is_end\
    \ = false;\n        while(curr != this->root) {\n            if(curr->num == 1)\
    \ {\n                auto parent = curr->parent;\n                parent->children[curr->alphabet\
    \ - 'a'] = nullptr;\n                delete curr;\n                curr = parent;\n\
    \            } else {\n                --curr->num;\n                curr = curr->parent;\n\
    \            } \n        }\n    };\n\n    int count_prefix(std::string perfix)\
    \ {\n        auto curr = this->root;\n        for(const char& c : perfix) {\n\
    \            if(curr->children[c-'a'] == nullptr) return 0;\n            curr\
    \ = curr->children[c - 'a'];\n        }\n        return curr->num;\n    }\n};\n\
    \n\n} // namespace otukado\n\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include <string>\n\n\
    namespace otukado {\n\n\nstruct Node {\n    Node* parent = nullptr;\n    std::array<Node*,\
    \ 26> children{};\n\n    char alphabet = '$';\n    char num = 0;\n    bool is_end\
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
    \        } \n        }\n    };\n\n    int count_prefix(std::string perfix) {\n\
    \        auto curr = this->root;\n        for(const char& c : perfix) {\n    \
    \        if(curr->children[c-'a'] == nullptr) return 0;\n            curr = curr->children[c\
    \ - 'a'];\n        }\n        return curr->num;\n    }\n};\n\n\n} // namespace\
    \ otukado\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/trie.hpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/trie.hpp
layout: document
redirect_from:
- /library/src/data-structure/trie.hpp
- /library/src/data-structure/trie.hpp.html
title: src/data-structure/trie.hpp
---
