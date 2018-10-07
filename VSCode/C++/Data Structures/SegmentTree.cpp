#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;
#define fi first
#define se second
#define pb push_back

#define INF 0x3f3f3f3f

typedef std::pair<int, int> pii;

class SegmentTree {
public:
    int *seg;
    int *origin;
    int len;
    int size;

    pii maxTwo;

    SegmentTree(int input[], int N) {
        len = N;
        origin = new int[N];

        for (int i = 0; i < N; ++i) {
            origin[i] = input[i];
        }

        int height = static_cast<int>(ceil(log2(N)));
        size = 2 * static_cast<int>(pow(2, height)) - 1;
        seg = new int[size]();
        this->construct_segment_tree(input, 0, N - 1, 0);
    }

    SegmentTree(int N) {
        len = N;
        origin = new int[N]();
        int height = static_cast<int>(ceil(log2(N)));
        size = 2 * static_cast<int>(pow(2, height)) - 1;
        seg = new int[size]();
        this->construct_segment_tree(origin, 0, N - 1, 0);
    }

    int construct_segment_tree(int input[], int start, int end, int curr) {
        if (start == end) {
            seg[curr] = input[start];
            return seg[curr];
        }
        int mid = get_mid(start, end);
        seg[curr] = construct_segment_tree(input, start, mid, curr * 2 + 1) +
                    construct_segment_tree(input, mid + 1, end, curr * 2 + 2);
        return seg[curr];
    }

    int get_mid(int start, int end) {
        return start + (end - start) / 2;
    }

    void update_value(int i, int new_val) {
        if (i < 0 || i > len - 1) {
            return;
        }

        int diff = new_val - origin[i];

        // origin[i] = new_val;

        update_value_recur(0, len - 1, i, diff, 0);
    }

    void update_value_recur(int s, int e, int i, int diff, int curr) {
        if (i < s || i > e)
            return;

        seg[curr] += diff;
        if (e != s) {
            int mid = get_mid(s, e);
            update_value_recur(s, mid, i, diff, 2 * curr + 1);
            update_value_recur(mid + 1, e, i, diff, 2 * curr + 2);
        }
    }

    int query(int r_s, int r_e, int err, int (*f)(int, int)) {
        if (r_s < 0 || r_e > len - 1 || r_s > r_e) {
            return -1;
        }
        return query_recur(0, len - 1, r_s, r_e, 0, err, f);
    }

    int query_recur(int s, int e, int r_s, int r_e, int curr, int err,
                    int (*f)(int, int)) {
        if (r_s <= s && r_e >= e)
            return seg[curr];

        if (e < r_s || s > r_e)
            return err;

        int mid = get_mid(s, e);
        return f(query_recur(s, mid, r_s, r_e, 2 * curr + 1, err, f),
                 query_recur(mid + 1, e, r_s, r_e, 2 * curr + 2, err, f));
    }

    int sum_query(int r_s, int r_e) {
        return query(r_s, r_e, 0, [](int a, int b) -> int { return a + b; });
    }

    int min_query(int r_s, int r_e) {
        return query(r_s, r_e, INF,
                     [](int a, int b) -> int { return std::min(a, b); });
    }

    int max_query(int r_s, int r_e) {
        return query(r_s, r_e, -INF,
                     [](int a, int b) -> int { return std::max(a, b); });
    }
};