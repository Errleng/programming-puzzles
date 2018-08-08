#include <bits/stdc++.h>

using namespace std;

const int INF = 999999;
const int MAXN = 5001;

vector<int> adj[MAXN];
int lvl[MAXN];
int deg[MAXN];
int N, S, u, v, ans, rad = 0, maxlvl = 0;
queue<int> q;

int main() {
    scanf("%d %d", &N, &S);
    for (int i=0; i<N-1; i++) {
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=0; i<N; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i : adj[v]) {
            deg[i]--;
            if (deg[i] == 1) {
                q.push(i);
                lvl[i] = lvl[v] + 1;
                maxlvl = max(maxlvl, lvl[i]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (lvl[i] == maxlvl) {
            rad += 1;
        }
    }
    rad += 2 * maxlvl;
    rad = ceil((double)rad / 2);
    if (N > S) {
        ans = ceil((double)rad / S);
    }
    else {
        ans = 0;
    }
    printf("%d\n", ans);
    return 0;
}