// Bellman-Ford algorithm for finding shortest paths from a single source in a weighted digraph.
// It handles negative edge weights and can detect negative cycles.
// Time complexity: O(V * E), where V is the number of vertices and E is the number of edges.
// Space complexity: O(V) for storing distances and predecessors.

#include <vector>
#include <algorithm>

const long long INF = 1e18; // Use a large value for infinity

struct Edge {
    int u, v, weight;
};

struct BellmanFordResult {
    bool has_negative_cycle;
    std::vector<long long> distance;
    std::vector<int> predecessor;
};

class BellmanFord {
public:
    BellmanFordResult find_shortest_paths(int num_vertices, const std::vector<Edge>& edges, int start_node) {
        std::vector<long long> distance(num_vertices, INF);
        std::vector<int> predecessor(num_vertices, -1);
        distance[start_node] = 0;

        // Relax edges for V-1 iterations.
        for (int i = 0; i < num_vertices - 1; ++i) {
            for (const auto& edge : edges) {
                if (distance[edge.u] != INF && distance[edge.u] + edge.weight < distance[edge.v]) {
                    distance[edge.v] = distance[edge.u] + edge.weight;
                    predecessor[edge.v] = edge.u;
                }
            }
        }

        // Check for negative-weight cycles by running one more iteration.
        bool has_negative_cycle = false;
        for (const auto& edge : edges) {
            if (distance[edge.u] != INF && distance[edge.u] + edge.weight < distance[edge.v]) {
                has_negative_cycle = true;
                break;
            }
        }

        return {has_negative_cycle, distance, predecessor};
    }

    // Reconstructs the shortest path to a target node.
    // Returns an empty vector if no path exists to the target from the start node.
    std::vector<int> reconstruct_path(int target_node, int start_node, const std::vector<int>& predecessor) {
        if (predecessor[target_node] == -1 && target_node != start_node) {
             return {}; // No path exists.
        }

        std::vector<int> path;
        for (int current = target_node; current != -1; current = predecessor[current]) {
            path.push_back(current);
        }
        std::reverse(path.begin(), path.end());

        // Ensure the path starts from the start_node.
        if (path.empty() || path[0] != start_node) {
            return {};
        }

        return path;
    }
};
