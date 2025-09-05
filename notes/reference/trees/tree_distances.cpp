/**
 * @brief Farthest Node for All Nodes in a Tree.
 *
 * This implementation calculates, for each node in a tree, the maximum distance
 * to any other node in that tree. It is a classic problem that can be solved
 * optimally in linear time using a two-pass DFS approach (a form of dynamic
 * programming on trees).
 *
 * The algorithm works in two main phases:
 *
 * 1. `dfs1` (Bottom-up DP): This first DFS traversal computes, for each node `u`,
 *    the lengths of the two longest paths that start at `u` and go downwards
 *    into its subtree. Let's call these `fir[u]` and `sec[u]`.
 *
 * 2. `dfs2` (Top-down DP): This second DFS traversal computes the final answers.
 *    For any node `u`, the farthest node is either in its subtree (the path
 *    length is `fir[u]`) or it's somewhere else, requiring the path to go "up"
 *    towards its parent `p`. The length of the longest upward path from `u` is
 *    passed down from its parent `p` during the traversal. This upward path from `p`
 *    is either the longest upward path for `p` or one of `p`'s own downward
 *    paths that doesn't include `u`. The logic correctly combines the longest
 *    downward path (`fir[u]`) and the longest upward path to find the final
 *    answer for `u`.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> fir, sec, ans;

// DFS1: Compute longest and second longest downward paths for each node.
void dfs1(int u, int p) {
    fir[u] = sec[u] = 0;
    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            int child_path = fir[v] + 1;
            if (child_path > fir[u]) {
                sec[u] = fir[u];
                fir[u] = child_path;
            } else if (child_path > sec[u]) {
                sec[u] = child_path;
            }
        }
    }
}

// DFS2: Compute final answers by passing longest upward path info down.
void dfs2(int u, int p, int up_path) {
    ans[u] = max(fir[u], up_path);
    for (int v : adj[u]) {
        if (v != p) {
            // If the parent's longest downward path goes through v,
            // we must use the parent's second longest for the new up_path.
            if (fir[v] + 1 == fir[u]) {
                dfs2(v, u, max(up_path, sec[u]) + 1);
            } else {
                // Otherwise, the parent's longest downward path is available.
                dfs2(v, u, max(up_path, fir[u]) + 1);
            }
        }
    }
}

/**
 * @brief Computes the max distance to any other node for all nodes.
 * @param n The number of nodes in the tree.
 * @param edges A list of edges defining the tree.
 * @return A vector where ans[i] is the max distance for node i.
 */
vector<int> compute_all_farthest_distances(int n, const vector<pair<int, int>>& edges) {
    adj.assign(n + 1, vector<int>());
    fir.assign(n + 1, 0);
    sec.assign(n + 1, 0);
    ans.assign(n + 1, 0);

    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    // Assuming the tree is connected and nodes are 1-indexed.
    dfs1(1, 0);
    dfs2(1, 0, 0);

    return ans;
}
