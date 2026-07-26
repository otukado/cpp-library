#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP2_8_B"

#include <iostream>
#include <string>

#include "src/data-structure/hash-table.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;

    HashTable<std::string, int> table;
    while (q--) {
        int type;
        std::string key;
        std::cin >> type >> key;

        if (type == 0) {
            int value;
            std::cin >> value;
            table.put(key, value);
        } else if (type == 1) {
            std::cout << table.get(key).value_or(0) << '\n';
        } else {
            table.erase(key);
        }
    }
}
