#include <cstring>
#include <iostream>
#include <queue>

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

int N;
int cnt = 0;

struct word {
    string s;
    word(string str) { s = str; }
};

int main() {
    scan(N);
    queue<word> q;
    string empty = "";
    q.push(word(empty));
    while (cnt < N) {
        word w = q.front();
        q.pop();
        rep(i, 26) { q.push(word(w.s + (char)(i + 'a'))); }
        if (w.s != "") {
            cout << w.s;
            if (cnt + 1 < N) {
                cout << " ";
            }
            cnt++;
        }
    }
    return 0;
}