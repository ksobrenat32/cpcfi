int n;
vector<vector<int>> adj(MAX);
vector<int> in_degree(MAX);
vector<int> group_ids(MAX);
vector<int> ans;

//topological sort implementation: https://cp-algorithms.com/graph/topological-sort.html

void topological_sort() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 1; i <= n; i++) {
        if(in_degree[i] == 0) {
            pq.emplace(group_ids[i], i);
        }
    }

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        ans.push_back(u);

        for(int v : adj[u]) {
            in_degree[v]--;
            if(in_degree[v] == 0) {
                pq.emplace(group_ids[v], v);
            }
        }
    }

}
