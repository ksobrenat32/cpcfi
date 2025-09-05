// Finds a cycle in an undirected graph using Depth First Search (DFS).
// If a cycle is found, it returns the vertices of the cycle.
// Time complexity: O(V + E), as it's based on a single DFS traversal.
// Space complexity: O(V) for storing visited status, parent pointers, and the recursion stack.

#include <vector>
#include <algorithm>

class UndirectedCycleFinder {
public:
    UndirectedCycleFinder(int num_vertices, const std::vector<std::vector<int>>& graph_adj)
        : n(num_vertices), adj(graph_adj), visited(n, false), parent(n, -1) {}

    // Returns a vector containing the nodes of one cycle, or an empty vector if no cycle exists.
    std::vector<int> find_cycle() {
        cycle_start_node = -1;
        cycle_end_node = -1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (dfs(i, -1)) {
                    break; // Cycle found, no need to search further.
                }
            }
        }

        if (cycle_start_node == -1) {
            return {}; // No cycle found in the entire graph.
        }

        std::vector<int> cycle;
        cycle.push_back(cycle_start_node);
        for (int v = cycle_end_node; v != cycle_start_node; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start_node);
        std::reverse(cycle.begin(), cycle.end());

        return cycle;
    }

private:
    int n;
    const std::vector<std::vector<int>>& adj;
    std::vector<bool> visited;
    std::vector<int> parent;
    int cycle_start_node;
    int cycle_end_node;

    // Performs DFS from node u and returns true if a cycle is detected in its subtree.
    bool dfs(int u, int p) {
        visited[u] = true;
        parent[u] = p;

        for (int v : adj[u]) {
            if (v == p) {
                continue; // Skip the edge leading back to the parent in the DFS tree.
            }
            if (visited[v]) {
                // Found a back edge to an already visited node that is not the immediate parent.
                cycle_end_node = u;
                cycle_start_node = v;
                return true;
            }
            if (dfs(v, u)) {
                return true;
            }
        }
        return false;
    }
};
