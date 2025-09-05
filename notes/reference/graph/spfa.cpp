// Shortest Path Faster Algorithm (SPFA), an improvement on Bellman-Ford for SSSP.
// It finds the shortest paths from a single source vertex in a weighted directed graph.
// It can handle negative edge weights and is efficient on average for sparse graphs.
// Time complexity: O(E) on average for random graphs, but O(V * E) in the worst case.
// Space complexity: O(V) for storing distances, predecessors, and the queue.

#include <vector>
#include <queue>
#include <utility>
#include <limits>

const long long SPFA_INF = std::numeric_limits<long long>::max();

struct SpfaResult {
    bool has_negative_cycle;
    std::vector<long long> distance;
    std::vector<int> predecessor;
};

// num_vertices: The number of vertices in the graph (labeled 0 to n-1).
// start_node: The source vertex.
// adj: The graph represented by an adjacency list where adj[u] contains pairs {v, weight}.
SpfaResult spfa(int num_vertices, int start_node, const std::vector<std::vector<std::pair<int, int>>>& adj) {
    if (num_vertices == 0) {
        return {false, {}, {}};
    }

    std::vector<long long> distance(num_vertices, SPFA_INF);
    std::vector<int> predecessor(num_vertices, -1);
    std::vector<int> relax_count(num_vertices, 0);
    std::vector<bool> in_queue(num_vertices, false);
    std::queue<int> q;

    distance[start_node] = 0;
    q.push(start_node);
    in_queue[start_node] = true;
    relax_count[start_node]++;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != SPFA_INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    relax_count[v]++;
                    // If a vertex is relaxed V times, a negative cycle involving it exists.
                    if (relax_count[v] > num_vertices) {
                        return {true, {}, {}}; // Negative cycle detected.
                    }
                }
            }
        }
    }

    return {false, distance, predecessor};
}
