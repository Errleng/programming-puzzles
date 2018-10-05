#include <cmath>
#include <cstring>
#include <iostream>

#define repn(i, j, k, step) for (int i = j; i < k; i += step)
#define rrepn(i, j, k, step) for (int i = j; i >= k; i -= step)
#define rep(i, j) repn(i, 0, j, 1)
#define srep(i, j, k) repn(i, j, k, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define fi first
#define se second
#define pb push_back

#define INF 0x3f3f3f3f

// clang-format off
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// clang-format on

using namespace std;

void print() {}

template <typename T, typename... Types> void print(T var, Types... args) {
    cout << var << " ";
    print(args...);
}

void println() { cout << endl; }

template <typename T, typename... Types> void println(T var, Types... args) {
    cout << var << " ";
    println(args...);
}

#define MAXN 100000

int N, M, a, b, arr[MAXN], cnt[MAXN];
char c;

int main() {
    scan(N);
    scan(M);
    srep(i, 1, N + 1) {
        scan(arr[i]);
        ++cnt[arr[i]];
    }
    SegmentTree tree(arr, MAXN + 1);
    SegmentTree cnts(cnt, MAXN + 1);
    rep(i, M) {
        scanf(" %c", &c);
        switch (c) {
        case 'C': {
            scan(a);
            scan(b);
            tree.update_value(a, b);
            --cnt[arr[a]];
            cnts.update_value(arr[a], cnt[arr[a]]);
            arr[a] = b;
            ++cnt[b];
            cnts.update_value(b, cnt[b]);
            break;
        }
        case 'Q': {
            scan(a);
            printf("%d\n", cnts.sum_query(0, a));
            break;
        }
        case 'S': {
            scan(a);
            scan(b);
            printf("%d\n", tree.sum_query(a, b));
            break;
        }
        default: {
            println("Something bad has been inputted:", c);
            break;
        }
        }
    }
    return 0;
}