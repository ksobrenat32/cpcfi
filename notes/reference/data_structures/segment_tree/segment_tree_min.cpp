ll  t[4*MAX];

// Shout-out to CP algo for the SegTree implementation: https://cp-algorithms.com/data_structures/segment_tree.html#memory-efficient-implementation

void buildSegTree(vector<ll> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildSegTree(a, v*2, tl, tm);
        buildSegTree(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]); // Change to minimum
    }
}


ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return LLONG_MAX; // Return maximum possible value for empty range
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]); // Change to minimum
    }
}
