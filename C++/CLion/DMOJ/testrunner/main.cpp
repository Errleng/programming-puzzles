#include "D:/Documents/SourceTree/Challenges/C++/CLion/DMOJ/tasks/ccc12s4.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
    std::string input;
    std::string output;
    bool active;
    bool has_output;
};

bool check(std::string expected, std::string actual) {
    while(!expected.empty() && isspace(*--expected.end()))
        expected.erase(--expected.end());
    while(!actual.empty() && isspace(*--actual.end()))
        actual.erase(--actual.end());
    return expected == actual;
}

} // namespace jhelper

int main() {
    std::vector<jhelper::Test> tests = {
        {"4\n4 1 3 2\n0\n", "18", true, true},{"1\n1\n2\n2 1\n2\n1 2\n3\n2 3 1\n3\n3 1 2\n0\n", "0\nIMPOSSIBLE\n0\n8\n16\n", true, true},{"3\n1 3 2\n3\n2 1 3\n4\n4 1 3 2\n4\n2 4 1 3\n0\n", "12\n4\n18\n12\n", true, true},{"4\n4 3 2 1\n5\n5 4 3 2 1\n5\n4 3 2 5 1\n5\n2 4 5 1 3\n0\n", "22\n32\n20\n16\n", true, true},{"5\n1 2 5 4 3\n5\n5 2 1 3 4\n6\n6 5 3 4 2 1\n6\n5 4 6 1 2 3\n6\n4 3 5 6 2 1\n0\n", "18\n22\n38\n28\n26\n", true, true},{"7\n2 1 3 4 5 7 6\n7\n2 1 3 4 7 5 6\n6\n4 6 3 1 5 2\n0\n", "16\n18\n28\n", true, true},
    };
    bool allOK = true;
    int testID = 0;
    std::cout << std::fixed;
    double maxTime = 0.0;
    for(const jhelper::Test& test: tests ) {
        std::cout << "Test #" << ++testID << std::endl;
        std::cout << "Input: \n" << test.input << std::endl;
        if (test.has_output) {
            std::cout << "Expected output: \n" << test.output << std::endl;
        }
        else {
            std::cout << "Expected output: \n" << "N/A" << std::endl;
        }
        if (test.active) {
            std::stringstream in(test.input);
            std::ostringstream out;
            std::clock_t start = std::clock();
            ccc12s4 solver;
            solver.solve(in, out);
            std::clock_t finish = std::clock();
            double currentTime = double(finish - start) / CLOCKS_PER_SEC;
            maxTime = std::max(currentTime, maxTime);
            std::cout << "Actual output: \n" << out.str() << std::endl;
            if (test.has_output) {
                bool result = jhelper::check(test.output, out.str());
                allOK = allOK && result;
                std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
            }
            std::cout << "Time: " << currentTime << std::endl;
        }
        else {
            std::cout << "SKIPPED\n";
        }

        std::cout << std::endl;

    }
    if(allOK) {
        std::cout << "All OK" << std::endl;
    }
    else {
        std::cout << "Some cases failed" << std::endl;
    }
    std::cout << "Maximal time: " << maxTime << "s." << std::endl;
    return 0;
}
