#include <bits/stdc++.h>
using namespace std;

int sqrCnt(int m, int x) {
    if (m == 0) return 0;
    int expon = pow(5, m-1);
    int xm = x / expon;
    if (xm == 1 || xm == 3) return expon + sqrCnt(m-1, x % expon);
    if (xm == 2) return 2 * expon + sqrCnt(m-1, x % expon);
}

int main() {
    freopen("input.txt", "r", stdin);

    int N, m, x, y;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &m, &x, &y);
        if (y < sqrCnt(m, x))
            printf("crystal\n");
        else
            printf("empty\n");
    }
}