// Calculates binomial coefficient C(n, k) using a 2D DP table (Pascal's triangle).
// This method is illustrative but uses more memory than the 1D DP version.
// Time complexity: O(n * min(k, n-k))
// Space complexity: O(n * min(k, n-k))

long long combinations_pascal_2d(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    // C(n, k) == C(n, n-k), using smaller k is more efficient.
    if (k > n / 2) {
        k = n - k;
    }
    if (k == 0) {
        return 1;
    }

    // dp[i][j] stores the value of C(i, j).
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= std::min(i, k); j++) {
            // Base cases: C(i, 0) = 1 and C(i, i) = 1.
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                // Pascal's identity: C(i, j) = C(i-1, j-1) + C(i-1, j).
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}
