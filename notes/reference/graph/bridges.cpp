// Finds all bridges in an undirected graph using Tarjan's bridge-finding algorithm.
// A bridge is an edge whose removal increases the number of connected components of the graph.
// Time complexity: O(V + E), as it's based on a single DFS traversal.
// Space complexity: O(V) for storing discovery times and low-link values.

#include <vector>
#include <algorithm>
#include <utility>

class BridgeFinder {
public:
    BridgeFinder(int num_vertices, const std::vector<std::vector<int>>& graph_adj)
        : n(num_vertices), adj(graph_adj), visited(n, false), discovery_time(n), low_link(n), time(0) {}

    // Returns a vector of pairs, where each pair represents a bridge (u, v).
    std::vector<std::pair<int, int>> find_bridges() {
        bridges.clear();
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                find_bridges_dfs(i, -1);
            }
        }
        return bridges;
    }

private:
    int n;
    const std::vector<std::vector<int>>& adj;
    std::vector<bool> visited;
    std::vector<int> discovery_time;
    std::vector<int> low_link;
    int time;
    std::vector<std::pair<int, int>> bridges;

    void find_bridges_dfs(int u, int p) {
        visited[u] = true;
        discovery_time[u] = low_link[u] = time++;

        for (int v : adj[u]) {
            if (v == p) continue; // Don't go back to the parent immediately.

            if (visited[v]) { // Back edge found.
                low_link[u] = std::min(low_link[u], discovery_time[v]);
            } else { // Tree edge, explore the subtree.
                find_bridges_dfs(v, u);
                low_link[u] = std::min(low_link[u], low_link[v]);

                // If the earliest reachable vertex from v is after u in DFS tree, then (u,v) is a bridge.
                if (low_link[v] > discovery_time[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
};
