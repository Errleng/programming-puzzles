#include <iostream>

#define MAXN 100001

using namespace std;

int N, swifts[MAXN], sephamores[MAXN];
int sumSwifts[MAXN], sumSephamores[MAXN];

int main() {
    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> swifts[i];
        sumSwifts[i] = sumSwifts[i-1] + swifts[i];
    }
    for (int i=1; i<=N; ++i) {
        cin >> sephamores[i];
        sumSephamores[i] = sumSephamores[i-1] + sephamores[i];
    }
    int K = 0;
    for (int i=1; i<=N; ++i) {
        if (sumSwifts[i] == sumSephamores[i]) {
            K = i;
        }
    }
    cout << K << '\n';
    return 0;
}