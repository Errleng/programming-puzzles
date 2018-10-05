#include <cstring>
#include <iostream>

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

const int MAXT = 2001;
const int MOD = 1'000'000'007;

int memo[2][MAXT][MAXT];

// int win(bool stressful, int us, int them) {
//     int res = 0;
//     if (memo[stressful][us][them]) {
//         return memo[stressful][us][them];
//     }
//     if (!us || !them) {
//         res = 1;
//     } else {
//         if (stressful) {
//             if (us < them) {
//                 res += win(stressful, us, them - 1);
//             }
//             res += win(stressful, us - 1, them);
//         } else {
//             if (us > them + 1) {
//                 res += win(stressful, us - 1, them);
//             }
//             res += win(stressful, us, them - 1);
//         }
//     }
//     return memo[stressful][us][them] = res % MOD;
// }

// int main() {
//     int T;
//     int a, b;
//     char c;
//     scan(T);
//     srep(i, 1, T + 1) {
//         scanf("%d%c%d", &a, &c, &b);
//         printf("Case #%d: %d %d\n", i, win(false, a, b), win(true, a, b));
//     }
//     return 0;
// }

int T, a, b, relaxed[MAXT][MAXT], stressful[MAXT][MAXT];

int main() {
    char c;
    scan(T);

    rep(i, MAXT) {
        relaxed[0][i] = relaxed[i][0] = 1;
        stressful[0][i] = stressful[i][0] = 1;
    }

    srep(us, 1, MAXT) {
        srep(them, 1, MAXT) {
            relaxed[us][them] = relaxed[us][them - 1];
            if (us > them + 1) {
                relaxed[us][them] += relaxed[us - 1][them];
                relaxed[us][them] %= MOD;
            }
            stressful[us][them] = stressful[us - 1][them];
            if (us < them) {
                stressful[us][them] += (stressful[us][them - 1]);
                stressful[us][them] %= MOD;
            }
        }
    }
    srep(i, 1, T + 1) {
        scanf("%d%c%d", &a, &c, &b);
        printf("Case #%d: %d %d\n", i, relaxed[a][b], stressful[a][b]);
    }
    return 0;
}