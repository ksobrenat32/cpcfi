// Implements the Number Theoretic Transform (NTT) for precise polynomial multiplication using modular arithmetic.
// Time complexity: O(N log N)
// Space complexity: O(N)

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int inverse(int n) {
    return power(n, mod - 2);
}

void ntt(vector<int> & coefficients, bool invert) {
    int n = coefficients.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(coefficients[i], coefficients[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = coefficients[i+j], v = (int)(1LL * coefficients[i+j+len/2] * w % mod);
                coefficients[i+j] = u + v < mod ? u + v : u + v - mod;
                coefficients[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n);
        for (int & x : coefficients)
            x = (int)(1LL * x * n_1 % mod);
    }
}
