// Computes the discrete logarithm x for base^x = target (mod modulus).
// It finds the smallest non-negative integer x that satisfies the congruence.
// The method is the Baby-step Giant-step algorithm, extended to work
// even when `base` and `modulus` are not coprime.
// Time complexity: O(sqrt(modulus))
// Space complexity: O(sqrt(modulus))

long long discrete_log(long long base, long long target, long long modulus) {
    base %= modulus;
    target %= modulus;

    long long coefficient = 1;
    long long reductions = 0;
    long long common_divisor;

    // Part 1: Reduce the problem until `base` and `modulus` are coprime.
    // The equation is transformed from base^x = target (mod modulus)
    // to `coefficient * base^(x - reductions) = target' (mod modulus')`.
    while ((common_divisor = std::gcd(base, modulus)) > 1) {
        if (target == coefficient) { // Solution found during reduction
            return reductions;
        }
        if (target % common_divisor != 0) {
            return -1; // No solution
        }
        target /= common_divisor;
        modulus /= common_divisor;
        reductions++;
        coefficient = (coefficient * (base / common_divisor)) % modulus;
    }

    // Part 2: Solve `coefficient * base^y = target (mod modulus)` using Baby-step Giant-step,
    // where y = x - reductions. This is equivalent to base^y = target * modInverse(coefficient).
    // The algorithm is adapted to solve it in the `k * a^y = b` form.
    // We seek y = p*n - q, so we check for the collision `k * (a^n)^p = b * a^q`.

    long long step_size = sqrt(modulus) + 1;

    // Calculate giant_step_multiplier = base^step_size (mod modulus)
    long long giant_step_multiplier = 1;
    for (int i = 0; i < step_size; ++i) {
        giant_step_multiplier = (giant_step_multiplier * base) % modulus;
    }

    // Baby steps: store `target * base^q` for q in [0, step_size]
    std::unordered_map<long long, long long> baby_steps;
    long long baby_step_val = target;
    for (long long q = 0; q <= step_size; ++q) {
        baby_steps[baby_step_val] = q;
        baby_step_val = (baby_step_val * base) % modulus;
    }

    // Giant steps: find a collision with a baby step.
    long long giant_step_val = coefficient;
    for (long long p = 1; p <= step_size; ++p) {
        giant_step_val = (giant_step_val * giant_step_multiplier) % modulus;
        if (baby_steps.count(giant_step_val)) {
            long long y = step_size * p - baby_steps[giant_step_val];
            return reductions + y;
        }
    }

    return -1; // No solution found
}
