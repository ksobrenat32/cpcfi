// Finds the minimum number of coins required to form a target sum.
// Time Complexity: O(num_coins * target_sum)
// Space Complexity: O(target_sum)
#include <iostream>
#include <vector>
#include <algorithm>

void solve_min_coins() {
    int num_coins, target_sum;
    std::cin >> num_coins >> target_sum;
    std::vector<int> coins(num_coins);
    for (int i = 0; i < num_coins; ++i) {
        std::cin >> coins[i];
    }

    // dp[i] stores the minimum number of coins to make sum i.
    // Initialize with a value larger than any possible answer.
    const int infinity = target_sum + 1;
    std::vector<int> dp(target_sum + 1, infinity);

    // Base case: 0 coins are needed to make a sum of 0.
    dp[0] = 0;

    for (int i = 1; i <= target_sum; ++i) {
        for (int coin_value : coins) {
            if (i - coin_value >= 0) {
                // If the subproblem can be solved, update the current state.
                if (dp[i - coin_value] != infinity) {
                    dp[i] = std::min(dp[i], dp[i - coin_value] + 1);
                }
            }
        }
    }

    if (dp[target_sum] == infinity) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[target_sum] << std::endl;
    }
}
