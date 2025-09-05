// Finds the maximum flow in a flow network using the Ford-Fulkerson method with Edmonds-Karp (BFS for augmenting paths).
// Time Complexity: O(V * E^2)
// Space Complexity: O(V^2)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct FordFulkerson {
    int num_nodes;
    vector<vector<long long>> capacity;
    vector<vector<int>> adj;

    FordFulkerson(int n) : num_nodes(n) {
        adj.resize(num_nodes);
        capacity.assign(num_nodes, vector<long long>(num_nodes, 0));
    }

    void add_edge(int from, int to, long long cap) {
        adj[from].push_back(to);
        adj[to].push_back(from); // For residual graph
        capacity[from][to] = cap;
    }

    long long bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2; // Mark source as visited
        queue<pair<int, long long>> q;
        q.push({source, numeric_limits<long long>::max()});

        while (!q.empty()) {
            int u = q.front().first;
            long long flow = q.front().second;
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v] > 0) {
                    parent[v] = u;
                    long long new_flow = min(flow, capacity[u][v]);
                    if (v == sink) {
                        return new_flow;
                    }
                    q.push({v, new_flow});
                }
            }
        }
        return 0;
    }

    long long max_flow(int source, int sink) {
        long long total_flow = 0;
        vector<int> parent(num_nodes);
        long long new_flow;

        while ((new_flow = bfs(source, sink, parent))) {
            total_flow += new_flow;
            int current = sink;
            while (current != source) {
                int prev = parent[current];
                capacity[prev][current] -= new_flow;
                capacity[current][prev] += new_flow; // Update residual capacity
                current = prev;
            }
        }
        return total_flow;
    }
};
