#include <algorithm>
#include <cstring>
#include <iostream>

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

#define scan(x)                                                                \
    do {                                                                       \
        while ((x = getchar()) < '0')                                          \
            ;                                                                  \
        for (x -= '0'; '0' <= (_ = getchar());                                 \
             x = (x << 3) + (x << 1) + _ - '0')                                \
            ;                                                                  \
    } while (0)
char _;

using namespace std;

const int MAX = 700 * 700;
int N, total, A[MAX], dp[2][MAX];

int main() {
    scan(N);
    rep(i, N) {
        scan(A[i]);
        total += A[i];
    }
    rep(i, total + 1) { dp[0][i] = abs(i - (total - i)); }
    rep(i, N) {
        rep(j, total + 1) {
            if (j - A[i] >= 0) {
                dp[1][j] = min(dp[0][j], dp[0][j - A[i]]);
            } else {
                dp[1][j] = INF;
            }
        }
        rep(j, total + 1) { dp[0][j] = dp[1][j]; }
    }
    printf("%d\n", dp[1][total]);
    return 0;
}