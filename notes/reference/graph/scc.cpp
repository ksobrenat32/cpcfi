// Tarjan's algorithm for finding Strongly Connected Components (SCCs) in a directed graph.
// It finds all SCCs in a single DFS pass using low-link values.
// Time complexity: O(V + E), as it's a single DFS traversal.
// Space complexity: O(V) for storing discovery times, low-link values, and the recursion stack.

#include <vector>
#include <algorithm>
#include <stack>

struct SccResult {
    int scc_count;
    std::vector<int> scc_id; // scc_id[v] = the ID of the SCC containing vertex v.
    std::vector<std::vector<int>> components; // List of SCCs, where each SCC is a list of vertices.
};

class TarjanSccFinder {
public:
    TarjanSccFinder(int num_vertices, const std::vector<std::vector<int>>& graph_adj)
        : n(num_vertices),
          adj(graph_adj),
          discovery_time(n, -1),
          low_link(n),
          on_stack(n, false),
          time(0),
          scc_count(0) {
        scc_id.resize(n);
    }

    SccResult find_sccs() {
        for (int i = 0; i < n; ++i) {
            if (discovery_time[i] == -1) {
                dfs(i);
            }
        }

        std::vector<std::vector<int>> components_list(scc_count);
        for(int i = 0; i < n; ++i) {
            components_list[scc_id[i]].push_back(i);
        }

        return {scc_count, scc_id, components_list};
    }

private:
    int n;
    const std::vector<std::vector<int>>& adj;

    std::vector<int> discovery_time;
    std::vector<int> low_link;
    std::vector<bool> on_stack;
    std::stack<int> scc_stack;

    int time;
    int scc_count;
    std::vector<int> scc_id;

    void dfs(int u) {
        discovery_time[u] = low_link[u] = time++;
        scc_stack.push(u);
        on_stack[u] = true;

        for (int v : adj[u]) {
            if (discovery_time[v] == -1) { // v has not been visited yet
                dfs(v);
                low_link[u] = std::min(low_link[u], low_link[v]);
            } else if (on_stack[v]) { // v is on the stack, so (u, v) is a back edge to an ancestor
                low_link[u] = std::min(low_link[u], discovery_time[v]);
            }
        }

        // If u is the root of an SCC (its low-link value did not change)
        if (low_link[u] == discovery_time[u]) {
            std::vector<int> current_component;
            while (true) {
                int node_in_scc = scc_stack.top();
                scc_stack.pop();
                on_stack[node_in_scc] = false;
                scc_id[node_in_scc] = scc_count;
                current_component.push_back(node_in_scc);
                if (u == node_in_scc) break;
            }
            scc_count++;
        }
    }
};
