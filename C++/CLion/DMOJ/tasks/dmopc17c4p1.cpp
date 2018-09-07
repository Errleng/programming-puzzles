#include "../library/lib.hpp"
#include <bits/stdc++.h>
#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);
using namespace std;

class dmopc17c4p1 {
public:
    void solve(std::istream& in, std::ostream& out) {
        const int MAXN = 100000;
        int N, Q, x, y;
        int start[MAXN] = {0};
        int finish[MAXN] = {0};
        in >> N >> Q;
        up(i, Q) {
            in >> x >> y;
            start[x]++;
            finish[y]--;
        }
        int blue = 0, purple = 0;
        int change = 0;
        up(i, N) {
            change += start[i];
            change += finish[i];
            if (change > 0) {
                blue++;
            } else {
                purple++;
            }
        }
        out << purple << " " << blue << endl;
    }
};
