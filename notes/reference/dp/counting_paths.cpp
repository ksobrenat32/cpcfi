// Counts the number of paths from top-left to bottom-right in a grid with obstacles.
// Allowed moves are right and down.
// Time Complexity: O(N*N) where N is the grid size.
// Space Complexity: O(N*N)
#include <iostream>
#include <vector>
#include <string>

void solve_counting_paths() {
    int size;
    std::cin >> size;
    std::vector<std::string> grid(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> grid[i];
    }

    const int MOD = 1e9 + 7;
    std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));

    // Base case: If starting cell is not an obstacle, there is one way to be there.
    if (grid[0][0] == '.') {
        dp[0][0] = 1;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0; // No paths can go through an obstacle.
                continue;
            }

            // Add paths from the cell above.
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            // Add paths from the cell to the left.
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    std::cout << dp[size - 1][size - 1] << std::endl;
}
