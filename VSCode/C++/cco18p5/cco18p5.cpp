#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#include "../Library/debug.h"

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

#define MAXN 1000001

int N, K, Q, quality[MAXN];

struct SegTree {
    int len;
    int size;
    int s_idx;
    int *seg;
    int *input;
    SegTree(int N, int original[], int start) {
        len = N;
        input = original;
        s_idx = start;

        int height = (int)(ceil(log2(N)));
        size = 2 * (1 << height) - 1;

        seg = new int[size]();
        construct(start, 0, len - 1);
    }
    int getMid(int s, int e) {
        return (s + e) / 2;
    }
    void construct(int curr, int s, int e) {
        if (s == e) {
            seg[curr] = s;
            return;
        }
        int mid = getMid(s, e);
        int id1 = (curr << 1) + 1;
        int id2 = (curr << 1) + 2;
        construct(id1, s, mid);
        construct(id2, mid + 1, e);
        if (input[seg[id1]] > input[seg[id2]]) {
            seg[curr] = seg[id1];
        } else {
            seg[curr] = seg[id2];
        }
    }
    void update(int start, int r_s, int r_e) {
        update_h(start, 0, len - 1, r_s, r_e);
    }
    void update_h(int curr, int s, int e, int r_s, int r_e) {
        if (s > r_s || e < r_s) {
            return;
        }
        if (s == e) {
            seg[curr] = r_e;
            return;
        }
        int mid = getMid(s, e);
        int id1 = (curr << 1) + 1;
        int id2 = (curr << 1) + 2;
        update_h(id1, s, mid, r_s, r_e);
        update_h(id2, mid + 1, e, r_s, r_e);
        seg[curr] = max(seg[id1], seg[id2]);
    }
    void update_2(int start, int r_s) {
        update_2_h(start, 0, len - 1, r_s);
    }
    void update_2_h(int curr, int s, int e, int r_s) {
        if (s > r_s || e < r_s) {
            return;
        }
        if (s == e) {
            seg[curr] = s;
            return;
        }
        int mid = getMid(s, e);
        int id1 = (curr << 1) + 1;
        int id2 = (curr << 1) + 2;
        update_2_h(id1, s, mid, r_s);
        update_2_h(id2, mid + 1, e, r_s);
        if (input[seg[id1]] > input[seg[id2]]) {
            seg[curr] = seg[id1];
        } else {
            seg[curr] = seg[id2];
        }
    }
    int query(int r_s, int r_e) {
        return query_h(s_idx, 0, len - 1, r_s, r_e);
    }
    int query_h(int curr, int s, int e, int r_s, int r_e) {
        if (s > r_e || e < r_s || r_s > r_e) {
            return len;
        }
        if (s >= r_s && e <= r_e) {
            return seg[curr];
        }
        int mid = getMid(s, e);
        int id1 = (curr << 1) + 1;
        int id2 = (curr << 1) + 2;
        int a = query_h(id1, s, mid, r_s, r_e);
        int b = query_h(id2, mid + 1, e, r_s, r_e);
        if (input[a] > input[b]) {
            return a;
        } else {
            return b;
        }
    }
};

int main() {
    int a, b, c, d;
    scan(N);
    scan(K);
    scan(Q);
    rep(i, N) {
        scan(quality[i]);
    }
    SegTree one(N, quality, 1);
    rep(i, N) {
        a = one.query(max(0, i - K + 1), i - 1);
        b = one.query(i + 1, min(N - 1, i + K - 1));
        if (quality[a] < quality[i] && quality[i] > quality[b]) {
            one.update(1, i, quality[i] + max(quality[a], quality[b]));
        }
    }
    printf("%d\n", one.seg[1]);
    rep(i, Q) {
        scan(a);
        scan(b);
        quality[--a] = b;
        one.update_2(1, a);
        c = one.query(max(0, a - K + 1), a - 1);
        d = one.query(a + 1, min(N - 1, a + K - 1));
        if (quality[a] < quality[c] && quality[a] > quality[d]) {
            one.update(1, a, quality[a] + max(quality[a], quality[d]));
        } else {
            one.update(1, a, 0);
            if (quality[c]) {
                c = one.query(c + 1, min(N - 1, c + K - 1));
                b = one.query(min(0, c - K + 1), c - 1);
            }
            if (quality[d]) {
                c = one.query(c + 1, min(N - 1, c + K - 1));
                b = one.query(max(0, c - K + 1), c - 1);
            }
        }
    }
    printf("%d\n", one.seg[1]);
    return 0;
}