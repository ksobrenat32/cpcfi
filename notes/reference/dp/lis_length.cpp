// Finds the length of the Longest Increasing Subsequence (LIS) using an O(n log n) algorithm.
// Time Complexity: O(N log N)
// Space Complexity: O(N) in the worst case for the tails vector.
#include <iostream>
#include <vector>
#include <algorithm>

int solve_lis_length() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) {
        return 0;
    }

    // `tails` is a sorted vector where tails[i] is the smallest tail of all
    // increasing subsequences of length i+1.
    std::vector<int> tails;
    tails.push_back(a[0]);

    for (int i = 1; i < n; ++i) {
        // If a[i] is greater than the current largest tail, it extends the LIS.
        if (a[i] > tails.back()) {
            tails.push_back(a[i]);
        }
        // Otherwise, find the smallest tail that is greater than or equal to a[i]
        // and replace it with a[i]. This can potentially lead to a better LIS later.
        else {
            auto it = std::lower_bound(tails.begin(), tails.end(), a[i]);
            *it = a[i];
        }
    }

    return tails.size();
}
