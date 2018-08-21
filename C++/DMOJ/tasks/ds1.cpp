#include <bits/stdc++.h>

using namespace std;

class BIT {
public:
    int size;
    int *arr;

    explicit BIT(int a) {
        size = a;
        arr = new int[size + 1]();
        for (int i = 1; i <= size; ++i) {
            update(i, arr[i]);
        }
    }

    BIT(int inp[], int N) {
        size = N + 1;
        arr = new int[size]();
        for (int i = 1; i <= size; ++i) {
            update(i, inp[i - 1]);
        }
    }

    void update(int a, int b) {
        while (a <= size) {
            arr[a] += b;
            a += a & (-a);
        }
    }

    int query(int a) {
        int s = 0;
        while (a > 0) {
            s += arr[a];
            a -= a & (-a);
        }
        return s;
    }
};

class ds1 {
public:
    void solve(std::istream &in, std::ostream &out) {
        const int MAXN = 100000;
        int N, M, a, b;
        char op;
        int inp[MAXN];

        in >> N >> M;
        BIT C(N);
        for (int i = 0; i < N; ++i) {
            in >> inp[i];
            C.update(inp[i], 1);
        }
        BIT F(inp, N);
        for (int i = 0; i < M; ++i) {
            in >> op;
            if (op == 'C') {
                in >> a >> b;
                int change = F.query(a) - F.query(a - 1);
                F.update(a, (b - inp[a]));
                C.update(inp[a], -1);
                C.update(b, 1);
            } else if (op == 'S') {
                in >> a >> b;
                out << F.query(b) - F.query(a - 1) << endl;
            } else if (op == 'Q') {
                in >> a;
                out << C.query(a) << endl;
            }
        }
    }
};