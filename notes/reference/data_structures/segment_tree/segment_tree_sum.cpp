// Implements a generic, recursive Segment Tree.
// It can be configured for different associative operations (sum, min, max, gcd, etc.)
// by providing a "join" operation functor and a corresponding identity element.
//
// By default, it is configured for Range Sum Queries.
//
// Time Complexity: O(N) for construction, O(log N) for updates and queries.
// Space Complexity: O(N)

#include <vector>
#include <functional>

template<typename T, class JoinOp = std::plus<T>>
class SegmentTree {
private:
    int n;
    std::vector<T> tree;
    JoinOp join;
    T identity_element;

    void build_recursive(const std::vector<T>& arr, int v_idx, int tl, int tr) {
        if (tl == tr) {
            if (tl < arr.size()) tree[v_idx] = arr[tl];
        } else {
            int tm = tl + (tr - tl) / 2;
            build_recursive(arr, 2 * v_idx, tl, tm);
            build_recursive(arr, 2 * v_idx + 1, tm + 1, tr);
            tree[v_idx] = join(tree[2 * v_idx], tree[2 * v_idx + 1]);
        }
    }

    T query_recursive(int v_idx, int tl, int tr, int l, int r) {
        if (l > r) {
            return identity_element;
        }
        if (l == tl && r == tr) {
            return tree[v_idx];
        }
        int tm = tl + (tr - tl) / 2;
        T left_res = query_recursive(2 * v_idx, tl, tm, l, std::min(r, tm));
        T right_res = query_recursive(2 * v_idx + 1, tm + 1, tr, std::max(l, tm + 1), r);
        return join(left_res, right_res);
    }

    void update_recursive(int v_idx, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v_idx] = new_val;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm) {
                update_recursive(2 * v_idx, tl, tm, pos, new_val);
            } else {
                update_recursive(2 * v_idx + 1, tm + 1, tr, pos, new_val);
            }
            tree[v_idx] = join(tree[2 * v_idx], tree[2 * v_idx + 1]);
        }
    }

public:
    // Construct from an array, with a custom join operation and identity element.
    SegmentTree(const std::vector<T>& arr, JoinOp op = JoinOp(), T ident = T{})
        : n(arr.size()), join(op), identity_element(ident) {
        tree.resize(4 * n);
        if (n > 0) {
            build_recursive(arr, 1, 0, n - 1);
        }
    }

    // Construct an empty tree of a given size.
    SegmentTree(int size, JoinOp op = JoinOp(), T ident = T{})
        : n(size), join(op), identity_element(ident) {
        tree.assign(4 * n, identity_element);
    }

    // Query the range [l, r] (inclusive).
    T query(int l, int r) {
        if (l > r || l < 0 || r >= n) return identity_element;
        return query_recursive(1, 0, n - 1, l, r);
    }

    // Update the value at a single position `pos`.
    void update(int pos, T new_val) {
        if (pos < 0 || pos >= n) return;
        update_recursive(1, 0, n - 1, pos, new_val);
    }
};
