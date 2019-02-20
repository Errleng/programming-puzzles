#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

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

struct Electron {
    int a, b, ab;
};

int N;
vector<int> A, B;
vector<Electron> E;

int main() {
    scan(N);
    A.resize(N);
    B.resize(N);
    E.resize(N);
    rep(i, N) {
        scan(A[i]);
    }
    rep(i, N) {
        scan(B[i]);
        E[i] = {A[i], B[i], B[i] - A[i]};
    }
    sort(E.begin(), E.end(),
         [](Electron &a, Electron &b) -> bool { return a.ab < b.ab; });
    int ans = (N % 2) ? E[N - 1].a : 0;
    repn(i, 0, N - 1, 2) {
        ans += min(E[i].b + E[i + 1].b, E[i].a + E[i + 1].a);
    }
    printf("%d\n", ans);
    return 0;
}