// Finds the maximum cardinality matching in a bipartite graph using Kuhn's algorithm.
// This is a simple but effective algorithm. For better performance on large or dense graphs,
// a max-flow algorithm like Dinic's on a constructed flow network is faster (O(E * sqrt(V))).
// Time Complexity: O(V * E) where V is the number of vertices in the left partition.
// Space Complexity: O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Kuhn {
    int n_left, n_right;
    vector<vector<int>> adj;
    vector<int> match_R;
    vector<bool> visited;

    Kuhn(int nl, int nr) : n_left(nl), n_right(nr) {
        adj.resize(n_left);
    }

    void add_edge(int u_left, int v_right) {
        adj[u_left].push_back(v_right);
    }

    bool dfs_match(int u) {
        if (visited[u]) {
            return false;
        }
        visited[u] = true;
        for (int v : adj[u]) {
            if (match_R[v] < 0 || dfs_match(match_R[v])) {
                match_R[v] = u;
                return true;
            }
        }
        return false;
    }

    // Returns the size of the maximum matching
    int solve() {
        match_R.assign(n_right, -1);
        int matching_size = 0;
        for (int u = 0; u < n_left; ++u) {
            visited.assign(n_left, false);
            if (dfs_match(u)) {
                matching_size++;
            }
        }
        return matching_size;
    }
};
