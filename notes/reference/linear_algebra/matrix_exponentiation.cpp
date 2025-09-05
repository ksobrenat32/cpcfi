#include <iostream>
#include <vector>

using ll = long long;
using Matrix = std::vector<std::vector<ll>>;

// Set a default modulus, can be changed as needed.
const ll MOD = 1e9 + 7;

// Multiplies two matrices under a modulo. Assumes matrices are compatible.
Matrix multiply(const Matrix& a, const Matrix& b) {
    if (a.empty() || b.empty() || a[0].size() != b.size()) {
        // Return empty matrix for invalid multiplication
        return {};
    }
    int r1 = a.size();
    int c1 = a[0].size();
    int c2 = b[0].size();
    Matrix result(r1, std::vector<ll>(c2, 0));
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

// Calculates matrix to the power of n using binary exponentiation.
// Time: O(S^3 * log(exp)), Space: O(S^2) for a square matrix of size S.
Matrix matrix_pow(Matrix base, ll exp) {
    if (base.empty() || base.size() != base[0].size()) {
        // Return empty for non-square matrices
        return {};
    }
    int n = base.size();
    Matrix result(n, std::vector<ll>(n));
    for (int i = 0; i < n; ++i) result[i][i] = 1; // Identity matrix

    while (exp > 0) {
        if (exp % 2 == 1) result = multiply(result, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

// Example: Calculate Fibonacci numbers using matrix exponentiation.
int main() {
    ll n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // The transformation matrix for Fibonacci numbers
    Matrix T = {{1, 1}, {1, 0}};

    // (M^n)[0][1] gives the n-th Fibonacci number.
    Matrix result_matrix = matrix_pow(T, n);

    if (!result_matrix.empty()) {
        std::cout << result_matrix[0][1] << std::endl;
    }

    return 0;
}
