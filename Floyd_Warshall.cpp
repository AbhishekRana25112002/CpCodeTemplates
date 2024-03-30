void floydWarshall(vector<vector<int>> &dist, int V) {
        // Initialize diagonal elements to 0
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0;
        }

        // Compute shortest paths
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
}
int main() {
    vector<vector<int>> edges = {
        {0,1,3}, {1,3,4}, {2,3,6}, {3,4,2}
    };
    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for(auto x: edges) {
        int i = x[0], j = x[1], w = x[2];
        dist[i][j] = w;
        // For and undirected graph, also all dist[j][i] = w;
    }
    floydWarshall(dist, n);
}