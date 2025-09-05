// Description: Determines if a point is inside, outside, or on the boundary of a simple polygon using the Winding Number algorithm.
// Time Complexity: O(N) for a polygon with N vertices.
// Space Complexity: O(1).

#include <vector>
#include <algorithm>

struct Point {
    long long x, y;
};

// Enum to represent the location of the point.
enum PointLocation { INSIDE, OUTSIDE, BOUNDARY };

// Computes the orientation of the ordered triplet (p, q, r).
// Returns > 0 for counter-clockwise, < 0 for clockwise, 0 for collinear.
long long orientation(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

// Checks if point q lies on the line segment pr.
bool on_segment(Point p, Point q, Point r) {
    return (orientation(p, q, r) == 0 &&
            q.x >= std::min(p.x, r.x) && q.x <= std::max(p.x, r.x) &&
            q.y >= std::min(p.y, r.y) && q.y <= std::max(p.y, r.y));
}

// Determines the location of a query point relative to a polygon.
PointLocation point_in_polygon(const std::vector<Point>& polygon, Point query_point) {
    int n = polygon.size();
    if (n < 3) return OUTSIDE; // A polygon must have at least 3 vertices.

    int winding_number = 0;

    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        // First, check if the point is on the boundary.
        if (on_segment(p1, query_point, p2)) {
            return BOUNDARY;
        }

        // Check for crossings of the horizontal ray from the query point.
        if (p1.y <= query_point.y) {
            // An upward crossing.
            if (p2.y > query_point.y && orientation(p1, p2, query_point) > 0) {
                winding_number++;
            }
        } else { // p1.y > query_point.y
            // A downward crossing.
            if (p2.y <= query_point.y && orientation(p1, p2, query_point) < 0) {
                winding_number--;
            }
        }
    }

    // A non-zero winding number means the point is inside.
    return (winding_number != 0) ? INSIDE : OUTSIDE;
}
