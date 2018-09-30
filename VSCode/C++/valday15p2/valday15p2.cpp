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

#define MAXC 1000

using namespace std;

typedef pair<int, int> pii;

int C, M, memo[MAXC][MAXC];
pii cages[MAXC];

int sing(int pos, int princesses, int minutes) {
    if (pos < C && minutes >= cages[pos].first) {
        if (memo[pos][minutes] != -1) {
            return memo[pos][minutes];
        }
        return memo[pos][minutes] = max(sing(pos + 1, princesses, minutes), sing(pos + 1, princesses, minutes - cages[pos].first) + cages[pos].second);
    } else {
        return 0;
    }
}

int main() {
    scan(C);
    scan(M);
    rep(i, MAXC) {
        rep(j, MAXC) {
            memo[i][j] = -1;
        }
    }
    rep(i, C) {
        scan(cages[i].second);
        scan(cages[i].first);
    }
    sort(cages, cages + C);
    printf("%d\n", sing(0, 0, M));
    return 0;
}

