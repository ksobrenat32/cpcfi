// Kruskal's algorithm to find the Minimum Spanning Tree (MST) of an undirected, weighted graph.
// Time complexity: O(E log E) because of sorting the edges.
// Space complexity: O(V + E) for the graph representation and DSU structure.

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Returns the total weight of the MST, or -1 if the graph is not connected.
// The `mst_edges` vector will contain the edges of the MST.
int kruskal(int num_vertices, vector<Edge>& edges, vector<Edge>& mst_edges) {
    sort(edges.begin(), edges.end());

    DisjointSets dsu(num_vertices);
    int mst_weight = 0;
    mst_edges.clear();

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.weight;
            mst_edges.push_back(edge);
        }
    }

    // An MST of a connected graph with V vertices has V-1 edges.
    if (num_vertices > 0 && mst_edges.size() != num_vertices - 1) {
        return -1; // Graph is not connected
    }

    return mst_weight;
}
