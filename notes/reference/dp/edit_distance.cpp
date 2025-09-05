// Calculates the Levenshtein (edit) distance between two strings using space-optimized DP.
// Edit distance is the minimum number of single-character edits (insertions, deletions, or substitutions)
// required to change one string into the other.
// Time Complexity: O(M*N) where M and N are the lengths of the strings.
// Space Complexity: O(min(M,N))
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solve_edit_distance() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    // Ensure s1 is the shorter string to optimize space.
    if (s1.length() < s2.length()) {
        std::swap(s1, s2);
    }

    int m = s1.length();
    int n = s2.length();

    // We only need one row (plus one variable) to compute the next row.
    std::vector<int> prev_row(n + 1, 0);

    // Initialize the first row. The distance from an empty string to s2[0..j] is j.
    for (int j = 0; j <= n; ++j) {
        prev_row[j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        int prev_row_prev_col = prev_row[0]; // Stores dp[i-1][j-1]
        prev_row[0] = i; // First element of the current row is i.

        for (int j = 1; j <= n; ++j) {
            int temp = prev_row[j]; // Store dp[i-1][j] to use in the next iteration
            if (s1[i - 1] == s2[j - 1]) {
                prev_row[j] = prev_row_prev_col;
            } else {
                prev_row[j] = 1 + std::min({prev_row[j],        // Deletion
                                            prev_row[j - 1],    // Insertion
                                            prev_row_prev_col});// Substitution
            }
            prev_row_prev_col = temp;
        }
    }

    return prev_row[n];
}
