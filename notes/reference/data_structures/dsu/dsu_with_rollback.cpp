// Implements a DSU with rollback capabilities.
// This version does NOT use path compression, so `find` operations are O(log n).
// Path compression is omitted because it makes rollbacks complex. Union by size is used.
// This data structure is useful for problems requiring backtracking or checking states.
//
// Time Complexity: find O(log n), unite O(log n). Rollback is O(changes_to_revert).
// Space Complexity: O(n + total_unites) for DSU arrays and history stack.

class DSU_Rollback {
private:
    vector<int> parent;
    vector<int> sz;
    int num_components;
    // History stores pairs of (pointer_to_variable, old_value)
    vector<pair<int*, int>> history;

public:
    DSU_Rollback(int n) : parent(n), sz(n, 1), num_components(n) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find without path compression.
    int find(int i) {
        while (i != parent[i]) {
            i = parent[i];
        }
        return i;
    }

    // Unites the sets containing a and b.
    // Returns true if a merge occurred, false otherwise.
    bool unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a == root_b) {
            return false;
        }
        if (sz[root_a] < sz[root_b]) {
            swap(root_a, root_b);
        }

        // Save old values before modification.
        history.push_back({&parent[root_b], parent[root_b]});
        history.push_back({&sz[root_a], sz[root_a]});
        history.push_back({&num_components, num_components});

        parent[root_b] = root_a;
        sz[root_a] += sz[root_b];
        num_components--;
        return true;
    }

    // Returns the current number of disjoint sets.
    int components() const {
        return num_components;
    }

    // Returns a checkpoint of the current state.
    int snapshot() {
        return history.size();
    }

    // Rolls back all unite operations performed after the given checkpoint.
    void rollback(int checkpoint) {
        while (history.size() > checkpoint) {
            *history.back().first = history.back().second;
            history.pop_back();
        }
    }
};
