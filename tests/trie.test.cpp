#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP2_7_B"

#include <iostream>
#include <string>

#include "src/data-structure/trie.hpp"

std::string encode(int value) {
    std::string result;
    do {
        result += static_cast<char>('a' + value % 26);
        value /= 26;
    } while (value > 0);
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    otukado::Trie trie;
    while (n--) {
        int type;
        int value;
        std::cin >> type >> value;
        const std::string word = encode(value);

        if (type == 0) {
            trie.insert(word);
            std::cout << trie.count_prefix("") << '\n';
        } else if (type == 1) {
            std::cout << (trie.search(word) == nullptr ? 0 : 1) << '\n';
        } else {
            trie.erase(word);
        }
    }
}
