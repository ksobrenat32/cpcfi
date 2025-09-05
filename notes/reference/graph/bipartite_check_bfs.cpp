bool bfs(int s){
    queue<int> q;
    q.push(s);
    color[s] = 1; // Assign the initial color

    while(!q.empty()){
        int u = q.front();
        q.pop();

        // Check all adjacent vertices of u
        for(auto v : adj[u]){
            // If v is not colored yet
            if(color[v] == 0){
                color[v] = (color[u] == 1) ? 2 : 1;
                q.push(v);
            }
            else if (color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}
