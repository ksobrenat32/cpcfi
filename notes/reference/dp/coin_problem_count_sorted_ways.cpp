// Counts the number of ways (combinations) to form a sum using given coins.
// This approach processes coins one by one to count unique sets of coins, not permutations.
// Time Complexity: O(num_coins * target_sum)
// Space Complexity: O(target_sum)
#include <iostream>
#include <vector>

void solve_coin_combinations() {
    int num_coins, target_sum;
    std::cin >> num_coins >> target_sum;
    std::vector<int> coins(num_coins);
    for (int i = 0; i < num_coins; ++i) {
        std::cin >> coins[i];
    }

    const int MOD = 1e9 + 7;
    std::vector<int> dp(target_sum + 1, 0);
    dp[0] = 1; // Base case: one way to make sum 0 (by choosing no coins)

    for (int coin_value : coins) {
        for (int j = coin_value; j <= target_sum; ++j) {
            dp[j] = (dp[j] + dp[j - coin_value]) % MOD;
        }
    }

    std::cout << dp[target_sum] << std::endl;
}
