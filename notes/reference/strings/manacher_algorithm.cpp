//=========== Manacher's Algorithm ===========
// Description: Finds the longest palindromic substring in a string.
// It cleverly handles both even and odd length palindromes by transforming the string
// and then expanding from centers to find all palindromic substrings.
// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(N) for the transformed string and LPS array.

#include <string>
#include <vector>
#include <algorithm>

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) {
        return "";
    }

    // Transform the string to handle even length palindromes, e.g., "aba" -> "#a#b#a#"
    std::string transformed_s = "#";
    for (char c : s) {
        transformed_s += c;
        transformed_s += '#';
    }

    int n = transformed_s.length();
    std::vector<int> lps(n, 0); // lps[i] stores the radius of the palindrome centered at i

    int center = 0; // Current center of the palindrome with the rightmost reach
    int right_boundary = 0; // Right boundary of this palindrome

    for (int i = 1; i < n; i++) {
        // Find the mirror index of i with respect to the current center
        int mirror_i = 2 * center - i;

        // If i is within the right boundary of the current center's palindrome,
        // we can reuse the LPS value from its mirror.
        if (i < right_boundary) {
            lps[i] = std::min(right_boundary - i, lps[mirror_i]);
        }

        // Attempt to expand palindrome centered at i
        int a = i + (1 + lps[i]);
        int b = i - (1 + lps[i]);
        while (a < n && b >= 0 && transformed_s[a] == transformed_s[b]) {
            lps[i]++;
            a++;
            b--;
        }

        // If the palindrome centered at i expands past the current right boundary,
        // update the center and the right boundary.
        if (i + lps[i] > right_boundary) {
            center = i;
            right_boundary = i + lps[i];
        }
    }

    // Find the longest palindrome from the LPS array
    int max_len = 0;
    int center_index = 0;
    for (int i = 0; i < n; i++) {
        if (lps[i] > max_len) {
            max_len = lps[i];
            center_index = i;
        }
    }

    // Extract the longest palindromic substring from the original string
    int start = (center_index - max_len) / 2;
    return s.substr(start, max_len);
}
