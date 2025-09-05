// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k) {
      vector<vector<int>> dp(n + 1, vector<int> (k + 1));

    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {

            // Base Cases
            if (j == 0 || j == i)
                dp[i][j] = 1;

            // Calculate value using previously
            // stored values
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}
