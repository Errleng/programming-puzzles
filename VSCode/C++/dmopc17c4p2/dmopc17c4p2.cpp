#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_map>
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

#define MAXN 1000

int N, Q, a, b, q, vals[MAXN];
unordered_map<int, int> cnt;
vector<int> adj[MAXN], path;

bool dfs(int cur, int end, int prev) {
    if (cur == end) {
        path.pb(cur);
        return true;
    }
    foreach (nxt, adj[cur]) {
        if (nxt != prev) {
            if (dfs(nxt, end, cur)) {
                path.pb(cur);
                return true;
            }
        }
    }
    return false;
}

int main() {
    scan(N);
    scan(Q);
    rep(i, N) {
        scan(vals[i]);
    }
    rep(i, N - 1) {
        scan(a);
        scan(b);
        --a;
        --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    rep(i, Q) {
        scan(q);
        scan(a);
        scan(b);
        --a;
        --b;
        path.clear();
        dfs(a, b, -1);
        switch (q) {
        case 1: {
            int sum = 0;
            foreach (node, path) {
                sum += vals[node];
            }
            printf("%d\n", (int)round(sum / (double)path.size()));
            break;
        }
        case 2: {
            int median;
            vector<int> pathVals;
            foreach (node, path) {
                pathVals.pb(vals[node]);
            }
            int len = pathVals.size();
            sort(pathVals.begin(), pathVals.end());
            if (len % 2 == 0) {
                median = (int)round(
                             (pathVals[len / 2 - 1] + pathVals[len / 2]) / 2.0);
            } else {
                median = pathVals[len / 2];
            }
            printf("%d\n", median);
            break;
        }
        case 3: {
            cnt.clear();
            int maxCnt = 0;
            int maxI = 0;
            foreach (node, path) {
                ++cnt[vals[node]];
            }
            foreach (valCnt, cnt) {
                if (valCnt.se > maxCnt) {
                    maxCnt = valCnt.se;
                    maxI = valCnt.fi;
                } else if (valCnt.se == maxCnt) {
                    if (valCnt.fi < maxI) {
                        maxI = valCnt.fi;
                    }
                }
            }
            printf("%d\n", maxI);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
