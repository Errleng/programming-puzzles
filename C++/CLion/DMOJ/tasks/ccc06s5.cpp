#include "../library/lib.hpp"
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class ccc06s5 {
public:
    int M, N, A, B, C;

    int flatten(int a, int b) {
        return a * N + b;
    }

    void solve(std::istream &in, std::ostream &out) {
        const int MAXM = 4;
        const int MAXN = 5;
        char grid[MAXM][MAXN];
        pii side[] = {pii(0, 1), pii(0, -1), pii(1, 0), pii(-1, 0), pii(1, 1), pii(1, -1), pii(-1, 1), pii(-1, -1)};
        in >> M >> N >> A >> B >> C;
        auto *adj = new vector<int>[(1 << (M * N))];
        int limit = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                in >> grid[i][j];
                if (grid[i][j] == '*')
                    limit |= (1 << flatten(i, j));
            }
        }
        for (int config = 0; config < (1 << (M * N)); ++config) {
            int curr = config;
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    int cnt = 0;
                    for (auto s: side) {
                        int a = i + s.first;
                        int b = j + s.second;
                        if (a >= 0 && a < M && b >= 0 && b < N)
                            if (config & (1 << flatten(a, b)))
                                cnt++;
                    }
                    if (config & (1 << flatten(i, j))) {
                        if (cnt < A || cnt > B)
                            curr &= ~(1 << flatten(i, j));
                    } else if (cnt > C)
                        curr |= (1 << flatten(i, j));
                }
            }
            if (curr != config)
                adj[curr].push_back(config);
        }
        int ans = -1;
        deque<pii> d;
        set<int> vis;
        d.emplace_back(pii(limit, 0));
        while (!d.empty()) {
            pii curr = d.front();
            d.pop_front();
            if (vis.find(curr.first) != vis.end())
                continue;
            vis.insert(curr.first);
            if (adj[curr.first].empty()) {
                ans = curr.second;
                break;
            }
            for (auto next: adj[curr.first]) {
                d.emplace_back(pii(next, curr.second + 1));
            }
        }
        out << ans << endl;
    }
};
