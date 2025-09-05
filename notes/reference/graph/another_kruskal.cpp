struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

int kruskal(int n, vector<Edge> &edges, DisjointSets &dsu, vector<Edge> &ans) {
    int cost = 0;
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (ans.size() == n - 1) break;
        if(dsu.unite(e.u, e.v)){
            cost += e.w;
            ans.push_back(e);
        }
    }

    if(ans.size()!=n-1) return -1;
    return cost;
}
