// Solves the Min-Cost Max-Flow problem using successive shortest paths (with SPFA).
// This algorithm finds the cheapest way to send a specific amount of flow 'K'
// from a source to a sink.
// Time Complexity: O(F * V * E), where F is the desired flow amount. This is pseudo-polynomial.
// Space Complexity: O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Edge {
    int to;
    int capacity, flow;
    long long cost;
    int reverse_edge;
};

struct MinCostMaxFlow {
    int n;
    vector<vector<Edge>> adj;

    MinCostMaxFlow(int size) : n(size) {
        adj.resize(n);
    }

    void add_edge(int from, int to, int capacity, long long cost) {
        Edge forward_edge = {to, capacity, 0, cost, (int)adj[to].size()};
        Edge backward_edge = {from, 0, 0, -cost, (int)adj[from].size()};
        adj[from].push_back(forward_edge);
        adj[to].push_back(backward_edge);
    }

    // Returns {cost, flow}
    pair<long long, int> solve(int s, int t, int required_flow) {
        long long total_cost = 0;
        int total_flow = 0;

        while (total_flow < required_flow) {
            vector<long long> dist(n, INF);
            vector<int> parent_edge(n, -1);
            vector<int> parent_node(n, -1);
            vector<bool> in_queue(n, false);
            queue<int> q;

            dist[s] = 0;
            q.push(s);
            in_queue[s] = true;

            // SPFA to find the shortest path in the residual graph
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                in_queue[u] = false;

                for (size_t i = 0; i < adj[u].size(); ++i) {
                    Edge& e = adj[u][i];
                    if (e.capacity - e.flow > 0 && dist[e.to] > dist[u] + e.cost) {
                        dist[e.to] = dist[u] + e.cost;
                        parent_node[e.to] = u;
                        parent_edge[e.to] = i;
                        if (!in_queue[e.to]) {
                            q.push(e.to);
                            in_queue[e.to] = true;
                        }
                    }
                }
            }

            if (dist[t] == INF) {
                // No more augmenting paths
                break;
            }

            int push = required_flow - total_flow;
            int current = t;
            while (current != s) {
                push = min(push, adj[parent_node[current]][parent_edge[current]].capacity - adj[parent_node[current]][parent_edge[current]].flow);
                current = parent_node[current];
            }

            current = t;
            while (current != s) {
                Edge& e = adj[parent_node[current]][parent_edge[current]];
                e.flow += push;
                adj[e.to][e.reverse_edge].flow -= push;
                current = parent_node[current];
            }

            total_flow += push;
            total_cost += (long long)push * dist[t];
        }

        return {total_cost, total_flow};
    }
};
