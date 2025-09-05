// Checks if a number is prime using an optimized trial division method.
// This method is efficient for relatively small numbers but is too slow for
// very large numbers (e.g., 64-bit integers). For large inputs, a
// probabilistic test like Miller-Rabin is strongly preferred.
// Time complexity: O(sqrt(n))
// Space complexity: O(1)
bool is_prime_trial_division(long long n) {
    // Prime numbers are integers greater than 1.
    if (n <= 1) {
        return false;
    }
    // 2 is the only even prime number.
    if (n == 2) {
        return true;
    }
    // All other even numbers are not prime.
    if (n % 2 == 0) {
        return false;
    }
    // Check for odd divisors from 3 up to the square root of n.
    // We can increment by 2 because we have already handled all even numbers.
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    // If no divisors are found, the number is prime.
    return true;
}
