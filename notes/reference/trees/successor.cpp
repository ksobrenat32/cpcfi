/**
 * @brief K-th Successor Finding using Binary Lifting.
 *
 * This implementation finds the k-th successor of any node in a functional graph
 * (a graph where each node has exactly one outgoing edge). This structure is
 * essentially a collection of paths and cycles.
 *
 * The algorithm uses binary lifting. It preprocesses a table `up[i][j]` which
 * stores the 2^j-th successor of node `i`. This table can be built in O(N log K)
 * time, where K is the maximum possible value for k.
 *
 * With the precomputed table, finding the k-th successor of a node involves
 * breaking down `k` into its binary representation and making jumps of powers of
 * two. This allows any query to be answered in O(log K) time.
 *
 * Time Complexity:
 * - Preprocessing: O(N log K)
 * - Query: O(log K)
 *
 * Space Complexity: O(N log K)
 */

#include <vector>
#include <cmath>

const int MAX_NODES = 200005;
const int LOG_MAX_K = 30; // Sufficient for k up to 2^30

int up[MAX_NODES][LOG_MAX_K];

/**
 * @brief Precomputes the successor table for binary lifting.
 * @param n The number of nodes.
 * @param successors A vector where successors[i] is the direct successor of node i.
 *                   Nodes should be 0-indexed.
 */
void build_successor_table(int n, const std::vector<int>& successors) {
    for (int i = 0; i < n; ++i) {
        up[i][0] = successors[i];
    }

    for (int j = 1; j < LOG_MAX_K; ++j) {
        for (int i = 0; i < n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

/**
 * @brief Finds the k-th successor of a given node.
 * @param start_node The node to start from (0-indexed).
 * @param k The number of steps to take.
 * @return The k-th successor of the start_node.
 */
int get_kth_successor(int start_node, long long k) {
    int current_node = start_node;
    for (int j = 0; j < LOG_MAX_K; ++j) {
        if ((k >> j) & 1) {
            current_node = up[current_node][j];
        }
    }
    return current_node;
}
