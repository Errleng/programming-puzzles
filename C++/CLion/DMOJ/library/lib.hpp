#include <iostream>

using namespace std;

void print() {
    return;
}

template<typename T, typename... Types>
void print(T var1, Types... var2) {
    cout << var1 << " ";
    print(var2...);
}

void println() {
    cout << endl;
}

template<typename T, typename... Types>
void println(T var1, Types... var2) {
    cout << var1 << " ";
    println(var2...);
}

template<typename T, size_t N>
void print1D(T(&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T, size_t R, size_t C>
void print2D(T(&arr)[R][C]) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

