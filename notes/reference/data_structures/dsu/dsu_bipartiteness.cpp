// Implements a DSU that can check for bipartiteness in a dynamic graph.
// For each node `u`, we create two nodes in the DSU: `2*u` and `2*u+1`, representing
// the two partitions of a bipartite graph. An edge `(u, v)` is modeled by uniting
// `2*u` with `2*v+1` and `2*u+1` with `2*v`. The graph is not bipartite if `2*u` and
// `2*u+1` end up in the same set, as this indicates an odd-length cycle.
//
// Time Complexity: O(α(n)) for `unite` and `is_bipartite` queries.
// Space Complexity: O(n)

class DSU_Bipartite {
private:
    vector<int> parent;
    vector<int> sz;

    // Standard DSU find with path compression.
    int find_set(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find_set(parent[i]);
    }

    // Standard DSU unite by size.
    void unite_sets(int i, int j) {
        int root_i = find_set(i);
        int root_j = find_set(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }

public:
    DSU_Bipartite(int n) : parent(2 * n), sz(2 * n, 1) {
        for (int i = 0; i < 2 * n; ++i) {
            parent[i] = i;
        }
    }

    // Adds an edge between u and v.
    void unite(int u, int v) {
        // Unite u's first partition with v's second, and vice-versa.
        unite_sets(2 * u, 2 * v + 1);
        unite_sets(2 * u + 1, 2 * v);
    }

    // Checks if the component containing node u is bipartite.
    // It is not bipartite if u is in the same partition as its "mirror" node.
    bool is_bipartite(int u) {
        return find_set(2 * u) != find_set(2 * u + 1);
    }
};
