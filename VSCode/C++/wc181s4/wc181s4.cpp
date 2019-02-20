#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

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

#define MAXN 300001

int N, S[MAXN], D[MAXN], R[MAXN];
bool phone[MAXN];

struct Student {
    int id, s, d, r;
    Student(int i, int a, int b, int c) {
        id = i;
        s = a;
        d = b;
        r = c;
    }
};
vector<Student> social;

bool sorter(Student a, Student b) {
    return a.s > b.s;
}

void phoneOut(Student s, int nStudents) {
    phone[s.id] = true;
    rep(i, nStudents) {
        Student r = social[i];
        int dif = s.d - s.r;
        int sum = s.d + s.r;
        bool affected = r.s < s.s && dif <= r.d && r.d <= sum;
        if (s.id != r.id && affected) {
            phoneOut(r, nStudents);
        }
    }
}

int main() {
    scan(N);
    rep(i, N) {
        scan(S[i]);
        scan(D[i]);
        scan(R[i]);
        social.pb(Student(i, S[i], D[i], R[i]));
        mem(phone, false);
        sort(social.begin(), social.end(), sorter);
        int count = 0;
        rep(j, i) {
            Student s = social[j];
            if (!phone[s.id]) {
                phoneOut(s, i);
                count++;
            }
        }
        if (count == 0) {
            count = 1;
        }
        printf("%d\n", count);
    }
    return 0;
}