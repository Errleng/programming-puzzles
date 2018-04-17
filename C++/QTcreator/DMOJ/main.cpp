#include <iostream>
#include <chrono>
#include <vector>

#include <queue>

using namespace std;
using namespace std::chrono;

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> wQ;

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

void showpq(wQ queue)
{
    wQ g = queue;
    while (!g.empty())
    {
        cout << '\t' << g.top().second;
        g.pop();
    }
    cout << '\n';
}


void trial() {
    int largeNum = 1000000000;
    int numCities, numRoutes, numStores;
    vector<pair<int, int>> adjacent[5001];
    int cost[5001];
    int x, y, z;

    scanf("%d %d", &numCities, &numRoutes);
    for (int i = 0; i < numRoutes; i++) {
        scanf("%d %d %d", &x, &y, &z);
        x -= 1;
        y -= 1;
        adjacent[x].push_back(make_pair(z, y));
        adjacent[y].push_back(make_pair(z, x));
    }

    for (int i = 0; i < numCities; i++) {
        cost[i] = largeNum;
    }

    wQ cityQueue;

    scanf("%d", &numStores);
    for (int i = 0; i < numStores; i++) {
        scanf("%d %d", &x, &y);
        x -= 1;
        cost[x] = y;
        cityQueue.push(make_pair(y, x));
    }

    scanf("%d", &z);
    z -= 1;

    while(!cityQueue.empty()){
        pair<int,int>city=cityQueue.top();
        cityQueue.pop();
        if(city.first>cost[city.second]) continue;
        if(city.second==z) break;
        for(pair<int,int>othcity : adjacent[city.second]){
            if(city.first+othcity.first<cost[othcity.second]){
                cost[othcity.second]=city.first+othcity.first;
                cityQueue.push(make_pair(cost[othcity.second],othcity.second));
            }
        }
    }
    for (int i =0 ; i < numCities; i++) {
        cout << cost[i] << " ";
    }
    cout << "\n";
    cout << cost[z] << endl;
}

int main(int argc, char *argv[])
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    S4_2009();

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "\nEND\n" << endl;

    cout << "\nExecution took " << duration << " microseconds" << endl;
    duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "\nExecution took " << duration << " milliseconds" << endl;
    return 0;
}
