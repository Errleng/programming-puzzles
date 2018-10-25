#include <algorithm>
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

#define MAXN 2001
#define MAXK 201

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

int K, N, M, A, B, a, b, t, h, dist[MAXN][MAXK];
vector<Edge> adj[MAXN];
priority_queue<ppii, vector<ppii>, greater<ppii>> pq;

int main() {
    scan(K);
    scan(N);
    scan(M);
    rep(i, N) {
        rep(j, K + 1) {
            dist[i][j] = INF;
        }
    }
    rep(i, M) {
        scan(a);
        scan(b);
        scan(t);
        scan(h);
        --a;
        --b;
        adj[a].pb(Edge(b, t, h));
        adj[b].pb(Edge(a, t, h));
    }
    scan(A);
    scan(B);
    --A;
    --B;
    rep(i, K + 1) {
        dist[A][i] = 0;
    }
    pq.push({0, {0, A}});

    while (!pq.empty()) {
        int u = pq.top().se.se;
        int ud = pq.top().se.fi;
        pq.pop();
        for (Edge e : adj[u]) {
            int dmg = e.d + ud;
            if (dmg < K) {
                int nd = e.w + dist[u][ud];
                if (nd < dist[e.v][dmg]) {
                    dist[e.v][dmg] = nd;
                    pq.push({nd, {dmg, e.v}});
                }
            }
        }
    }
    int ans = INF;
    rep(i, K + 1) {
        ans = min(ans, dist[B][i]);
    }

    if (ans == INF) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", ans);
    }
    return 0;
}