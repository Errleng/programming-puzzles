#include <iostream>
#include <cstring>

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

int main() {
    return 0;
}