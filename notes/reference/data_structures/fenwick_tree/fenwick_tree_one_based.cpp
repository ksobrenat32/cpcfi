// Implements a 1-indexed Fenwick Tree (or Binary Indexed Tree) for sum queries.
// It supports point updates and prefix sum queries on indices in the range [1, N].
//
// Time Complexity: O(N) for construction, O(log N) for update and query operations.
// Space Complexity: O(N)

template<typename T>
struct FenwickTreeOneBased {
    vector<T> tree;
    int size;

    // Constructor for a tree of size n. Indices are 1...n.
    FenwickTreeOneBased(int n) : size(n + 1), tree(n + 1, 0) {}

    // Builds the Fenwick tree from a 0-indexed array in O(N) time.
    FenwickTreeOneBased(const vector<T>& arr) : FenwickTreeOneBased(arr.size()) {
        for (size_t i = 0; i < arr.size(); ++i) {
            tree[i + 1] = arr[i];
        }
        for (int i = 1; i < size; ++i) {
            int r = i + (i & -i);
            if (r < size) {
                tree[r] += tree[i];
            }
        }
    }

    // Adds a value 'delta' to the element at 1-based index 'idx'.
    void update(int idx, T delta) {
        for (; idx < size; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    // Queries the sum of the prefix [1, idx].
    T query(int idx) {
        T result = 0;
        for (; idx > 0; idx -= idx & -idx) {
            result += tree[idx];
        }
        return result;
    }

    // Queries the sum of the range [l, r] (inclusive, 1-based).
    T query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
