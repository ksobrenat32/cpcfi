// Implements a 0-indexed Fenwick Tree (or Binary Indexed Tree) for sum queries.
// It supports point updates and prefix sum queries.
//
// Time Complexity: O(N) for construction, O(log N) for update and query operations.
// Space Complexity: O(N)

template<typename T>
struct FenwickTree {
    vector<T> tree;
    int size;

    FenwickTree(int n) : size(n), tree(n, 0) {}

    // Builds the Fenwick tree from an existing array in O(N) time.
    FenwickTree(const vector<T>& arr) : FenwickTree(arr.size()) {
        for (int i = 0; i < size; i++) {
            tree[i] += arr[i];
            int r = i | (i + 1);
            if (r < size) {
                tree[r] += tree[i];
            }
        }
    }

    // Adds a value 'delta' to the element at index 'idx'.
    void update(int idx, T delta) {
        for (; idx < size; idx = idx | (idx + 1)) {
            tree[idx] += delta;
        }
    }

    // Queries the sum of the prefix [0, r].
    T query(int r) {
        T result = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            result += tree[r];
        }
        return result;
    }

    // Queries the sum of the range [l, r].
    T query_range(int l, int r) {
        if (l > r) return 0;
        if (l == 0) return query(r);
        return query(r) - query(l - 1);
    }
};
