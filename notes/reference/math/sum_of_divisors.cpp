// Calculates the sum of all positive divisors of a number n.
// The function is based on the prime factorization of n.
// If n = p1^a1 * p2^a2 * ... * pk^ak, then the sum of divisors is
// σ(n) = (1+...+p1^a1) * (1+...+p2^a2) * ... * (1+...+pk^ak).
// This is the standard algorithm for single-number queries.
// Time complexity: O(sqrt(n))
// Space complexity: O(1)

long long sum_of_divisors(long long n) {
    if (n <= 0) {
        return 0; // Divisors are typically defined for positive integers.
    }
    if (n == 1) {
        return 1;
    }

    long long total_sum = 1;

    // Iterate through potential prime factors up to sqrt(n).
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            // p is a prime factor. Find its exponent in the factorization of n.
            int exponent = 0;
            while (n % p == 0) {
                exponent++;
                n /= p;
            }

            // Calculate the sum of powers for this prime: (1 + p + p^2 + ... + p^exponent)
            long long sum_of_powers = 1;
            long long power_of_p = 1;
            for (int i = 0; i < exponent; ++i) {
                power_of_p *= p;
                sum_of_powers += power_of_p;
            }

            total_sum *= sum_of_powers;
        }
    }

    // If n is still greater than 1 after the loop, it must be a prime factor itself.
    if (n > 1) {
        total_sum *= (1 + n);
    }

    return total_sum;
}
