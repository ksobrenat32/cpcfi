// Implements a generic, iterative (non-recursive) Segment Tree.
// This version can be faster than the recursive one by avoiding recursion overhead.
// The tree is stored in an array of size 2*N, with leaves in the range [N, 2N-1].
//
// It can be configured for different associative operations (sum, min, max, etc.)
// by providing a "join" operation functor and a corresponding identity element.
//
// Time Complexity: O(N) for construction, O(log N) for updates and queries.
// Space Complexity: O(N)

#include <vector>
#include <functional>

template<typename T, class JoinOp = std::plus<T>>
class IterativeSegmentTree {
private:
    int n;
    std::vector<T> tree;
    JoinOp join;
    T identity_element;

public:
    // Construct from an array, with a custom join operation and identity element.
    IterativeSegmentTree(const std::vector<T>& arr, JoinOp op = JoinOp(), T ident = T{})
        : n(arr.size()), join(op), identity_element(ident) {
        tree.assign(2 * n, identity_element);
        // Copy initial array to the second half of the tree (the leaves).
        for (int i = 0; i < n; ++i) {
            tree[n + i] = arr[i];
        }
        // Build the tree's internal nodes by iterating backwards from the leaves.
        for (int i = n - 1; i > 0; --i) {
            tree[i] = join(tree[2 * i], tree[2 * i + 1]);
        }
    }

    // Update the value at a single position `pos`.
    void update(int pos, T new_val) {
        if (pos < 0 || pos >= n) return;
        pos += n;
        tree[pos] = new_val;
        // Traverse up the tree, updating parent nodes.
        while (pos > 1) {
            pos /= 2;
            tree[pos] = join(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    // Queries the half-open interval [l, r).
    T query(int l, int r) {
        if (l < 0 || r > n || l >= r) return identity_element;
        T result = identity_element;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = join(result, tree[l++]);
            if (r & 1) result = join(result, tree[--r]);
        }
        return result;
    }
};
