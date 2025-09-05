// Ternary search for finding the extremum of a unimodal function.
// A unimodal function is one that has exactly one peak (maximum) or
// valley (minimum) within the given interval.
//
// Dependencies: Requires <functional> for std::function.
// Time complexity: O(log((high-low)/epsilon))
// Space complexity: O(1)

// Finds the input value `x` that **maximizes** a unimodal function `f(x)`
// within a given interval [low, high].
double ternary_search_maximize(
    const std::function<double(double)>& f,
    double low,
    double high,
    double epsilon = 1e-9
) {
    while ((high - low) > epsilon) {
        // Divide the interval into three parts.
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;

        if (f(m1) < f(m2)) {
            // The maximum must be in the right two-thirds: [m1, high].
            low = m1;
        } else {
            // The maximum must be in the left two-thirds: [low, m2].
            high = m2;
        }
    }
    // Return the x-coordinate of the found maximum.
    return (low + high) / 2.0;
}

// Finds the input value `x` that **minimizes** a unimodal function `f(x)`
// within a given interval [low, high].
double ternary_search_minimize(
    const std::function<double(double)>& f,
    double low,
    double high,
    double epsilon = 1e-9
) {
    while ((high - low) > epsilon) {
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;

        if (f(m1) < f(m2)) {
            // The minimum must be in the left two-thirds: [low, m2].
            high = m2;
        } else {
            // The minimum must be in the right two-thirds: [m1, high].
            low = m1;
        }
    }
    return (low + high) / 2.0;
}
