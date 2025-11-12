/*
Problem: Given an m×nm×n grid where each cell can have one of three values:

    0: An empty cell
    1: A cell containing a fresh orange
    2: A cell containing a rotten orange

Any fresh orange 4-directionally adjacent to a rotten orange will become rotten at each minute.

Determine the minimum time required for all fresh oranges to rot. If all oranges can’t rot, return -1.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    // Read all
    vector<vector<int>> v(n, vector<int> (m));
    int fresh = 0;

    // Store th rotten oranges in a queue for bfs
    queue<array<int, 3>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
            // If rotten
            if(v[i][j] == 2){
                q.push({i,j,0});
            } else if (v[i][j] == 1){
                fresh++;
            }
        }
    }

    vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int max_time = 0;
    
    // Implement bfs for each rotten oranges
    // tmp variable for comprehension
    array<int, 3> t;
    int x, y;
    while(! q.empty()){
        // Get the rotten orange
        t = q.front();
        q.pop();        
        
        // Update max rotting time
        max_time = max(t[2], max_time);

        // the rotten orange, rot the nearby if not already rotten
        for(auto &d : dir){
            x = t[0] + d.first;
            y = t[1] + d.second;

            // If valid position
            if(x >= 0 && x < n && y >= 0 && y < m){
                // If it is fresh, rot
                if(v[x][y] == 1){
                    v[x][y] = 2;
                    fresh--;
                    // Add the new rotten to the queue with updated time
                    q.push({x,y,t[2]+1});                
                }
            }
        }
    }

    if(fresh > 0){
        cout << -1 << endl;
    } else {
        cout << max_time << endl;
    }

    return 0;
}