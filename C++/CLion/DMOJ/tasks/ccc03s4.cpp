#include "../library/lib.hpp"
#include <bits/stdc++.h>

using namespace std;

#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

class TrieNode {
public:
    bool is_leaf;
    map<char, TrieNode *> children;
    TrieNode() { is_leaf = false; }
    ~TrieNode() {
        for (auto const &i : children) {
            delete i.second;
        }
    }
    void insert_suffix(string s) {
        if (s.length() > 0) {
            if (children.find(s[0]) == children.end()) {
                children[s[0]] = new TrieNode();
            }
            children[s[0]]->insert_suffix(s.substr(1));
        }
        is_leaf = true;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie(TrieNode *a) { this->root = a; }
    ~Trie() { delete root; }
    void insert(string s) {
        map<char, TrieNode *>::iterator it;
        TrieNode *node = root;
        up(i, s.length()) {
            if (node->children.find(s[i]) == node->children.end()) {
                node->children[s[i]] = new TrieNode();
            }
            node = node->children[s[i]];
        }
        node->is_leaf = true;
    }
    bool search(string s) {
        map<char, TrieNode *>::iterator it;
        TrieNode *node = root;
        up(i, s.length()) {
            char c = s[i];
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[s[i]];
        }
        return node != nullptr && node->is_leaf;
    }
    int count_nodes(TrieNode *node) {
        int res = 0;
        if (node->is_leaf)
            ++res;
        for (auto i : node->children) {
            res += count_nodes(i.second);
        }
        return res;
    }
};

class ccc03s4 {
public:
    void solve(std::istream& in, std::ostream& out) {
        int N;
        string str;
        in >> N;
        up(i, N) {
            in >> str;
            auto *node = new TrieNode();
            Trie *trie = new Trie(node);
            up(i, str.length()) {
                trie->root->insert_suffix(str.substr(i));
            }
            out << trie->count_nodes(trie->root) << endl;
            for (auto i : trie->root->children) {
                delete i.second;
            }
        }
    }
};
