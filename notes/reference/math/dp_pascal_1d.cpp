// Calculates binomial coefficient C(n, k) using a space-optimized DP.
// It uses Pascal's identity: C(n, k) = C(n-1, k-1) + C(n-1, k).
// Time complexity: O(n * min(k, n-k))
// Space complexity: O(min(k, n-k))

long long combinations_pascal_1d(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    // C(n, k) == C(n, n-k), using smaller k is more efficient.
    if (k > n / 2) {
        k = n - k;
    }

    // dp[j] will store C(i, j) as we iterate i from 1 to n.
    std::vector<long long> dp(k + 1, 0);

    // Base case: C(i, 0) is always 1.
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        // Compute the i-th row of Pascal's triangle from the (i-1)-th row.
        // Iterate j downwards to use values from the previous row (i-1).
        for (int j = std::min(i, k); j > 0; j--) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[k];
}
