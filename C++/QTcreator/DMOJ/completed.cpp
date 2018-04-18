#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory>

using namespace std;

class DisjointSet {
public:
    int* joined;
    int* ranks;

    DisjointSet(const int n) {
        joined = new int[n];
        ranks = new int[n];
    }

    ~DisjointSet() {
        delete[] joined;
        delete[] ranks;
    }

    void create(int x) {
        joined[x] = x;
        ranks[x] = 1;
    }

    int find(int x) {
        if (joined[x] == x) {
            return x;
        }
        else {
            int xTop = find(joined[x]);
            joined[x] = xTop;
            return xTop;
        }
    }

    void unite(int x, int y) {
        int xTop = find(x);
        int yTop = find(y);

        if (xTop == yTop) return;

        int xRank = ranks[xTop];
        int yRank = ranks[yTop];

        if (xRank < yRank) {
            joined[xTop] = yTop;
        }
        else {
            joined[yTop] = xTop;
            ranks[yTop]++;
        }
    }
};

template<typename T>
void printArr(T* array, const int length) {
    ostringstream output;
    for (int i = 0; i < length; i++) {
        output << array[i] << " ";
    }
    cout << output.str() << endl;
}

template<typename T>
void printVec(vector<T>& vec) {
    ostringstream output;
    for (int i = 0; i < vec.size(); i++) {
        output << vec[i] << " ";
    }
    cout << output.str() << endl;
}

// Convenience
typedef pair<int, int> PII;

// WIP Directed Graph
class Graph {
public:
    int numVert;
    std::unique_ptr<vector<int>[]> adjList;

    Graph(int numVertices)
        : numVert(numVertices), adjList{new vector<int>[numVertices]} {
    }

    void printGraph() {
        for (int i = 0; i < numVert; i++) {
            cout << "\nAdjacency List origin: " << i;
            for (int j : adjList[i]) {
                cout << "-> " << j;
            }
            printf("\n");
        }
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        // adjList[v].push_back(u);
    }

    void BFS(int src) {
        bool *visited = new bool[numVert];

        for (int i = 0; i < numVert; i++) {
            visited[i] = false;
        }
        visited[src] = true;
        queue<int> bfsQueue;
        bfsQueue.push(src);

        while (!bfsQueue.empty()) {
            src = bfsQueue.front();
            bfsQueue.pop();

            cout << src << " ";

            for (int i = 0; i < adjList[src].size(); i++) {
                if (!visited[adjList[src][i]]) {
                    visited[adjList[src][i]] = true;
                    bfsQueue.push(adjList[src][i]);
                }
            }
        }
        delete[] visited;
    }
};

void S4_2009_Adjacency_List() {
    const int INFINITE = 1000000000;
    const int N = 5001;
    int costs[N];
    bool visited[N];
    vector<PII> adj[N];

    int numCities, numRoutes, numStores;
    scanf("%d %d", &numCities, &numRoutes);

    for (int i = 0; i < numCities; i++) {
        costs[i] = INFINITE;
        visited[i] = false;
    }

    for (int i = 0; i < numRoutes; i++) {
        int src, dst, costs;
        scanf("%d %d %d", &src, &dst, &costs);
        src -= 1;
        dst -= 1;
        adj[src].push_back(PII(costs, dst));
        adj[dst].push_back(PII(costs, src));
    }

    scanf("%d", &numStores);
    for (int i = 0; i < numStores; i++) {
        int storeCity, storeCost;
        scanf("%d %d", &storeCity, &storeCost);
        storeCity -= 1;
        costs[storeCity] = storeCost;
    }

    int dst;
    scanf("%d", &dst);
    dst -= 1;
    for (int i = 0; i < numCities; i++) {
        int ind = 0;
        for (int j = 0; j < numCities; j++) {
            if (!visited[j] && costs[j] < costs[ind]) {
                ind = j;
            }
        }
        visited[ind] = true;
        for (PII p : adj[ind]) {
            if (costs[ind] + p.first < costs[p.second]) {
                costs[p.second] = costs[ind] + p.first;
            }
        }
    }
    cout << costs[dst] << endl;
}

