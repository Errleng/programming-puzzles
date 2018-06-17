#include <bits/stdc++.h>
using namespace std;

const int BIG = 100000;

map<string, int> G;
int visited[BIG];
vector<int> adj[BIG];

int BFS(int start) {
    queue<int> q;
    int res = -1;
    q.push(start);
    memset(visited, -1, sizeof(visited));
    visited[start] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int c : adj[node]) {
            if (visited[c] == -1) {
                visited[c] = visited[node] + 1;
                res = max(res, visited[c]);
                q.push(c);
            }
        }
    }
    return res;
}

int main() {
    int L, N;
    string a;
    string b;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        cin >> N;
        int people = 0;
        int home, messages;
        for (int j = 0; j < N; ++j) {
            adj[j].clear();
        }
        G.clear();
        for (int j = 0; j < N/2; ++j) {
            cin >> a;
            cin >> b;
            if (!G.count(a))
                G[a] = people++;
            if (!G.count(b))
                G[b] = people++;
            adj[G[a]].push_back(G[b]);
            adj[G[b]].push_back(G[a]);
            if ((j+1) == (N/2))
                home = G[b];
        }
        messages = 2 * BFS(home);
        cout << (N * 10) - (10 * messages) << endl;
    }
    return 0;
}