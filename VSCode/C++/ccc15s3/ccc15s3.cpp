#include <iostream>
#include <cstring>
#include <vector>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define rep(i, j) repn(i, 0, j, 1)
#define srep(i, j, k) repn(i, j, k, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

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

int main() {
    int G, P, g, low, high, mid, gate;
    scan(G);
    scan(P);
    vector<int> free;
    srep(i, 1, G + 1) {
        free.emplace_back(i);
    }
    rep(i, P) {
        scan(g);
        gate = -1;
        low = 0;
        high = free.size() - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (free[mid] > g) {
                high = mid - 1;
            } else if (free[mid] < g) {
                gate = mid;
                low = mid + 1;
            } else {
                gate = mid;
                break;
            }
        }
        if (gate != -1) {
            free.erase(free.begin() + gate);
        } else {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", P);
    return 0;
}