#pragma once
#include <array>
#include <vector>
#include <string>

namespace otukado {


struct Node {
    Node* parent = nullptr;
    std::array<Node*, 26> children{};

    char alphabet = '$';
    char num = 0;
    bool is_end = false;

    Node() = default;
    Node(Node* par, char alp) : parent(par), alphabet(alp) {}

    ~Node() {
        for(auto& child : this->children) {
            delete child;
        }
    }
};

struct Trie {
    Node* root = new Node();

    ~Trie() {
        delete this->root;
    }

    void insert (std::string word) {
        auto curr = this->root;
        for(const auto& c: word) {
            if(curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new Node(curr, c);
            }
            curr = curr->children[c-'a'];
        }
        if(curr->is_end) return;
        curr->is_end = true;
        while(curr != this->root) {
            ++curr->num;
            curr = curr->parent;
        }
        ++curr->num;
    }

    // 見つからなければ nullptr を返す
    Node* search(std::string word) {
        auto curr = this->root;
        for(const char& c : word) {
            if(curr->children[c-'a'] == nullptr) return nullptr;
            curr = curr->children[c - 'a'];
        }
        return curr->is_end ? curr : nullptr;
    }

    // 指定した word を削除
    void erase (std::string word) {
        auto end = search(word);
        if(end == nullptr) return;
        auto curr = end;
        curr->is_end = false;
        while(curr != this->root) {
            if(curr->num == 1) {
                auto parent = curr->parent;
                parent->children[curr->alphabet - 'a'] = nullptr;
                delete curr;
                curr = parent;
            } else {
                --curr->num;
                curr = curr->parent;
            } 
        }
    };

    int count_prefix(std::string perfix) {
        auto curr = this->root;
        for(const char& c : perfix) {
            if(curr->children[c-'a'] == nullptr) return 0;
            curr = curr->children[c - 'a'];
        }
        return curr->num;
    }
};


} // namespace otukado

