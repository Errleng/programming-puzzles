#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
void S3_2018() {
    const int MAX = 101;
    const int LARGE = 1000000000;
    int steps[MAX][MAX];
    char maze[MAX][MAX];
    bool visited[MAX][MAX];
    bool invalid[MAX][MAX];
    vector<pii> passable;
    vector<pii> cameras;
    int N, M;
    char c;
    pii start;
    pii dirs[4];
    dirs[0] = pii(-1, 0);
    dirs[1] = pii(1, 0);
    dirs[2] = pii(0, -1);
    dirs[3] = pii(0, 1);
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            steps[i][j] = LARGE;
            visited[i][j] = false;
            scanf(" %c", &c);
            maze[i][j] = c;
            if (c == 'S') {
                start = pii(i,j);
            }
            else if (c == 'C') {
                cameras.push_back(pii(i,j));
            }
            else if (c == '.') {
                passable.push_back(pii(i,j));
            }
        }
    }
    for (pii p : cameras) {
        for (int i = p.first; i < N && maze[i][p.second] != 'W'; i++) {
            if (maze[i][p.second] == '.' || maze[i][p.second] == 'C' || maze[i][p.second] == 'S') {
                invalid[i][p.second] = true;
            }
        }
        for (int i = p.first; i > -1 && maze[i][p.second] != 'W'; i--) {
            if (maze[i][p.second] == '.' || maze[i][p.second] == 'C' || maze[i][p.second] == 'S') {
                invalid[i][p.second] = true;
            }
        }
        for (int i = p.second; i < M && maze[p.first][i] != 'W'; i++) {
            if (maze[p.first][i] == '.' || maze[p.first][i] == 'C' || maze[i][p.second] == 'S') {
                invalid[p.first][i] = true;
            }
        }
        for (int i = p.second; i > -1 && maze[p.first][i] != 'W'; i--) {
            if (maze[p.first][i] == '.' || maze[p.first][i] == 'C' || maze[i][p.second] == 'S') {
                invalid[p.first][i] = true;
            }
        }
    }
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    steps[start.first][start.second] = 0;
    while (!q.empty()) {
        pii tile = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = tile.first + dirs[i].first;
            int ty = tile.second + dirs[i].second;
            if (tx>0 && ty>0 && tx<N && ty<M && maze[tx][ty] != 'W' && invalid[tx][ty] == false) {
                int step = steps[tile.first][tile.second] + 1;
                if (maze[tx][ty] == 'U' || maze[tx][ty] == 'D' || maze[tx][ty] == 'L' || maze[tx][ty] == 'R') {
                    step = step - 1;
                }
                if (step <steps[tx][ty]) {
                    steps[tx][ty] = step;
                }
                if (!visited[tx][ty]) {
                    visited[tx][ty] = true;
                    q.push(pii(tx,ty));
                }
            }
        }
    }

    for (pii t : passable) {
        if (steps[t.first][t.second] == LARGE) {
            cout << -1 << endl;
        }
        else {
            cout << steps[t.first][t.second] << endl;
        }
    }
}

map<int, long long> memo;

long long recursion(int n) {
    long long ans = memo[n];
    if (ans) {
        return memo[n];
    }
    if (n == 1) {
        return 1;
    }
    for (int i = 2; i <= n;) {
        long long p = n/i;
        long long times = n % i == 0 ? i : n / p;
        ans += (times - i + 1) * recursion(p);
        i = times + 1;
    }
    memo[n] = ans;
    return ans;
}
