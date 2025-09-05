struct Edge { int u, v, weight; };

int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(),
        [](Edge& a, Edge& b) { return a.weight < b.weight; });

    DisjointSets dsu(n);
    int total_weight = 0;

    for (Edge& e : edges) {
        if (!dsu.connected(e.u, e.v)) {
            dsu.unite(e.u, e.v);
            total_weight += e.weight;
        }
    }
    return total_weight;
}
