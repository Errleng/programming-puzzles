#include <bits/stdc++.h>

using namespace std;

void print() {
    cout << endl;
}

template <typename T, typename... Args>
void print(T curArg, Args&&... remArgs) {
    cout << curArg << " ";
    print(remArgs...);
}

template <typename T>
void print1D(T arr1D, size_t N) {
    for (int elem = 0; elem < N; ++elem) {
        cout << arr1D[elem] << " ";
    }
    cout << endl;
}

template <typename T>
void print2D(T arr2D, size_t N, size_t M) {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cout << arr2D[r][c] << " ";
        }
        cout << '\n';
    }
    cout << endl;
}