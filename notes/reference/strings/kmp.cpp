//=========== Knuth-Morris-Pratt (KMP) Algorithm ===========
// Description: An efficient string searching algorithm that finds occurrences of a pattern within a text.
// It preprocesses the pattern to create a Longest Proper Prefix (LPS) array, which is then used
// to skip unnecessary comparisons, achieving linear time complexity.

// Description: Computes the Longest Proper Prefix (LPS) array for the KMP algorithm.
// The value lps[i] is the length of the longest proper prefix of pattern[0..i] which is also a suffix of pattern[0..i].
// Time Complexity: O(M), where M is the length of the pattern.
// Space Complexity: O(M) to store the LPS array.
vector<int> computeLPS(const string& pattern) {
    int pattern_len = pattern.size();
    vector<int> lps(pattern_len, 0);
    int length = 0; // Length of the previous longest prefix suffix

    int i = 1;
    while (i < pattern_len) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Description: Counts the number of occurrences of a pattern in a text using the KMP algorithm.
// Time Complexity: O(N + M), where N is the text length and M is the pattern length.
// Space Complexity: O(M) for the LPS array.
int KMPOccurrences(const string& pattern, const string& text) {
    int pattern_len = pattern.size();
    int text_len = text.size();
    vector<int> lps = computeLPS(pattern);

    int text_idx = 0;    // index for text
    int pattern_idx = 0; // index for pattern
    int count = 0;

    while (text_idx < text_len) {
        if (pattern[pattern_idx] == text[text_idx]) {
            pattern_idx++;
            text_idx++;
        }

        if (pattern_idx == pattern_len) {
            count++;
            pattern_idx = lps[pattern_idx - 1];
        } else if (text_idx < text_len && pattern[pattern_idx] != text[text_idx]) {
            if (pattern_idx != 0) {
                pattern_idx = lps[pattern_idx - 1];
            } else {
                text_idx++;
            }
        }
    }
    return count;
}
