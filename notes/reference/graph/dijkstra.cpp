// Dijkstra's algorithm for finding the shortest paths from a single source vertex
// to all other vertices in a weighted graph with non-negative edge weights.
// Time complexity: O(E log V) using a binary heap (std::priority_queue).
// Space complexity: O(V + E) for the graph, distances, and priority queue.

#include <vector>
#include <queue>
#include <utility>
#include <limits>

// A large value to represent infinity. Using long long for distances to avoid overflow.
const long long DIJKSTRA_INF = std::numeric_limits<long long>::max();

struct DijkstraResult {
    std::vector<long long> distance;
    std::vector<int> predecessor;
};

// The graph is represented by an adjacency list where adj[u] contains pairs {v, weight} for each neighbor v of u.
DijkstraResult dijkstra(int num_vertices, int start_node, const std::vector<std::vector<std::pair<int, int>>>& adj) {
    std::vector<long long> distance(num_vertices, DIJKSTRA_INF);
    std::vector<int> predecessor(num_vertices, -1);

    // The priority queue stores pairs of {distance, vertex}, ordered by the smallest distance.
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;

    distance[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we have found a shorter path to u already, we can ignore this entry.
        if (current_dist > distance[u]) {
            continue;
        }

        // Relax all edges from u.
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != DIJKSTRA_INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    return {distance, predecessor};
}
