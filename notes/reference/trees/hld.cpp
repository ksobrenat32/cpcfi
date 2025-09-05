/**
 * @brief Heavy-Light Decomposition for Path Queries on a Tree.
 *
 * Heavy-Light Decomposition (HLD) is a powerful technique that decomposes a tree
 * into a set of disjoint paths (heavy paths). This is done by classifying edges
 * as either "heavy" or "light". For each node, the edge leading to the child
 * with the largest subtree size is a heavy edge, and all other edges are light.
 * This forms heavy paths.
 *
 * The key property of HLD is that any path from the root to any node in the tree
 * will cross at most O(log N) light edges. This means any path between two nodes
 * `a` and `b` can be split into at most O(log N) segments that are part of a
 * heavy path.
 *
 * This implementation linearizes these heavy paths into an array (indexed by `pos`),
 * allowing the use of a data structure like a Segment Tree for efficient queries
 * on the paths. The `query` function demonstrates how to find the maximum value
 * on the path between two nodes `a` and `b`. It assumes the existence of a
 * `segment_tree_query(l, r)` function that operates on the linearized array.
 *
 * Time Complexity:
 * - Preprocessing (init): O(N)
 * - Path Query/Update: O(log^2 N) (O(log N) calls to the underlying O(log N) segment tree)
 *
 * Space Complexity: O(N) (for HLD arrays and the segment tree)
 */

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

// Assumes a segment tree or similar data structure is implemented elsewhere.
// int segment_tree_query(int l, int r);

/**
 * @brief First DFS to compute subtree sizes, depth, and identify heavy children.
 */
int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

/**
 * @brief Second DFS to decompose the tree into heavy paths.
 */
void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

/**
 * @brief Initializes the HLD data structures.
 */
void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

/**
 * @brief Example query to find the maximum value on the path between a and b.
 */
int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        // int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        // res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    // int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    // res = max(res, last_heavy_path_max);
    return res;
}
