#include "../library/lib.hpp"
#include <bits/stdc++.h>

using namespace std;

class ccc16s4 {
public:
    static const int MAXN = 400;
    array<int, MAXN> balls;
    array<int, MAXN> sums;
    array<array<int, MAXN>, MAXN> memo;

    int range_sum(int l, int r) {
        if (l == r)
            return balls[l];
        else
            return sums[r] - sums[l-1];
    }

    int combine(int l, int r) {
        if (memo[l][r] != -1)
            return memo[l][r];
        if (l >= r)
            return memo[l][r] = 1;
        int i = l;
        int j = r;
        while (i < j) {
            int sumL = range_sum(l, i);
            int sumR = range_sum(j, r);
            if (sumL < sumR) {
                i++;
            } else if (sumL > sumR) {
                j--;
            }
            else {
                if (combine(l, i) && combine(i+1, j-1) && combine(j, r)) {
                    return memo[l][r] = 1;
                }
                i++;
                j--;
            }
        }
        return memo[l][r] = 0;
    }

    void solve(std::istream &in, std::ostream &out) {
        int N;
        in >> N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                memo[i][j] = -1;
            }
        }
        for (int i = 0; i < N; ++i) {
            in >> balls[i];
        }
        sums[0] = balls[0];
        for (int i = 1; i < N; ++i) {
            sums[i] = sums[i - 1] + balls[i];
        }
        int ans = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (combine(i, j) == 1) {
                    ans = max(ans, range_sum(i, j));
                }
            }
        }
        out << ans << endl;
        for (int i = 0; i < N; ++i) {
            print(sums[i]);
        }
        println();
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                print(range_sum(i, j));
            }
            println();
        }
    }
};
