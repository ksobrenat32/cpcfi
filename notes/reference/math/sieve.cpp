// Finds all prime numbers up to a given limit `n` using the Sieve of Eratosthenes.
// This is a highly efficient algorithm for generating all primes up to a large number.
// After running, the returned vector `is_prime` will have `is_prime[i] == true` if i is prime.
// Time complexity: O(n * log(log n))
// Space complexity: O(n)

std::vector<bool> sieve_of_eratosthenes(int n) {
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    // The outer loop only needs to go up to sqrt(n).
    for (long long p = 2; p * p <= n; p++) {
        // If p has not been marked composite, it is a prime.
        if (is_prime[p]) {
            // Mark all multiples of p as composite.
            // We can start from p*p because smaller multiples (e.g., 2*p, 3*p)
            // would have already been marked by smaller primes (2, 3).
            for (long long i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}
