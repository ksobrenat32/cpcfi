/**
 * @brief Euler Tour (Tree Flattening) with Fenwick Tree for Subtree Queries.
 *
 * This file demonstrates the Euler tour technique, specifically for tree flattening,
 * combined with a Fenwick Tree (or Binary Indexed Tree) to perform efficient
 * subtree updates and queries.
 *
 * The `euler_tour` function performs a DFS traversal of the tree, recording the
 * entry (`in_time`) and exit (`out_time`) time for each node. This flattens the
 * tree structure into a linear representation. The key property is that all nodes
 * in the subtree of a node `u` are visited between `in_time[u]` and `out_time[u]`.
 * The implementation is iterative to prevent stack overflow on deep trees.
 *
 * A Fenwick Tree is included to showcase a common application. By building a
 * Fenwick tree over the flattened time range (1 to 2*N), we can answer subtree
 * queries. For example:
 * - To update a value at node `u`, you would update the Fenwick tree at `in_time[u]`.
 * - To query the sum of values in the subtree of `u`, you would perform a range
 *   query on the Fenwick tree from `in_time[u]` to `out_time[u]`.
 *
 * Time Complexity:
 * - Euler Tour Traversal: O(N)
 * - Fenwick Tree Update: O(log N)
 * - Fenwick Tree Query: O(log N)
 *
 * Space Complexity: O(N) for the adjacency list, time arrays, and Fenwick tree.
 */

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int in_time[MAXN], out_time[MAXN];
int timer = 0;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    int range_query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

void euler_tour(int root) {
    stack<tuple<int, int, bool>> st;
    st.push({root, -1, false});

    while (!st.empty()) {
        auto [u, parent, visited] = st.top();
        st.pop();

        if (!visited) {
            in_time[u] = ++timer;
            st.push({u, parent, true});

            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                if (*it != parent) {
                    st.push({*it, u, false});
                }
            }
        } else {
            out_time[u] = ++timer;
        }
    }
}
