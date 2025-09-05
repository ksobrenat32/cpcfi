// Constructs a bridge tree from an undirected graph.
// The bridge tree represents the 2-edge-connected components (2-ECCs) of the graph.
// Each node in the tree is a 2-ECC, and an edge connects two nodes if there's a bridge between them in the original graph.
// Time complexity: O(V + E) for finding bridges and building the tree.
// Space complexity: O(V + E) for the graph, discovery times, and the resulting tree.

#include <vector>
#include <algorithm>
#include <utility>

struct EdgeInfo {
    int to;
    int id;
};

class BridgeTreeBuilder {
public:
    BridgeTreeBuilder(int num_vertices, const std::vector<std::pair<int, int>>& edge_list)
        : n(num_vertices), adj(n), visited(n, false), discovery_time(n), low_link(n), component(n), time(0), component_id(0) {

        is_bridge.resize(edge_list.size(), false);
        for (int i = 0; i < edge_list.size(); ++i) {
            int u = edge_list[i].first;
            int v = edge_list[i].second;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }

    // Returns the bridge tree as an adjacency list.
    std::vector<std::vector<int>> build() {
        // Step 1: Find all bridges in the graph using Tarjan's bridge-finding algorithm.
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                find_bridges_dfs(i, -1);
            }
        }

        // Step 2: Find the 2-edge-connected components by traversing the graph without crossing bridges.
        std::fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                find_components_dfs(i, component_id++);
            }
        }

        // Step 3: Build the bridge tree from the components and bridges.
        std::vector<std::vector<int>> bridge_tree(component_id);
        for (int u = 0; u < n; ++u) {
            for (const auto& edge : adj[u]) {
                if (component[u] != component[edge.to]) {
                    bridge_tree[component[u]].push_back(component[edge.to]);
                }
            }
        }

        // Remove duplicate edges from the bridge tree.
        for(auto& neighbors : bridge_tree) {
            std::sort(neighbors.begin(), neighbors.end());
            neighbors.erase(std::unique(neighbors.begin(), neighbors.end()), neighbors.end());
        }

        return bridge_tree;
    }

private:
    int n;
    std::vector<std::vector<EdgeInfo>> adj;
    std::vector<bool> visited;
    std::vector<int> discovery_time;
    std::vector<int> low_link;
    std::vector<bool> is_bridge;
    std::vector<int> component;
    int time;
    int component_id;

    void find_bridges_dfs(int u, int parent_edge_id) {
        visited[u] = true;
        discovery_time[u] = low_link[u] = time++;

        for (const auto& edge : adj[u]) {
            if (edge.id == parent_edge_id) continue;

            if (visited[edge.to]) {
                low_link[u] = std::min(low_link[u], discovery_time[edge.to]);
            } else {
                find_bridges_dfs(edge.to, edge.id);
                low_link[u] = std::min(low_link[u], low_link[edge.to]);
                if (low_link[edge.to] > discovery_time[u]) {
                    is_bridge[edge.id] = true;
                }
            }
        }
    }

    void find_components_dfs(int u, int current_comp_id) {
        visited[u] = true;
        component[u] = current_comp_id;
        for (const auto& edge : adj[u]) {
            if (!visited[edge.to] && !is_bridge[edge.id]) {
                find_components_dfs(edge.to, current_comp_id);
            }
        }
    }
};
