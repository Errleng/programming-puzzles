#include <iostream>
#include <chrono>
#include <vector>

#include <queue>

using namespace std;
using namespace std::chrono;

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> wQ;

int main(int argc, char *argv[])
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // INSERT CODE BELOW

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "\nEND\n" << endl;

    cout << "\nExecution took " << duration << " microseconds" << endl;
    duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "\nExecution took " << duration << " milliseconds" << endl;
    return 0;
}
