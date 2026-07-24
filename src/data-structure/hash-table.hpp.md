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
  bundledCode: "#line 2 \"src/data-structure/hash-table.hpp\"\n#include <string>\n\
    #include <vector>\n#include <list>\n#include <optional>\n#include <cstdint>\n\n\
    using u64 = std::uint64_t;\n\nu64 calculate_hash(std::string);\n\n// T \u3068\
    \ BUCKET_SIZE \u3092\u6307\u5B9A\u3059\u308B\ntemplate<typename K, typename V>\n\
    struct HashTable {\n    // size \u306B\u3088\u3063\u3066\u52D5\u7684\u306B HashTable\
    \ \u5185\u3067\u30B5\u30A4\u30BA\u3092\u5909\u66F4\u3057\u305F\u3044\n    vector<list<pair<K,\
    \ V>>> table = vector<list<pair<K, V>>>(3);\n    int _size;\n    inline static\
    \ vector<u64> primes = {2}; // \u5168\u3066\u306E HashTable \u3067\u5171\u6709\
    \u3057\u305F\u3044\n    inline static vector<bool> is_prime;\n\n\n    bool put(K\
    \ key, V value) {\n        for(auto & element : this->get_bucket(key)) {\n   \
    \         if(element.first == key) {\n                element.second = value;\n\
    \                return false;\n            }\n        }\n        this->get_bucket(key).emplace_back(key,\
    \ value);\n        ++this->_size;\n        resize();\n        return true;\n \
    \   };\n\n    // key \u304C\u306A\u3051\u308C\u3070 nullopt \u3092\u8FD4\u3059\
    (error \u6295\u3052\u306A\u3044)\n    optional<V> get(K key) {\n        for(const\
    \ auto & element : this->get_bucket(key)) {\n            if(element.first == key)\
    \ return element.second;\n        }\n        return nullopt;\n    };\n\n    bool\
    \ erase(K key) {\n        auto & _table = get_bucket(key);\n        // iterator\
    \ \u3067\u56DE\u3059\n        for(auto it = _table.begin(); it != _table.end();\
    \ ++it) {\n            if(key == it->first) {\n                _table.erase(it);\
    \ // key \u3068\u4E00\u81F4\u3057\u305F\u3089\u524A\u9664\u3001list \u3060\u304B\
    \u3089 O(1)\n                --this->_size;\n                resize();\n     \
    \           return true;\n            }\n        }\n        return false;\n  \
    \  };\n\n    int size() {\n        return this->_size;\n    }\n    int bucket_size()\
    \ {\n        return this->table.size();\n    }\n\n    void resize() {\n      \
    \  if(!(3 * this->size() > 2 * this->bucket_size() || this->size() * 5 < this->bucket_size()))\
    \ return; // TODO: resize \u3059\u308B\u6761\u4EF6\u3092\u8003\u3048\u308B\n \
    \       // primes \u304B\u3089 bucket_size \u3092\u6C7A\u5B9A\u3059\u308B\n  \
    \      if((int) primes.back() < (int) this->size() * 5) expand_prime((int) this->size()\
    \ * 10); // TODO: \u7D20\u6570\u8868\u3092\u3044\u3064\u5927\u304D\u304F\u3059\
    \u308B\u304B\u8003\u3048\u308B\n         \n        const int x = *(lower_bound(this->primes.begin(),\
    \ this->primes.end(), this->size() * 3)); // TODO: size \u306E\u4F55\u500D\u306B\
    \u3059\u308B\u304B\u8003\u3048\u308B\n        auto copied = this->table;\n   \
    \     this->table.clear();\n        this->table.resize(x);\n        cout << x\
    \ << '\\n';\n        // copied \u304B\u3089 resize \u3057\u305F table \u306B\u8A70\
    \u3081\u76F4\u3059\n        for(const auto & bucket : copied) {\n            for(const\
    \ auto & element : bucket) {\n                get_bucket(element.first).push_back(element);\n\
    \            }\n        }\n    };\n\n    // \u7D20\u6570\u8868\u3092\u5927\u304D\
    \u304F\u3059\u308B\u3001\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    \n    void expand_prime(int next_size) {\n        // int sz = is_prime.size();\n\
    \        int max_prime = primes.back();\n        is_prime.resize(next_size+1,\
    \ true);\n\n        for(int i=2; i<=next_size; ++i) {\n            if(is_prime[i]\
    \ || i == 2) {\n                if(max_prime < i) {\n                    primes.push_back(i);\n\
    \                }\n                for(int j = max(2, max_prime / i); i * j <=\
    \ next_size; ++j) {\n                    is_prime[i * j] = false;\n          \
    \      }\n            }\n        }\n    }\n\n    // hash \u3092\u8A08\u7B97\u3057\
    \u3001mod \u3092\u53D6\u308B\n    u64 calculate_hash(K key) {\n        u64 hash\
    \ = ::calculate_hash(key) % this->bucket_size();\n        return hash;\n    }\n\
    \    \n    // key \u306B\u5BFE\u5FDC\u3059\u308B bucket \u3092\u8FD4\u3059\u95A2\
    \u6570\n    auto & get_bucket(K key) {\n        u64 hash = calculate_hash(key);\n\
    \        return this->table[hash];\n    }\n};\n\n// hash \u8A08\u7B97\u306E\u672C\
    \u4F53\u3002\u5916\u306B\u3042\u308B\u3079\u304D\u3002string \u7528\nu64 calculate_hash(std::string\
    \ key) {\n    u64 hash = 0;\n    for(const auto & c : key) {\n        hash +=\
    \ c - 'a'; // TODO: hash \u8A08\u7B97\u8003\u3048\u308B\n    }\n    return hash;\n\
    };\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n#include <list>\n#include\
    \ <optional>\n#include <cstdint>\n\nusing u64 = std::uint64_t;\n\nu64 calculate_hash(std::string);\n\
    \n// T \u3068 BUCKET_SIZE \u3092\u6307\u5B9A\u3059\u308B\ntemplate<typename K,\
    \ typename V>\nstruct HashTable {\n    // size \u306B\u3088\u3063\u3066\u52D5\u7684\
    \u306B HashTable \u5185\u3067\u30B5\u30A4\u30BA\u3092\u5909\u66F4\u3057\u305F\u3044\
    \n    vector<list<pair<K, V>>> table = vector<list<pair<K, V>>>(3);\n    int _size;\n\
    \    inline static vector<u64> primes = {2}; // \u5168\u3066\u306E HashTable \u3067\
    \u5171\u6709\u3057\u305F\u3044\n    inline static vector<bool> is_prime;\n\n\n\
    \    bool put(K key, V value) {\n        for(auto & element : this->get_bucket(key))\
    \ {\n            if(element.first == key) {\n                element.second =\
    \ value;\n                return false;\n            }\n        }\n        this->get_bucket(key).emplace_back(key,\
    \ value);\n        ++this->_size;\n        resize();\n        return true;\n \
    \   };\n\n    // key \u304C\u306A\u3051\u308C\u3070 nullopt \u3092\u8FD4\u3059\
    (error \u6295\u3052\u306A\u3044)\n    optional<V> get(K key) {\n        for(const\
    \ auto & element : this->get_bucket(key)) {\n            if(element.first == key)\
    \ return element.second;\n        }\n        return nullopt;\n    };\n\n    bool\
    \ erase(K key) {\n        auto & _table = get_bucket(key);\n        // iterator\
    \ \u3067\u56DE\u3059\n        for(auto it = _table.begin(); it != _table.end();\
    \ ++it) {\n            if(key == it->first) {\n                _table.erase(it);\
    \ // key \u3068\u4E00\u81F4\u3057\u305F\u3089\u524A\u9664\u3001list \u3060\u304B\
    \u3089 O(1)\n                --this->_size;\n                resize();\n     \
    \           return true;\n            }\n        }\n        return false;\n  \
    \  };\n\n    int size() {\n        return this->_size;\n    }\n    int bucket_size()\
    \ {\n        return this->table.size();\n    }\n\n    void resize() {\n      \
    \  if(!(3 * this->size() > 2 * this->bucket_size() || this->size() * 5 < this->bucket_size()))\
    \ return; // TODO: resize \u3059\u308B\u6761\u4EF6\u3092\u8003\u3048\u308B\n \
    \       // primes \u304B\u3089 bucket_size \u3092\u6C7A\u5B9A\u3059\u308B\n  \
    \      if((int) primes.back() < (int) this->size() * 5) expand_prime((int) this->size()\
    \ * 10); // TODO: \u7D20\u6570\u8868\u3092\u3044\u3064\u5927\u304D\u304F\u3059\
    \u308B\u304B\u8003\u3048\u308B\n         \n        const int x = *(lower_bound(this->primes.begin(),\
    \ this->primes.end(), this->size() * 3)); // TODO: size \u306E\u4F55\u500D\u306B\
    \u3059\u308B\u304B\u8003\u3048\u308B\n        auto copied = this->table;\n   \
    \     this->table.clear();\n        this->table.resize(x);\n        cout << x\
    \ << '\\n';\n        // copied \u304B\u3089 resize \u3057\u305F table \u306B\u8A70\
    \u3081\u76F4\u3059\n        for(const auto & bucket : copied) {\n            for(const\
    \ auto & element : bucket) {\n                get_bucket(element.first).push_back(element);\n\
    \            }\n        }\n    };\n\n    // \u7D20\u6570\u8868\u3092\u5927\u304D\
    \u304F\u3059\u308B\u3001\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    \n    void expand_prime(int next_size) {\n        // int sz = is_prime.size();\n\
    \        int max_prime = primes.back();\n        is_prime.resize(next_size+1,\
    \ true);\n\n        for(int i=2; i<=next_size; ++i) {\n            if(is_prime[i]\
    \ || i == 2) {\n                if(max_prime < i) {\n                    primes.push_back(i);\n\
    \                }\n                for(int j = max(2, max_prime / i); i * j <=\
    \ next_size; ++j) {\n                    is_prime[i * j] = false;\n          \
    \      }\n            }\n        }\n    }\n\n    // hash \u3092\u8A08\u7B97\u3057\
    \u3001mod \u3092\u53D6\u308B\n    u64 calculate_hash(K key) {\n        u64 hash\
    \ = ::calculate_hash(key) % this->bucket_size();\n        return hash;\n    }\n\
    \    \n    // key \u306B\u5BFE\u5FDC\u3059\u308B bucket \u3092\u8FD4\u3059\u95A2\
    \u6570\n    auto & get_bucket(K key) {\n        u64 hash = calculate_hash(key);\n\
    \        return this->table[hash];\n    }\n};\n\n// hash \u8A08\u7B97\u306E\u672C\
    \u4F53\u3002\u5916\u306B\u3042\u308B\u3079\u304D\u3002string \u7528\nu64 calculate_hash(std::string\
    \ key) {\n    u64 hash = 0;\n    for(const auto & c : key) {\n        hash +=\
    \ c - 'a'; // TODO: hash \u8A08\u7B97\u8003\u3048\u308B\n    }\n    return hash;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/hash-table.hpp
  requiredBy: []
  timestamp: '2026-07-24 12:16:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/hash-table.hpp
layout: document
redirect_from:
- /library/src/data-structure/hash-table.hpp
- /library/src/data-structure/hash-table.hpp.html
title: src/data-structure/hash-table.hpp
---
