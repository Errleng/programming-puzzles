#include <iostream>
#include <cstdio>
#include <algorithm>

#define upto(i, s, e, c) for (int (i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int (i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

using namespace std;

const int N = 8;
int bloods[N];
int patients[N];

int use_blood(int a, int b) {
    int used = min(bloods[a], patients[b]);
    bloods[a] -= used;
    patients[b] -= used;
    return used;
}

int main() {
    int ans = 0;
    up(i, N) {
        scanf("%d", &bloods[i]);
    }
    up (i, N) {
        scanf("%d", &patients[i]);
    }
    ans += use_blood(0, 0);
    ans += use_blood(1, 1);
    ans += use_blood(0, 1);
    ans += use_blood(2, 2);
    ans += use_blood(0, 2);
    ans += use_blood(4, 4);
    ans += use_blood(0, 4);
    ans += use_blood(2, 3);
    ans += use_blood(3, 3);
    ans += use_blood(1, 3);
    ans += use_blood(0, 3);
    ans += use_blood(4, 5);
    ans += use_blood(5, 5);
    ans += use_blood(1, 5);
    ans += use_blood(0, 5);
    upc(i, N, 2) {
        ans += use_blood(i, 6);
    }
    up(i, N) {
        ans += use_blood(i, 7);
    }
    printf("%d\n", ans);
    return 0;
}

