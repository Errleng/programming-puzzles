#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    int out = (N <= 5) ? (N/2 + 1) : ((10-N)/2+1);
    cout << out << '\n';
    return 0;
}