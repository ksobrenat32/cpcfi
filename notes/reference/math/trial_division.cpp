// Finds the prime factorization of a positive integer n using trial division.
// This method is efficient for numbers up to about 10^12.
// For larger numbers, more advanced algorithms like Pollard's rho are needed.
//
// @param n The number to factorize. Must be a positive integer.
// @return A vector of long longs containing the prime factors of n.
//
// Time complexity: O(sqrt(n))
// Space complexity: O(log n) for storing the result vector.

std::vector<long long> prime_factorize_trial_division(long long n) {
    if (n <= 1) {
        return {}; // Return an empty vector for numbers less than or equal to 1.
    }

    std::vector<long long> factorization;

    // Handle the factor of 2 separately to allow iterating by 2 later.
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }

    // Check for odd factors from 3 up to sqrt(n).
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    // If n is still greater than 1, the remaining n must be a prime factor.
    if (n > 1) {
        factorization.push_back(n);
    }

    return factorization;
}