void S4_2009_PriorityQueue() {
    const int ARR = 5001;
    const int INF = 1000000000;
    int numCities, numRoutes, numStores;
    vector<PII> adjacent[ARR];
    int costs[ARR];
    bool visited[ARR];
    int x, y, z;

    scanf("%d %d", &numCities, &numRoutes);
    for (int i = 0; i < numRoutes; i++) {
        scanf("%d %d %d", &x, &y, &z);
        x -= 1;
        y -= 1;
        adjacent[x].push_back(PII(z, y));
        adjacent[y].push_back(PII(z, x));
    }

    for (int i = 0; i < numCities; i++) {
        costs[i] = INF;
        visited[i] = false;
    }

    priority_queue<PII, vector<PII>, greater<PII>> cityQueue;

    scanf("%d", &numStores);
    for (int i = 0; i < numStores; i++) {
        scanf("%d %d", &x, &y);
        x -= 1;
        costs[x] = y;
        cityQueue.push(make_pair(y, x));
    }

    scanf("%d", &z);
    z -= 1;

    while (!cityQueue.empty()) {
        PII city = cityQueue.top();
        cityQueue.pop();
        if (visited[city.second]) {
            break;
        }
        if (city.first > costs[city.second]) {
            continue;
        }
        visited[city.second] = true;
        for (PII p : adjacent[city.second]) {
            int combine = city.first + p.first;
            if (combine < costs[p.second]) {
                costs[p.second] = combine;
                cityQueue.push(PII(costs[p.second], p.second));
            }
        }
    }
    cout << costs[z] << endl;
}

void S4_2007() {
    const int MAX = 10000;
    int numPoints, start, end;
    vector<int> adjList[MAX];
    int paths[MAX];

    scanf("%d", &numPoints);
    scanf("%d %d", &start, &end);
    int count = 0;
    while (start != 0 || end != 0) {
        paths[count] = 0;
        adjList[start-1].push_back(end-1);
        scanf("%d %d", &start, &end);
    }

    paths[numPoints-1] = 1;
    for (int i = numPoints-1; i > -1; i--) {
        cout << "i: " << i <<endl;
        for (int z = 0; z < numPoints; z++) {
            cout << paths[z] << " ";
        }
        cout << "\n";
        for (int v : adjList[i]) {
            cout << v << endl;
            paths[i] += paths[v];
        }
    }

    // cout << "\n";
    cout << paths[0] << endl;
}

void J5_2007() {
    const int ARR = 34;
    int answers[ARR] = {0};
    vector<int> stops = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int minDist, maxDist, extraStops, extra;
    scanf("%d %d", &minDist, &maxDist);
    scanf("%d", &extraStops);
    for (int i = 0; i < extraStops; i++) {
        scanf("%d", &extra);
        stops.push_back(extra);
    }
    sort(stops.begin(), stops.end());
    answers[0] = 1;
    for (int i = 0; i < stops.size(); i++) {
        for (int j = i + 1; j < stops.size(); j++) {
            if (stops[j] - stops[i] >= minDist && stops[j] - stops[i] <= maxDist) {
                answers[j] += answers[i];
            }
        }
    }
    cout << answers[stops.size()-1] << endl;
}

void S5_2003_MinimumSpanningTree() {
    const int MAX = 10001;
    const int LARGE = 1000000;
    int numCities, numRoads, numDests;
    int maxWeight = LARGE;
    vector<PII> graph[MAX];
    vector<int> dests;

    scanf("%d %d %d", &numCities, &numRoads, &numDests);
    for (int i=0; i<numRoads; i++) {
        int src, dst, cost;
        scanf("%d %d %d", &src, &dst, &cost);
        src -= 1;
        dst -= 1;
        graph[src].push_back(PII(-cost, dst));
        graph[dst].push_back(PII(-cost, src));
    }
    for (int i=0; i<numDests; i++) {
        int destination;
        scanf("%d", &destination);
        destination -= 1;
        dests.push_back(destination);
    }

    priority_queue<PII, vector<PII>, greater<PII> > pq;
    vector<int> weights(numCities, LARGE);
    vector<int> mst(numCities, -1);
    vector<bool> inMST(numCities, false);

    pq.push(PII(0, 0));
    weights[0] = 0;
    while (!pq.empty()) {
        int ind = pq.top().second;
        pq.pop();
        inMST[ind] = true;
        for (PII p : graph[ind]) {
            int v = p.second;
            int w = p.first;
            if (inMST[v] == false && weights[v] > w) {
                weights[v] = w;
                pq.push(PII(weights[v], v));
                mst[v] = ind;
            }
        }
    }
    for (int i = 0; i < dests.size(); i++) {
        if (-weights[dests[i]] < maxWeight) {
            maxWeight = -weights[dests[i]];
        }
    }
    printf("%d", maxWeight);
}

