#include "../library/lib.hpp"
#include <bits/stdc++.h>

#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);
#define scan(a) in >> (a)

using namespace std;
typedef pair<int, int> pii;
class cco10p1 {
public:
    static const int MAXD = 1000;
    void solve(std::istream& in, std::ostream& out) {
        int D, F, T, a, b, times[MAXD], barked[MAXD];
        int barking[MAXD];
        vector<int> adj[MAXD];
        memset(times, 0, sizeof(times));
        memset(barked, 0, sizeof(barked));
        memset(barking, -1, sizeof(barking));
        scan(D);
        up(i, D) {
            scan(times[i]);
        }
        scan(F);
        up(i, F) {
            scan(a); scan(b);
            --a; --b;
            adj[a].push_back(b);
        }
        scan(T);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
        q.push({0, 0});
        while(!q.empty()){
            int dog = q.top().second;
            int time = q.top().first;
            q.pop();
            ++barked[dog];
            for (int i : adj[dog]){
                int bark_time = time + times[i];
                if (time > barking[i] && bark_time <= T) {
                    q.push({bark_time, i});
                    barking[i] = bark_time;
                }
            }
        }
        up(i, D) {
            out << barked[i] << endl;
        }
    }
};
