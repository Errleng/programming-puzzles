#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
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

// clang-format off
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// clang-format on

using namespace std;

#define MAXN 100

typedef pair<double, double> pdd;

int N;
double x, y;
pdd pos, sheep[MAXN];
set<pdd> eaten;

double dist(pdd a, pdd b) {
    return sqrt(pow((b.fi - a.fi), 2) + pow((b.se - a.se), 2));
}

int main() {
    rep(i, MAXN) { sheep[i] = {1e9, 1e9}; }
    scan(N);
    rep(i, N) {
        scanf("%lf", &x);
        scanf("%lf", &y);
        sheep[i] = {y, x};
    }
    sort(begin(sheep), end(sheep));
    pos.fi = 0;
    for (double i = 0.00; i < 1000.00; i += 0.01) {
        double maxD = 1e9;
        pos.se = i;
        rep(j, N) {
            double eatDist = dist(pos, sheep[j]);
            if (eatDist <= maxD) {
                maxD = eatDist;
                eaten.insert(sheep[j]);
            }
        }
    }
    foreach (i, eaten) {
        printf("The sheep at (%.2lf, %.2lf) might be eaten.\n", i.se, i.fi);
    }
    return 0;
}