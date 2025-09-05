//=========== Suffix Array and LCP Array ===========
// This file contains an implementation for building a Suffix Array and a Longest Common Prefix (LCP) Array.

#include <vector>
#include <string>
#include <algorithm>

struct Suffix {
    int index;
    int rank[2];
};

int compareSuffixes(const Suffix& a, const Suffix& b) {
    if (a.rank[0] != b.rank[0]) {
        return a.rank[0] < b.rank[0];
    }
    return a.rank[1] < b.rank[1];
}

// Description: Builds a suffix array for a given string.
// A suffix array is a sorted array of all suffixes of a string.
// This implementation uses a radix sort-based approach.
// Time Complexity: O(N * log^2(N)) due to the sorting loop.
// Space Complexity: O(N) for storing suffixes and ranks.
std::vector<int> buildSuffixArray(const std::string& text) {
    int n = text.length();
    std::vector<Suffix> suffixes(n);

    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = text[i] - 'a';
        suffixes[i].rank[1] = (i + 1 < n) ? (text[i + 1] - 'a') : -1;
    }

    std::sort(suffixes.begin(), suffixes.end(), compareSuffixes);

    std::vector<int> index_map(n);
    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        index_map[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            index_map[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int next_index = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (next_index < n) ? suffixes[index_map[next_index]].rank[0] : -1;
        }

        std::sort(suffixes.begin(), suffixes.end(), compareSuffixes);
    }

    std::vector<int> suffix_array(n);
    for (int i = 0; i < n; i++) {
        suffix_array[i] = suffixes[i].index;
    }
    return suffix_array;
}

// Description: Computes the Longest Common Prefix (LCP) array using Kasai's algorithm.
// The LCP array stores the length of the longest common prefix between adjacent suffixes in the sorted suffix array.
// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(N) for the LCP and inverse suffix arrays.
std::vector<int> kasai(const std::string& text, const std::vector<int>& suffix_array) {
    int n = text.length();
    std::vector<int> lcp(n, 0);
    std::vector<int> inverse_suffix_array(n, 0);

    for (int i = 0; i < n; i++) {
        inverse_suffix_array[suffix_array[i]] = i;
    }

    int lcp_length = 0;
    for (int i = 0; i < n; i++) {
        if (inverse_suffix_array[i] == n - 1) {
            lcp_length = 0;
            continue;
        }

        int j = suffix_array[inverse_suffix_array[i] + 1];
        while (i + lcp_length < n && j + lcp_length < n && text[i + lcp_length] == text[j + lcp_length]) {
            lcp_length++;
        }

        lcp[inverse_suffix_array[i]] = lcp_length;
        if (lcp_length > 0) {
            lcp_length--;
        }
    }
    return lcp;
}
