#include "../library/lib.hpp"
#include <iostream>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

class cco07p3 {
public:
    void solve(std::istream &in, std::ostream &out) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        in.tie(nullptr);

        int t, n, k, w, range;
        in >> t;
        for (int _ = 0; _ < t; ++_) {
            in >> n >> k >> w;
            range = n+w;

            int scores[n+1];
            memset(scores, 0, sizeof(scores));
            int scoreSums[range+1];
            memset(scoreSums, 0, sizeof(scoreSums));
            int dp[k+1][range+1];
            memset(dp, 0, sizeof(dp));

            for (int i = 1; i <= n; ++i) {
                in >> scores[i];
            }

            for (int i = 1; i <= range; ++i) {
                scoreSums[i] = scoreSums[i-1] + scores[i];
            }

            for (int i = 1; i <= k; ++i) {
                for (int j = 1; j <= range; ++j) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            out << dp[k][range] << endl;
        }
    }
};
