// Description: Finds the minimum squared Euclidean distance between two points in a set using a sweep-line algorithm.
// Time Complexity: O(N log N), dominated by the initial sort.
// Space Complexity: O(N) for storing active points in a set.

#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

struct Point {
    long long x, y;
};

// Comparison function for sorting points by x-coordinate.
bool compareX(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

// Custom comparator for sorting points by y-coordinate in the active set.
struct CompareY {
    bool operator()(const Point& a, const Point& b) const {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }
};

// Calculates the squared Euclidean distance between two points.
long long squared_dist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Finds the minimum squared distance between any pair of points.
long long find_closest_pair(std::vector<Point>& points) {
    int n = points.size();
    if (n < 2) return -1; // Or throw an exception, as no pair exists.

    std::sort(points.begin(), points.end(), compareX);

    long long min_sq_dist = squared_dist(points[0], points[1]);

    std::set<Point, CompareY> active_set;
    active_set.insert(points[0]);
    active_set.insert(points[1]);

    int left_ptr = 0;
    for (int i = 2; i < n; ++i) {
        Point current_point = points[i];

        // Use a long long for the distance to avoid overflow with large coordinates.
        long long min_d = static_cast<long long>(ceil(sqrt(static_cast<double>(min_sq_dist))));

        // Remove points from the active set that are too far to the left.
        while (left_ptr < i && current_point.x - points[left_ptr].x > min_d) {
            active_set.erase(points[left_ptr]);
            left_ptr++;
        }

        // Search for candidate points in the vertical strip.
        // We only need to check points within [y - min_d, y + min_d].
        Point lower_bound = {0, current_point.y - min_d};
        Point upper_bound = {0, current_point.y + min_d};

        for (auto it = active_set.lower_bound(lower_bound); it != active_set.upper_bound(upper_bound); ++it) {
            min_sq_dist = std::min(min_sq_dist, squared_dist(current_point, *it));
        }

        active_set.insert(current_point);
    }

    return min_sq_dist;
}
