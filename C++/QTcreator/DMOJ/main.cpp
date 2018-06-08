#include<chrono>
using namespace std::chrono;

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string>

//#include <map>
#include <bits/stdc++.h>

typedef std::pair<int,int> pii;
using namespace std;

typedef pair<int,int> pii;
map<int, long long> memo;
int N;
long long recursion(int n) {
    long long ans = memo[n];
    if (ans) {
        return memo[n];
    }
    if (n == 1) {
        return 1;
    }
    for (int i = 1; i <= sqrt(N); i++) {
        ans += (n/i - n/(i+1)) * recursion(i);
        if (i >= 2 && n/i > sqrt(N)) {
            ans += recursion(n/i);
        }
    }
    memo[n] = ans;
    return ans;
}

int main() {
    N = 10;
    cout << recursion(N) << endl;
}

//int main(int argc, char *argv[])
//{
//    high_resolution_clock::time_point t1 = high_resolution_clock::now();

//    // INSERT CODE BELOW
//    S4_2018();

//    high_resolution_clock::time_point t2 = high_resolution_clock::now();

//    auto duration = duration_cast<microseconds>(t2 - t1).count();

//    cout << "END" << endl;

//    cout << "Execution took " << duration << " microseconds" << endl;
//    duration = duration_cast<milliseconds>(t2 - t1).count();
//    cout << "Execution took " << duration << " milliseconds" << endl;
//    return 0;
//}
