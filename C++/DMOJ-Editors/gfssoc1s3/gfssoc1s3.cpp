#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, M, T;
const int INF = 0x3f3f3f3f;
const int MAXN = 20;
const int MAXT = 5;

struct Node {
  int x, y, d;
  Node(int a, int b, int c) : x(a), y(b), d(c) {}
};

int move_x[] = {1, -1, 0, 0};
int move_y[] = {0, 0, 1, -1};

bool vis[MAXN][MAXN];
bool invalid[MAXN][MAXN];
int dist[MAXT + 1][MAXT + 1];
bool in_bounds(int x, int y) { return x >= 0 && y >= 0 && x < N && y < M; }
int search_hidden(Node pos, Node target) {
  memset(vis, false, sizeof(vis));
  queue<Node> q;
  q.push(pos);
  while (!q.empty()) {
    Node cur = q.front();
    q.pop();
    if (cur.x == target.x && cur.y == target.y) {
      return cur.d;
    }
    vis[cur.x][cur.y] = true;
    up(i, 4) {
      int x = cur.x + move_x[i];
      int y = cur.y + move_y[i];
      if (in_bounds(x, y) && !vis[x][y] && !invalid[x][y]) {
        q.push(Node(x, y, cur.d + 1));
      }
    }
  }
  return INF;
}

int main() {
  int cnt = 0;
  int ans = INF;
  char temp;
  Node start_pos(0, 0, 0);
  vector<int> permute;
  vector<Node> sources;

  scanf("%d %d %d", &N, &M, &T);
  up(i, N) {
    up(j, M) {
      scanf(" %c", &temp);
      if (temp == 'G') {
        sources.push_back(Node(i, j, 0));
        start_pos = sources[sources.size() - 1];
        permute.push_back(cnt++);
      } else if (temp == 'X') {
        invalid[i][j] = true;
      } else if (temp == 'H') {
        sources.push_back(Node(i, j, 0));
        permute.push_back(cnt++);
      }
    }
  }
  up(i, T + 1) {
    up(j, T + 1) { dist[i][j] = search_hidden(sources[i], sources[j]); }
  }
  do {
    int cost = 0;
    up(i, permute.size() - 1) { cost += dist[permute[i]][permute[i + 1]]; }
    ans = min(ans, cost);
  } while (next_permutation(permute.begin(), permute.end()));
  printf("%d\n", ans);
  return 0;
}
