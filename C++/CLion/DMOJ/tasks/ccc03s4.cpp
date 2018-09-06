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
        TrieNode *node = root;
        up(i, s.length()) {
            if (node->children.find(s[i]) == node->children.end()) {
                node->children[s[i]] = new TrieNode();
            }
            node = node->children[s[i]];
        }
        node->is_leaf = true;
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
const int MAX_CHAR = 256;
class SuffixNode {
public:
    int s, e, id;
    SuffixNode* suffix_link;
    map<char, SuffixNode*> ch;
    SuffixNode(int a, int b) {
        s = a; e = b;
        id = -1;
        suffix_link = nullptr;
    }
    ~SuffixNode() {
        for (auto const &i : ch) {
            delete i.second;
        }
    }
};
class SuffixTrie {
public:
    string str;
    int remainder, active_edge, active_length;
    SuffixNode *root, *active_node, *last_node;

    SuffixTrie(string s) {
        str = s;
        root = new SuffixNode(-1, -1);
        active_node = root;
        remainder = active_edge = active_length = 0;
        last_node = nullptr;
        for (int i = 0; i < str.length(); ++i) {
            extend(i);
        }
        dfs(root, 0);
    }
    ~SuffixTrie() {
        if (root != nullptr) {
            for (auto const& i : root->ch) {
                delete i.second;
            }
        }
    }
    int edge_length(SuffixNode* node) {
        return node->e - node->s + 1;
    }
    void print(int i, int j)
    {
        for (int k = 0; k <= i; ++k) {
            printf("%c", str[k]);
        }
    }
//    void print(SuffixNode* node, ostream& out) {
//        for (int i = node->s; i < node->e; ++i) {
//            out << str[i];
//        }
//        out << endl;
//        for (auto i : node->ch) {
//            print(i.second, out);
//        }
//    }
    bool walk_down(SuffixNode *node) {
        if (active_length >= edge_length(node)) {
            active_edge += edge_length(node);
            active_length -= edge_length(node);
            active_node = node;
            return true;
        }
        return false;
    }
    void extend(int c) {
        ++remainder;
        last_node = nullptr;
        cout << c << endl;
        while (remainder > 0) {
            if (active_length == 0) {
                active_edge = c;
            }
            if (active_node->ch.find(str[active_edge]) == active_node->ch.end()) {
                active_node->ch[str[active_edge]] = new SuffixNode(c, c);
                if (last_node != nullptr) {
                    last_node->suffix_link = active_node;
                    last_node = nullptr;
                }
            } else {
                SuffixNode *next = active_node->ch[str[active_edge]];
                if (walk_down(next)) {
                    continue;
                }
                if (str[next->s + active_length] == str[c]) {
                    if (last_node != nullptr && active_node != root) {
                        last_node->suffix_link = active_node;
                        last_node = nullptr;
                    }
                    ++active_length;
                    break;
                }
                SuffixNode *split = new SuffixNode(next->s, next->s + active_length - 1);
//                active_node->ch.insert(pair<char, SuffixNode*>(str[active_edge], split));
                active_node->ch[str[active_edge]] = split;
                split->ch[str[c]] = new SuffixNode(c, c);
                next->s += active_length;
                if (last_node != nullptr) {
                    last_node->suffix_link = split;
                }
                last_node = split;
            }
            --remainder;
            if (active_node == root && active_length > 0) {
                --active_length;
                active_edge = c - remainder + 1;
            } else if (active_node != root) {
                active_node = active_node->suffix_link;
            }
        }
    }
    void dfs(SuffixNode *node, int height) {
        if (node->s != -1) {
            print(node->s, node->e);
        }
        int leaf = 1;
        for (auto i : node->ch) {
            if (leaf == 1 && node->s != -1) {
                printf(" [%d]\n", node->id);
            }
            leaf = 0;
            dfs(i.second, height + edge_length(i.second));
        }
        if (leaf == 1) {
            node->id = str.length() - height;
            printf(" [%d]\n", node->id);
        }
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
            auto st = new SuffixTrie(str);
        }
    }
};
