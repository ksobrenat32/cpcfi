// Counts the number of ways (permutations) to form a sum using given coins.
// This approach iterates through sums first, counting different orderings as distinct.
// Time Complexity: O(num_coins * target_sum)
// Space Complexity: O(target_sum)
#include <iostream>
#include <vector>

void solve_coin_permutations() {
    int num_coins, target_sum;
    std::cin >> num_coins >> target_sum;
    std::vector<int> coins(num_coins);
    for (int i = 0; i < num_coins; ++i) {
        std::cin >> coins[i];
    }

    const int MOD = 1e9 + 7;
    std::vector<int> dp(target_sum + 1, 0);
    dp[0] = 1; // Base case: one way to make sum 0 (by choosing no coins)

    for (int i = 1; i <= target_sum; ++i) {
        for (int coin_value : coins) {
            if (i - coin_value >= 0) {
                dp[i] = (dp[i] + dp[i - coin_value]) % MOD;
            }
        }
    }

    std::cout << dp[target_sum] << std::endl;
}
