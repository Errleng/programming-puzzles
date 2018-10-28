#include "../library/lib.hpp"
#include <bits/stdc++.h>

#define repn(i, j, k, step) for (int i = j; i < k; i += step)
#define rrepn(i, j, k, step) for (int i = j; i >= k; i -= step)
#define rep(i, j) repn(i, 0, j, 1)
#define srep(i, j, k) repn(i, j, k, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define fi first
#define se second
#define pb push_back

#define INF 0x3f3f3f3f

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 500000

using namespace std;

class dmopc14c4p6 {
public:
    vector<int> adj[MAXN];
    int maxD, maxI, distFi[MAXN], distSe[MAXN];

    void dfs(int u, int p, int d, int type) {
        if (d > maxD) {
            maxD = d;
            maxI = u;
        }
        if (type == 1) {
            distFi[u] = d;
        } else if (type == 2) {
            distSe[u] = d;
        }
        for (int e : adj[u]) {
            if (e != p) {
                dfs(e, u, d + 1, type);
            }
        }
    }

    void solve(std::istream& in, std::ostream& out) {
        cin.sync_with_stdio(0);
        cin.tie(0);
        int N, a, b;
        in >> N;
        rep(i, N - 1) {
            in >> a >> b;
            --a;
            --b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        dfs(0, -1, 1, 0);
        int fi = maxI;
        maxD = 0;
        dfs(fi, -1, 1, 1);
        int se = maxI;
        maxD = 0;
        dfs(se, -1, 1, 2);
        for (int i = 0; i < N; ++i) {
            out << max(distFi[i], distSe[i]) << '\n';
        }
    }
};
