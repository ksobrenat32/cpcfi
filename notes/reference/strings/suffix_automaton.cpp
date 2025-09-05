//=========== Suffix Automaton ===========
// Description: A powerful data structure representing all substrings of a string in a minimal DAWG (Directed Acyclic Word Graph).
// It can be built in linear time and used to solve many string problems efficiently.

#include <string>
#include <vector>
#include <map>
#include <iostream>

struct SuffixAutomaton {
    struct State {
        int len, link;
        std::map<char, int> next;
    };

    std::vector<State> states;
    int size;
    int last;

    SuffixAutomaton(int max_len) {
        states.resize(max_len * 2);
        size = 0;
        last = 0;
    }

    // Initializes the automaton.
    // Time Complexity: O(1).
    void init() {
        states[0].len = 0;
        states[0].link = -1;
        size = 1;
        last = 0;
    }

    // Extends the automaton with a new character.
    // Time Complexity: O(log(alphabet_size)) amortized due to map usage. O(1) amortized with array-based transitions.
    // Space Complexity: O(1) amortized.
    void extend(char c) {
        int current = size++;
        states[current].len = states[last].len + 1;
        int p = last;
        while (p != -1 && states[p].next.find(c) == states[p].next.end()) {
            states[p].next[c] = current;
            p = states[p].link;
        }
        if (p == -1) {
            states[current].link = 0;
        } else {
            int q = states[p].next[c];
            if (states[p].len + 1 == states[q].len) {
                states[current].link = q;
            } else {
                int clone = size++;
                states[clone].len = states[p].len + 1;
                states[clone].next = states[q].next;
                states[clone].link = states[q].link;
                while (p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone;
                    p = states[p].link;
                }
                states[q].link = states[current].link = clone;
            }
        }
        last = current;
    }

    // --- Example Applications ---

    // Description: Calculates the number of distinct substrings in the original string.
    // Time Complexity: O(N), where N is the number of states.
    long long count_distinct_substrings() {
        long long total = 0;
        for (int i = 1; i < size; i++) {
            total += states[i].len - states[states[i].link].len;
        }
        return total;
    }

    // Description: Finds the longest common substring between string S and string T.
    // The automaton must be built on S first.
    // Time Complexity: O(|T|) after building the automaton on S in O(|S|).
    std::string longest_common_substring(const std::string& t) {
        int v = 0, l = 0, best_len = 0, best_pos = 0;
        for (int i = 0; i < t.length(); i++) {
            while (v != 0 && states[v].next.find(t[i]) == states[v].next.end()) {
                v = states[v].link;
                l = states[v].len;
            }
            if (states[v].next.count(t[i])) {
                v = states[v].next[t[i]];
                l++;
            }
            if (l > best_len) {
                best_len = l;
                best_pos = i;
            }
        }
        return t.substr(best_pos - best_len + 1, best_len);
    }
};

// Example usage:
void build_from_string(SuffixAutomaton& sa, const std::string& s) {
    sa.init();
    for (char c : s) {
        sa.extend(c);
    }
}
