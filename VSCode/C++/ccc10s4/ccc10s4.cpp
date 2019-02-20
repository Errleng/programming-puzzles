#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;

struct United {
    int size;
    vector<int> par;

    United(int length) {
        size = length;
        par.resize(length);
        for (int i=0; i<length; ++i) {
            par[i] = i;
        }
    }

    int find(int a) {
        if (a != par[a]) {
            par[a] = find(par[a]);
        }
        return par[a];
    }

    bool join(int a, int b) {
        int aR = find(a), bR = find(b);
        if (aR != bR) {
            par[aR] = bR;
            return true;
        } else {
            return false;
        }
    }
};

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) : u(a), v(b), w(c) {}

    string str() {
        return to_string(u) + " " + to_string(v) + " " + to_string(w);
    }
};
bool compareEdge(const Edge& left, const Edge& right) {
    return left.w < right.w;
}

int M;
map<piii, Edge> specified;

int MSTW(vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compareEdge);
    United d(1001);
    int w = 0;
    for (Edge &e : edges) {
        if (d.join(e.u, e.v)) {
            cout << e.str() << endl;
            w += e.w;
        }
    }
    return w;
}

int main() {
    cin >> M;

    for (int i=1; i<=M; ++i) {
        int numEdges;
        cin >> numEdges;
        vector<int> penCorners(numEdges);
        vector<int> penCosts(numEdges);
        for (int j=0; j<numEdges; ++j) {
            cin >> penCorners[j];
        }
        for (int j=0; j<numEdges; ++j) {
            cin >> penCosts[j];
        }
        for (int j=0; j<numEdges; ++j) {
            int next = 0;
            if (j != numEdges-1) {
                next = j+1;
            }
            piii link(penCorners[j], pii(penCorners[next], penCosts[j]));
            Edge e = Edge(i, 0, penCosts[j]);
            if (specified.find(link) == specified.end()) {
                specified[link] = e;
            } else {
                cout << specified[link].str() << endl;
                specified[link].v = i;
                cout << specified[link].str() << endl;
            }
        }
    }
    vector<Edge> inside;
    vector<Edge> outside;

    for (auto const &it : specified) {
        Edge e = it.second;
        if (e.v == 0) {
            outside.push_back(e);
        } else {
            inside.push_back(e);
        }
    }
    int toInW = MSTW(inside);
    cout << endl;
    int toOutW = MSTW(outside);
    cout << min(toInW, toOutW) << '\n';
    return 0;
}