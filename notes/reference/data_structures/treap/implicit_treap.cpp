// Implements an Implicit Treap, a randomized binary search tree used as a dynamic array.
// The position of an element is its "implicit key" determined by in-order traversal.
// This allows for O(log N) expected time complexity for insertion, deletion,
// and access by index. It's also easily augmented to support powerful range operations.
//
// This implementation is augmented to support reversing a subarray in O(log N).

#include <memory>
#include <random>
#include <chrono>
#include <functional>
#include <algorithm> // For std::swap

template<typename T>
class ImplicitTreap {
private:
    struct Node {
        T value;
        uint32_t priority;
        int size = 1;
        bool reverse_lazy = false;
        std::unique_ptr<Node> left = nullptr;
        std::unique_ptr<Node> right = nullptr;

        Node(T val, uint32_t p) : value(val), priority(p) {}
    };

    std::unique_ptr<Node> root = nullptr;
    inline static std::mt19937 rng = std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count());

    int get_size(const std::unique_ptr<Node>& node) {
        return node ? node->size : 0;
    }

    void update_size(std::unique_ptr<Node>& node) {
        if (node) {
            node->size = 1 + get_size(node->left) + get_size(node->right);
        }
    }

    void push_lazy(std::unique_ptr<Node>& node) {
        if (node && node->reverse_lazy) {
            node->reverse_lazy = false;
            std::swap(node->left, node->right);
            if (node->left) node->left->reverse_lazy ^= true;
            if (node->right) node->right->reverse_lazy ^= true;
        }
    }

    // Splits t into l and r. l gets the first `pos` elements, r gets the rest.
    void split(std::unique_ptr<Node> t, int pos, std::unique_ptr<Node>& l, std::unique_ptr<Node>& r, int add = 0) {
        if (!t) {
            l = nullptr;
            r = nullptr;
            return;
        }
        push_lazy(t);
        int current_pos = add + get_size(t->left);
        if (pos <= current_pos) {
            split(std::move(t->left), pos, l, t->left, add);
            r = std::move(t);
            update_size(r);
        } else {
            split(std::move(t->right), pos, t->right, r, current_pos + 1);
            l = std::move(t);
            update_size(l);
        }
    }

    // Merges l and r into t.
    std::unique_ptr<Node> merge(std::unique_ptr<Node> l, std::unique_ptr<Node> r) {
        push_lazy(l);
        push_lazy(r);
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
    ImplicitTreap() = default;

    void insert(int pos, T value) {
        auto new_node = std::make_unique<Node>(value, rng());
        std::unique_ptr<Node> l, r;
        split(std::move(root), pos, l, r);
        root = merge(std::move(l), std::move(new_node));
        root = merge(std::move(root), std::move(r));
    }

    void erase(int pos) {
        std::unique_ptr<Node> l, r, m;
        split(std::move(root), pos, l, r);
        split(std::move(r), 1, m, r); // a treap of size 1 (the element to delete)
        root = merge(std::move(l), std::move(r));
    }

    // Reverses the subarray [l, r] (inclusive, 0-indexed).
    void reverse(int l, int r) {
        if (l > r) return;
        std::unique_ptr<Node> t1, t2, t3;
        split(std::move(root), r + 1, t1, t3);
        split(std::move(t1), l, t1, t2);
        if(t2) t2->reverse_lazy ^= true;
        root = merge(std::move(t1), std::move(t2));
        root = merge(std::move(root), std::move(t3));
    }

    int size() {
        return get_size(root);
    }

    // Helper to traverse and collect values, useful for debugging.
    void get_values(std::unique_ptr<Node>& t, std::vector<T>& values) {
        if (!t) return;
        push_lazy(t);
        get_values(t->left, values);
        values.push_back(t->value);
        get_values(t->right, values);
    }

    std::vector<T> to_vector() {
        std::vector<T> values;
        get_values(root, values);
        return values;
    }
};
