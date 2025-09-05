// Description: Determines if a point is to the left, right, or on a directed line segment.
// Time Complexity: O(1)
// Space Complexity: O(1)

struct Point {
    long long x, y;
};

// Enum to represent the location of the point.
enum Location { LEFT, RIGHT, ON_LINE };

// Determines the location of point p3 relative to the directed line from p1 to p2.
Location point_location_test(Point p1, Point p2, Point p3) {
    // This is equivalent to the 2D cross product of vectors (p2-p1) and (p3-p1).
    long long cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

    if (cross_product > 0) {
        return LEFT;
    } else if (cross_product < 0) {
        return RIGHT;
    } else {
        return ON_LINE;
    }
}
