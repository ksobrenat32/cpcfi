// A complete implementation of the Miller-Rabin primality test.
// It is deterministic for all 64-bit unsigned integers.
//
// Dependencies: Requires a C++ compiler that supports 128-bit integers (__uint128_t), like GCC or Clang.
//
// Time complexity: O(k * log n), where k is the number of bases (12 in this case).
// Space complexity: O(1)

// Use standard types for clarity. u64 for unsigned 64-bit, u128 for unsigned 128-bit.
using u64 = unsigned long long;
using u128 = __uint128_t;

// Computes (base^exp) % mod using binary exponentiation.
// Uses 128-bit integers to prevent overflow during intermediate multiplications.
u64 power(u64 base, u64 exp, u64 mod) {
    u64 res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (u128)res * base % mod;
        base = (u128)base * base % mod;
        exp /= 2;
    }
    return res;
}

// The core check for the Miller-Rabin test.
// It returns true if `n` is found to be composite using witness `a`.
// `n - 1` is factored as `d * 2^r`.
bool check_composite(u64 n, u64 a, u64 d, int r) {
    u64 x = power(a, d, n);
    // If x is 1 or n-1, n might be prime.
    if (x == 1 || x == n - 1) {
        return false;
    }
    // Repeat r-1 times: x = x^2 mod n. If x becomes n-1, n might be prime.
    for (int s = 1; s < r; s++) {
        x = (u128)x * x % n;
        if (x == n - 1) {
            return false;
        }
    }
    // If we get here, n is definitely composite.
    return true;
}

// Miller-Rabin primality test. Returns true if `n` is prime, false otherwise.
bool is_prime_miller_rabin(u64 n) {
    if (n < 2) {
        return false;
    }

    // Factor n-1 as d * 2^r where d is odd.
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    // Use a set of bases `a` that are proven to be deterministic for all 64-bit integers.
    for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) {
            return true;
        }
        if (check_composite(n, a, d, r)) {
            return false;
        }
    }
    return true;
}
