// Computes Euler's totient function phi(i) for all i from 1 to n.
// It uses a linear sieve, which is the most optimal approach.
// phi(n) counts the number of positive integers up to n that are relatively prime to n.
// Time complexity: O(n)
// Space complexity: O(n)

std::vector<int> euler_phi_sieve(int n) {
    std::vector<int> phi(n + 1);
    std::vector<int> primes;
    std::vector<int> lp(n + 1, 0); // lp[i] stores the least prime factor of i

    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            // i is a prime number
            lp[i] = i;
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int p : primes) {
            // Optimization to keep the sieve linear:
            // 1. p must be <= the smallest prime factor of i.
            // 2. The composite i*p must be within bounds.
            if (p > lp[i] || i * p > n) {
                break;
            }
            lp[i * p] = p;
            if (p == lp[i]) { // p is the smallest prime factor of i
                // The prime factors of i*p are the same as i.
                // phi(i*p) = phi(i) * p
                phi[i * p] = phi[i] * p;
                break; // Essential for linearity
            } else { // p is a new, smaller prime factor for i*p
                // Since gcd(i, p) = 1, phi is multiplicative.
                // phi(i*p) = phi(i) * phi(p) = phi(i) * (p-1)
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
    return phi;
}
