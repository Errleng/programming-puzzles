#include <cstring>
#include <iostream>
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

const int MAXN = 500'001;

int N, a, b, U, D, S;
vector<int> adj[MAXN];

void calc(int u, int p) { foreach (i, ) }

int main() {
    scan(N);
    rep(i, N - 1) {
        scan(a);
        scan(b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    calc(1, -1);
    create(1, -1);
    return 0;
}