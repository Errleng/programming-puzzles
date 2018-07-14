const int MAXN = 10001;
int dp[MAXN][MAXN];
int memo[MAXN][MAXN];
int recur(string str, int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    if (i == 0 || j == 0) return memo[i][j] = 1;
    if (str[i-1] == str[j-1]) {
        return memo[i][j] = (recur(str, i - 1, j) + recur(str, i, j - 1));
    }
    else {
        return memo[i][j] = (recur(str, i, j - 1) + recur(str, i - 1, j)) - recur(str, i - 1, j - 1);
    }
}

void Solve() {
    memset(memo, -1, sizeof(memo));
    int M, n;
    string S;
    cin >> S;
    cin >> M;
    n = S.length();
    FOR(i, n+1) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    FORR(i, 1, n+1) {
        FORR(j, 1, n+1) {
            if (S[i-1] == S[j-1]) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
            }
            else {
                dp[i][j] = ((dp[i-1][j] + dp[i][j-1]) - dp[i-1][j-1]) % M;
            }
        }
    }
	// dp[i][i] = reptivitiy of substring(0, i)
    printf("%d", dp[n][n]);
}

int mod;
char str[11000];
int len;
int dp[10001], old[10001];
int cnt[133];

template <typename T>
void printA(T *arr, size_t N) {
    for (size_t elem = 0; elem < N; ++elem) {
        cout << arr[elem] << " ";
    }
    cout << endl;
}

void add(int& a, int b) {
    if ((a += b) >= mod) a -= mod;
}

int main() {
    scanf("%s %d", str + 1, &mod);
    len = strlen(str + 1);
    for (int i = 1; i <= len; i++) {
        memset(cnt, 0, sizeof (cnt));
        for (int j = 1; j <= len; j++) {
            add(cnt[(int) str[j]], 1 + old[j - 1]);
            //cnt[(int) str[j]] += 1 + old[j-1];
            cout << "(" << str[j] << " " << cnt[(int)str[j]] << " " << old[j-1] << " " << cnt[(int)str[i]] << ") ";
            dp[j] = old[j];
            add(dp[j], cnt[(int) str[i]]);
            //dp[j] += cnt[(int) str[i]];
        }
        cout << endl;
        cout << "Added " << str[i] << " to DP" << endl;
        cout << "old DP: ";
        printA(old, len+1);
        memcpy(old, dp, sizeof (old));
        cout << "cur DP: ";
        printA(old, len+1);
        cout << endl;
    }
    int res = dp[len] + 1;
    if (res >= mod) res -= mod;
    printf("%d\n", res);
    return 0;
}

char s[10002]; int M, n, dp[10002];
int main(){
    gets(s+1); scanf("%d", &M);
    n = strlen(s+1); dp[0] = 1;
    for(int i=1; i<=n; i++){
        int add = 0;
        for(int j=1; j<i; j++){
            if(s[j]==s[i]) add = dp[j-1];
            dp[j] = (dp[j] + add)%M;
        }
        dp[i] = (dp[i-1] + dp[i-1])%M;
    }
    printf("%d\n", dp[n]);
}