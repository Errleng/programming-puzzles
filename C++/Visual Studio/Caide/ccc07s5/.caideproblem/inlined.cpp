#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


#include <chrono>
#include <iostream>

#define SZ(c) (int)(c).size()

static void timing(bool end) {
    const int MICROSECOND_LIMIT = 1000;
    const int MILLISECOND_LIMIT = 10000;

    static std::chrono::high_resolution_clock::time_point startPoint;

    if (end) {
        std::chrono::high_resolution_clock::time_point endPoint = std::chrono::high_resolution_clock::now();

        std::chrono::microseconds elapsedMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(endPoint - startPoint);
        std::chrono::milliseconds elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint);
        std::chrono::seconds elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(endPoint - startPoint);

        if (elapsedMicroseconds.count() <= MICROSECOND_LIMIT) {
            std::cerr << "MICRO = " << elapsedMicroseconds.count() << std::endl;
        } else if (elapsedMilliseconds.count() <= MILLISECOND_LIMIT) {
            std::cerr << "MILLI = " << elapsedMilliseconds.count() << std::endl;
        } else {
            std::cerr << "Seconds = " << elapsedSeconds.count() << std::endl;
        }
    } else {
        startPoint = std::chrono::high_resolution_clock::now();
    }
}


using namespace std;
// Powered by caide (code generator, tester, and library code inliner)

class Solution {
  public:
    void solve(std::istream &in, std::ostream &out) {

        int t;
        in >> t;
        while (t-- > 0) {
            timing(false);

            int n, k, w;
            in >> n >> k >> w;
            int nSize = n + 1, kSize = k + 1;

            vector<int> scores(nSize);
            vector<int> sums(nSize);
            vector<vector<int>> dp(nSize, vector<int>(kSize));

            for (size_t i = 1; i < nSize; i++) {
                in >> scores[i];
            }

            for (size_t i = 1; i < nSize; i++) {
                sums[i] = sums[i - 1] + scores[i];
            }

            for (size_t i = 1; i < nSize; i++) {
                for (size_t j = 1; j < kSize; j++) {
                    if (i >= w) {
                        dp[i][j] = max(dp[i - 1][j], (sums[i] - sums[i - w]) + dp[i - w][j - 1]);
                    } else {
                        dp[i][j] = max(dp[i - 1][j], sums[i]);
                    }
                }
            }

            out << dp[n][k] << endl;

            timing(true);
        }
    }
};

void solve(std::istream &in, std::ostream &out) {
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

#define CAIDE_STDIN 1
#define CAIDE_STDOUT 1
#include <fstream>


void solve(std::istream& in, std::ostream& out);
int main() {
    using namespace std;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef CAIDE_STDIN
    istream& in = cin;
#else
    ifstream in(CAIDE_IN_FILE);
#endif

#ifdef CAIDE_STDOUT
    ostream& out = cout;
#else
    ofstream out(CAIDE_OUT_FILE);
#endif
    solve(in, out);
    return 0;
}



/// dummy.cpp: force creation of static library in VsCaide extension.
/// Feel free to remove this file when you add at least one 'real' cpp file.
void dummy_caide_function () {
}


