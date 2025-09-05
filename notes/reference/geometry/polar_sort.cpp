// Description: Sorts a set of 2D points by their polar angle around the origin or a custom center.
// This is achieved efficiently without trigonometry by partitioning points into half-planes and using the cross product.
// Time Complexity: O(N log N) for sorting N points.
// Space Complexity: O(1) for the in-place sort.

#include <vector>
#include <complex>
#include <algorithm>
#include <tuple>

typedef double T;
typedef std::complex<T> Point;
#define x real()
#define y imag()

// Calculates the 2D cross product of vectors v and w.
T cross_product(Point v, Point w) { return v.x * w.y - v.y * w.x; }

// Calculates the squared magnitude (distance from origin).
T squared_magnitude(Point a) { return a.x * a.x + a.y * a.y; }

// Helper function to determine if a point is in the upper half-plane (y > 0)
// or on the negative x-axis. This partitions the plane for sorting.
bool is_in_upper_half(Point p) {
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

// Sorts points by polar angle around the origin.
void polar_sort(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), [](Point v, Point w) {
        // The tuple comparison sorts first by half-plane, then by angle (using cross product).
        return std::make_tuple(is_in_upper_half(v), 0) <
               std::make_tuple(is_in_upper_half(w), cross_product(v, w));
    });
}

// Sorts points by polar angle, then by distance from the origin for collinear points.
void polar_sort_by_distance(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), [](Point v, Point w) {
        // The tuple comparison sorts by half-plane, then angle, then distance.
        return std::make_tuple(is_in_upper_half(v), 0, squared_magnitude(v)) <
               std::make_tuple(is_in_upper_half(w), cross_product(v, w), squared_magnitude(w));
    });
}

// Sorts points by polar angle around a specified center point.
void polar_sort_around_center(std::vector<Point>& points, Point center) {
    std::sort(points.begin(), points.end(), [&](Point v, Point w) {
        Point v_rel = v - center;
        Point w_rel = w - center;
        return std::make_tuple(is_in_upper_half(v_rel), 0) <
               std::make_tuple(is_in_upper_half(w_rel), cross_product(v_rel, w_rel));
    });
}
