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


template <typename T> void print1D(const std::vector<T> &vec) {
    const std::string PRINT_DELIMITER = " ";
    
    bool first = true;
    for (auto &i : vec) {
        if (!first) {
            std::cerr << PRINT_DELIMITER;
        } else {
            first = false;
        }
        std::cerr << i;
    }
    std::cerr << std::endl;
}

template <typename T> void print2D(const std::vector<std::vector<T>> &vec2D) {
    for (auto &i : vec2D) {
        print1D(i);
    }
}

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


#include <fstream>


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}


