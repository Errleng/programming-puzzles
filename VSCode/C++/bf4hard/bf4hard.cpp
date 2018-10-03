#include <iostream>
#include <cstring>
#include <string>

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

void KMP_init(string text, int *table) {
    int pos = 1, cnd = 0;
    table[0] = -1;
    while (pos < text.length()) {
        if (text[pos] == text[cnd]) {
            table[pos] = table[cnd];
            ++pos;
            ++cnd;
        } else {
            table[pos] = cnd;
            cnd = table[cnd];
            while (cnd >= 0 && text[pos] != text[cnd]) {
                cnd = table[cnd];
            }
            ++pos;
            ++cnd;
        }
    }
    table[pos] = cnd;
}

int KMP_search(string text, string pattern, int *table) {
    int first_pos = -1;
    int j = 0, k = 0;
    while (j < text.length()) {
        if (text[j] == pattern[k]) {
            ++j;
            ++k;
            if (k == pattern.length()) {
                first_pos = j - k;
                break;
            }
        } else {
            k = table[k];
            if (k < 0) {
                ++j;
                ++k;
            }
        }
    }
    return first_pos;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string text;
    string pattern;
    int *table = new int[1000000]();
    cin >> text >> pattern;
    KMP_init(pattern, table);
    int ans_pos = KMP_search(text, pattern, table);
    printf("%d\n", ans_pos);
    return 0;
}