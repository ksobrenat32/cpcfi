## Graphs algorithms

### Breadth First Search (BFS)

Use this to find the shortest path to a node.

```c++
// s = start node, adj = adjacency list, visited = vector of visited nodes, n = number of nodes
void bfs(int s, vector<vector<int>> &adj, vector<bool> &visited, int n){
    queue<int> q;
    q.push(s);
    visited[q.front()]=true;

    while(! q.empty()){
        cout << q.front() << endl;
        for(size_t i = 0; i < adj[q.front()].size(); i++){
            if(!visited[adj[q.front()][i]]){
                q.push(adj[q.front()][i]);
                visited[adj[q.front()][i]]=true;
            }
        }
        q.pop();
    }
}
```

### DFS

Use this to find all the nodes connected to a node.

```c++
// s = start node, adj = adjacency list, visited = vector of visited nodes
void dfs(int s, vector<vector<int>> &adj, vector<bool> &visited){
    if(visited[s]){
        return;
    }
    cout << s << endl;
    visited[s]=true;
    for(size_t i = 0; i < adj[s].size(); i++){
        dfs(adj[s][i]);
    }
}
```

### Connections

Print connected nodes

```c++
// s = start node, adj = adjacency list, visited = vector of visited nodes
void conex(int s, vector<vector<int>> &adj, vector<bool> &visited){
    for(size_t i = 0; i < adj.size(); i++){
        if(!visited[i]){
            bfs(i);
        }
        cout << endl;
    }
}
```
