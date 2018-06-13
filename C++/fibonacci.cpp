#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

const ull P = 2000000016;
const ull MOD = 1000000007;

map<ull, ull> M;

ull fib(ull n) { // Even or Odd Fibonacci calculation. Apparently O(log(N) * log(log(N))) time
    if (M.count(n)) {
        return M[n];
    }
    ull k = n/2;
    if (n % 2 == 0) {
        ull f = fib(k);
        ull s = fib(k-1);
        return M[n] = (f*f + s*s) % MOD;
    }
    else {
        ull f = fib(k);
        return M[n] = (f * fib(k+1) + fib(k-1) * f) % MOD;
    }
}

typedef struct {
  ull a, b;
} Matrix;
ull a, b, c, d;

Matrix Fib (ull n) { // Matrix exponentiation. I should figure out how this works one day. Very fast
    if (!n) return (Matrix) {0, 1};
    else {
        Matrix ret = Fib (n >> 1);
        a = ret.a; 
        b = ret.b;
        c = (ull) (a * (b * 2ull % MOD - a + MOD) % MOD);
        d = (ull) (a * a % MOD + b * b % MOD);
        if (!(n & 1)) return (Matrix) { c % MOD, d % MOD };
        else if (n & 1) return (Matrix) { d % MOD, c % MOD + d % MOD};
    }
}

ull solve(ull n) {
    M[0] = 1;
    M[1] = 1;
    ull rem = n % P;
    return fib(rem-1);
}

unordered_map<ull, ull> smug_map; // Apparently 2x more smug than boring fib()
ull smug_fib(ull n) {
    if (n < 2)
        return 1;
    if (smug_map.find(n) != smug_map.end())
        return smug_map[n];
    return smug_map[n] = (smug_fib((n+1) / 2) * smug_fib(n/2) + smug_fib((n-1) / 2) * smug_fib((n-2) / 2)) % MOD;
}

void better_fib(ull n, ull& x, ull& y) { // Apparently O(log(N)) time
    if (n == 0) {
        x = 0;
        y = 1;
        return;
    }
    
    if (n & 1) {
        better_fib(n - 1, y, x);
        y = (y + x) % MOD;
    } else {
        ull a, b;
        better_fib(n >> 1, a, b);
        y = (a*a + b*b) % MOD;
        x = (a*b + a*(b - a + MOD)) % MOD;
    }
} 

int main() {
    // cin >> N;
    ull N;
    N = 5100007887;

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    cout << Fib(N).a << endl;
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << duration << endl;

    t1 = chrono::high_resolution_clock::now();
    cout << solve(N) << endl;
    t2 = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << duration << endl;

    t1 = chrono::high_resolution_clock::now();
    cout << smug_fib(N-1) << endl;
    t2 = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << duration << endl;

    t1 = chrono::high_resolution_clock::now();
    ull x, y;
    better_fib(N-1, x, y);
    cout << y << endl;
    t2 = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << duration << endl;

    return 0;
}