// Implements a 1-indexed Fenwick Tree for Range Updates and Point Queries (RUPQ).
// This allows adding a value to a range [l, r] and querying the final value
// at a single point, both in logarithmic time.
//
// The core idea is to represent a range update `(l, r, val)` as two point updates
// on an internal tree: one that adds `val` at index `l`, and one that subtracts
// `val` at index `r+1`. A point query at `idx` is then just the prefix sum up
// to `idx`, which correctly accumulates the changes from all relevant ranges.
//
// Time Complexity: O(log N) for both range updates and point queries.
// Space Complexity: O(N)

template<typename T>
struct FenwickTreeRUPQ {
private:
    vector<T> tree;
    int size;

    // Private helper for point updates on the internal tree.
    void update(int idx, T delta) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

public:
    // Constructor for a tree supporting n elements, indexed 1 to n.
    FenwickTreeRUPQ(int n) : size(n), tree(n + 1, 0) {}

    // Adds 'delta' to all elements in the range [l, r] (inclusive, 1-based).
    void range_update(int l, int r, T delta) {
        update(l, delta);
        if (r + 1 <= size) {
            update(r + 1, -delta);
        }
    }

    // Queries the value at a single 1-based index 'idx'.
    T point_query(int idx) {
        T result = 0;
        for (; idx > 0; idx -= idx & -idx) {
            result += tree[idx];
        }
        return result;
    }
};
