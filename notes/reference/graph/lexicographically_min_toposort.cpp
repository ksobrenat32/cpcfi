// Finds the lexicographically smallest topological sort of a Directed Acyclic Graph (DAG).
// This is a variation of Kahn's algorithm that uses a min-priority queue instead of a regular queue
// to ensure that smaller vertices are always chosen first from the set of nodes with an in-degree of zero.
// Time complexity: O(E + V log V) due to the use of a priority queue.
// Space complexity: O(V + E) for the graph, in-degrees, and priority queue.

#include <vector>
#include <queue>
#include <functional>
#include <utility>

// num_vertices: The number of vertices in the graph (labeled 0 to n-1).
// edges: A list of pairs, where each pair (u, v) represents a directed edge from u to v.
// Returns the lexicographically smallest topological sort, or an empty vector if the graph has a cycle.
std::vector<int> lexicographically_smallest_toposort(int num_vertices, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adj(num_vertices);
    std::vector<int> in_degree(num_vertices, 0);

    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        in_degree[edge.second]++;
    }

    // Use a min-priority queue to always select the smallest vertex with an in-degree of 0.
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < num_vertices; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    std::vector<int> result;
    result.reserve(num_vertices);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        // Sort the neighbors to process them in a consistent order, although not strictly necessary
        // for the correctness of the topological sort itself.
        // std::sort(adj[u].begin(), adj[u].end());

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }

    // If the result doesn't contain all vertices, the graph must have a cycle.
    if (result.size() == num_vertices) {
        return result;
    } else {
        return {}; // Cycle detected.
    }
}
