#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 101;
const int LARGE = 1000000;
char grid[MAXN][MAXN];
bool marked[MAXN][MAXN];
int dists[MAXN][MAXN];
vector<pii> cameraPos;
int N, M;
char conveyors[4] = {'L', 'R', 'U', 'D'};
bool inbounds(int r, int c) {
    return (r < N && c < M && r >= 0 && c >= 0);
}
int foundCon(char c) {
    for (int i = 0; i < 4; ++i) {
        if (c == conveyors[i])
            return i;
    }
    return -1;
}
int main() {
    freopen("input.txt", "r", stdin);
    pii startPos;
    int moves[4][4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i)
    {
        for(int j= 0; j < M; ++j)
        {
            char c;
            scanf(" %c", &c);
            dists[i][j] = LARGE;
            marked[i][j] = false;
            grid[i][j] = c;
            if (c == 'S') {
                startPos = pii(i, j);
            }
            else if (c == 'C')
                cameraPos.push_back(pii(i, j));
        }
    }
    for (pii p : cameraPos)
    {
        int r = p.first;
        int c = p.second;
        for (int i = r; i < N && grid[i][c] != 'W'; ++i) marked[i][c] = true;
        for (int i = r; i > -1 && grid[i][c] != 'W'; --i) marked[i][c] = true;
        for (int i = c; i < M && grid[r][i] != 'W'; ++i) marked[r][i] = true;
        for (int i = c; i > -1 && grid[r][i] != 'W'; --i) marked[r][i] = true;
    }
    queue<pii> q;
    q.push(startPos);
    dists[startPos.first][startPos.second] = 0;

    if (!marked[startPos.first][startPos.second]) {
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            char pos = grid[r][c];
            int conv = foundCon(pos);
            if (conv != -1) {
                int newr = r + moves[conv][0];
                int newc = c + moves[conv][1];
                char newpos = grid[newr][newc];
                int newconv = foundCon(newpos);
                if (dists[newr][newc] > dists[r][c] && newpos != 'W') {
                    if (!marked[newr][newc] || newconv != -1) {
                        dists[newr][newc] = dists[r][c];
                        q.push(pii(newr, newc));
                    }
                }
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                int newr = r + moves[i][0];
                int newc = c + moves[i][1];
                char newpos = grid[newr][newc];
                int newconv = foundCon(newpos);
                if (newpos != 'W' && dists[newr][newc] > dists[r][c] + 1) {
                    if (!marked[newr][newc] || newconv != -1) {
                        dists[newr][newc] = dists[r][c] + 1;
                        q.push(pii(newr, newc));
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '.')
                printf("%d\n", (dists[i][j] == LARGE ? -1 : dists[i][j]));
        }
    }
    return 0;
}

    // cout << endl;
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         if (grid[i][j] == '.') {
    //             cout << (dists[i][j] == LARGE ? 0 : dists[i][j]) << " ";
    //         } else {
    //             cout << grid[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << marked[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // if (!marked[startPos.first][startPos.second]) {
    //     while (!q.empty()) {
    //         pii p = q.front();
    //         q.pop();
    //         int r = p.first;
    //         int c = p.second;
    //         char pos = grid[r][c];
    //         visited[r][c] = true;
    //         for (int i = 0; i < 4; ++i) {
    //             int newr = r + moves[i][0];
    //             int newc = c + moves[i][1];
    //             if (inbounds(newr, newc)) {
    //                 char newpos = grid[newr][newc];
    //                 if (newpos != 'W' && !marked[newr][newc]) {
    //                     if (pos == '.' || pos == 'S' || pos == conveyors[i]) {
    //                         int d = dists[r][c] + (pos == conveyors[i] ? 0 : 1);
    //                         if (d < dists[newr][newc]) {
    //                             dists[newr][newc] = d;
    //                             if (!visited[newr][newc]) {
    //                                 q.push(pii(newr, newc));
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }