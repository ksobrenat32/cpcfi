// Solves offline dynamic connectivity problems using a segment tree and DSU with rollbacks.
// This allows processing edge additions and removals over a period of time and querying
// the number of connected components at each time step.
//
// The approach requires all queries to be known beforehand (offline).
// 1. Edge Lifetimes: Each edge's presence in the graph is converted into one or more
//    time intervals [start, end].
// 2. Segment Tree: A segment tree is built over the total time span. An edge active
//    during [start, end] is added to the segment tree nodes covering this interval.
// 3. DFS Traversal: A DFS on the segment tree applies edge unions upon entering a node's
//    time range and rolls them back upon exiting, using a DSU with rollback.
//
// This file requires the DSU_Rollback class from 'dsu_with_rollback.cpp'.

struct Edge {
    int u, v;
};

class DynamicConnectivity {
private:
    // The segment tree, storing edges active in each time-based node.
    vector<vector<Edge>> segment_tree;
    // DSU that supports undoing unite operations.
    DSU_Rollback dsu;
    // The total number of time steps to be queried.
    int time_span;
    // The number of nodes in the graph.
    int num_nodes;

    // Recursively adds an edge to the segment tree nodes covering its lifetime.
    void add_edge_to_tree(const Edge& edge, int start, int end, int v_idx, int l, int r) {
        if (start > end) return;
        if (l == start && r == end) {
            segment_tree[v_idx].push_back(edge);
            return;
        }
        int mid = l + (r - l) / 2;
        add_edge_to_tree(edge, start, min(end, mid), 2 * v_idx, l, mid);
        add_edge_to_tree(edge, max(start, mid + 1), end, 2 * v_idx + 1, mid + 1, r);
    }

    // Performs a DFS on the segment tree to compute the answers.
    void dfs(int v_idx, int l, int r, vector<int>& answers) {
        // Apply the unions for all edges in the current time segment.
        int checkpoint = dsu.snapshot();
        for (const auto& edge : segment_tree[v_idx]) {
            dsu.unite(edge.u, edge.v);
        }

        if (l == r) {
            // We are at a leaf, representing a single point in time.
            // Record the number of connected components.
            answers[l] = dsu.components();
        } else {
            // Recurse to children.
            int mid = l + (r - l) / 2;
            dfs(2 * v_idx, l, mid, answers);
            dfs(2 * v_idx + 1, mid + 1, r, answers);
        }

        // Backtrack: undo the unions applied at this node.
        dsu.rollback(checkpoint);
    }

public:
    DynamicConnectivity(int n, int t) : num_nodes(n), time_span(t), dsu(n) {
        segment_tree.resize(4 * t);
    }

    // Adds an edge that is active during the time interval [start_time, end_time].
    void add_edge(int u, int v, int start_time, int end_time) {
        add_edge_to_tree({u, v}, start_time, end_time, 1, 0, time_span - 1);
    }

    // Solves the problem and returns a vector where ans[t] is the number of
    // connected components at time t.
    vector<int> solve() {
        vector<int> answers(time_span);
        dfs(1, 0, time_span - 1, answers);
        return answers;
    }
};
