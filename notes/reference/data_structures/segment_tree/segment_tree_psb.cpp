// Implements a Segment Tree to solve the Maximum Subarray Sum problem.
// Supports point updates and range queries for the max subarray sum in O(log N).
//
// The core idea is to store a Node in each segment of the tree containing 4 values:
// 1. sum: The total sum of the elements in the range.
// 2. max_prefix: The maximum sum of a prefix of the range.
// 3. max_suffix: The maximum sum of a suffix of the range.
// 4. max_subarray: The maximum sum of any contiguous subarray in the range.
//
// A parent node's values are calculated by intelligently joining its two children.
//
// Time Complexity: O(N) for construction, O(log N) for updates and queries.
// Space Complexity: O(N)

#include <vector>
#include <algorithm>

template<typename T>
class MaxSubarraySumSegmentTree {
public:
    struct Node {
        T sum;
        T max_prefix;
        T max_suffix;
        T max_subarray;
    };

private:
    int n;
    std::vector<Node> tree;
    Node identity_node = {0, 0, 0, 0};

    Node join(const Node& left, const Node& right) {
        Node res;
        res.sum = left.sum + right.sum;
        res.max_prefix = std::max(left.max_prefix, left.sum + right.max_prefix);
        res.max_suffix = std::max(right.max_suffix, right.sum + left.max_suffix);
        res.max_subarray = std::max({left.max_subarray, right.max_subarray, left.max_suffix + right.max_prefix});
        return res;
    }

    void build_recursive(const std::vector<T>& arr, int v_idx, int tl, int tr) {
        if (tl == tr) {
            T val = (tl < arr.size()) ? arr[tl] : 0;
            T non_neg_val = std::max((T)0, val);
            tree[v_idx] = {val, non_neg_val, non_neg_val, non_neg_val};
        } else {
            int tm = tl + (tr - tl) / 2;
            build_recursive(arr, 2 * v_idx, tl, tm);
            build_recursive(arr, 2 * v_idx + 1, tm + 1, tr);
            tree[v_idx] = join(tree[2 * v_idx], tree[2 * v_idx + 1]);
        }
    }

    void update_recursive(int v_idx, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            T non_neg_val = std::max((T)0, new_val);
            tree[v_idx] = {new_val, non_neg_val, non_neg_val, non_neg_val};
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

    Node query_recursive(int v_idx, int tl, int tr, int l, int r) {
        if (l > r) return identity_node;
        if (l == tl && r == tr) return tree[v_idx];
        int tm = tl + (tr - tl) / 2;
        Node left_res = query_recursive(2 * v_idx, tl, tm, l, std::min(r, tm));
        Node right_res = query_recursive(2 * v_idx + 1, tm + 1, tr, std::max(l, tm + 1), r);
        return join(left_res, right_res);
    }

public:
    MaxSubarraySumSegmentTree(const std::vector<T>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        if (n > 0) build_recursive(arr, 1, 0, n - 1);
    }

    // The query returns a Node containing the answer.
    // Access the `.max_subarray` member for the final result.
    Node query(int l, int r) {
        if (l > r || l < 0 || r >= n) return identity_node;
        return query_recursive(1, 0, n - 1, l, r);
    }

    void update(int pos, T new_val) {
        if (pos < 0 || pos >= n) return;
        update_recursive(1, 0, n - 1, pos, new_val);
    }
};
