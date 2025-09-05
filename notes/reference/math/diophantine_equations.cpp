// Finds the number of solutions for a linear Diophantine equation ax + by = c
// for x in [min_x, max_x] and y in [min_y, max_y].
// It relies on a function `find_any_solution(a, b, c, &x, &y, &g)` which should
// find one integer solution (x, y) and g = gcd(a, b) using the Extended Euclidean Algorithm.
// Time complexity: O(log(min(abs(a), abs(b)))) from `find_any_solution`.
// Space complexity: O(1).

// Helper to shift a solution (x, y) to another valid solution.
// All solutions are of the form x' = x + k*(b/g), y' = y - k*(a/g).
void shift_diophantine_solution(long long& x, long long& y, long long a_norm, long long b_norm, long long k) {
    x += k * b_norm;
    y -= k * a_norm;
}

long long count_diophantine_solutions_in_range(
    long long a, long long b, long long c,
    long long min_x, long long max_x,
    long long min_y, long long max_y)
{
    long long x, y, g;
    // find_any_solution is not provided here, but is required.
    // It should return false if no solution exists (i.e., c % gcd(a, b) != 0).
    if (!find_any_solution(a, b, c, x, y, g)) {
        return 0;
    }

    // Normalize a and b to step between solutions.
    a /= g;
    b /= g;

    // Start with an arbitrary solution (x, y) and find the solution range boundaries.
    // First, find the range of x values imposed by the x-constraints [min_x, max_x].

    // Shift x to be the smallest solution >= min_x.
    shift_diophantine_solution(x, y, a, b, (min_x - x) / b);
    if (x < min_x) shift_diophantine_solution(x, y, a, b, b > 0 ? 1 : -1);
    if (x > max_x) return 0;
    long long x_min_by_x_range = x;

    // Shift x to be the largest solution <= max_x.
    shift_diophantine_solution(x, y, a, b, (max_x - x) / b);
    if (x > max_x) shift_diophantine_solution(x, y, a, b, b > 0 ? -1 : 1);
    long long x_max_by_x_range = x;

    // Next, find the range of x values imposed by the y-constraints [min_y, max_y].
    // Shift y to be the smallest solution >= min_y and find the corresponding x.
    shift_diophantine_solution(x, y, a, b, -(min_y - y) / a);
    if (y < min_y) shift_diophantine_solution(x, y, a, b, a > 0 ? -1 : 1);
    if (y > max_y) return 0;
    long long x_for_min_y = x;

    // Shift y to be the largest solution <= max_y and find the corresponding x.
    shift_diophantine_solution(x, y, a, b, -(max_y - y) / a);
    if (y > max_y) shift_diophantine_solution(x, y, a, b, a > 0 ? 1 : -1);
    long long x_for_max_y = x;

    // The range of x values corresponding to the y-constraints.
    if (x_for_min_y > x_for_max_y) std::swap(x_for_min_y, x_for_max_y);
    long long x_min_by_y_range = x_for_min_y;
    long long x_max_by_y_range = x_for_max_y;

    // Intersect the two ranges for x to get the final valid range.
    long long final_min_x = std::max(x_min_by_x_range, x_min_by_y_range);
    long long final_max_x = std::min(x_max_by_x_range, x_max_by_y_range);

    if (final_min_x > final_max_x) return 0;

    // The number of solutions is the number of steps of size abs(b) in the final x range.
    return (final_max_x - final_min_x) / std::abs(b) + 1;
}
