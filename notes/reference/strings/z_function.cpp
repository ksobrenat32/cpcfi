//=========== Z-Algorithm ===========
// Description: Computes the Z-array for a string. The Z-array z[i] is the length of the
// longest common prefix between the original string s and the suffix of s starting at i.
// This algorithm is very useful for pattern searching problems.

#include <string>
#include <vector>
#include <algorithm>

// Computes the Z-array for a given string.
// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(N) to store the Z-array.
std::vector<int> z_function(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    int left = 0, right = 0; // Represents the [left, right) interval of the rightmost Z-box

    for (int i = 1; i < n; i++) {
        // If i is inside the current Z-box, we can initialize z[i] with a value.
        if (i < right) {
            z[i] = std::min(right - i, z[i - left]);
        }
        // Naively extend the match from the current position.
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        // If we found a Z-box that extends further to the right, update the boundaries.
        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }
    return z;
}
