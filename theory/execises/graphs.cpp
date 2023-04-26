// Graphs exercise

#include <bits/stdc++.h>
using namespace std;

int n = 6;
vector<bool> visited(n,false);
vector<vector<int>> adj(n); // adjacency

void bfs(int s){
    queue<int> q;
    q.push(s);

    while(! q.empty()){
        cout << q.front() << endl;
        visited[q.front()]=true;
        for(size_t i = 0; i < adj[q.front()].size(); i++){
            if(!visited[adj[q.front()][i]]){
                q.push(adj[q.front()][i]);
            }
        }
        q.pop();
    }
}

void dfs(int s){
    if(visited[s]){
        return;
    }
    cout << s << endl;
    visited[s]=true;
    for(size_t i = 0; i < adj[s].size(); i++){
        dfs(adj[s][i]);
    }
}

void conex(){
    for(size_t i = 0; i < adj.size(); i++){
        if(!visited[i]){
            bfs(i);            
        }
        cout << endl;
    }
}

int main(){
    /*
    // BFS y DFS
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);
    adj[0].push_back(4);
    
    //cout << "BFS" << endl;
    //bfs(0);
    //cout << "DFS" << endl;
    //dfs(0);
    */

    // Nodos conexos
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[4].push_back(5);
    adj[5].push_back(4);
    cout << "conexos" << endl;
    conex();

    return 0;
}