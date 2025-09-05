class BipartiteDSU {
    vector<int> parent;
    vector<int> size;

public:
    BipartiteDSU(int n) : parent(2*n), size(2*n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // Returns true if graph remains bipartite after adding u-v
    bool add_edge(int u, int v) {
        int u_orig = 2*u;      // Original node
        int u_mirror = 2*u+1;  // Mirror node
        int v_orig = 2*v;
        int v_mirror = 2*v+1;

        // Union u_orig <-> v_mirror and v_orig <-> u_mirror
        for(int i = 0; i < 2; i++) {
            int x = i ? v_orig : u_orig;
            int y = i ? u_mirror : v_mirror;

            int x_root = find(x);
            int y_root = find(y);
            if (x_root != y_root) {
                if (size[x_root] < size[y_root]) swap(x_root, y_root);
                parent[y_root] = x_root;
                size[x_root] += size[y_root];
            }
        }

        // Check if u is in both partitions
        return find(u_orig) != find(u_mirror);
    }
};


// -- Other implementation --

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rank[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    } else {
        if (rank[a] < rank[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (rank[a] == rank[b])
            ++rank[a];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}
