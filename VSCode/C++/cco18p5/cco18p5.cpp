#include <cmath>
#include <cstring>
#include <iostream>
#include <map>

#include "../Library/debug.h"
#include "../Data Structures/SegmentTree.cpp"

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

#define MAXN 1000000

int N, K, Q, quality[MAXN];
map<int, int> valid;

int main() {
    int a, b;
    scan(N);
    scan(K);
    scan(Q);
    srep(i, 1, N + 1) { scan(quality[i]); }
    SegmentTree fiMax(quality, MAXN);
    SegmentTree seMax(quality, MAXN);
    rep(i, MAXN) {
        valid[i] = true;
    }
    rep(i, Q) {
        scan(a);
        scan(b);
        fiMax.update_value(a, b);
    }
    rep(i, N - K) {
        println(fiMax.max_q(i, i + K + 1, valid));
    }
    return 0;
}