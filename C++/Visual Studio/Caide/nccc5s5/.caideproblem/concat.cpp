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

#define CAIDE_STDIN 1
#define CAIDE_STDOUT 1
#include <fstream>
#include <iostream>

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


