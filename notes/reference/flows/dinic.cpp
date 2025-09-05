// Finds the maximum flow from a source to a sink in a flow network using Dinic's algorithm.
// Time Complexity: O(V^2 * E) in general, but faster on special graphs.
// Space Complexity: O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct FlowEdge {
    int from, to;
    long long capacity, flow = 0;
    FlowEdge(int from, int to, long long capacity) : from(from), to(to), capacity(capacity) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int num_nodes, num_edges = 0;
    int source, sink;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int num_nodes, int source, int sink) : num_nodes(num_nodes), source(source), sink(sink) {
        adj.resize(num_nodes);
        level.resize(num_nodes);
        ptr.resize(num_nodes);
    }

    void add_edge(int from, int to, long long capacity) {
        edges.emplace_back(from, to, capacity);
        edges.emplace_back(to, from, 0); // Residual edge
        adj[from].push_back(num_edges);
        adj[to].push_back(num_edges + 1);
        num_edges += 2;
    }

    bool bfs() {
        level.assign(num_nodes, -1);
        level[source] = 0;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].capacity - edges[id].flow == 0) continue;
                if (level[edges[id].to] != -1) continue;
                level[edges[id].to] = level[u] + 1;
                q.push(edges[id].to);
            }
        }
        return level[sink] != -1;
    }

    long long dfs(int u, long long pushed) {
        if (pushed == 0) return 0;
        if (u == sink) return pushed;
        for (int& edge_idx = ptr[u]; edge_idx < (int)adj[u].size(); edge_idx++) {
            int id = adj[u][edge_idx];
            int v = edges[id].to;
            if (level[u] + 1 != level[v] || edges[id].capacity - edges[id].flow == 0) continue;
            long long pushed_flow = dfs(v, min(pushed, edges[id].capacity - edges[id].flow));
            if (pushed_flow == 0) continue;
            edges[id].flow += pushed_flow;
            edges[id ^ 1].flow -= pushed_flow;
            return pushed_flow;
        }
        return 0;
    }

    long long max_flow() {
        long long total_flow = 0;
        while (bfs()) {
            ptr.assign(num_nodes, 0);
            while (long long pushed = dfs(source, flow_inf)) {
                total_flow += pushed;
            }
        }
        return total_flow;
    }
};
