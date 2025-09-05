// Range Update - Point Query (1-based indexing)
struct FenwickRUQ {
    int n;
    std::vector<int> bit;

    FenwickRUQ(int size) : n(size + 1), bit(size + 2) {}

    // Add val to range [l, r] (1-based)
    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    // Get value at position idx (1-based)
    int point_query(int idx) {
        int res = 0;
        for(; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

private:
    void add(int idx, int val) {
        for(; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }
};
