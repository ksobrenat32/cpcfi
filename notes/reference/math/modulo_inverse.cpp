// Computes the modular multiplicative inverse of a number 'a' under modulus 'm'.
// The method used is the Extended Euclidean Algorithm.
// This works for any modulus 'm', not just primes.
// An inverse exists if and only if a and m are coprime (i.e., gcd(a, m) = 1).
// Time complexity: O(log m)
// Space complexity: O(log m) due to recursion, or O(1) for an iterative version.

// Helper function: Extended Euclidean Algorithm.
// It finds gcd(a, b) and also the coefficients x, y such that ax + by = gcd(a, b).
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

// Main function to find modular inverse.
long long modular_inverse_extended_euclidean(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) {
        // Inverse doesn't exist.
        // Depending on the context, you might want to return -1, throw an exception, or handle it differently.
        return -1;
    }
    // The result x from extended_gcd can be negative, so we adjust it to be in [0, m-1].
    return (x % m + m) % m;
}
