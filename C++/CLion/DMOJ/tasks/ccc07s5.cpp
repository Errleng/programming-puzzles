#include "../library/lib.hpp"
#include <iostream>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

class ccc07s5 {
public:
    void solve(std::istream &in, std::ostream &out) {
        cin.sync_with_stdio(false);
        cin.tie(nullptr);
        in.sync_with_stdio(false);
        in.tie(nullptr);

        int t, n, k, w;
        in >> t;

        for (int _ = 0; _ < t; ++_) {
            in >> n >> k >> w;

            int scores[n + 1];
            memset(scores, 0, sizeof(scores));
            int sumPins[n + 1];
            memset(sumPins, 0, sizeof(sumPins));
            int dp[k + 1][n + 1]; // dp[ball amount][pin index]
            memset(dp, 0, sizeof(dp));

            for (int i = 1; i <= n; ++i) {
                in >> scores[i];
                for (int j = 0; j < w && j <= i; ++j) {
                    sumPins[i] += scores[i - j]; // original position + everything up to it
                }
            }

            for (int i = 1; i <= k; ++i) {
                for (int j = 1; j <= n; ++j) {
                    int sum = sumPins[j]; // sum of pins up to j
                    if (j >= w) { // pin index is greater than width, allowing ball to hit all
                        sum += dp[i - 1][j - w]; // one less ball and pin index shifted by ball width
                    }
                    dp[i][j] = max(dp[i][j - 1], sum);
                }
            }
            out << dp[k][n] << endl;
        }
    }
};
