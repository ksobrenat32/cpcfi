// Approximates the definite integral of a function `f` from `a` to `b` using Simpson's 1/3 rule.
// This method fits parabolic arcs to segments of the function for high accuracy.
//
// Dependencies: Requires <functional> for std::function and <stdexcept> for error handling.
//
// @param f The function to integrate. It should take a double and return a double.
// @param a The lower limit of integration.
// @param b The upper limit of integration.
// @param num_intervals The number of intervals to use. Must be a positive, even number.
//                      Higher values increase accuracy but also computation time.
//
// Time complexity: O(num_intervals) as it evaluates `f` at each interval point.
// Space complexity: O(1).

double integrate_simpson(const std::function<double(double)>& f, double a, double b, int num_intervals) {
    if (num_intervals <= 0 || num_intervals % 2 != 0) {
        throw std::invalid_argument("Number of intervals must be a positive, even integer.");
    }

    const double h = (b - a) / num_intervals;
    double sum = f(a) + f(b);

    for (int i = 1; i < num_intervals; ++i) {
        const double x = a + h * i;
        // Simpson's rule weights: 4 for odd-indexed points, 2 for even-indexed points.
        sum += f(x) * ((i % 2 == 1) ? 4.0 : 2.0);
    }

    return sum * h / 3.0;
}
