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

#define MAXN 18

using namespace std;

typedef pair<int, int> pii;

int N, M, a, b, c, memo[MAXN], path[MAXN];
vector<pii> adj[MAXN];
int longest_path(int u) {
    if (memo[u])
        return memo[u];
    int res = 0;
    foreach(v, adj[u]) {
        res = max(res, longest_path(v.se) + v.fi);
    }
    return memo[u] = res;
}

int main() {
    scan(N);
    scan(M);
    rep(i, M) {
        scan(a);
        scan(b);
        scan(c);
        adj[a].pb({c, b});
    }
    printf("%d\n", longest_path(0));
    return 0;
}