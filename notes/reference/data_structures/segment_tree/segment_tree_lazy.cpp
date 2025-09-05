// Implements a Segment Tree with Lazy Propagation.
// This implementation is configured for two common operations:
// 1. Range Update: Add a value to all elements in a range [l, r].
// 2. Range Query: Find the sum of all elements in a range [l, r].
//
// The template is designed to be adaptable for other operations (e.g., range set,
// range min/max) by modifying the `join_values`, `apply_lazy`, and `join_lazy` methods.
//
// Time Complexity: O(N) for construction, O(log N) for range updates and queries.
// Space Complexity: O(N)

#include <vector>
#include <functional>

template<typename T, typename U>
class LazySegmentTree {
private:
    int n;
    std::vector<T> tree;
    std::vector<U> lazy;
    T query_identity = 0;
    U update_identity = 0;

    // --- Core Operation Functions (customize for different problems) ---

    // Combines the results from left and right children.
    T join_values(T left, T right) {
        return left + right;
    }

    // Applies a lazy update to a node's actual value.
    T apply_lazy_to_value(T value, U lazy_val, int range_len) {
        return value + lazy_val * range_len;
    }

    // Combines a new lazy update with a pending one on a node.
    U join_lazy_updates(U existing_lazy, U new_lazy) {
        return existing_lazy + new_lazy;
    }

    // --- End of Core Operation Functions ---

    void push(int v_idx, int tl, int tr) {
        if (lazy[v_idx] == update_identity) return;

        tree[v_idx] = apply_lazy_to_value(tree[v_idx], lazy[v_idx], tr - tl + 1);
        if (tl != tr) {
            lazy[2 * v_idx] = join_lazy_updates(lazy[2 * v_idx], lazy[v_idx]);
            lazy[2 * v_idx + 1] = join_lazy_updates(lazy[2 * v_idx + 1], lazy[v_idx]);
        }
        lazy[v_idx] = update_identity;
    }

    void build_recursive(const std::vector<T>& arr, int v_idx, int tl, int tr) {
        if (tl == tr) {
            if (tl < arr.size()) tree[v_idx] = arr[tl];
        } else {
            int tm = tl + (tr - tl) / 2;
            build_recursive(arr, 2 * v_idx, tl, tm);
            build_recursive(arr, 2 * v_idx + 1, tm + 1, tr);
            tree[v_idx] = join_values(tree[2 * v_idx], tree[2 * v_idx + 1]);
        }
    }

    void update_recursive(int v_idx, int tl, int tr, int l, int r, U addend) {
        push(v_idx, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v_idx] = join_lazy_updates(lazy[v_idx], addend);
            push(v_idx, tl, tr);
        } else {
            push(v_idx, tl, tr);
            int tm = tl + (tr - tl) / 2;
            update_recursive(2 * v_idx, tl, tm, l, std::min(r, tm), addend);
            update_recursive(2 * v_idx + 1, tm + 1, tr, std::max(l, tm + 1), r, addend);
            tree[v_idx] = join_values(tree[2*v_idx], tree[2*v_idx+1]);
        }
    }

    T query_recursive(int v_idx, int tl, int tr, int l, int r) {
        if (l > r) return query_identity;
        push(v_idx, tl, tr);
        if (l == tl && r == tr) {
            return tree[v_idx];
        }
        int tm = tl + (tr - tl) / 2;
        T left_res = query_recursive(2 * v_idx, tl, tm, l, std::min(r, tm));
        T right_res = query_recursive(2 * v_idx + 1, tm + 1, tr, std::max(l, tm + 1), r);
        return join_values(left_res, right_res);
    }

public:
    LazySegmentTree(int size) : n(size) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    LazySegmentTree(const std::vector<T>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
        build_recursive(arr, 1, 0, n - 1);
    }

    void range_update(int l, int r, U addend) {
        update_recursive(1, 0, n - 1, l, r, addend);
    }

    T range_query(int l, int r) {
        return query_recursive(1, 0, n - 1, l, r);
    }
};
