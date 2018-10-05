#include <iostream>
#include <cstring>
#include <cmath>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define rep(i, j) repn(i, 0, j, 1)
#define srep(i, j, k) repn(i, j, k, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define fi first
#define se second
#define pb push_back

#define INF 0x3f3f3f3f

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

void print() {}

template<typename T, typename... Types>
void print(T var, Types... args) {
    cout << var << " ";
    print(args...);
}

void println() {
    cout << endl;
}

template<typename T, typename... Types>
void println(T var, Types... args) {
    cout << var << " ";
    println(args...);
}

#define MAXN 1000001

class SegmentTree {
    int *seg;
    int len;

    SegmentTree(int input[], int N) {
        len = N;
        int height = static_cast<int>(ceil(log2(N)));
        int max_size = 2 * static_cast<int>(pow(2, height)) - 1;
        seg = new int[max_size];
        this->construct_segment_tree(input, 0, N - 1, 0);
    }

    int get_mid(int start, int end) {
        return start + (end - start) / 2;
    }

    int sum_query_recur(int s, int e, int range_s, int range_e, int curr) {
        if (range_s <= s && range_e >= e) {
            return seg[curr];
        }
        if (e >= range_s && s <= range_e) {
            int mid = get_mid(s, e);
            return sum_query_recur(s, mid, range_s, range_e, 2 * curr + 1) + sum_query_recur(mid + 1, s, range_s, range_e, 2 * curr + 2);
        }
        return 0;
    }

    int sum_query(int start, int end) {
        if (start > 0 || end < len || start <= end) {
            return sum_query_recur(0, len - 1, start, end, 0);
        }
        return -1;
    }

    int construct_segment_tree(int input[], int start, int end, int curr) {
        if (start == end) {
            seg[curr] = input[start];
            return seg[curr];
        }
        int mid = get_mid(start, end);
        seg[curr] = construct_segment_tree(input, start, mid, curr * 2 + 1) + construct_segment_tree(input, mid + 1, end, curr * 2 + 2);
        return seg[curr];
    }
};

int N, K, Q, quality[MAXN];

int main() {
    int a, b;
    scan(N);
    scan(K);
    scan(Q);
    srep(i, 1, N + 1) {
        scan(quality[i]);
    }
    rep(i, Q) {
        scan(a);
        scan(b);
        quality[a] = b;
    }
    return 0;
}