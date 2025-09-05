// Implements a manager for multiple 2D Fenwick Trees, allowing for counting
// objects of different types on a 2D grid. It maps a type key to a dedicated
// Fenwick Tree instance.
//
// This file requires the `FenwickTree2D` implementation from `fenwick_2d_sum.cpp`.
//
// Time Complexity: O(log R * log C) for update and query (amortized due to map access).
// Space Complexity: O(K * R * C) where K is the number of distinct types used.

#include <unordered_map>

// Note: The following include is for context and assumes `fenwick_2d_sum.cpp` is available.
#include "fenwick_2d_sum.cpp"

template<typename TypeKey, typename T>
struct FenwickTree2DManager {
private:
    int rows, cols;
    std::unordered_map<TypeKey, FenwickTree2D<T>> trees;

public:
    FenwickTree2DManager(int r, int c) : rows(r), cols(c) {}

    // Adds 'delta' to the count of type 'key' at position (x, y) (1-based).
    void update(TypeKey key, int x, int y, T delta) {
        if (trees.find(key) == trees.end()) {
            // Lazily create a new Fenwick Tree for this type.
            trees.emplace(key, FenwickTree2D<T>(rows, cols));
        }
        trees.at(key).update(x, y, delta);
    }

    // Queries the total count of type 'key' in the rectangle from
    // (x1, y1) to (x2, y2) (1-based, inclusive).
    T query(TypeKey key, int x1, int y1, int x2, int y2) {
        if (trees.find(key) == trees.end()) {
            return 0;
        }
        return trees.at(key).range_query(x1, y1, x2, y2);
    }
};
