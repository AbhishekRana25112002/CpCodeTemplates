#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj, int V) {
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 0; u < V; ++u) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result;
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
    int n = 11;
    vector<vector<int>> graph = makegraph(edges, n);
    vector<int> ans = topologicalSort(graph, n);
    for(auto x: ans){
        cout << x << " ";
    }
}
