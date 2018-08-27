// #include <bits/stdc++.h>

// #define LOOP(a, b) for (int a = 0; a < b; ++a)
// #define LOOPN(a, n, b) for (int a = n; a < b; ++a)

// using namespace std;

// void prArr(int array[], int size) {
//     for (int i = 0; i < size; ++i) {
//         cout << array[i] << " ";
//     }
//     cout << endl;
// }

// const int MAX = 401;
// int N;
// int dp[MAX][MAX];
// int sizes[MAX];
// int sums[MAX];

// int solve(int l, int r) {
//     if (dp[l][r] != -1) return dp[l][r];
//     if (l >= r) return dp[l][r] = 1;
//     int ans = 0, a = l, b = r, sum1, sum2;
//     while (a < b) {
//         sum1 = sums[a] - sums[l];
//         sum2 = sums[r] - sums[b];
//         if (sum1 < sum2) a++;
//         else if (sum1 > sum2) b--;
//         else {
//             ans = solve(l, a) * solve(a+1, b-1) * solve(b, r);
//             if (ans == 1) break;
//             else {
//                 a++;
//                 b--;
//             }
//         }
//     }
//     return dp[l][r] = ans;
// }

// int main() {
//     freopen("input.txt", "r", stdin);

//     chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//     int ans = 0;
//     memset(dp, -1, sizeof(dp));
//     scanf("%d", &N);
//     scanf("%d", &sizes[0]);
//     sums[0] = sizes[0];
//     LOOPN(i, 1, N) {
//         scanf("%d", &sizes[i]);
//         sums[i] = sums[i-1] + sizes[i];
//     }
//     LOOP(i, N)
//         LOOPN(j, i, N) {
//             int s = solve(i,j)*(sums[j]-sums[i]);
//             if (s > ans) {
//                 ans = s;
//                 cout << s << " " << i << " " << j << " " << solve(i, j) << " " << sums[j] - sums[i] << endl;
//             }
//         }
//             // ans = max(ans, solve(i, j) * (sums[j] - sums[i]));
//     // prArr(sums, N);
//     printf("%d", ans);

//     chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::milliseconds>( t2 - t1 ).count();
//     cout << '\n' << duration << '\n' << endl;
//     return 0;
// }


    // int ans = 0;
    // scanf("%d", &N);
    // LOOP(i, N)
    //     LOOP(j, N)
    //         dp[l][r] = -1;
    // LOOP(i, N) {
    //     scanf("%d", &sizes[i]);
    // }
    // LOOPN(i, 2, N+1) {
    //     int start = N-i+1;
    //     LOOP(s, start) {
    //         int e = s + i - 1;
    //         bool found = adjTwo(s, e);
    //         if (found) continue;
    //         if (i > 2) adjThree(s, e);
    //     }
    // }
    // LOOP(i, N)
    //     LOOPN(j, i, N)
    //         ans = max(ans, rangeSum(i, j));
    // printf("%d", ans);

// bool solvedComb(int s, int e) {
//     if (s == e) return true;
//     else return dp[s][e] != -1;
// }

// int rangeSum(int s, int e) {
//     if (s == e) return sizes[s];
//     else return dp[s][e];
// }

// bool adjTwo(int s, int e) {
//     LOOPN(i, s+1, e+1) {
//         int j = i - 1;
//         if (!solvedComb(s, j) || !solvedComb(i, e)) continue;
//         int fsum = rangeSum(s, j);
//         int lsum = rangeSum(i, e);
//         if (fsum != lsum) continue;
//         dp[s][e] = fsum + lsum;
//         return true;
//     }
//     return false;
// }

// void adjThree(int s, int e) {
//     LOOPN(i, s+1, e) {
//         int j = i - 1;
//         if (!solvedComb(s, j)) continue;
//         int fsum = rangeSum(s, j);
//         LOOPN(k, i+1, e+1) {
//             int l = k - 1;
//             if (!solvedComb(i, l) || !solvedComb(k, e)) continue;
//             int lsum = rangeSum(k, e);
//             if (fsum != lsum) continue;
//             int bsum = rangeSum(i, l);
//             dp[s][e] = fsum + lsum + bsum;;
//             return;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 401;
int N, ans = 0;
int ball[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN];

int getS(int i, int j) {
    if (i == j) return ball[i];
    else return sum[j] - sum[i-1];
}

int search(int i, int j) {
    if (dp[i][j] == -1) {
        int val = 0;
        if (i >= j) val = 1;
        else {
            int k = i, l = j;
            while (k < l) {
                int ks = getS(i, k);
                int ls = getS(l, j);
                if (ks < ls) k++;
                else if (ls < ks) l--;
                else {
                    if (search(i, k) == 1 && search(k+1, l-1) == 1 && search(l, j) == 1) {
                        val = 1;
                        break;
                    }
                    k++;
                    l--;
                }
            }
        }
        dp[i][j] = val;
    }
    return dp[i][j];
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &ball[i]);
        sum[i] = sum[i-1] + ball[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            if (search(i, j) == 1) {
                ans = max(ans, getS(i, j));
            }
        }
    }
    printf("%d\n", ans);

    for (int i = 0; i <= N; ++i) {
      cout << sum[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= N; ++i) {
      for (int j = 0; j <= N; ++j) {
        cout << getS(i, j) << " ";
      }
      cout << endl;
    }
    return 0;
}
