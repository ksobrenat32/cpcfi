// Computes modular inverse of a number using Fermat's Little Theorem.
// This method is only valid when the modulus is a prime number.
// It relies on a modular exponentiation function 'power(base, exp, mod)'.
// Time complexity: O(log mod)
// Space complexity: O(1)

long long modular_inverse_fermat(long long num, long long prime_mod) {
    return power(num, prime_mod - 2, prime_mod);
}
