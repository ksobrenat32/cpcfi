// Implements a 1-indexed Fenwick Tree for Range Updates and Range Queries (RURQ).
// This allows adding a value to a range [l, r] and querying the sum of a
// range [l, r], both in logarithmic time.
//
// The technique uses two underlying Fenwick Trees, `tree1` and `tree2`.
// A range update `(l, r, val)` is decomposed into four point updates.
// The prefix sum up to `idx` is then calculated using the formula:
//   prefix_sum(idx) = query(tree1, idx) * idx - query(tree2, idx)
// A range sum for [l, r] is then `prefix_sum(r) - prefix_sum(l-1)`.
//
// Time Complexity: O(log N) for range updates and range queries.
// Space Complexity: O(N)

template<typename T>
struct FenwickTreeRURQ {
private:
    vector<T> tree1, tree2;
    int size;

    void update(vector<T>& t, int idx, T delta) {
        for (; idx <= size; idx += idx & -idx) {
            t[idx] += delta;
        }
    }

    T query(const vector<T>& t, int idx) {
        T result = 0;
        for (; idx > 0; idx -= idx & -idx) {
            result += t[idx];
        }
        return result;
    }

    T prefix_query(int idx) {
        if (idx <= 0) return 0;
        return query(tree1, idx) * idx - query(tree2, idx);
    }

public:
    FenwickTreeRURQ(int n) : size(n), tree1(n + 1, 0), tree2(n + 1, 0) {}

    // Adds 'delta' to all elements in the range [l, r] (inclusive, 1-based).
    void range_update(int l, int r, T delta) {
        update(tree1, l, delta);
        if (r + 1 <= size) {
            update(tree1, r + 1, -delta);
        }
        update(tree2, l, delta * (l - 1));
        if (r + 1 <= size) {
            update(tree2, r + 1, -delta * r);
        }
    }

    // Queries the sum of the range [l, r] (inclusive, 1-based).
    T range_query(int l, int r) {
        if (l > r) return 0;
        return prefix_query(r) - prefix_query(l - 1);
    }
};
