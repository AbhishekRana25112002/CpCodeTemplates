#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &graph, int n, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


vector<vector<int>> makegraph(vector<vector<int>> &edges, int n) {
    vector<vector<int>> graph(n);
    for(auto &x : edges) {
        graph[x[0]].push_back(x[1]);
    }
    return graph;
}
int main() {
    vector<vector<int>> edges = {
        {0,1}, {1,3}, {2,3}, {3,5}, {10,5}, {9,4}, {4,3}, {4,6}, {4,7}, {5,8}
    };
    int n = 11, source = 0;
    vector<vector<int>> graph = makegraph(edges, n);
    vector<int> ans = dijkstra(graph, n, source);
    for(auto x: ans){
        cout << x << " ";
    }
}
