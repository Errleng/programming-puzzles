#include <bits/stdc++.h>

// clang-format off
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// clang-format on

#define FOR(i, a) for (int i = 0; i < (a); ++i)
#define FORN(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef unsigned long long ull;
void print() { cout << endl; }
template <typename T, typename... Args>
void print(T curArg, Args &&... remArgs) {
  cout << curArg << " ";
  print(remArgs...);
}

template <typename T, size_t N> void printL(T (&arr1D)[N]) {
  for (size_t elem = 0; elem < N; ++elem) {
    cout << arr1D[elem] << " ";
  }
  cout << endl;
}

template <typename T> void printA(T *arr, size_t N) {
  for (size_t elem = 0; elem < N; ++elem) {
    cout << arr[elem] << " ";
  }
  cout << endl;
}

template <typename T, size_t N, size_t M> void print2DL(T (&arr2D)[N][M]) {
  for (size_t r = 0; r < N; ++r) {
    for (size_t c = 0; c < M; ++c) {
      cout << arr2D[r][c] << " ";
    }
    cout << '\n';
  }
  cout << endl;
}

template <typename T> void print2DA(T **arrSqr, size_t N, size_t M) {
  for (size_t row = 0; row < N; ++row) {
    for (size_t column = 0; column < M; ++column) {
      cout << arrSqr[row][column] << " ";
    }
    cout << '\n';
  }
  cout << endl;
}

template <typename T> void printSquare(T **arrSqr, size_t N) {
  for (size_t row = 0; row < N; ++row) {
    for (size_t column = 0; column < N; ++column) {
      cout << arrSqr[row][column] << " ";
    }
    cout << '\n';
  }
  cout << endl;
}

// const int INF = 1e9;
// int n, m, k;
// int *r, *c;
// int **dp;

// struct Point {
//    ll f, s;
//    Point() {}
//    Point(ll first, ll second) {
//        this->f = first;
//        this->s = second;
//    }

//};

// ostream& operator << (ostream &o, const Point& p) {
//    o << "(" << p.f << "," << p.s << ")";
//    return o;
//}

// bool pointCmp(Point const& p1, Point const& p2) {
//    return (p1.f < p2.f);
//}

// Point* P;

// ll take_photos(int n, int m, int k, int *r, int *c) {
//    FOR(i, n) {
//        P[i] = Point(r[i], c[i]);
//    }
//    FOR(i, n+1) {
//        FOR(j, k+1) {
//            if (i == 0)
//                dp[i][j] = 0;
//            else
//                dp[i][j] = INF;
//        }
//    }
//    printA(P, n);
//    sort(P, P + n, pointCmp);
//    printA(P, n);
//    print2DA(dp, n+1, k+1);
//    FORN(i, 1, n+1) {
//        FORN(j, 1, k+1) {
//            FOR(t, i) {
//                dp[i][j] = min(dp[i][j], (int)(dp[t][j-1] + pow((P[i-1].f -
//                P[i-1].s + 1), 2)));
//            }
//        }
//    }
//    print2DA(dp, n+1, k+1);
//    return dp[n][k];
//}

// void Solve() {
//    scan(n);
//    scan(m);
//    scan(k);
//    print(n, m, k);
//    r = new int[n];
//    c = new int[n];
//    P = new Point[n];
//    dp = new int*[n+1];
//    FOR(i, n) {
//        scan(r[i]);
//        scan(c[i]);
//    }
//    FOR(i, n+1) {
//        dp[i] = new int[k+1];
//    }
//    printf("%lld\n", take_photos(n, m, k, r, c));
//}

void Solve() {
  const int INF = 0x3f3f3f3f;
  const int MAXN = 200000;
  int N, M, K;
  int W = INF;
  int a, b;
  scan(N);
  scan(M);
  scan(K);
  int potats[MAXN] = { 0 };
  potats[0] = M;
  FOR(i, M) {
    scan(a);
    scan(b);
    potats[a - 1]--;
    potats[b]++;
  }
  FORN(i, 1, N) { potats[i] += potats[i - 1]; }
  int sum = 0;
  int lo = 0;
  FOR(hi, N) {
    sum += potats[hi];
    if (sum >= K) {
      cout << hi << " " << lo << ": " << sum << " ";
      while (sum - potats[lo] >= K) {
        sum -= potats[lo];
        lo++;
        cout << sum << " ";
      }
      W = min(W, hi - lo + 1);
      print(W);
    }
  }
  if (W == INF)
    W = -1;
  printf("%d", W);
}

int main() {
  freopen("input.txt", "r", stdin);

  time_point<steady_clock> start = steady_clock::now();

  Solve();

  time_point<steady_clock> end = steady_clock::now();
  auto diff = duration_cast<milliseconds>(end - start);
  cout << "\nTime: " << diff.count() << " ms" << endl;
  return 0;
}
