// 2-Satisfiability (2-SAT) solver using Kosaraju's algorithm for Strongly Connected Components.
// Time complexity: O(V + E) where V is the number of variables and E is the number of clauses.
// Space complexity: O(V + E).

struct TwoSatSolver {
    int num_variables;
    int num_vertices;
    vector<vector<int>> implication_graph;
    vector<vector<int>> implication_graph_transpose;
    vector<bool> visited;
    vector<int> topological_order;
    vector<int> scc;
    vector<bool> assignment;

    TwoSatSolver(int n_vars) :
        num_variables(n_vars),
        num_vertices(2 * n_vars),
        implication_graph(num_vertices),
        implication_graph_transpose(num_vertices),
        visited(num_vertices),
        scc(num_vertices, -1),
        assignment(n_vars) {
        topological_order.reserve(num_vertices);
    }

    void find_topological_order(int u) {
        visited[u] = true;
        for (int v : implication_graph[u]) {
            if (!visited[v])
                find_topological_order(v);
        }
        topological_order.push_back(u);
    }

    void find_scc(int u, int current_scc_id) {
        scc[u] = current_scc_id;
        for (int v : implication_graph_transpose[u]) {
            if (scc[v] == -1)
                find_scc(v, current_scc_id);
        }
    }

    bool is_satisfiable() {
        topological_order.clear();
        visited.assign(num_vertices, false);
        for (int i = 0; i < num_vertices; ++i) {
            if (!visited[i])
                find_topological_order(i);
        }

        scc.assign(num_vertices, -1);
        int scc_count = 0;
        for (int i = 0; i < num_vertices; ++i) {
            int u = topological_order[num_vertices - 1 - i];
            if (scc[u] == -1)
                find_scc(u, scc_count++);
        }

        assignment.assign(num_variables, false);
        for (int i = 0; i < num_vertices; i += 2) {
            if (scc[i] == scc[i + 1])
                return false; // A variable and its negation are in the same SCC.
            assignment[i / 2] = scc[i] > scc[i + 1];
        }
        return true;
    }

    // Adds a disjunction (clause) of the form (variable_a OR variable_b).
    // is_negated_a and is_negated_b are true if the variables are negated.
    void add_disjunction(int var_a, bool is_negated_a, int var_b, bool is_negated_b) {
        // A disjunction (a OR b) is equivalent to (NOT a => b) AND (NOT b => a).
        // Variable i is mapped to vertex 2*i, and its negation to 2*i+1.
        int u = 2 * var_a + (is_negated_a ? 1 : 0);
        int v = 2 * var_b + (is_negated_b ? 1 : 0);
        int neg_u = u ^ 1;
        int neg_v = v ^ 1;
        implication_graph[neg_u].push_back(v);
        implication_graph[neg_v].push_back(u);
        implication_graph_transpose[v].push_back(neg_u);
        implication_graph_transpose[u].push_back(neg_v);
    }
};
