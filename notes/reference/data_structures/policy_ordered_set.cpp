// A guide to using the GNU Policy-Based Data Structures (PBDS),
// specifically the `tree` container, often used as an "ordered set".
//
// This data structure is essentially a self-balancing binary search tree (Red-Black Tree)
// that is augmented to support order statistics. It provides the functionality of
// std::set plus two additional O(log N) operations:
// 1. find_by_order(k): Returns an iterator to the k-th smallest element (0-indexed).
// 2. order_of_key(x): Returns the number of items in the set that are strictly less than x.
//
// To compile, you might need g++ and a command line like:
// g++ -std=c++17 -O2 your_file.cpp

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Bring the necessary namespaces into scope
using namespace __gnu_pbds;

// Template for a generic ordered set
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// --- How to Handle Duplicate Elements (Creating a Multiset) ---
// The default `ordered_set` does not allow duplicates. Here are two ways to create an ordered multiset.

// Option 1: Use std::pair.
// Store pairs of {value, unique_id}. The unique_id can be a timestamp or an index.
// This is safe and preserves the behavior of `lower_bound` and `upper_bound`.
// The downside is that erasing elements requires knowing the unique_id.
template<typename T>
using ordered_multiset_pair = tree<std::pair<T, int>, null_type, std::less<std::pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

// Option 2: Use `less_equal`.
// This is simpler to write, but it breaks the functionality of `lower_bound`.
// `lower_bound` will behave like `upper_bound`. Use this if you mainly need `order_of_key`.
template<typename T>
using ordered_multiset_le = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


/*
// --- Example Usage ---

int main() {
    // 1. Standard Ordered Set (unique elements)
    std::cout << "--- Standard Ordered Set ---" << std::endl;
    ordered_set<int> os;
    os.insert(10);
    os.insert(20);
    os.insert(30);
    os.insert(40);
    os.insert(20); // This insert will be ignored

    // Find the 2nd smallest element (0-indexed)
    // Should be 30
    auto it = os.find_by_order(2);
    std::cout << "2nd smallest element: " << *it << std::endl;

    // Find the number of elements strictly less than 25
    // Should be 2 (10, 20)
    size_t count_less_25 = os.order_of_key(25);
    std::cout << "Elements strictly less than 25: " << count_less_25 << std::endl;

    // Erase an element
    os.erase(20);

    // 2. Ordered Multiset using std::pair
    std::cout << "\n--- Ordered Multiset (using std::pair) ---" << std::endl;
    ordered_multiset_pair<int> omp;
    omp.insert({10, 0});
    omp.insert({20, 1});
    omp.insert({30, 2});
    omp.insert({20, 3}); // Now we can insert 20 again with a new unique id

    // Find number of elements strictly less than 20
    // This is tricky. We search for {20, -1}
    size_t count_less_20_pair = omp.order_of_key({20, -1});
    std::cout << "Elements strictly less than 20: " << count_less_20_pair << std::endl;

    // Find number of elements less than or equal to 20
    // We search for {20, __INT_MAX__} or similar
    size_t count_le_20_pair = omp.order_of_key({20, __INT_MAX__});
    std::cout << "Elements less than or equal to 20: " << count_le_20_pair << std::endl;


    return 0;
}
*/
