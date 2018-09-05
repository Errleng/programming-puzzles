#include "../library/lib.hpp"
#include <bits/stdc++.h>
#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);
using namespace std;

class cco00p1 {
public:
    static const int NSETS = 26;
    set<char> sets[NSETS];
    vector<int> adj[NSETS];
    bool include[NSETS] = {false};
    bool vis[NSETS] = {false};
    int N;
    char a, b;
    string garbage;

    void update(int a, int b) {
        vis[b] = true;
        for (char c : sets[b]) {
            sets[a].insert(c);
        }
        for (int c : adj[b]) {
            if (!vis[c]) {
                update(a, c);
            }
        }
    }
    void solve(std::istream& in, std::ostream& out) {
        in >> N;
        up(i, N) {
            in >> a >> garbage >> b;
            int x = a - 'A', y = b - 'A';
            if (islower(b)) {
                sets[x].insert(b);
            } else {
                adj[x].push_back(y);
                include[y] = true;
            }
            include[x] = true;
        }
        up(i, NSETS) {
            if (include[i]) {
                memset(vis, false, sizeof(vis));
                update(i, i);
                out << static_cast<char>('A' + i) << " = {";
                bool flag = true;
                for (char c : sets[i]) {
                    if (flag) {
                        out << c;
                        flag = false;
                    } else {
                        out << "," << c;
                    }
                }
                out << "}" << endl;
            }
        }
    }
};
