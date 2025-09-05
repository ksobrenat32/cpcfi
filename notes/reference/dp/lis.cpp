// Finds the Longest Increasing Subsequence (LIS) using an O(n log n) algorithm.
// Time Complexity: O(N log N)
// Space Complexity: O(N)
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> find_lis(const std::vector<int>& a) {
    if (a.empty()) {
        return {};
    }

    int n = a.size();
    // p[i] stores the index of the predecessor of a[i] in the LIS ending at a[i].
    std::vector<int> p(n, -1);
    // tails_indices[k] stores the index of the smallest tail of all increasing
    // subsequences with length k+1.
    std::vector<int> tails_indices(n, 0);
    int len = 1; // Length of the longest subsequence found so far.

    for (int i = 1; i < n; i++) {
        // Case 1: a[i] is smaller than the smallest tail; it starts a new LIS of length 1.
        if (a[i] < a[tails_indices[0]]) {
            tails_indices[0] = i;
        }
        // Case 2: a[i] is larger than the largest tail; it extends the LIS.
        else if (a[i] > a[tails_indices[len - 1]]) {
            p[i] = tails_indices[len - 1];
            tails_indices[len++] = i;
        }
        // Case 3: a[i] is in between; it can become a new, smaller tail for some LIS.
        // We find the smallest tail that is greater than or equal to a[i] and replace it.
        else {
            // Binary search to find the position to replace.
            auto it = std::lower_bound(tails_indices.begin(), tails_indices.begin() + len, a[i],
                [&a](int index, int value) {
                    return a[index] < value;
                });
            int pos = std::distance(tails_indices.begin(), it);

            if (pos > 0) {
                p[i] = tails_indices[pos - 1];
            }
            tails_indices[pos] = i;
        }
    }

    // Reconstruct the LIS by backtracking from the last element.
    std::vector<int> subseq;
    for (int i = tails_indices[len - 1]; i >= 0; i = p[i]) {
        subseq.push_back(a[i]);
    }
    std::reverse(subseq.begin(), subseq.end());
    return subseq;
}
