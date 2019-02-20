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

int h[2], w[2];

int main() {
    rep(i, 2) {
        scan(h[i]);
        scan(w[i]);
    }
    int die1 = (h[0] - 1) * w[1];
    int die2 = (h[1] - 1) * w[0];
    if (die1 == die2) {
        cout << -1;
    } else if (die2 < die1) {
        cout << 1;
    } else if (die1 < die2) {
        cout << 2;
    }
    return 0;
}