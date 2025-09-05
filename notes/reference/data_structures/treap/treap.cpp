// Implements a Treap, a randomized binary search tree.
// This provides the functionality of an ordered set/map with O(log N) expected
// time complexity for insertions, deletions, and lookups.
//
// A Treap is a BST that maintains the heap property for randomly assigned priorities,
// which keeps the tree balanced with high probability.
//
// This implementation includes an order statistics augmentation to find the k-th element.

#include <memory>
#include <random>
#include <chrono>
#include <functional>

template<typename T, class Compare = std::less<T>>
class Treap {
private:
    struct Node {
        T key;
        uint32_t priority;
        int size = 1;
        std::unique_ptr<Node> left = nullptr;
        std::unique_ptr<Node> right = nullptr;

        Node(T k, uint32_t p) : key(k), priority(p) {}
    };

    std::unique_ptr<Node> root = nullptr;
    Compare comp;
    inline static std::mt19937 rng = std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count());

    int get_size(const std::unique_ptr<Node>& node) {
        return node ? node->size : 0;
    }

    void update_size(std::unique_ptr<Node>& node) {
        if (node) {
            node->size = 1 + get_size(node->left) + get_size(node->right);
        }
    }

    // Splits t into l and r such that keys in l are < key, and keys in r are >= key.
    void split(std::unique_ptr<Node> t, T key, std::unique_ptr<Node>& l, std::unique_ptr<Node>& r) {
        if (!t) {
            l = nullptr;
            r = nullptr;
            return;
        }
        if (comp(t->key, key)) {
            split(std::move(t->right), key, t->right, r);
            l = std::move(t);
            update_size(l);
        } else {
            split(std::move(t->left), key, l, t->left);
            r = std::move(t);
            update_size(r);
        }
    }

    // Merges l and r into t. Assumes all keys in l are less than all keys in r.
    std::unique_ptr<Node> merge(std::unique_ptr<Node> l, std::unique_ptr<Node> r) {
        if (!l) return r;
        if (!r) return l;

        if (l->priority > r->priority) {
            l->right = merge(std::move(l->right), std::move(r));
            update_size(l);
            return l;
        } else {
            r->left = merge(std::move(l), std::move(r->left));
            update_size(r);
            return r;
        }
    }

public:
    Treap(Compare c = Compare()) : comp(c) {}

    bool contains(T key) {
        Node* current = root.get();
        while (current) {
            if (comp(key, current->key)) {
                current = current->left.get();
            } else if (comp(current->key, key)) {
                current = current->right.get();
            } else {
                return true;
            }
        }
        return false;
    }

    void insert(T key) {
        if (contains(key)) return;

        std::unique_ptr<Node> l, r;
        split(std::move(root), key, l, r);
        auto new_node = std::make_unique<Node>(key, rng());
        root = merge(std::move(l), std::move(new_node));
        root = merge(std::move(root), std::move(r));
    }

    // Recursive helper for erase
    std::unique_ptr<Node> erase_recursive(std::unique_ptr<Node> t, T key) {
        if (!t) return nullptr;

        if (comp(key, t->key)) {
            t->left = erase_recursive(std::move(t->left), key);
        } else if (comp(t->key, key)) {
            t->right = erase_recursive(std::move(t->right), key);
        } else {
            // Found the node, merge its children to effectively delete it.
            return merge(std::move(t->left), std::move(t->right));
        }

        update_size(t);
        return t;
    }

    void erase(T key) {
        root = erase_recursive(std::move(root), key);
    }

    // Finds the k-th smallest element (0-indexed).
    // Returns a pointer to the key, or nullptr if k is out of bounds.
    const T* find_by_order(int k) {
        Node* current = root.get();
        while(current) {
            int left_size = get_size(current->left);
            if (k == left_size) {
                return &current->key;
            }
            if (k < left_size) {
                current = current->left.get();
            } else {
                k -= (left_size + 1);
                current = current->right.get();
            }
        }
        return nullptr;
    }

    int size() {
        return get_size(root);
    }
};
