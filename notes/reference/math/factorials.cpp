// Precomputes factorials and their modular inverses up to a given limit `n`.
// This is essential for calculating combinations C(n, k) in O(1) time after precomputation.
// Assumes a prime modulus `MOD` and a modular inverse function `modular_inverse(a, m)`.
// It also assumes global arrays `factorial` and `inverse_factorial` are declared.
// Time complexity: O(n + log MOD) - dominated by O(n).
// Space complexity: O(n) for storing the precomputed values.

void precompute_factorials(long long n) {
    // factorial[i] stores i! mod MOD
    factorial[0] = 1;
    for (long long i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    // inverse_factorial[i] stores (i!)^-1 mod MOD
    // We compute the inverse of n! first, which takes O(log MOD) with Fermat's Little Theorem.
    inverse_factorial[n] = modular_inverse(factorial[n], MOD);

    // Then, we compute the rest of the inverse factorials in O(n) using a recurrence.
    // The recurrence is based on the identity: (i!)^-1 = ((i+1)!)^-1 * (i+1).
    for (long long i = n - 1; i >= 0; i--) {
        inverse_factorial[i] = (inverse_factorial[i + 1] * (i + 1)) % MOD;
    }
}
