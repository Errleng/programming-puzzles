#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#include "../Library/debug.h"

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

// clang-format off
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// clang-format on

using namespace std;

#define MAXN 1601
#define MAXS 3601

typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

struct Edge {
    int v, w, d;
    Edge(int a, int b, int c) {
        v = a;
        w = b;
        d = c;
    }
};

priority_queue<ppii, vector<ppii>, greater<ppii>> pq;
vector<Edge> adj[MAXN];
int S, N, E, s, t, d, u, dist[MAXN][MAXS];

int main() {
    rep(i, MAXN) {
        rep(j, MAXS) {
            dist[i][j] = INF;
        }
    }

    scan(S);
    scan(N);
    scan(E);

    rep(i, E) {
        scan(s);
        scan(t);
        scan(d);
        scan(u);
        adj[s].pb(Edge(t, d, u));
        adj[t].pb(Edge(s, d, u));
    }

    rep(i, S + 1) {
        dist[0][i] = 0;
    }

    pq.push({0, {0, 0}});
    while (!pq.empty()) {
        int d = pq.top().fi;
        int u = pq.top().se.se;
        int burn = pq.top().se.fi;
        pq.pop();
        if (u == N - 1) {
            printf("%d\n", d);
            return 0;
        }
        for (Edge e : adj[u]) {
            int sunburn = burn;
            if (e.d) {
                sunburn += e.w;
            }
            if (sunburn <= S) {
                int nd = e.w + d;
                if (nd < dist[e.v][sunburn]) {
                    dist[e.v][sunburn] = nd;
                    pq.push({nd, {sunburn, e.v}});
                }
            }
        }
    }
    printf("%d\n", -1);
    return 0;
}