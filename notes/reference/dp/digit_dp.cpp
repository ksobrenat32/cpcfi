// Digit DP to count numbers in a range [L, R] where no two adjacent digits are the same.
// Time Complexity: O(log10(R) * 10 * 10) which is proportional to the number of digits in R.
// Space Complexity: O(log10(R) * 10 * 2 * 2) for the memoization table.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring> // For memset

// dp[pos][prev_digit][is_leading_zero][is_tight]
long long dp[20][10][2][2];
std::string num_as_string;

// Counts numbers from 0 up to the number represented by num_as_string
long long count_valid(int pos, int prev_digit, bool is_leading_zero, bool is_tight) {
    // Base case: we have successfully constructed a valid number.
    if (pos == num_as_string.length()) {
        return 1;
    }

    // Return memoized result if it exists.
    if (dp[pos][prev_digit][is_leading_zero][is_tight] != -1) {
        return dp[pos][prev_digit][is_leading_zero][is_tight];
    }

    long long ans = 0;
    int upper_bound = is_tight ? (num_as_string[pos] - '0') : 9;

    for (int current_digit = 0; current_digit <= upper_bound; ++current_digit) {
        // Condition: adjacent digits must not be the same.
        // This is ignored for leading zeros.
        if (is_leading_zero || current_digit != prev_digit) {
            // A new state is no longer a leading zero if the current digit is not 0.
            bool new_leading_zero = is_leading_zero && (current_digit == 0);
            // A new state is no longer tight if we pick a digit smaller than the upper bound.
            bool new_tight = is_tight && (current_digit == upper_bound);

            ans += count_valid(pos + 1, current_digit, new_leading_zero, new_tight);
        }
    }

    return dp[pos][prev_digit][is_leading_zero][is_tight] = ans;
}

// Helper function to solve for a single number N, counting valid numbers in [0, N].
long long solve_for_n(long long n) {
    num_as_string = std::to_string(n);
    memset(dp, -1, sizeof(dp));
    // The initial previous digit doesn't matter for leading zeros, can be anything (e.g., 0).
    return count_valid(0, 0, true, true);
}

// Example of how to use for a range [L, R]
void solve_range() {
    long long L, R;
    std::cin >> L >> R;
    // We count numbers up to R and subtract numbers up to L-1.
    // The number 0 is counted as valid (no adjacent digits), so we subtract 1 from the
    // final result of solve_for_n(R) if L=0, but since solve_for_n(L-1) for L>0 handles it,
    // this works. But for L=0, L-1 is -1, which is tricky. A simple way is:
    // count(R) - count(L-1).
    // The count for "0" is tricky. `solve_for_n(0)` returns 1.
    // `count_valid` for "0" will return 1.
    // Let's analyze `solve_for_n(R) - solve_for_n(L-1)`.
    // The problem this code solves is "count numbers with no adjacent same digits".
    // `solve_for_n(n)` counts numbers in `[0, n]` that satisfy the property.
    // Number 0 is counted. So total valid numbers in [L, R] is `solve_for_n(R) - solve_for_n(L-1)`.
    long long result = solve_for_n(R) - solve_for_n(L - 1);
    std::cout << result << std::endl;
}
