#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int r, r2, cnt;
    scanf("%d", &r);
    while (r != 0) {
        r2 = r * r;
        cnt = 0;
        for (int i = 0; i <= r; ++i) {
            cnt += (int)(sqrt(r2 - i*i));
        }
        printf("%d\n", cnt * 4 + 1);
        scanf("%d", &r);
    }
}