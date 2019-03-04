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
#include "functions.h"
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) { int N;
        in >> N;

        vector<vector<char>> fornias(N, vector<char>(N));

        for (size_t i = 0; i < N; i++) {
            string cali;
            in >> cali;
            for (size_t j = 0; j < cali.length(); j++) {
                fornias[i][j] = cali[j];
            }
        }
        print2D(fornias);
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
