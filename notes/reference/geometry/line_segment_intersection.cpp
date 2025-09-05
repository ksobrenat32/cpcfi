// Description: Checks if two line segments intersect, properly handling collinear and overlapping cases.
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <algorithm>

struct Point {
    long long x, y;
};

// Computes the orientation of the ordered triplet (p, q, r).
// Returns 0 if points are collinear, 1 if clockwise, 2 if counter-clockwise.
int orientation(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counter-clockwise
}

// Given three collinear points p, q, r, this function checks if point q lies on segment 'pr'.
bool on_segment(Point p, Point q, Point r) {
    return (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
            q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
}

// Returns true if line segment 'p1q1' and 'p2q2' intersect.
bool segments_intersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and special cases.
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case: segments cross each other.
    if (o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0) {
        if (o1 != o2 && o3 != o4) {
            return true;
        }
        return false;
    }

    // Special Cases for collinear points.
    if (o1 == 0 && on_segment(p1, p2, q1)) return true;
    if (o2 == 0 && on_segment(p1, q2, q1)) return true;
    if (o3 == 0 && on_segment(p2, p1, q2)) return true;
    if (o4 == 0 && on_segment(p2, q1, q2)) return true;

    return false;
}
