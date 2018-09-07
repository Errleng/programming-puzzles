#include "../library/lib.hpp"
#include <bits/stdc++.h>

using namespace std;

#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

const int MAX_CHAR = 256;

class Node {
public:
    Node *children[MAX_CHAR];
    Node *suffixLink;
    int start;
    int *end;
    int suffixIndex;

    Node(int start, int *end, Node *root) {
        for (int i = 0; i < MAX_CHAR; i++)
            children[i] = nullptr;
        suffixLink = root;
        this->start = start;
        this->end = end;
        suffixIndex = -1;
    }
};

class SuffixTrie {
public:
    string text;
    Node *root = nullptr;
    Node *lastNewNode = nullptr;
    Node *activeNode = nullptr;
    int activeEdge = -1;
    int activeLength = 0;
    int remainingSuffixCount = 0;
    int leafEnd = -1;
    int *rootEnd = nullptr;
    int *splitEnd = nullptr;
    int size = -1;
    SuffixTrie(string s) {
        text = s;
        size = s.length();
        int i;
        rootEnd = (int *) malloc(sizeof(int));
        *rootEnd = -1;
        root = new Node(-1, rootEnd, root);
        activeNode = root;
        for (i = 0; i < size; i++)
            extend(i);
        setSuffixIndexByDFS(root, 0);
    }
    ~SuffixTrie() {
        freeSuffixTreeByPostOrder(root);
    }

    void setSuffixIndexByDFS(Node *n, int labelHeight)
    {
        if (n == NULL)  return;
        int leaf = 1;
        int i;
        for (i = 0; i < MAX_CHAR; i++)
        {
            if (n->children[i] != NULL)
            {
                if (leaf == 1 && n->start != -1)
                leaf = 0;
                setSuffixIndexByDFS(n->children[i], labelHeight +
                                                    edgeLength(n->children[i]));
            }
        }
        if (leaf == 1)
        {
            n->suffixIndex = size - labelHeight;
        }
    }

    void freeSuffixTreeByPostOrder(Node *n)
    {
        if (n == NULL)
            return;
        int i;
        for (i = 0; i < MAX_CHAR; i++)
        {
            if (n->children[i] != NULL)
            {
                freeSuffixTreeByPostOrder(n->children[i]);
            }
        }
        if (n->suffixIndex == -1)
            free(n->end);
        free(n);
    }

    int edgeLength(Node *n) {
        return *(n->end) - (n->start) + 1;
    }

    int walkDown(Node *currNode) {
        if (activeLength >= edgeLength(currNode)) {
            activeEdge += edgeLength(currNode);
            activeLength -= edgeLength(currNode);
            activeNode = currNode;
            return 1;
        }
        return 0;
    }

    void extend(int pos) {
        leafEnd = pos;
        remainingSuffixCount++;
        lastNewNode = nullptr;


        while (remainingSuffixCount > 0) {
            if (activeLength == 0)
                activeEdge = pos;
            if (activeNode->children[text[activeEdge]] == nullptr) {
                activeNode->children[text[activeEdge]] =
                        new Node(pos, &leafEnd, root);
                if (lastNewNode != nullptr) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }
            }
            else {
                Node *next = activeNode->children[text[activeEdge]];
                if (walkDown(next))
                {
                    continue;
                }
                if (text[next->start + activeLength] == text[pos]) {
                    if (lastNewNode != nullptr && activeNode != root) {
                        lastNewNode->suffixLink = activeNode;
                        lastNewNode = nullptr;
                    }

                    activeLength++;
                    break;
                }
                splitEnd = (int *) malloc(sizeof(int));
                *splitEnd = next->start + activeLength - 1;
                Node *split = new Node(next->start, splitEnd, root);
                activeNode->children[text[activeEdge]] = split;
                split->children[text[pos]] = new Node(pos, &leafEnd, root);
                next->start += activeLength;
                split->children[text[next->start]] = next;
                if (lastNewNode != nullptr) {
                    lastNewNode->suffixLink = split;
                }

                lastNewNode = split;
            }

            remainingSuffixCount--;
            if (activeNode == root && activeLength > 0)
            {
                activeLength--;
                activeEdge = pos - remainingSuffixCount + 1;
            } else if (activeNode != root)
            {
                activeNode = activeNode->suffixLink;
            }
        }
    }
    int count_nodes(Node *n) {
        int res = *n->end - n->start + 1;
        for (int i = 0; i < MAX_CHAR; ++i) {
            if (n->children[i] != nullptr) {
                res += count_nodes(n->children[i]);
            }
        }
        return res;
    }
};

class ccc03s4 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int N;
        string str;
        in >> N;
        up(i, N) {
            in >> str;
            auto st = new SuffixTrie(str);
            out << st->count_nodes(st->root) << endl;
        }
    }
};
