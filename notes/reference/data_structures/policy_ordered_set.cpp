#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;

// To allow repetitions
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

// To not allow repetitions
typedef tree<pair<int, int>, null_type,
             less<pair<int, int> >, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

ordered_set pt; // Definition

pt.order_of_key(x); // Number of items strictly smaller than x
pt.find_by_order(k); // Iterator to the kth element
