// Hierholzer's algorithm for finding an Eulerian path or circuit in a directed graph.
// An Eulerian circuit is a trail that visits every edge exactly once and returns to the starting vertex.
// An Eulerian path is a trail that visits every edge exactly once.
// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space complexity: O(V + E) for the graph representation and path storage.

#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

// For an undirected graph, add each edge (u, v) as two directed edges: u->v and v->u.
// Returns the sequence of vertices in the Eulerian path/circuit, or an empty vector if none exists.
std::vector<int> find_eulerian_path(int num_vertices, const std::vector<std::pair<int, int>>& edges) {
    if (num_vertices == 0) return {};
    if (edges.empty()) return {0}; // Or handle as per requirements for a graph with no edges.

    // Step 1: Build adjacency list and calculate in/out degrees.
    std::map<int, std::vector<int>> adj;
    std::vector<int> in_degree(num_vertices, 0);
    std::vector<int> out_degree(num_vertices, 0);

    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        out_degree[edge.first]++;
        in_degree[edge.second]++;
    }

    // Step 2: Check for the existence of an Eulerian path/circuit and find the start node.
    int start_node = -1;
    int start_node_candidates = 0;
    int end_node_candidates = 0;

    for (int i = 0; i < num_vertices; ++i) {
        if (std::abs(out_degree[i] - in_degree[i]) > 1) return {}; // Condition for Eulerian path violated.
        if (out_degree[i] - in_degree[i] == 1) {
            start_node_candidates++;
            start_node = i;
        } else if (in_degree[i] - out_degree[i] == 1) {
            end_node_candidates++;
        }
    }

    // A valid Eulerian path exists if there is one start and one end node.
    // A valid Eulerian circuit exists if there are no start or end nodes.
    if (!((start_node_candidates == 0 && end_node_candidates == 0) || (start_node_candidates == 1 && end_node_candidates == 1))) {
        return {};
    }

    // If it's a circuit, start from any vertex that has outgoing edges.
    if (start_node == -1) {
        start_node = edges[0].first;
    }

    // Step 3: Find the path using a non-recursive DFS approach.
    std::vector<int> current_path_stack;
    current_path_stack.push_back(start_node);
    std::vector<int> eulerian_path;

    while (!current_path_stack.empty()) {
        int u = current_path_stack.back();
        if (!adj[u].empty()) {
            // Follow an edge.
            int v = adj[u].back();
            adj[u].pop_back();
            current_path_stack.push_back(v);
        } else {
            // If stuck, backtrack and add the node to the final path.
            eulerian_path.push_back(u);
            current_path_stack.pop_back();
        }
    }

    std::reverse(eulerian_path.begin(), eulerian_path.end());

    // Step 4: Verify that all edges were used. If not, the graph is not strongly connected enough.
    if (eulerian_path.size() != edges.size() + 1) {
        return {};
    }

    return eulerian_path;
}
