#include <bits/stdc++.h>

#define FOR(a, b) for (int a = 0; a < b; ++a)
#define FORR(a, n, b) for (int a = n; a < b; ++a)

using namespace std;
using namespace std::chrono;

void print() {
    cout << endl;
}

template <typename T, typename... Args>
void print(T curArg, Args&&... remArgs) {
    cout << curArg << " ";
    print(remArgs...) ;
}

template <typename T, size_t N>
void printL(T(&arr1D)[N]) {
    for (int elem = 0; elem < N; ++elem) {
        cout << arr1D[elem] << " ";
    }
    cout << endl;
}

template <typename T, size_t N, size_t M>
void print2D(T(&arr2D)[N][M]) {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cout << arr2D[r][c] << " ";
        }
        cout << '\n';
    }
    cout << endl;
}

typedef pair<int, int> pii;

void transposeGraph(vector<vector<int>> &transpose, vector<vector<int>> &graph) {
    FOR(i, graph.size()) {
        FOR(j, graph[i].size()) {
            transpose[graph[i][j]].push_back(i);
        }
    }
}

void Kosaraju_Stack(int node, stack<int> &stack, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (int c : graph[node]) {
        if (!visited[c]) {
            Kosaraju_Stack(c, stack, graph, visited);
        }
    }
    stack.push(node);
}

void Kosaraju_DFS(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (int c : graph[node]) {
        if (!visited[c]) {
            Kosaraju_DFS(c, graph, visited);
        }
    }
}

void Kosaraju_Algorithm(vector<vector<int>> &graph) {
    vector<bool> visited(graph.size());
    stack<int> SCCs;
    FOR(i, graph.size()) {
        if (!visited[i])
            Kosaraju_Stack(0, SCCs, graph, visited);
    }
    cout << endl;
    FOR(i, visited.size()) {
        visited[i] = false;
    }
    int cur;
    vector<vector<int>> transpose(graph.size());
    transposeGraph(transpose, graph);
    FOR(i, transpose.size()) {
        cout << "Town " << i << ": ";
        FOR(j, transpose[i].size()) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    while (!SCCs.empty()) {
        cur = SCCs.top();
        SCCs.pop();
        if (!visited[cur]) {
            Kosaraju_DFS(cur, transpose, visited);
            cout << endl;
        }
    }
}

void Tarjan_DFS(int node, vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, stack<int> &stack, vector<bool> &inStack, int& counter) {
    disc[node] = low[node] = ++counter;
    stack.push(node);
    inStack[node] = true;
    FOR(i, graph[node].size()) {
        int cur = graph[node][i];
        if (disc[cur] == -1) {
            Tarjan_DFS(cur, graph, disc, low, stack, inStack, counter);
            low[node] = min(low[node], low[cur]);
        }
        else if (inStack[cur]) {
            low[node] = min(low[node], disc[cur]);
        }
    }
    int r = 0;
    if (low[node] == disc[node]) {
        while (stack.top() != node) {
            r = stack.top();
            cout << r << " ";
            inStack[r] = false;
            stack.pop();
        }
        r = stack.top();
        cout << r << "\n";
        inStack[r] = false;
        stack.pop();
    }
}

void Tarjan_Algorithm(vector<vector<int>> &graph) {
    // DFS produces DFS Tree
    // The root of a strongly connected component is when disc[u] == low[u]
    // disc[] contains the time/order the nodes are visited in DFS
    // low[u] contanis the topmost ancestor node reachable from subtree with u as the root
    // Ancestor nodes can be reached through back edges
    // When first visiting a nide, low[u] = disc[u]
    // When visiting adjacent nodes, tree edge: low[u] = min(low[u], low[v]) and back edge: low[u] = min(low[u], disc[v])
    int N = graph.size();
    vector<int> disc(N);
    vector<int> low(N);
    vector<bool> inStack(N);
    stack<int> dfsVisit;
    FOR(i, N) {
        disc[i] = -1;
        low[i] = -1;
        inStack[i] = false;
    }
    int counter = 0;
    FOR(i, N) {
        if (disc[i] == -1)
            Tarjan_DFS(i, graph, disc, low, dfsVisit, inStack, counter);
    }
}

void Solve() {
    int N, M, V;
    vector<int> loot;
    scanf("%d %d", &N, &M);

    print(N, M);
    vector<vector<int>> adj(M-1);
    vector<bool> visited(N, false);

    FOR(i, N) {
        scanf("%d", &V);
        loot.push_back(V);
    }

    int a, b;
    FOR(i, M) {
        scanf("%d %d", &a, &b);
        --a; --b;
        adj[a].push_back(b);
    }

    FOR(i, adj.size()) {
        cout << "Town " << i << ": ";
        FOR(j, adj[i].size()) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    FOR(i, loot.size()) {
        cout << loot[i] << " ";
    }
    cout << endl;
//    Kosaraju_Algorithm(adj);
//    Tarjan_Algorithm(adj);
}

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

pii Solve3(int node, bool taken) {
    if (node == provN[N-1]) {
        if (!taken) return dp[node][taken] = pii(provVal[node], 1);
        return dp[node][taken] = pii(0, 1);
    }
    pii res = pii(-1, 0), tmp;
    if (dp[node][taken] != pii(-1, -1))
        return dp[node][taken];
    for (int c : provs[node]) {
        tmp = Solve3(c, false);
        if (tmp.first > res.first) {
            res = tmp;
        } else if (tmp.first == res.first) {
            res.second += tmp.second;
            res.second %= MOD;
        }
        if (taken) continue;
        tmp = Solve3(c, true);
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

void Solve2() {
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
    pii ans = Solve3(provN[0], false);
    printf("%d %d\n", ans.first, ans.second);
}

int main() {
    freopen("../../DMOJ/input.txt", "r", stdin);

    time_point<steady_clock> start = steady_clock::now();

    Solve2();

    time_point<steady_clock> end = steady_clock::now();
    auto diff = duration_cast<milliseconds>(end - start);
    cout << "\nTime: " << diff.count() << " ms" << endl;
    return 0;
}