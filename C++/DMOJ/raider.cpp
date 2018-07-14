#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define FOR(a, b) for (int a = 0; a < b; ++a)
#define FORR(a, n, b) for (int a = n; a < b; ++a)
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 500000;
const int MOD = 1000000007;
vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], borrowed[MAXN];
bool inT[MAXN];
stack<int> T_stack;
vector<int> provs[MAXN];
int provN[MAXN];
int provVal[MAXN];

int N, M, a, b;
int counter = 0;
pii dp[MAXN][2];

int provNum = 0;
void T_DFS(int node) {
    disc[node] = low[node] = ++counter;
    T_stack.push(node);
    inT[node] = true;
    FOR(i, adj[node].size()) {
        int c = adj[node][i];
        if (disc[c] == -1) {
            T_DFS(c);
            low[node] = min(low[node], low[c]);
        }
        else if (inT[c]) {
            low[node] = min(low[node], disc[c]);
        }
    }
    int r;
    if (low[node] == disc[node]) {
        while (T_stack.top() != node) {
            r = T_stack.top();
            provN[r] = provNum;
            provVal[provNum] += borrowed[r];
            inT[r] = false;
            T_stack.pop();
        }
        r = T_stack.top();
        provN[r] = provNum;
        provVal[provNum] += borrowed[r];
        provNum++;
        inT[r] = false;
        T_stack.pop();
    }
}

pii recur(int node, bool taken) {
    if (node == provN[N-1]) {
        if (!taken) return dp[node][taken] = pii(provVal[node], 1);
        return dp[node][taken] = pii(0, 1);
    }
    pii res = pii(-1, 0), tmp;
    if (dp[node][taken] != pii(-1, -1))
        return dp[node][taken];
    for (int c : provs[node]) {
        tmp = recur(c, false);
        if (tmp.first > res.first) {
            res = tmp;
        } else if (tmp.first == res.first) {
            res.second += tmp.second;
            res.second %= MOD;
        }
        if (taken) continue;
        tmp = recur(c, true);
        tmp.first += provVal[node];
        if (tmp.first > res.first) {
            res = tmp;
        } else if (tmp.first == res.first) {
            res.second += tmp.second;
            res.second %= MOD;
        }
    }
    return dp[node][taken] = res;
}

int main() {
    scanf("%d %d", &N, &M);
    FOR(i, N) {
        disc[i] = -1;
        low[i] = -1;
        dp[i][0] = dp[i][1] = pii(-1, -1);
        scanf("%d", &borrowed[i]);
    }
    FOR(i, M) {
        scanf("%d %d", &a, &b);
        --a; --b;
        adj[a].push_back(b);
    }
    T_DFS(0);
    FOR(i, N) {
        FOR(j, adj[i].size()) {
            int n = adj[i][j];
            if (provN[i] != provN[n] && find(provs[provN[i]].begin(), provs[provN[i]].end(), provN[n]) == provs[provN[i]].end()) {
                provs[provN[i]].push_back(provN[n]);
            }
        }
    }
    pii ans = recur(provN[0], false);
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}