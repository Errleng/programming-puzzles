#include "../library/lib.hpp"
#include <bits/stdc++.h>

using namespace std;

#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

const int INF = 0x3f3f3f3f;

struct State {
    int dist;
    string id;
    vector<int> coins[9];

    State(int a) {
        dist = a;
        id = "";
    }

    int stPeek(int i) {
        if (coins[i].empty()) {
            return INF;
        } else {
            return coins[i].back();
        }
    }

    int stPop(int i) {
        if (coins[i].empty()) {
            return INF;
        } else {
            int a = coins[i].back();
            coins[i].pop_back();
            return a;
        }
    }

    string genID() {
        string res = "";
        bool first = true;
        for (int i = 0; i < 9; ++i) {
            if (first) {
                first = false;
            } else {
                res += "/";
            }
            if (coins[i].empty()) {
                res += "0";
            } else {
                for (int elem : coins[i]) {
                    res += to_string(elem);
                }
            }
        }
        return res;
    }
};

class ccc12s4 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int N, t;
        in >> N;
        while (N != 0) {
            int ans = -1;
            State start = State(0);


            for (int i = 1; i <= N; ++i) {
                in >> t;
                start.coins[i].push_back(t);
            }

            if (N == 1) {
                out << 0 << endl;
                in >> N;
                continue;
            }

            start.id = start.genID();

            queue<State> q;
            q.push(start);
            set<string> vis;

            while (!q.empty()) {
                State cur = q.front();
                q.pop();
                int count = 0;
                for (int i = 1; i <= N + 1; ++i) {
                    if (cur.stPeek(i) > cur.stPeek(i - 1)) {
                        ++count;
                    }
                    if (count == N) {
                        ans = cur.dist;
                        break;
                    }
                }
                if (vis.find(cur.id) != vis.end()) {
                    continue;
                } else {
                    vis.insert(cur.id);
                }
                if (ans != -1) {
                    break;
                }
                for (int i = 1; i <= N; ++i) {
                    if (i > 1 && cur.stPeek(i) < cur.stPeek(i - 1)) {
                        State next = State(cur.dist + 1);
                        for (int j = 0; j <= N; ++j) {
                            next.coins[j] = cur.coins[j];
                        }
                        int a = next.stPop(i);
                        if (a != INF) {
                            next.coins[i - 1].push_back(a);
                            next.id = next.genID();
                            q.push(next);
                        }
                    }
                    if (i < N && cur.stPeek(i) < cur.stPeek(i + 1)) {
                        State next = State(cur.dist + 1);
                        for (int j = 0; j <= N; ++j) {
                            next.coins[j] = cur.coins[j];
                        }
                        int a = next.stPop(i);
                        if (a != INF) {
                            next.coins[i + 1].push_back(a);
                            next.id = next.genID();
                            q.push(next);
                        }
                    }
                }
            }
            if (ans != -1) {
                out << ans << endl;
            } else {
                out << "IMPOSSIBLE" << endl;
            }
            in >> N;
        }
    }
};
