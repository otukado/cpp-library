#pragma once
#include <string>
#include <vector>
#include <list>
#include <optional>
#include <cstdint>

using u64 = std::uint64_t;

u64 calculate_hash(std::string);

// T と BUCKET_SIZE を指定する
template<typename K, typename V>
struct HashTable {
    // size によって動的に HashTable 内でサイズを変更したい
    vector<list<pair<K, V>>> table = vector<list<pair<K, V>>>(3);
    int _size;
    inline static vector<u64> primes = {2}; // 全ての HashTable で共有したい
    inline static vector<bool> is_prime;


    bool put(K key, V value) {
        for(auto & element : this->get_bucket(key)) {
            if(element.first == key) {
                element.second = value;
                return false;
            }
        }
        this->get_bucket(key).emplace_back(key, value);
        ++this->_size;
        resize();
        return true;
    };

    // key がなければ nullopt を返す(error 投げない)
    optional<V> get(K key) {
        for(const auto & element : this->get_bucket(key)) {
            if(element.first == key) return element.second;
        }
        return nullopt;
    };

    bool erase(K key) {
        auto & _table = get_bucket(key);
        // iterator で回す
        for(auto it = _table.begin(); it != _table.end(); ++it) {
            if(key == it->first) {
                _table.erase(it); // key と一致したら削除、list だから O(1)
                --this->_size;
                resize();
                return true;
            }
        }
        return false;
    };

    int size() {
        return this->_size;
    }
    int bucket_size() {
        return this->table.size();
    }

    void resize() {
        if(!(3 * this->size() > 2 * this->bucket_size() || this->size() * 5 < this->bucket_size())) return; // TODO: resize する条件を考える
        // primes から bucket_size を決定する
        if((int) primes.back() < (int) this->size() * 5) expand_prime((int) this->size() * 10); // TODO: 素数表をいつ大きくするか考える
         
        const int x = *(lower_bound(this->primes.begin(), this->primes.end(), this->size() * 3)); // TODO: size の何倍にするか考える
        auto copied = this->table;
        this->table.clear();
        this->table.resize(x);
        cout << x << '\n';
        // copied から resize した table に詰め直す
        for(const auto & bucket : copied) {
            for(const auto & element : bucket) {
                get_bucket(element.first).push_back(element);
            }
        }
    };

    // 素数表を大きくする、エラトステネスの篩
    void expand_prime(int next_size) {
        // int sz = is_prime.size();
        int max_prime = primes.back();
        is_prime.resize(next_size+1, true);

        for(int i=2; i<=next_size; ++i) {
            if(is_prime[i] || i == 2) {
                if(max_prime < i) {
                    primes.push_back(i);
                }
                for(int j = max(2, max_prime / i); i * j <= next_size; ++j) {
                    is_prime[i * j] = false;
                }
            }
        }
    }

    // hash を計算し、mod を取る
    u64 calculate_hash(K key) {
        u64 hash = ::calculate_hash(key) % this->bucket_size();
        return hash;
    }
    
    // key に対応する bucket を返す関数
    auto & get_bucket(K key) {
        u64 hash = calculate_hash(key);
        return this->table[hash];
    }
};

// hash 計算の本体。外にあるべき。string 用
u64 calculate_hash(std::string key) {
    u64 hash = 0;
    for(const auto & c : key) {
        hash += c - 'a'; // TODO: hash 計算考える
    }
    return hash;
};