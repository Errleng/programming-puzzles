#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#include "../Library/debug.h"

#define repn(i, j, k, step) for (int(i) = (j); (i) < (k); (i) += (step))
#define rrepn(i, j, k, step) for (int(i) = (j); (i) >= (k); (i) -= (step))
#define rep(i, j) repn(i, 0, j, 1)
#define srep(i, j, k) repn(i, j, k, 1)
#define rrep(i, j, k) rrepn(i, j, k, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define fi first
#define se second
#define pb push_back

#define INF 0x3f3f3f3f

#define scan(x)                                                                \
    do {                                                                       \
        while ((x = getchar()) < '0')                                          \
            ;                                                                  \
        for (x -= '0'; '0' <= (_ = getchar());                                 \
             x = (x << 3) + (x << 1) + _ - '0')                                \
            ;                                                                  \
    } while (0)
char _;

using namespace std;

struct edge {
    int u, id;
    edge(int a, int b) : u(a), id(b) {}
};

int N, M;

int main() {
    scan(N);
    scan(M);
    vector<int> a(M), b(M);
    vector<int> prev(N);
    vector<bool> vis(N);
    vector<vector<int>> adj(N);
    rep(i, N) {
        adj[i].resize(N);
    }
    fill(prev.begin(), prev.end(), -1);

    rep(i, M) {
        scan(a[i]);
        scan(b[i]);
        --a[i];
        --b[i];
        adj[a[i]][b[i]] = 1 + i;
    }

    int start = a[0];
    int end = b[M - 1];

    queue<edge> q;
    q.push(edge(start, 0));
    bool search = true;
    while (!q.empty() && search) {
        auto n = q.front();
        q.pop();
        rep(i, N) {
            int index = adj[n.u][i];
            if (adj[n.u][i] && !vis[i] && index > n.id) {
                vis[i] = true;
                prev[i] = n.u;
                if (i == end) {
                    search = false;
                }
                q.push(edge(i, index));
            }
        }
    }
    vector<int> path;
    int back = end;
    path.pb(back);
    while (prev[back] != -1) {
        path.pb(prev[back]);
        back = prev[back];
    }
    cout << path.size() - 1 << endl;
    rrep(i, path.size() - 1, 1) {
        cout << path[i] + 1 << " " << path[i - 1] + 1 << endl;
    }

    return 0;
}