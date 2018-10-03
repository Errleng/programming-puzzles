#include <iostream>
#include <cstring>
#include <vector>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
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

using namespace std;

#define MAXN 18

bool get_bit(int in, int index) {
    return in & (1 << index);
}

int N, M, dest, a, b, c, memo[MAXN][1 << MAXN];
vector<pair<int, int>> adj[MAXN];

int longest_path(int u, int bitmask) {
    if (memo[u][bitmask] != -1)
        return memo[u][bitmask];
    else if (u == dest)
        return memo[u][bitmask] = 0;
    int res = -INF;
    foreach(v, adj[u]) {
        if (!get_bit(bitmask, v.se)) {
            res = max(res, v.fi + longest_path(v.se, bitmask | (1 << v.se)));
        }
    }
    return memo[u][bitmask] = res;
}

int main() {
    scan(N);
    scan(M);
    dest = N - 1;
    mem(memo, -1);
    rep(i, M) {
        scan(a);
        scan(b);
        scan(c);
        adj[a].pb({c, b});
    }
    printf("%d\n", longest_path(0, 1));
    return 0;
}