// Maintains the number of bridges in a graph that allows adding edges online.
// This implementation uses a Disjoint Set Union (DSU) data structure on top of a forest of 2-edge-connected components.
// Complexity: O(alpha(N)) amortized time per edge addition, where alpha is the inverse Ackermann function.
// Space complexity: O(N) for the DSU structures and other metadata.

#include <vector>
#include <numeric>
#include <algorithm>

class OnlineBridgeTracker {
public:
    OnlineBridgeTracker(int num_vertices) :
        n(num_vertices),
        num_bridges(0),
        lca_iteration(0),
        parent(num_vertices, -1),
        dsu_2ecc(num_vertices),
        dsu_cc(num_vertices),
        dsu_cc_size(num_vertices, 1),
        last_visit(num_vertices, 0) {

        std::iota(dsu_2ecc.begin(), dsu_2ecc.end(), 0);
        std::iota(dsu_cc.begin(), dsu_cc.end(), 0);
    }

    // Adds an edge between vertices u and v.
    void add_edge(int u, int v) {
        u = find_2ecc_root(u);
        v = find_2ecc_root(v);
        if (u == v) return; // Already in the same 2-ECC.

        int root_u = find_cc_root(u);
        int root_v = find_cc_root(v);

        if (root_u != root_v) {
            // The edge connects two previously disconnected components, creating a bridge.
            num_bridges++;
            // Union by size for the connected components tree.
            if (dsu_cc_size[root_u] > dsu_cc_size[root_v]) {
                std::swap(u, v);
                std::swap(root_u, root_v);
            }
            make_root(u);
            parent[u] = dsu_cc[u] = v;
            dsu_cc_size[root_v] += dsu_cc_size[root_u];
        } else {
            // The edge creates a cycle, potentially merging several 2-ECCs.
            merge_path(u, v);
        }
    }

    int get_num_bridges() const {
        return num_bridges;
    }

private:
    int n;
    int num_bridges;
    std::vector<int> parent;
    std::vector<int> dsu_2ecc; // DSU for vertices within the same 2-ECC.
    std::vector<int> dsu_cc;   // DSU for the tree of 2-ECCs.
    std::vector<int> dsu_cc_size;

    int lca_iteration;
    std::vector<int> last_visit;

    int find_2ecc_root(int i) {
        if (i == -1) return -1;
        return dsu_2ecc[i] == i ? i : dsu_2ecc[i] = find_2ecc_root(dsu_2ecc[i]);
    }

    int find_cc_root(int i) {
        i = find_2ecc_root(i);
        return dsu_cc[i] == i ? i : dsu_cc[i] = find_cc_root(dsu_cc[i]);
    }

    // Re-roots the tree of 2-ECCs at node u.
    void make_root(int u) {
        u = find_2ecc_root(u);
        int root = u;
        int child = -1;
        while (u != -1) {
            int p = find_2ecc_root(parent[u]);
            parent[u] = child;
            dsu_cc[u] = root;
            child = u;
            u = p;
        }
        dsu_cc_size[root] = dsu_cc_size[child];
    }

    // Merges all 2-ECCs on the path between u and v in the component tree.
    void merge_path(int u, int v) {
        lca_iteration++;
        std::vector<int> path_u, path_v;
        int lca = -1;

        while (true) {
            if (u != -1) {
                u = find_2ecc_root(u);
                path_u.push_back(u);
                if (last_visit[u] == lca_iteration) { lca = u; break; }
                last_visit[u] = lca_iteration;
                u = parent[u];
            }
            if (v != -1) {
                v = find_2ecc_root(v);
                path_v.push_back(v);
                if (last_visit[v] == lca_iteration) { lca = v; break; }
                last_visit[v] = lca_iteration;
                v = parent[v];
            }
        }

        auto collapse_path = [&](const std::vector<int>& path) {
            for (int node : path) {
                if (node == lca) break;
                dsu_2ecc[node] = lca;
                num_bridges--;
            }
        };

        collapse_path(path_u);
        collapse_path(path_v);
    }
};
