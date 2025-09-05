// Finds all prime numbers in a given range [L, R] using a segmented sieve.
// This method is highly efficient for finding primes in a range where R can be large,
// but the size of the range (R - L) is manageable.
//
// Time complexity: O(sqrt(R) + (R - L) * log(log R))
// Space complexity: O(sqrt(R) + (R - L))

std::vector<bool> segmented_sieve(long long L, long long R) {
    // Part 1: Generate all primes up to sqrt(R) using a simple sieve.
    long long limit = sqrt(R);
    std::vector<long long> primes;
    std::vector<bool> is_prime_small(limit + 1, true);
    is_prime_small[0] = is_prime_small[1] = false;

    for (long long p = 2; p <= limit; ++p) {
        if (is_prime_small[p]) {
            primes.push_back(p);
            for (long long i = p * p; i <= limit; i += p) {
                is_prime_small[i] = false;
            }
        }
    }

    // Part 2: Sieve the range [L, R] using the primes found in Part 1.
    std::vector<bool> is_prime_segment(R - L + 1, true);
    if (L == 1) {
        is_prime_segment[0] = false;
    }

    for (long long p : primes) {
        // Find the first multiple of p that is >= L.
        long long start_multiple = (L + p - 1) / p * p;

        // Mark all multiples of p in the range [L, R].
        // We can start marking from max(start_multiple, p*p) because smaller
        // multiples of p would have already been marked by smaller prime factors.
        for (long long j = std::max(start_multiple, p * p); j <= R; j += p) {
            is_prime_segment[j - L] = false;
        }
    }

    return is_prime_segment;
}
