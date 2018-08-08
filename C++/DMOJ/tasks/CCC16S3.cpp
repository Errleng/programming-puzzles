#include <bits/stdc++.h>

using namespace std;

class CCC16S3 {
public:
    const int MAXN = 100000;
    int N, M, cost = 0, maxDist = -1, maxIdx = -1, *dist = new int[MAXN]();
    vector<int> pho;
    vector<int> *adj = new vector<int>[MAXN];
    bool *isPho = new bool[MAXN](), *include = new bool[MAXN]();

    void mark(int cur, int prev) {
        if (isPho[cur]) {
            include[cur] = true;
        }
        for (int i : adj[cur]) {
            if (i != prev) {
                mark(i, cur);
                if (include[i]) {
                    cost += 2;
                    include[cur] = true;
                }
            }
        }
    }

    void DFS(int cur, int prev) {
        for (int i : adj[cur]) {
            if (i != prev && include[i]) {
                dist[i] = dist[cur] + 1;
                if (dist[i] > maxDist) {
                    maxDist = dist[i];
                    maxIdx = i;
                }
                DFS(i, cur);
            }
        }
    }

    void solve(std::istream& in, std::ostream& out) {
        in >> N >> M;
        int a, b;
        for (int i = 0; i < M; ++i) {
            in >> a;
            pho.push_back(a);
            isPho[a] = true;
        }
        for (int i = 0; i < N - 1; ++i) {
            in >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        mark(pho[0], -1);
        DFS(pho[0], -1);
        for (int i = 0; i < N; ++i) {
            dist[i] = 0;
        }
        DFS(maxIdx, -1);
        maxDist = 0;
        for (int i = 0; i < N; ++i) {
            if (dist[i] > maxDist) {
                maxDist = dist[i];
            }
        }
        int ans = cost - maxDist;
        out << ans << endl;
    }
};