#include "../library/lib.hpp"
#include <bits/stdc++.h>

using namespace std;

#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

class dmopc14c2p5 {
public:
    void solve(std::istream& in, std::ostream& out) {
        const int MAXN = 1000;
        vector<int> adj[MAXN];
        vector<int> mills;
        double prob[MAXN] = {0};
        int N, M, a, b;
        in >> N >> M;
        int lake1;
        up(i, M) {
            in >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
        }
        prob[0] = 1.0;
        up(c, N) {
            double chance = prob[c] / adj[c].size();
            for (int i : adj[c]) {
                prob[i] += chance;
            }
        }
        up (i, N) {
            if (adj[i].empty()) {
                printf("%0.9f\n", prob[i]);
            }
        }
    }
};
