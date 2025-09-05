// Finds all prime numbers up to a given limit `n` using a linear sieve.
// It also computes the smallest prime factor (spf) for each number up to `n`.
// This is the most efficient sieve algorithm for finding primes.
// Time complexity: O(n)
// Space complexity: O(n)

void linear_sieve(int n, std::vector<int>& primes, std::vector<int>& smallest_prime_factor) {
    smallest_prime_factor.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; ++i) {
        if (smallest_prime_factor[i] == 0) {
            // i is a prime number, as it has no smaller prime factor.
            smallest_prime_factor[i] = i;
            primes.push_back(i);
        }
        // Each composite number `c` is marked exactly once.
        // `c` is represented as `c = i * p` where `p` is the smallest prime factor of `c`.
        // This implies that `p` must be less than or equal to the smallest prime factor of `i`.
        for (int p : primes) {
            if (p > smallest_prime_factor[i] || (long long)i * p > n) {
                break;
            }
            smallest_prime_factor[i * p] = p;
        }
    }
}
