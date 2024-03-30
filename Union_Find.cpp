#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent; // Stores the parent of each element
    vector<int> rank; // Stores the rank (depth) of each set

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Initialize each element as its own parent
        }
    }

    // Find the representative (root) of the set containing element x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union (merge) two sets containing elements x and y
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            // Union by rank (attach smaller rank tree to larger rank tree)
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n = 5; // Number of elements
    UnionFind uf(n);

    // Example usage
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(1, 3);

    std::cout << "Are elements 0 and 2 in the same set? " << (uf.find(0) == uf.find(2)) << std::endl;
    std::cout << "Are elements 1 and 4 in the same set? " << (uf.find(1) == uf.find(4)) << std::endl;

    return 0;
}
