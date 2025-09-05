// Calculates the length of the Longest Common Subsequence (LCS) using space-optimized DP.
// Time Complexity: O(M*N) where M and N are the lengths of the strings.
// Space Complexity: O(min(M,N))
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solve_lcs_length() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    // Ensure s2 is the shorter string to optimize space.
    if (s1.length() < s2.length()) {
        std::swap(s1, s2);
    }

    int m = s1.length();
    int n = s2.length();

    // We only need two rows for the DP table.
    std::vector<int> prev_row(n + 1, 0);
    std::vector<int> current_row(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                current_row[j] = 1 + prev_row[j - 1];
            } else {
                current_row[j] = std::max(prev_row[j], current_row[j - 1]);
            }
        }
        // Move current row to previous row for the next iteration.
        prev_row = current_row;
    }

    return prev_row[n];
}
