// Finds articulation points (cut vertices) in an undirected graph using Tarjan's algorithm.
// An articulation point is a vertex whose removal increases the number of connected components.
// Time complexity: O(V + E), as it's based on a single DFS traversal.
// Space complexity: O(V) for storing discovery times, low-link values, and parent pointers.

struct ArticulationPointFinder {
    int num_vertices;
    const vector<vector<int>>& adj;
    vector<int> discovery_time;
    vector<int> low_link;
    vector<int> parent;
    vector<bool> is_articulation_point;
    int time;

    ArticulationPointFinder(const vector<vector<int>>& graph_adj) :
        num_vertices(graph_adj.size()),
        adj(graph_adj),
        discovery_time(num_vertices, 0),
        low_link(num_vertices, 0),
        parent(num_vertices, -1),
        is_articulation_point(num_vertices, false),
        time(0) {}

    void find_articulation_points_dfs(int u) {
        discovery_time[u] = low_link[u] = ++time;
        int children_in_dfs_tree = 0;

        for (int v : adj[u]) {
            if (v == parent[u]) continue;

            if (discovery_time[v] != 0) { // This is a back edge.
                low_link[u] = min(low_link[u], discovery_time[v]);
            } else { // This is a tree edge.
                children_in_dfs_tree++;
                parent[v] = u;
                find_articulation_points_dfs(v);
                low_link[u] = min(low_link[u], low_link[v]);

                // u is an articulation point if:
                // 1. It is the root of the DFS tree and has more than one child.
                if (parent[u] == -1 && children_in_dfs_tree > 1) {
                    is_articulation_point[u] = true;
                }
                // 2. It is not the root, and for some child v, there is no back edge from v or its descendants to an ancestor of u.
                if (parent[u] != -1 && low_link[v] >= discovery_time[u]) {
                    is_articulation_point[u] = true;
                }
            }
        }
    }

    // Returns a vector containing all articulation points in the graph.
    vector<int> find() {
        for (int i = 0; i < num_vertices; ++i) {
            if (discovery_time[i] == 0) {
                find_articulation_points_dfs(i);
            }
        }

        vector<int> result;
        for (int i = 0; i < num_vertices; ++i) {
            if (is_articulation_point[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
