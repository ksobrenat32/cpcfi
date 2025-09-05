// Implements a Persistent Segment Tree using an arena allocation scheme.
// This version is optimized for performance by avoiding heap allocations for each node,
// but requires the user to estimate the maximum number of nodes required upfront.
//
// This implementation is generic and supports various range queries (sum, min, max)
// by providing a custom join operation functor. It defaults to range sum.
//
// Time Complexity: O(log N) for update and query. O(N) for initial build.
// Space Complexity: O(MX_NODES). A safe estimate for MX_NODES is
// initial_nodes (approx 2*N) + num_updates * (log N).

#include <vector>
#include <functional>
#include <stdexcept>

template<typename T, class JoinOp = std::plus<T>>
class PersistentSegmentTree {
private:
    struct Node {
        T value;
        int left_child = 0;
        int right_child = 0;
    };

    const int n;
    std::vector<Node> tree;
    int next_node_idx = 1;
    JoinOp join;
    T identity_element;

    int create_node() {
        if (next_node_idx >= tree.size()) {
            throw std::runtime_error("PersistentSegmentTree arena exhausted.");
        }
        return next_node_idx++;
    }

    int build_recursive(const std::vector<T>& arr, int tl, int tr) {
        int v_idx = create_node();
        if (tl == tr) {
            if (tl < arr.size()) tree[v_idx].value = arr[tl];
            return v_idx;
        }
        int mid = tl + (tr - tl) / 2;
        int l_child = build_recursive(arr, tl, mid);
        int r_child = build_recursive(arr, mid + 1, tr);
        tree[v_idx] = {join(tree[l_child].value, tree[r_child].value), l_child, r_child};
        return v_idx;
    }

    T query_recursive(int v_idx, int ql, int qr, int tl, int tr) {
        if (!v_idx || qr < tl || tr < ql) {
            return identity_element;
        }
        if (ql <= tl && tr <= qr) {
            return tree[v_idx].value;
        }
        int mid = tl + (tr - tl) / 2;
        T left_res = query_recursive(tree[v_idx].left_child, ql, qr, tl, mid);
        T right_res = query_recursive(tree[v_idx].right_child, ql, qr, mid + 1, tr);
        return join(left_res, right_res);
    }

    int update_recursive(int v_idx, int pos, T val, int tl, int tr) {
        int new_v_idx = create_node();
        if (tl == tr) {
            tree[new_v_idx].value = val;
            return new_v_idx;
        }
        int mid = tl + (tr - tl) / 2;
        int l_child = tree[v_idx].left_child;
        int r_child = tree[v_idx].right_child;
        if (pos <= mid) {
            l_child = update_recursive(l_child, pos, val, tl, mid);
        } else {
            r_child = update_recursive(r_child, pos, val, mid + 1, tr);
        }
        tree[new_v_idx] = {join(tree[l_child].value, tree[r_child].value), l_child, r_child};
        return new_v_idx;
    }

public:
    PersistentSegmentTree(int size, int max_nodes, T ident = T{})
        : n(size), tree(max_nodes), identity_element(ident) {}

    // Builds from a 0-indexed array. Returns the root index of the new tree.
    int build(const std::vector<T>& arr) {
        return build_recursive(arr, 0, n - 1);
    }

    // Updates the value at `pos` in the tree version rooted at `root_idx`.
    // Returns the root index of the new tree version.
    int update(int root_idx, int pos, T val) {
        return update_recursive(root_idx, pos, val, 0, n - 1);
    }

    // Performs a range query on the tree version rooted at `root_idx`.
    T query(int root_idx, int l, int r) {
        return query_recursive(root_idx, l, r, 0, n - 1);
    }
};
