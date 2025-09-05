// Implements a DSU to detect cycles in an undirected graph.
// An edge (u,v) creates a cycle if u and v are already in the same component.
// Time Complexity: O(α(n)) for the unite operation, where α is the inverse Ackermann function.
// Space Complexity: O(n)

class DSU_CycleDetection {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU_CycleDetection(int n) : parent(n), sz(n, 1) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    // Unites the sets containing u and v.
    // Returns true if adding the edge (u,v) creates a cycle, false otherwise.
    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v) {
            return true; // A cycle is detected.
        }

        if (sz[root_u] < sz[root_v]) swap(root_u, root_v);
        parent[root_v] = root_u;
        sz[root_u] += sz[root_v];

        return false; // No cycle was created.
    }
};
