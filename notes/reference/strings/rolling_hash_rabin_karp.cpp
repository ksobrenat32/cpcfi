//=========== Rolling Hash (Rabin-Karp) ===========
// Description: A technique to compute hash values for substrings of a string efficiently.
// It precomputes prefix hashes to allow for constant-time hash calculation of any substring.
// This is particularly useful for the Rabin-Karp algorithm for pattern searching.
// Using two different hash functions (double hashing) is recommended to reduce collisions.

#include <string>
#include <vector>

struct RollingHash {
    long long prime1 = 31, mod1 = 1e9 + 7;
    long long prime2 = 37, mod2 = 1e9 + 9;

    std::vector<long long> p_pow1, p_pow2;
    std::vector<long long> inv_p_pow1, inv_p_pow2;
    std::vector<long long> prefix_hashes1, prefix_hashes2;

    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n, long long mod) {
        return power(n, mod - 2, mod);
    }

    // Precomputes powers of primes, their modular inverses, and prefix hashes.
    // Time Complexity: O(N + log(mod)) due to modular inverse calculation and precomputation loop.
    // Space Complexity: O(N).
    RollingHash(const std::string& s) {
        int n = s.length();
        p_pow1.resize(n);
        p_pow2.resize(n);
        inv_p_pow1.resize(n);
        inv_p_pow2.resize(n);
        prefix_hashes1.resize(n + 1, 0);
        prefix_hashes2.resize(n + 1, 0);

        p_pow1[0] = 1;
        p_pow2[0] = 1;
        inv_p_pow1[0] = 1;
        inv_p_pow2[0] = 1;
        long long inv_p1 = modInverse(prime1, mod1);
        long long inv_p2 = modInverse(prime2, mod2);

        for (int i = 1; i < n; i++) {
            p_pow1[i] = (p_pow1[i - 1] * prime1) % mod1;
            p_pow2[i] = (p_pow2[i - 1] * prime2) % mod2;
            inv_p_pow1[i] = (inv_p_pow1[i-1] * inv_p1) % mod1;
            inv_p_pow2[i] = (inv_p_pow2[i-1] * inv_p2) % mod2;
        }

        for (int i = 0; i < n; i++) {
            prefix_hashes1[i + 1] = (prefix_hashes1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % mod1;
            prefix_hashes2[i + 1] = (prefix_hashes2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % mod2;
        }
    }

    // Calculates the hash of the substring s[i..j].
    // Time Complexity: O(1).
    // Space Complexity: O(1).
    std::pair<long long, long long> get_hash(int i, int j) {
        long long hash1 = (prefix_hashes1[j + 1] - prefix_hashes1[i] + mod1) % mod1;
        long long hash2 = (prefix_hashes2[j + 1] - prefix_hashes2[i] + mod2) % mod2;

        hash1 = (hash1 * inv_p_pow1[i]) % mod1;
        hash2 = (hash2 * inv_p_pow2[i]) % mod2;

        return {hash1, hash2};
    }
};
