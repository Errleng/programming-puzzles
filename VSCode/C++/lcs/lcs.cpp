#include <iostream>
#include <cstring>
#include <algorithm>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define rep(i, j) repn(i, 0, j, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define INF 0x3f3f3f3f

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 1001

using namespace std;

// int LCS(int a, int b, int *seq1, int *seq2, int **memo) {
//     if (memo[a][b] != -1) {
//         return memo[a][b];
//     }
//     if (a == 0 || b == 0)
//         return memo[a][b] = 0;
//     if (seq1[a - 1] == seq2[b - 1]) {
//         return memo[a][b] = 1 + LCS(a - 1, b - 1, seq1, seq2, memo);
//     } else {
//         return memo[a][b] = max(LCS(a - 1, b, seq1, seq2, memo), LCS(a, b - 1, seq1, seq2, memo));
//     }
// }

// int main() {
//     int N, M, *seq1, *seq2, **memo;
//     scan(N);
//     scan(M);
//     seq1 = new int[N]();
//     seq2 = new int[M]();
//     memo = new int*[N + 1];
//     rep(i, N + 1) {
//         memo[i] = new int[M + 1];
//         rep(j, M + 1) {
//             memo[i][j] = -1;
//         }
//     }
//     rep(i, N) {
//         scan(seq1[i]);
//     }
//     rep(i, M) {
//         scan(seq2[i]);
//     }
//     printf("%d\n", LCS(N, M, seq1, seq2, memo));
//     return 0;
// }

int main() {
    int N, M, *seq1, *seq2, **dp;
    scan(N);
    scan(M);
    seq1 = new int[N]();
    seq2 = new int[M]();
    dp = new int*[N + 1];
    rep(i, N + 1) {
        dp[i] = new int[M + 1]();
    }
    rep(i, N) {
        scan(seq1[i]);
    }
    rep(i, M) {
        scan(seq2[i]);
    }
    repn(i, 1, N + 1, 1) {
        repn(j, 1, M + 1, 1) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d\n", dp[N][M]);
    return 0;
}