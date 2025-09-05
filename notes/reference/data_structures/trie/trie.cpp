// Implements a Trie (Prefix Tree).
// A Trie is a tree-like data structure that stores a dynamic set of strings,
// commonly used for efficient prefix-matching tasks like autocomplete.
//
// This version is templated on the alphabet size and a starting character,
// making it suitable for various character sets (e.g., lowercase, uppercase, digits).
// Memory is managed automatically using std::unique_ptr.
//
// Time Complexity: O(L) for insert, search, and starts_with, where L is the length of the key.
// Space Complexity: O(C * A) where C is the total number of characters in all keys
// and A is the alphabet size.

#include <string>
#include <vector>
#include <memory>

template<size_t AlphabetSize = 26, char StartChar = 'a'>
class Trie {
private:
    struct TrieNode {
        std::vector<std::unique_ptr<TrieNode>> children;
        bool is_end_of_word = false;

        TrieNode() : children(AlphabetSize, nullptr) {}
    };

    std::unique_ptr<TrieNode> root;

    // Helper to find the node corresponding to the end of a key.
    // Returns nullptr if the key's prefix is not found.
    const TrieNode* find_node(const std::string& key) const {
        const TrieNode* current = root.get();
        for (char ch : key) {
            int index = ch - StartChar;
            if (index < 0 || index >= AlphabetSize || !current->children[index]) {
                return nullptr;
            }
            current = current->children[index].get();
        }
        return current;
    }

public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string& key) {
        TrieNode* current = root.get();
        for (char ch : key) {
            int index = ch - StartChar;
             if (index < 0 || index >= AlphabetSize) {
                // Character out of supported alphabet range
                return;
            }
            if (!current->children[index]) {
                current->children[index] = std::make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        current->is_end_of_word = true;
    }

    // Returns true if the exact key exists in the trie.
    bool search(const std::string& key) const {
        const TrieNode* node = find_node(key);
        return node && node->is_end_of_word;
    }

    // Returns true if there is any key in the trie that starts with the given prefix.
    bool starts_with(const std::string& prefix) const {
        return find_node(prefix) != nullptr;
    }
};
