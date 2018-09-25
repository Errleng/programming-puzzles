#include "../library.hpp"
#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

#include <iostream>
#include <string>
#include <map>

using namespace std;
class TrieNode {
public:
  map<char, TrieNode *> children;
  TrieNode() {}
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
  }
  int count_nodes(TrieNode *node) {
    int res = 1;
    for (auto i : node->children) {
      res += count_nodes(i.second);
    }
    return res;
  }
};

int main() {
  int N;
  string str;
  scanf("%d", &N);
  up(i, N) {
    cin >> str;
    TrieNode *node = new TrieNode();
    Trie *trie = new Trie(node);
    up(i, str.length()) {
      trie->root->insert_suffix(str.substr(i));
    }
    printf("%d\n", trie->count_nodes(trie->root));
    for (auto i : trie->root->children) {
      delete i.second;
    }
  }
  return 0;
}
