struct Fenwick2D {
    vector<vector<int>> tree;
    int rows, cols;

    Fenwick2D(int r, int c) : rows(r), cols(c),
        tree(r + 1, vector<int>(c + 1)) {}

    // Update: add delta to (x, y) (1-based)
    void update(int x, int y, int delta) {
        for(int i = x; i <= rows; i += lsb(i))
            for(int j = y; j <= cols; j += lsb(j))
                tree[i][j] += delta;
    }

    // Query sum from (1,1) to (x,y)
    int query(int x, int y) {
        int sum = 0;
        for(int i = x; i > 0; i -= lsb(i))
            for(int j = y; j > 0; j -= lsb(j))
                sum += tree[i][j];
        return sum;
    }

    // Range sum from (x1,y1) to (x2,y2)
    int range_query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1-1, y2)
             - query(x2, y1-1) + query(x1-1, y1-1);
    }

    int lsb(int i) { return i & -i; }
};
