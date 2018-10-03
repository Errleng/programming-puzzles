#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define rep(i, j) repn(i, 0, j, 1)
#define srep(i, j, k) repn(i, j, k, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), A(b), sizeof(a))

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

class SegmentTree {
public:
    int *seg;
    int *origin;
    int len;

    SegmentTree(int input[], int N) {
        len = N;
        origin = new int[N];

        rep(i, N) {
            origin[i] = input[i];
        }

        int height = static_cast<int>(ceil(log2(N)));
        int max_size = 2 * static_cast<int>(pow(2, height)) - 1;
        seg = new int[max_size];
        this->construct_segment_tree(input, 0, N - 1, 0);
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

    int get_mid(int start, int end) {
        return start + (end - start) / 2;
    }

    void update_value(int i, int new_val) 
    { 
        if (i < 0 || i > len - 1) { 
            return; 
        } 
  
        int diff = new_val - origin[i]; 
  
        // origin[i] = new_val; 
  
        update_value_recur(0, len - 1, i, diff, 0); 
    }

    void update_value_recur(int start, int se, int i, int diff, int curr) 
    { 
        if (i < start || i > se) 
            return; 
  
        seg[curr] = seg[curr] + diff; 
        if (se != start) { 
            int mid = get_mid(start, se); 
            update_value_recur(start, mid, i, diff, 2 * curr + 1); 
            update_value_recur(mid + 1, se, i, diff, 2 * curr + 2); 
        } 
    } 

    // void update_value(int arr[], int i, int new_val) 
    // { 
    //     if (i < 0 || i > len - 1) { 
    //         return; 
    //     } 
  
    //     int diff = new_val - arr[i]; 
  
    //     arr[i] = new_val; 
  
    //     update_value_recur(0, len - 1, i, diff, 0); 
    // }
    int sum_query(int r_s, int r_e) 
    { 
        if (r_s < 0 || r_e > len - 1 || r_s > r_e) { 
            return -1; 
        } 
        return sum_query_recur(0, len - 1, r_s, r_e, 0); 
    } 

    int sum_query_recur(int s, int e, int r_s, int r_e, int curr) {
        if (r_s <= s && r_e >= e) 
            return seg[curr]; 
  
        if (e < r_s || s > r_e) 
            return 0; 
  
        int mid = get_mid(s, e); 
        return sum_query_recur(s, mid, r_s, r_e, 2 * curr + 1) + sum_query_recur(mid + 1, e, r_s, r_e, 2 * curr + 2); 
    }

    int RMQ(int r_s, int r_e) {
        if (r_s < 0 || r_e > len - 1 || r_s > r_e)
            return -1;
        return RMQ_recur(0, len - 1, r_s, r_e, 0);
    }

    int RMQ_recur(int s, int e, int r_s, int r_e, int curr) {
        if (r_s <= s && r_e >= e)
            return seg[curr];
        if (e < r_s || s > r_e)
            return INF;
        int mid = get_mid(s, e);
        return min(RMQ_recur(s, mid, r_s, r_e, 2 * curr + 1), RMQ_recur(mid + 1, e, r_s, r_e, 2 * curr + 2));
    }

    int GCD(int r_s, int r_e) {
        if (r_s < 0 || r_e > len - 1 || r_s > r_e)
            return -1;
        return GCD_recur(0, len - 1, r_s, r_e, 0);
    }

    int GCD_recur(int s, int e, int r_s, int r_e, int curr) {
        if (r_s <= s && r_e >= e)
            return seg[curr];
        if (e < r_s || s > r_e)
            return INF;
        int mid = get_mid(s, e);
        return __gcd(GCD_recur(s, mid, r_s, r_e, 2 * curr + 1), GCD_recur(mid + 1, e, r_s, r_e, 2 * curr + 2));
    }

    int CNT_EQ(int r_s, int r_e, int val) {
        if (r_s < 0 || r_e > len - 1 || r_s > r_e)
            return -1;
        return CNT_EQ_recur(0, len - 1, r_s, r_e, 0, val);
    }

    int CNT_EQ_recur(int s, int e, int r_s, int r_e, int curr, int val) { // WIP
        if (r_s <= s && r_e >= e) {
            if (r_s == r_e) {
                if (val == seg[curr])
                    return 1;
                else 
                    return 0;
            }
        }
        if (e < r_s || s > r_e)
            return INF;
        int mid = get_mid(s, e);
        return CNT_EQ_recur(s, mid, r_s, r_e, 2 * curr + 1, val) + CNT_EQ_recur(mid + 1, e, r_s, r_e, 2 * curr + 2, val);
    }
};

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 2, 3, 6, 9, 5};
    SegmentTree *tree = new SegmentTree(arr, sizeof(arr)/sizeof(arr[0]));
    println("Sum(1, 3) =", tree->sum_query(1, 3)); // 15
    println("RMQ(1, 5) =", tree->RMQ(1, 5)); // 3
    tree->update_value(1, 10);
    println("Sum(1, 3) =", tree->sum_query(1, 3)); // 22
    println("GCD(6, 10) =", tree->GCD(7, 9)); // 3
    println("CNT EQ(1, 10, 5) =", tree->CNT_EQ(1, 10, 5)); // 2
    return 0;
}