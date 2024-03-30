void bellmanFord(vector<vector<int>> &edges, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; ++i) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative-weight cycle!\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Shortest distances from node " << src << " to all other nodes:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << dist[i] << " units away\n";
    }
}
int main() {
    
    int n = 11;
    bellmanFord(edges, n, source);
    
}