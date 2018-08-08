#include <bits/stdc++.h>
using namespace std;
int lengths[2001];
int heights[4001];

int main() {
    freopen("input.txt", "r", stdin);
    int N, in, ans = 0, len = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &in);
        lengths[in]++;
    }

    for (int i = 1; i <= 2000; ++i) {
        for (int j = i; j <= 2000; ++j) {
            if (i == j) heights[i + j] += lengths[i] / 2;
            else heights[i + j] += min(lengths[i], lengths[j]);
        }
    }

    for (int i = 1; i <= 4000; ++i) {
        if (heights[i] > ans) {
            ans = heights[i];
            len = 1;
        }
        else if (heights[i] == ans) {
            len++;
        }
    }

    printf("%d %d", ans, len);

    return 0;
}