void S5_2003_AdjacencyMatrix() {
    const int INFINITE = 1000000000;
    const int MAX = 5001;
    int costs[MAX];
    int dists[MAX];
    bool visited[MAX];
    int numCities, numRoutes, numStores, dest;
    int minCost = INFINITE;
    int** matrix = new int*[MAX];

    scanf("%d %d", &numCities, &numRoutes);

    for (int i = 1; i <= numCities; i++) {
        matrix[i] = new int[MAX];
        dists[i] = INFINITE;
        visited[i] = false;
    }

    for (int i = 0; i < numRoutes; i++) {
        int src, dst, dist;
        scanf("%d %d %d", &src, &dst, &dist);
        matrix[src][dst] = dist;
        matrix[dst][src] = dist;
    }

    scanf("%d", &numStores);
    for (int i = 0; i < numStores; i++) {
        int storeCity, storeCost;
        scanf("%d %d", &storeCity, &storeCost);
        costs[storeCity] = storeCost;
    }

    scanf("%d", &dest);
    dists[dest] = 0;
    for (int i=1; i <=numCities; i++) {
        int minInd = 0;
        int minimum = INFINITE;
        for (int j=1; j<=numCities; j++) {
            if (!visited[j] && dists[j] < minimum) {
                minimum = dists[j];
                minInd = j;
            }
        }
        visited[minInd] = true;
        for (int j=1; j<=numCities; j++) {
            if (!visited[j] && matrix[minInd][j] > 0 && dists[minInd] != INFINITE && dists[minInd] + matrix[minInd][j] < dists[j]) {
                dists[j] = dists[minInd] + matrix[minInd][j];
            }
        }
    }
    for (int i = 1; i <= numCities; i++) {
        if (dists[i] + costs[i] < minCost && costs[i] > 0) {
            minCost = dists[i] + costs[i];
        }
    }
    printf("%d", minCost);
}

void S2_DMPG_2017() {
    const int MAX = 100001;
    DisjointSet disjoint(MAX);
    int numCities, numQueries;
    scanf("%d %d", &numCities, &numQueries);

    for (int i=1; i<=numCities; i++) {
        disjoint.create(i);
    }

    for (int i=0; i<numQueries; i++) {
        char query;
        int src, dst;
        scanf(" %c %d %d", &query, &src, &dst);
        if (query == 'A') {
            disjoint.unite(src, dst);
        }
        else if (query == 'Q')
        {
            if (disjoint.find(src) == disjoint.find(dst)) {
                printf("%c\n", 'Y');
            }
            else {
                printf("%c\n", 'N');
            }
        }
    }
}

void S4_2009() {
    const int INFINITE = 1000000000;
    const int N = 5001;
    int costs[N];
    bool visited[N];
    int** adj = new int*[N];
    for (int i = 0; i < N; i++) {
        adj[i] = new int[N];
    }

    int numCities, numRoutes, numStores;
    scanf("%d %d", &numCities, &numRoutes);

    for (int i = 0; i < numCities; i++) {
        costs[i] = INFINITE;
        visited[i] = false;
    }

    for (int i = 0; i < numRoutes; i++) {
        int src, dst, cost;
        scanf("%d %d %d", &src, &dst, &cost);
        src -= 1;
        dst -= 1;
        adj[src][dst] = cost;
        adj[dst][src] = cost;
    }

    scanf("%d", &numStores);
    for (int i = 0; i < numStores; i++) {
        int city, cost;
        scanf("%d %d", &city, &cost);
        city -= 1;
        costs[city] = cost;
    }

    int dst;
    scanf("%d", &dst);
    dst -= 1;
    while (true) {
        int index = 0;
        for (int i = 0; i < numCities; i++) {
            if (!visited[i] && costs[i] < costs[index]) {
                index = i;
            }
        }
        if (index == dst || visited[index]) {
            break;
        }
        visited[index] = true;
        for (int i = 0; i < numCities; i++) {
            if (adj[index][i] != 0) {
                if (costs[index] + adj[index][i] < costs[i]) {
                    costs[i] = costs[index] + adj[index][i];
                }
            }
        }
    }
    cout << costs[dst] << endl;
}
