// Finds a topological sort of a Directed Acyclic Graph (DAG) using Depth First Search (DFS).
// A topological sort is a linear ordering of vertices such that for every directed
// edge from vertex u to vertex v, u comes before v in the ordering.
// This implementation also detects if the graph contains a cycle.
// Time complexity: O(V + E), as it's a single DFS traversal.
// Space complexity: O(V + E) for the graph representation and recursion stack.

#include <vector>
#include <algorithm>
#include <utility>

enum class NodeState { UNVISITED, VISITING, VISITED };

// Helper function for the recursive DFS. Returns true if a cycle is detected.
bool dfs_visit(int u, const std::vector<std::vector<int>>& adj,
               std::vector<NodeState>& state, std::vector<int>& result) {
    state[u] = NodeState::VISITING;

    for (int v : adj[u]) {
        if (state[v] == NodeState::VISITING) {
            return true; // Cycle detected: back edge to a node in the current recursion stack.
        }
        if (state[v] == NodeState::UNVISITED) {
            if (dfs_visit(v, adj, state, result)) {
                return true; // Propagate cycle detection signal.
            }
        }
    }

    state[u] = NodeState::VISITED;
    result.push_back(u); // Add the vertex to the list after visiting all its descendants.
    return false;
}

// Main function to perform topological sort.
// num_vertices: The number of vertices in the graph (labeled 0 to n-1).
// edges: A list of pairs, where each pair (u, v) represents a directed edge from u to v.
// Returns a topologically sorted list of vertices, or an empty vector if the graph has a cycle.
std::vector<int> topological_sort(int num_vertices, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adj(num_vertices);
    for(const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
    }

    std::vector<NodeState> state(num_vertices, NodeState::UNVISITED);
    std::vector<int> result;
    result.reserve(num_vertices);

    for (int i = 0; i < num_vertices; ++i) {
        if (state[i] == NodeState::UNVISITED) {
            if (dfs_visit(i, adj, state, result)) {
                return {}; // Cycle detected, return empty vector.
            }
        }
    }

    // The result is built in reverse post-order, so it needs to be reversed.
    std::reverse(result.begin(), result.end());
    return result;
}
