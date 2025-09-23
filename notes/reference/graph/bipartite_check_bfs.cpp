// Checks if a graph is bipartite using Breadth-First Search (BFS).
// A graph is bipartite if its vertices can be divided into two disjoint sets, U and V,
// such that every edge connects a vertex in U to one in V.
// Time complexity: O(V + E), as each vertex and edge is visited once across all BFS traversals.
// Space complexity: O(V) for the color vector and the queue.

#include <vector>
#include <queue>

// The graph is represented by an adjacency list.
// Colors are represented by integers: 0 (uncolored), 1 (color A), 2 (color B).
bool is_bipartite(int num_vertices, const std::vector<std::vector<int>>& adj) {
    if (num_vertices == 0) {
        return true;
    }

    std::vector<int> color(num_vertices, 0);

    for (int i = 0; i < num_vertices; ++i) {
        if (color[i] == 0) { // If the vertex is not yet colored, start a new BFS.
            std::queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (v < 0 || v >= num_vertices) continue; // Optional: handle invalid edges gracefully.

                    if (color[v] == 0) {
                        // Assign the opposite color to the adjacent vertex.
                        color[v] = (color[u] == 1) ? 2 : 1;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // If an adjacent vertex has the same color, the graph is not bipartite.
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
