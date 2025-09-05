// Solves the elevator ride problem (bin packing variation) using bitmask DP.
// Time Complexity: O(n * 2^n)
// Space Complexity: O(2^n)
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int num_items;
    long long capacity;
    std::cin >> num_items >> capacity;
    std::vector<long long> weights(num_items);
    for (int i = 0; i < num_items; ++i) {
        std::cin >> weights[i];
    }

    // dp[mask] stores {number_of_rides, weight_of_last_ride}
    std::vector<std::pair<int, long long>> dp(1 << num_items);

    // Base case: 0 items processed. We are on the 1st ride, which is empty.
    // This works for n >= 1, which is the typical constraint for this problem.
    dp[0] = {1, 0};

    for (int mask = 1; mask < (1 << num_items); ++mask) {
        // Initialize with a value that will surely be overridden
        dp[mask] = {num_items + 1, 0};

        for (int i = 0; i < num_items; ++i) {
            if (mask & (1 << i)) {
                // State before adding item i
                std::pair<int, long long> prev_state = dp[mask ^ (1 << i)];
                long long item_weight = weights[i];

                if (prev_state.second + item_weight <= capacity) {
                    // Add item to the last ride
                    prev_state.second += item_weight;
                } else {
                    // Start a new ride for this item
                    prev_state.first++;
                    prev_state.second = item_weight;
                }
                // Update with the best option found so far for this mask
                dp[mask] = std::min(dp[mask], prev_state);
            }
        }
    }

    std::cout << dp[(1 << num_items) - 1].first << std::endl;
}
