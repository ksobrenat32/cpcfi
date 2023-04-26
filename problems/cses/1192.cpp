// Problem link:
// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

void dfs(int i, int j, int n, int m,vector<vector<bool>> &visited,vector<string> &building){
    if(visited[i][j]){
        return;
    } else {
        visited[i][j]=true;
    }

    // Arriba
    if(i > 0){
        if(building[i-1][j] == '.'){
            dfs(i-1, j, n, m, visited, building);
        }
    }
    // Abajo
    if(i < n-1){
        if(building[i+1][j] == '.'){
            dfs(i+1, j, n, m, visited, building);
        }
    }
    // Izquierda 
    if(j > 0){
        if(building[i][j-1] == '.'){
            dfs(i, j-1, n, m, visited, building);
        }
    }
    // Derecha
    if(j < m-1){
        if(building[i][j+1] == '.'){
            dfs(i, j+1, n, m, visited, building);
        }
    }
}

inline void solve(){
    int n,m; cin >> n >> m;
    int cnt = 0;

    vector<vector<bool>> visited(n,(vector<bool> (m,false)));
    vector<string> building(n);

    FO(i,n){
        cin >> building[i];
    }

    FO(i,n){
        FO(j,m){
            if(building[i][j] == '.' && ! visited[i][j]){
                cnt++;
                dfs(i,j,n,m,visited,building);
            }
        }
    }

    cout << cnt << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
