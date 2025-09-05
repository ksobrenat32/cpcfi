// Solves a system of linear recurrences using DP with two states, optimized to O(1) space.
// This pattern is common in tiling problems; the specific recurrence relations are problem-dependent.
// Time Complexity: O(N)
// Space Complexity: O(1)
#include <iostream>

void solve_tiling_style_dp() {
    int n;
    std::cin >> n;
    const int MOD = 1e9 + 7;

    if (n == 0) {
        // The base case for many tiling problems is 1 way for a 0-sized grid.
        std::cout << 1 << std::endl;
        return;
    }

    // Base cases for the recurrence, corresponding to dp[n][0] and dp[n][1].
    long long state_A = 1; // Represents the first state (e.g., a "flat" end)
    long long state_B = 1; // Represents the second state (e.g., a "jagged" end)

    // We iterate from n-1 down to 1, as in the original code.
    for (int i = n - 1; i > 0; --i) {
        // Calculate the next states based on the previous ones.
        // Using temporary variables to avoid overwriting values before they are used.
        long long next_state_A = (2 * state_A + state_B) % MOD;
        long long next_state_B = (4 * state_B + state_A) % MOD;

        state_A = next_state_A;
        state_B = next_state_B;
    }

    // The final answer is the sum of the two states at position 1.
    std::cout << (state_A + state_B) % MOD << std::endl;
}
