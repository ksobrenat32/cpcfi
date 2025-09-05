// Computes the square root of a floating-point number using Newton's method.
// Newton's method finds the root of f(x) = x^2 - n via the iteration x_new = (x + n/x)/2.
// The convergence is quadratic, making it extremely fast.
// Time complexity: O(log n) effectively, due to rapid convergence.
// Space complexity: O(1)
double sqrt_newton(double n) {
    if (n < 0) {
        // Return NaN for negative input, as real square root is not defined.
        return 0.0 / 0.0; // NAN
    }
    if (n == 0) {
        return 0.0;
    }

    const double epsilon = 1e-15;
    double x = (n > 1.0) ? n / 2.0 : 1.0; // Start with a reasonable guess.

    while (true) {
        double next_x = (x + n / x) / 2.0;
        // Stop when the change is smaller than our desired precision.
        if (std::abs(x - next_x) < epsilon) {
            x = next_x;
            break;
        }
        x = next_x;
    }
    return x;
}

// Computes the integer square root (i.e., floor(sqrt(n))) of a non-negative integer.
// It uses Newton's method adapted for integer arithmetic, which is very efficient.
// Time complexity: O(log n)
// Space complexity: O(1)
long long isqrt_newton(long long n) {
    if (n < 0) {
        return 0; // Or handle error appropriately.
    }
    if (n == 0) {
        return 0;
    }

    // Start with a safe initial guess.
    long long x = n;

    // The sequence of x values converges monotonically from above.
    // The loop terminates when x no longer decreases.
    while (true) {
        long long next_x = (x + n / x) / 2;
        if (next_x >= x) {
            return x;
        }
        x = next_x;
    }
}
