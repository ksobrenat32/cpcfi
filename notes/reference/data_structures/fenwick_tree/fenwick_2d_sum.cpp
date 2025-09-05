// Implements a 1-indexed 2D Fenwick Tree for point updates and range sum queries.
//
// Time Complexity:
// - Construction from array: O(R * C * log R * log C)
// - Point Update: O(log R * log C)
// - Range Sum Query: O(log R * log C)
// Note: A more complex O(R*C) construction algorithm exists but is omitted here for clarity.
//
// Space Complexity: O(R * C)

template<typename T>
struct FenwickTree2D {
private:
    vector<vector<T>> tree;
    int rows, cols;

    static int lsb(int i) { return i & -i; }

public:
    FenwickTree2D(int r, int c) : rows(r), cols(c), tree(r + 1, vector<T>(c + 1, 0)) {}

    // Builds the tree from a 0-indexed 2D vector.
    FenwickTree2D(const vector<vector<T>>& arr) : FenwickTree2D(arr.size(), arr.empty() ? 0 : arr[0].size()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] != 0) {
                    update(i + 1, j + 1, arr[i][j]);
                }
            }
        }
    }

    // Adds 'delta' to the value at (x, y) (1-based).
    void update(int x, int y, T delta) {
        for (int i = x; i <= rows; i += lsb(i)) {
            for (int j = y; j <= cols; j += lsb(j)) {
                tree[i][j] += delta;
            }
        }
    }

    // Returns the sum of the rectangle from (1, 1) to (x, y).
    T query(int x, int y) {
        T sum = 0;
        for (int i = x; i > 0; i -= lsb(i)) {
            for (int j = y; j > 0; j -= lsb(j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    // Queries the sum of the rectangle from (x1, y1) to (x2, y2) (1-based, inclusive).
    T range_query(int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return 0;
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};
