// Computes base^exp using binary exponentiation (exponentiation by squaring).
// Time complexity: O(log exp)
// Space complexity: O(1)

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}
