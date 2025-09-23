// Floyd-Warshall algorithm for finding all-pairs shortest paths in a weighted directed graph.
// It can handle positive or negative edge weights and can detect negative cycles.
// Time complexity: O(V^3) due to the three nested loops.
// Space complexity: O(V^2) for the distance and predecessor matrices.

#include <vector>
#include <algorithm>
#include <limits>

const long long FW_INF = std::numeric_limits<long long>::max();

struct Edge {
    int u, v, weight;
};

struct FloydWarshallResult {
    bool has_negative_cycle;
    std::vector<std::vector<long long>> distance;
    std::vector<std::vector<int>> predecessor; // 'next' vertex on the path from i to j
};

// Takes the number of vertices and a list of edges as input.
FloydWarshallResult floyd_warshall(int num_vertices, const std::vector<Edge>& edges) {
    std::vector<std::vector<long long>> dist(num_vertices, std::vector<long long>(num_vertices, FW_INF));
    std::vector<std::vector<int>> next(num_vertices, std::vector<int>(num_vertices, -1));

    for (int i = 0; i < num_vertices; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    for (const auto& edge : edges) {
        if (dist[edge.u][edge.v] > (long long)edge.weight) {
            dist[edge.u][edge.v] = edge.weight;
            next[edge.u][edge.v] = edge.v;
        }
    }

    // Main algorithm loop.
    for (int k = 0; k < num_vertices; ++k) {
        for (int i = 0; i < num_vertices; ++i) {
            for (int j = 0; j < num_vertices; ++j) {
                if (dist[i][k] != FW_INF && dist[k][j] != FW_INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    // Check for negative cycles.
    bool has_negative_cycle = false;
    for (int i = 0; i < num_vertices; ++i) {
        if (dist[i][i] < 0) {
            has_negative_cycle = true;
            break;
        }
    }

    return {has_negative_cycle, dist, next};
}

// Reconstructs the shortest path from u to v using the 'next' matrix.
std::vector<int> reconstruct_path(int u, int v, const FloydWarshallResult& result) {
    if (result.has_negative_cycle || result.predecessor[u][v] == -1) {
        return {}; // No path exists or a negative cycle is present.
    }

    std::vector<int> path;
    int current = u;
    while (current != v) {
        if (current == -1) return {}; // Should not happen if predecessor[u][v] is valid.
        path.push_back(current);
        current = result.predecessor[current][v];
    }
    path.push_back(v);

    return path;
}
