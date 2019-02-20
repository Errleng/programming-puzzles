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

#define MAXR 50000
#define MAXC 10

int R, C, K, type[MAXR][MAXC];

int main() {
    int count = 0;
    scan(R);
    scan(C);
    scan(K);
    rep(i, R) {
        rep(j, C) {
            scan(type[i][j]);
        }
    }
    rep(i, R) {
        rep(j, C) {
            if (type[i][j] == 2) {
                srep(k, 1, K + 1) {
                    int idx = i - k;
                    if (idx >= 0) {
                        if (type[idx][j] == 1) {
                            count++;
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}