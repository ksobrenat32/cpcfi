// Implements a Persistent Segment Tree using path copying.
// This data structure allows for efficient updates and queries on historical
// versions of an array. Each update creates a new version of the array
// without modifying the old one.
//
// This is achieved by rebuilding only the nodes on the path to the updated
// element (path copying). All other nodes are shared with the previous version.
//
// Time Complexity: O(log N) for update and query. O(N) for initial build.
// Space Complexity: O(N + M * log N) where N is the array size and M is the number of updates.

#include <vector>
#include <memory>   // For std::shared_ptr
#include <stdexcept> // For std::out_of_range

template<typename T>
class PersistentSegmentTree {
private:
    struct Node {
        T value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(T val) : value(val), left(nullptr), right(nullptr) {}
        Node(std::shared_ptr<Node> l, std::shared_ptr<Node> r) : value(), left(l), right(r) {}
    };

    int array_size;
    std::vector<std::shared_ptr<Node>> roots;

    std::shared_ptr<Node> build(const std::vector<T>& arr, int l, int r) {
        if (l == r) {
            return std::make_shared<Node>(arr[l]);
        }
        int mid = l + (r - l) / 2;
        return std::make_shared<Node>(build(arr, l, mid), build(arr, mid + 1, r));
    }

    T query_recursive(std::shared_ptr<Node> node, int pos, int l, int r) {
        if (l == r) {
            return node->value;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            return query_recursive(node->left, pos, l, mid);
        } else {
            return query_recursive(node->right, pos, mid + 1, r);
        }
    }

    std::shared_ptr<Node> update_recursive(std::shared_ptr<Node> node, int pos, T val, int l, int r) {
        if (l == r) {
            return std::make_shared<Node>(val);
        }
        int mid = l + (r - l) / 2;
        std::shared_ptr<Node> new_left = node->left;
        std::shared_ptr<Node> new_right = node->right;
        if (pos <= mid) {
            new_left = update_recursive(node->left, pos, val, l, mid);
        } else {
            new_right = update_recursive(node->right, pos, val, mid + 1, r);
        }
        return std::make_shared<Node>(new_left, new_right);
    }

public:
    // Builds the persistent structure from an initial array.
    // The initial state will be version 0.
    PersistentSegmentTree(const std::vector<T>& arr) : array_size(arr.size()) {
        if (array_size > 0) {
            roots.push_back(build(arr, 0, array_size - 1));
        }
    }

    // Get value at index 'pos' in a specific 'version' of the array.
    T query(int version, int pos) {
        if (version < 0 || version >= roots.size() || pos < 0 || pos >= array_size) {
            throw std::out_of_range("Version or position is out of range.");
        }
        return query_recursive(roots[version], pos, 0, array_size - 1);
    }

    // Update index 'pos' with value 'val', based on a 'version'.
    // Returns the ID of the new version created.
    int update(int version, int pos, T val) {
        if (version < 0 || version >= roots.size() || pos < 0 || pos >= array_size) {
            throw std::out_of_range("Version or position is out of range.");
        }
        roots.push_back(update_recursive(roots[version], pos, val, 0, array_size - 1));
        return roots.size() - 1;
    }

    // Returns the ID of the most recent version.
    int latest_version() const {
        return roots.empty() ? -1 : roots.size() - 1;
    }
};
