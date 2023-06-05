// Problem link:
// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

void isB(vector<string> &building, vector<vector<char>> &steps,int i,int j){
    // Draw what was done
    /*
    for(size_t n = 0; n < steps.size();n++){
        for(size_t m = 0; m < steps[n].size();m++){
            if(steps[n][m] == '\0'){
                cout << ' ';
            } else {
                cout << steps[n][m];
            }
        }
        cout << endl;
    }
    */

    string res;
    cout << "YES" << endl;

    while(building[i][j] != 'A'){
        switch(steps[i][j]){
            case 'U':
                res += 'U';
                i += 1;
                break;
            case 'D':
                res += 'D';
                i -= 1;
                break;
            case 'R':
                res += 'R';
                j -= 1;
                break;
            case 'L':
                res += 'L';
                j += 1;
                break;
            default:
                return;
        }
    }

    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    cout << res << endl;
}

inline void solve(){
    int n,m; cin >> n >> m;

    // Visited
    vector<vector<bool>> visited(n,(vector<bool> (m,false)));
    // Steps taken
    vector<vector<char>> steps(n,(vector<char> (m)));
    // Save building
    vector<string> building(n);
    // Temporal pair
    pair<int, int> p;

    // Read building
    FO(i,n){
        cin >> building[i];
    }

    FO(i,n){
        FO(j,m){
            // Get to the start
            if(building[i][j] == 'A'){
                // BFS queue
                queue<pair<int,int>> q;

                // BFS
                p.first = i;
                p.second = j;
                // Push start place and mark as visited
                q.push(p);
                visited[p.first][p.second] = true;

                while(! q.empty() ){
                    i = q.front().first;
                    j = q.front().second;

                    // Arriba
                    if(i > 0){
                        if(building[i-1][j] == '.' && !visited[i-1][j]){
                            p.first = i-1;
                            p.second = j;
                            q.push(p);
                            visited[p.first][p.second] = true;
                            steps[p.first][p.second] = 'U';
                        } else if(building[i-1][j] == 'B'){
                            p.first = i-1;
                            p.second = j;
                            steps[p.first][p.second] = 'U';
                            isB(building,steps,i-1,j);
                            return;
                        }
                    }
                    // Abajo
                    if(i < n-1){
                        if(building[i+1][j] == '.' && !visited[i+1][j]){
                            p.first = i+1;
                            p.second = j;
                            q.push(p);
                            visited[p.first][p.second] = true;
                            steps[p.first][p.second] = 'D';
                        } else if(building[i+1][j] == 'B'){
                            p.first = i+1;
                            p.second = j;
                            steps[p.first][p.second] = 'D';
                            isB(building,steps,i+1,j);
                            return;
                        }
                    }
                    // Izquierda 
                    if(j > 0){
                        if(building[i][j-1] == '.' && !visited[i][j-1]){
                            p.first = i;
                            p.second = j-1;
                            q.push(p);
                            visited[p.first][p.second] = true;
                            steps[p.first][p.second] = 'L';
                        } else if(building[i][j-1] == 'B'){
                            p.first = i;
                            p.second = j-1;
                            steps[p.first][p.second] = 'L';
                            isB(building,steps,i,j-1);
                            return;
                        }
                    }
                    // Derecha
                    if(j < m-1){
                        if(building[i][j+1] == '.' && !visited[i][j+1]){
                            p.first = i;
                            p.second = j+1;
                            q.push(p);
                            visited[p.first][p.second] = true;
                            steps[p.first][p.second] = 'R';
                        } else if(building[i][j+1] == 'B'){
                            p.first = i;
                            p.second = j+1;
                            steps[p.first][p.second] = 'R';
                            isB(building,steps,i,j+1);
                            return;
                        }
                    }
                    // Eliminar el ya revisado
                    q.pop();
                }

                cout << "NO" << endl;
                return;
            }
        }
    }

}

int main(){
    solve();
    return 0;
}