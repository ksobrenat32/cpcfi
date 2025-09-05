struct Fenwick2DPerType {
    int rows, cols;
    unordered_map<int, Fenwick2D> trees;  // Map from type to 2D Fenwick Tree

    Fenwick2DPerType(int r, int c) : rows(r), cols(c) {}

    // Update: add 'delta' objects of type 't' at position (x, y)
    void update(int t, int x, int y, int delta) {
        if (trees.find(t) == trees.end()) {
            trees[t] = Fenwick2D(rows, cols);
        }
        trees[t].update(x, y, delta);
    }

    // Query: count of type 't' in rectangle [x1,y1] to [x2,y2]
    int query(int t, int x1, int y1, int x2, int y2) {
        if (trees.find(t) == trees.end()) return 0;
        return trees[t].range_query(x1, y1, x2, y2);
    }
};

// Requires the base Fenwick2D implementation from previous answer
struct Fenwick2D {
    vector<vector<int>> tree;
    int rows, cols;

    Fenwick2D(int r, int c) : rows(r), cols(c),
        tree(r + 1, vector<int>(c + 1)) {}

    void update(int x, int y, int delta) { /* same as before */ }

    int query(int x, int y) { /* same as before */ }

    int range_query(int x1, int y1, int x2, int y2) { /* same as before */ }

    int lsb(int i) { return i & -i; }
};
