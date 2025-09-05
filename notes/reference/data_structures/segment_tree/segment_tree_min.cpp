// This file demonstrates how to use the generic SegmentTree class (defined in
// `segment_tree_sum.cpp`) to implement a tree for Range Minimum Queries (RMQ).

// Note: Assumes the generic SegmentTree class from `segment_tree_sum.cpp` is available.
#include "segment_tree_sum.cpp"
#include <algorithm> // For std::min
#include <limits>   // For std::numeric_limits

// A standard functor for the 'min' operation.
template<typename T>
struct MinFunctor {
    T operator()(const T& a, const T& b) const {
        return std::min(a, b);
    }
};

// A convenient type alias for a Range Minimum Query Segment Tree.
// To use it, you must provide the data type (e.g., int, long long).
template<typename T>
using MinSegmentTree = SegmentTree<T, MinFunctor<T>>;

/*
// --- Example Usage ---
#include <iostream>

int main() {
    std::vector<int> arr = {5, 2, 8, 1, 9, 4};

    // The identity element for the 'min' operation is positive infinity.
    const int INF = std::numeric_limits<int>::max();

    // Instantiate the generic SegmentTree with our MinFunctor and identity element.
    MinSegmentTree<int> min_tree(arr, MinFunctor<int>(), INF);

    // Query the minimum in range [1, 4] (should be 1)
    std::cout << "Min in [1, 4]: " << min_tree.query(1, 4) << std::endl;

    // Update position 3 to value 0
    min_tree.update(3, 0);

    // Query the minimum in range [1, 4] again (should be 0)
    std::cout << "Min in [1, 4] after update: " << min_tree.query(1, 4) << std::endl;

    return 0;
}
*/
