#include <iostream>
#include <cstring>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define rep(i, j) repn(i, 0, j, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define INF 0x3f3f3f3f

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, A, B, C, D, memo[30][30][30][30];

bool perfect(int a, int b, int c, int d) {
    if (memo[a][b][c][d] != -1)
        return memo[a][b][c][d];
    bool res = false;
    if (res == false && a >= 2 && b >= 1 && d >= 2)
        res = !perfect(a - 2, b - 1, c, d - 2);
    if (res == false && a >= 1 && b >= 1 && c >= 1 && d >= 1)
        res = !perfect(a - 1, b - 1, c - 1, d - 1);
    if (res == false && c >= 2 && d >= 1)
        res = !perfect(a, b, c - 2, d - 1);
    if (res == false && b >= 3)
        res = !perfect(a, b - 3, c, d);
    if (res == false && a >= 1 && d >= 1)
        res = !perfect(a - 1, b, c, d - 1);
    return memo[a][b][c][d] = res;
}

int main() {
    scan(N);
    mem(memo, -1);
    rep(_, N) {
        scanf("%d", &A);
        scanf("%d", &B);
        scanf("%d", &C);
        scanf("%d", &D);
        printf("%s\n", perfect(A, B, C, D) ? "Patrick" : "Roland");
    }
    return 0;
}