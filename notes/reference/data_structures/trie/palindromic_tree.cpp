// Implements a Palindromic Tree (Eertree).
// This data structure allows finding all unique palindromic substrings of a string
// as it's being built online. The entire tree for a string of length N can be
// built in O(N) time (amortized).
//
// Each node in the tree represents a unique palindrome.
// `len`: The length of the palindrome.
// `link`: The suffix link, which points to the node representing the longest
//         proper palindromic suffix of the current palindrome.
//
// The tree has two special roots:
// - Root 1 (idx 0): An imaginary palindrome of length -1.
// - Root 2 (idx 1): An empty palindrome of length 0.

#include <string>
#include <vector>
#include <vector>

template<size_t AlphabetSize = 26, char StartChar = 'a'>
class PalindromicTree {
private:
    struct Node {
        int len = 0;
        int link = 0;
        std::vector<int> next;
        // Add other properties as needed, e.g., count of occurrences.
        // int count = 0;

        Node() : next(AlphabetSize, 0) {}
    };

    std::string s;
    std::vector<Node> tree;
    int last = 0; // Index of the node for the longest palindromic suffix of the whole string
    int sz = 0;   // Current number of nodes

public:
    PalindromicTree() {
        // Initial state with two roots
        tree.resize(2);
        sz = 2;

        // Root 1: imaginary palindrome of len -1
        tree[0].len = -1;
        tree[0].link = 0;

        // Root 2: empty palindrome of len 0
        tree[1].len = 0;
        tree[1].link = 0; // Points to root 1

        last = 1; // Start with empty string suffix
    }

    // Process a new character `c` from the input string.
    void add_char(char c) {
        s += c;
        int char_idx = c - StartChar;
        int current_s_idx = s.length() - 1;

        // Find the longest palindromic suffix of the new string by traversing suffix links
        int cur = last;
        while (current_s_idx - 1 - tree[cur].len < 0 || s[current_s_idx - 1 - tree[cur].len] != c) {
            cur = tree[cur].link;
        }

        // If a palindrome `c + P + c` already exists, just update `last`
        if (tree[cur].next[char_idx] != 0) {
            last = tree[cur].next[char_idx];
            return;
        }

        // Create a new node for the new palindrome
        int new_node_idx = sz++;
        tree.emplace_back();
        tree[cur].next[char_idx] = new_node_idx;
        tree[new_node_idx].len = tree[cur].len + 2;

        last = new_node_idx;

        // If the new palindrome is a single character, its suffix link is the empty palindrome (root 2)
        if (tree[new_node_idx].len == 1) {
            tree[new_node_idx].link = 1;
            return;
        }

        // Find the suffix link for the new node by traversing suffix links again
        while (true) {
            cur = tree[cur].link;
            int potential_s_idx = current_s_idx - 1 - tree[cur].len;
            if (potential_s_idx >= 0 && s[potential_s_idx] == c) {
                tree[new_node_idx].link = tree[cur].next[char_idx];
                break;
            }
        }
    }

    // Returns the number of unique palindromic substrings found so far.
    int num_unique_palindromes() const {
        return sz - 2; // Exclude the two dummy roots
    }
};
