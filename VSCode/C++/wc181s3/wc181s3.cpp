#include <cstring>
#include <iostream>
#include <queue>

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

#define MAXN 10000

int H, J, N, A[MAXN], B[MAXN], mm[MAXN][MAXN];
int itch[MAXN];

int minSteps(int h, int d) {
    if (mm[h][d] != -1) {
        return mm[h][d];
    }
    if (h >= H) {
        return mm[h][d] = d;
    }
    int minD = INF;
    int idx = h + J;
    if (idx >= 0 && idx < MAXN) {
        if (itch[idx] > 0) {
            srep(i, 1, J) {
                int down = h - i;
                if (itch[down] <= 0) {
                    minD = min(minD, minSteps(down, d + 1));
                }
            }
        } else {
            return mm[h][d] = minSteps(idx, d + 1);
        }
    }
    return mm[h][d] = minD;
}

int main() {
    scan(H);
    scan(J);
    scan(N);
    int maxItch = 0;
    rep(i, MAXN) {
        rep(j, MAXN) { mm[i][j] = -1; }
    }
    rep(i, N) {
        scan(A[i]);
        scan(B[i]);
        int ni = B[i] + 1;
        itch[A[i]]++;
        if (ni < MAXN) {
            itch[ni]--;
        }
    }
    srep(i, 1, MAXN) { itch[i] += itch[i - 1]; }
    int ans = minSteps(0, 0);
    printf("%d\n", (ans == INF) ? -1 : ans);
    return 0;
}