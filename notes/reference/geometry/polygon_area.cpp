// Description: Calculates the area of a simple polygon using the Shoelace (or Surveyor's) formula.
// The formula works by summing the cross products of adjacent vertices.
// Time Complexity: O(N) for a polygon with N vertices.
// Space Complexity: O(1).

#include <vector>
#include <cmath>

struct Point {
    long long x, y;
};

// Calculates the area of a simple polygon.
// The result is always non-negative.
double polygon_area(const std::vector<Point>& polygon) {
    int n = polygon.size();
    if (n < 3) {
        return 0.0; // A polygon must have at least 3 vertices to have an area.
    }

    long long twice_the_area = 0;

    for (int i = 0; i < n; ++i) {
        Point current_vertex = polygon[i];
        Point next_vertex = polygon[(i + 1) % n]; // Next vertex, wraps around for the last segment.

        // Add the cross product of the two vectors from the origin to the vertices.
        twice_the_area += (current_vertex.x * next_vertex.y - current_vertex.y * next_vertex.x);
    }

    // The area is half the absolute value of the sum.
    return std::abs(twice_the_area) / 2.0;
}
