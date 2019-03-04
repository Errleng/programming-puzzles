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
        std::chrono::high_resolution_clock::time_point endPoint =
            std::chrono::high_resolution_clock::now();

        std::chrono::microseconds elapsedMicroseconds =
            std::chrono::duration_cast<std::chrono::microseconds>(endPoint -
                                                                  startPoint);
        std::chrono::milliseconds elapsedMilliseconds =
            std::chrono::duration_cast<std::chrono::milliseconds>(endPoint -
                                                                  startPoint);
        std::chrono::seconds elapsedSeconds =
            std::chrono::duration_cast<std::chrono::seconds>(endPoint -
                                                             startPoint);

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

void print() {}

template <typename T> void print(const T &item) { std::cerr << item; }

template <typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    const std::string PRINT_DELIMITER = " ";

    std::cerr << head << PRINT_DELIMITER;
    print(tail...);
}

void println() { std::cerr << std::endl; }

template <typename T> void println(const T &item) {
    std::cerr << item << std::endl;
}

template <typename Head, typename... Tail>
void println(const Head &head, const Tail &... tail) {
    const std::string PRINT_DELIMITER = " ";

    std::cerr << head << PRINT_DELIMITER;
    println(tail...);
}

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


