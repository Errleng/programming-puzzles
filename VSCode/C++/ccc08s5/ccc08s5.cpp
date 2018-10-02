#include <iostream>
#include <cstring>
#include <tuple>

#define repn(i, j, k, step) for (int i=j ; i<k ; i+=step)
#define rrepn(i, j, k, step) for (int i=j ; i>=k ; i-=step)
#define rep(i, j) repn(i, 0, j, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define INF 0x3f3f3f3f

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXP 31

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
    cout << var << endl;
    print(args...);
}

int N, A, B, C, D, memo[MAXP][MAXP][MAXP][MAXP];
struct Particles {
    int A, B, C, D;
};

int reactions[5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};

bool perfect(int p[]) {
    if (memo[p[0]][p[1]][p[2]][p[3]] != -1)
        return memo[p[0]][p[1]][p[2]][p[3]];
    bool res = false;
    bool canReact;
    int newP[4];
    for (int i = 0; i < 5 && !res; ++i) {
        rep(j, 4) {
            canReact = true;
            newP[j] = p[j];
            if (newP[j] >= reactions[i][j]) {
                newP[j] -= reactions[i][j];
            } else {
                canReact = false;
                break;
            }
        }
        if (canReact) {
            res = !perfect(newP);
        }
    }
    return memo[p[0]][p[1]][p[2]][p[3]] = res;
}

int main() {
    int particles[4];
    scan(N);
    mem(memo, -1);
    rep(_, N) {
        scanf("%d %d %d %d", &particles[0], &particles[1], &particles[2], &particles[3]);
        printf("%s\n", perfect(particles) ? "Patrick" : "Roland");
    }
    return 0;
}