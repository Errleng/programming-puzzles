#define upto(i, s, e, c) for (int (i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int (i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

#include <iostream>

using namespace std;

int N, M, T;

int main() {
    scanf("%d %d %d", &N, &M, &T);
    int ans = 0;
    printf("%d\n", ans);
    return 0;
}

