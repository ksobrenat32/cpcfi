/**
 * @brief Centroid Decomposition of a tree.
 *
 * Centroid decomposition is a divide-and-conquer technique for problems on trees.
 * It decomposes a tree into a "tree of centroids" by repeatedly finding a
 * centroid, making it the root of the current decomposition, and then recursively
 * processing the remaining connected components (subtrees).
 *
 * A centroid is a node whose removal splits the tree into subtrees, each with a
 * size of at most N/2, where N is the size of the current tree. This property
 * ensures that the height of the resulting centroid tree is at most O(log N).
 * This is useful for problems involving paths, as any path in the original tree
 * passes through exactly one centroid in the decomposition tree.
 *
 * The `build_centroid_decomp` function is the main driver. The comment "// do something"
 * inside it is a placeholder for the specific logic required by the problem being
 * solved (e.g., building the actual centroid tree, updating data structures).
 *
 * Time Complexity: O(N log N) for the decomposition process.
 * Space Complexity: O(N) for storing the tree and auxiliary arrays.
 */

vector<vector<int>> adj;
vector<bool> is_removed;
vector<int> subtree_size;

/**
 * @brief DFS to calculate the size of the subtree rooted at `node`.
 * @param node The root of the subtree.
 * @param parent The parent of the current node in the DFS traversal.
 * @return The size of the subtree.
 */
int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

/**
 * @brief Finds a centroid of the subtree containing `node`.
 * A tree may have one or two centroids; this function returns the first one it finds.
 * @param node The current node to check.
 * @param tree_size The total size of the current subtree.
 * @param parent The parent of the current node in the DFS traversal.
 * @return A centroid of the subtree.
 */
int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

/**
 * @brief Builds the centroid decomposition recursively.
 * @param node The starting node for the current decomposition step.
 */
void build_centroid_decomp(int node = 0) {
	int centroid = get_centroid(node, get_subtree_size(node));

	// The logic for the specific problem goes here.
	// For example, you might add edges to a new centroid tree,
	// or perform calculations based on the paths through the centroid.

	is_removed[centroid] = true;

	for (int child : adj[centroid]) {
		if (is_removed[child]) { continue; }
		build_centroid_decomp(child);
	}
}
