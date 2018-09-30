#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define rep(i, j) repn(i, 0, j, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define INF 0x3f3f3f3f

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int A, B, N, temp, *memo;
vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int findPaths(int pos) {
    if (memo[pos] != -1) {
        return memo[pos];
    }
    if (pos == motels.size() - 1) {
        return memo[pos] = 1;
    }
    int paths = 0;
    repn(i, pos + 1, motels.size(), 1) {
        int dist = abs(motels[i] - motels[pos]);
        if (dist > B) {
            break;
        } else if (dist >= A) {
            paths += findPaths(i);
        }
    }
    return memo[pos] = paths;
}

int main() {
    scan(A);
    scan(B);
    scan(N);
    rep(i, N) {
        scan(temp);
        motels.push_back(temp);
    }
    sort(motels.begin(), motels.end());
    memo = new int[motels.size()]();
    fill(memo, memo+motels.size(), -1);
    printf("%d\n", findPaths(0));
    return 0;
}