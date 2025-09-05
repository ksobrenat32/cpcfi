// Prim's algorithm for finding a Minimum Spanning Tree (MST) in an undirected, weighted, connected graph.
// It works by greedily selecting the cheapest edge that connects a vertex in the MST to a vertex outside the MST.
// This implementation is conceptually similar to Dijkstra's algorithm.
// Time complexity: O(E log V) using a priority queue.
// Space complexity: O(V + E) for the graph representation and auxiliary data structures.

#include <vector>
#include <queue>
#include <utility>
#include <limits>

const long long PRIM_INF = std::numeric_limits<long long>::max();

struct MstResult {
    bool is_possible; // True if a spanning tree was found for the whole graph.
    long long total_weight;
    std::vector<std::pair<int, int>> mst_edges;
};

// The graph is represented by an adjacency list where adj[u] contains pairs {v, weight} for each neighbor v of u.
MstResult prim_mst(int num_vertices, const std::vector<std::vector<std::pair<int, int>>>& adj, int start_node = 0) {
    if (num_vertices == 0) {
        return {true, 0, {}};
    }

    // A priority queue to store pairs of {cost, vertex}, ordered by the minimum cost to reach the vertex.
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;

    std::vector<long long> min_cost(num_vertices, PRIM_INF);
    std::vector<int> parent(num_vertices, -1);
    std::vector<bool> in_mst(num_vertices, false);

    min_cost[start_node] = 0;
    pq.push({0, start_node});

    long long total_weight = 0;
    int edges_in_mst = 0;

    while (!pq.empty() && edges_in_mst < num_vertices) {
        long long cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (in_mst[u]) {
            continue;
        }

        in_mst[u] = true;
        total_weight += cost;
        edges_in_mst++;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!in_mst[v] && (long long)weight < min_cost[v]) {
                min_cost[v] = weight;
                parent[v] = u;
                pq.push({min_cost[v], v});
            }
        }
    }

    // If not all vertices are included, the graph is not connected.
    if (edges_in_mst != num_vertices) {
        return {false, -1, {}};
    }

    // Reconstruct MST edges from the parent array.
    std::vector<std::pair<int, int>> mst_edges_list;
    for (int i = 0; i < num_vertices; ++i) {
        if (parent[i] != -1) {
            mst_edges_list.push_back({parent[i], i});
        }
    }

    return {true, total_weight, mst_edges_list};
}
