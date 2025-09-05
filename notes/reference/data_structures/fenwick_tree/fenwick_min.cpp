// Implements a 0-indexed Fenwick Tree for prefix minimum queries.
//
// !!! IMPORTANT WARNING !!!
// This data structure has significant limitations and is NOT a general-purpose
// Range Minimum Query (RMQ) structure. For general RMQ, use a Segment Tree.
//
// 1. PREFIX QUERIES ONLY: It can only answer queries for the minimum in a prefix,
//    i.e., get_min(0, r). It CANNOT answer queries for an arbitrary range [l, r].
//
// 2. DECREASING UPDATES ONLY: The `update` operation can only decrease the value
//    at an index. It sets the value to min(current_value, new_value). It cannot
//    be used to increase a value or set it arbitrarily.
//
// Time Complexity: O(log N) for update and query operations.
// Space Complexity: O(N)

template<typename T>
struct FenwickTreePrefixMin {
    const T INF;
    vector<T> tree;
    int size;

    // Constructor requires the size and a value for infinity.
    FenwickTreePrefixMin(int n, T infinity) : size(n), INF(infinity), tree(n, infinity) {}

    // Updates the value at index 'idx' to be min(current_value, val).
    void update(int idx, T val) {
        for (; idx < size; idx = idx | (idx + 1)) {
            tree[idx] = min(tree[idx], val);
        }
    }

    // Queries the minimum of the prefix [0, r].
    T query(int r) {
        T result = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            result = min(result, tree[r]);
        }
        return result;
    }
};
