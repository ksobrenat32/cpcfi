// Description: Computes the convex hull of a set of 2D points using Andrew's monotone chain algorithm.
// Time Complexity: O(N log N), dominated by sorting the points.
// Space Complexity: O(N), for storing the hull points.

#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    long long x, y;

    // For sorting and removing duplicates
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// Computes the cross product (a, b, c)
// Returns > 0 for a counter-clockwise turn, < 0 for a clockwise turn, and 0 for collinear points.
long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Returns the convex hull of a set of points.
std::vector<Point> convex_hull(std::vector<Point>& points) {
    int n = points.size();
    if (n <= 2) {
        return points;
    }

    // Sort points lexicographically
    std::sort(points.begin(), points.end());

    std::vector<Point> lower_hull;
    for (int i = 0; i < n; i++) {
        while (lower_hull.size() >= 2 && cross_product(lower_hull[lower_hull.size() - 2], lower_hull.back(), points[i]) <= 0) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(points[i]);
    }

    std::vector<Point> upper_hull;
    for (int i = n - 1; i >= 0; i--) {
        while (upper_hull.size() >= 2 && cross_product(upper_hull[upper_hull.size() - 2], upper_hull.back(), points[i]) <= 0) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(points[i]);
    }

    // Combine the hulls
    std::vector<Point> hull = lower_hull;
    for (size_t i = 1; i < upper_hull.size() - 1; i++) {
        hull.push_back(upper_hull[i]);
    }

    return hull;
}
