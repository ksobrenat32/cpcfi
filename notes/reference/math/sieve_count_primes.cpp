// Counts primes up to n using a memory-efficient segmented sieve.
// This is ideal when n is too large for a simple O(n) space sieve.
// Time complexity: O(n * log(log n))
// Space complexity: O(sqrt(n) + S) where S is the segment size.

long long count_primes_segmented(long long n) {
    // Segment size, chosen to be cache-friendly (e.g., 16KB or 32KB).
    const int SEGMENT_SIZE = 32768;

    // Part 1: Generate primes up to sqrt(n) using a simple sieve.
    long long limit = sqrt(n);
    std::vector<long long> primes;
    std::vector<bool> is_prime_small(limit + 1, true);
    is_prime_small[0] = is_prime_small[1] = false;
    for (long long p = 2; p <= limit; ++p) {
        if (is_prime_small[p]) {
            primes.push_back(p);
            for (long long i = p * p; i <= limit; i += p)
                is_prime_small[i] = false;
        }
    }

    // Part 2: Sieve the range [1, n] in segments and count the primes.
    long long prime_count = 0;
    std::vector<bool> is_prime_segment(SEGMENT_SIZE);

    for (long long k = 0; k * SEGMENT_SIZE <= n; ++k) {
        std::fill(is_prime_segment.begin(), is_prime_segment.end(), true);
        long long segment_start = k * SEGMENT_SIZE;
        long long segment_end = std::min(segment_start + SEGMENT_SIZE - 1, n);

        // Mark multiples of primes in the current segment.
        for (long long p : primes) {
            long long first_multiple = (segment_start + p - 1) / p * p;
            long long start_j = std::max(first_multiple, p * p);

            for (long long j = start_j; j <= segment_end; j += p) {
                is_prime_segment[j - segment_start] = false;
            }
        }

        // Handle 0 and 1 in the first segment.
        if (k == 0) {
            if (segment_start <= 0 && 0 <= segment_end) is_prime_segment[0 - segment_start] = false;
            if (segment_start <= 1 && 1 <= segment_end) is_prime_segment[1 - segment_start] = false;
        }

        // Count primes in the current segment.
        for (long long i = 0; i <= segment_end - segment_start; ++i) {
            if (is_prime_segment[i]) {
                prime_count++;
            }
        }
    }
    return prime_count;
}
