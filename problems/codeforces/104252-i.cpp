// Problem link:
// https://codeforces.com/gym/104252/problem/I

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

int calmax(vector<vector<int>> &v,unordered_map<int,pair<int,int>> &m, int i, int j,int r, int c){
    priority_queue<int, vector<int>, greater<int> > q;
    vector<vector<bool>> visited(r,vector<bool> (c));
    q.push(v[i][j]);

    int cnt = 0;
    while(! q.empty()){
        cnt++;
        i = m[q.top()].first;
        j = m[q.top()].second;
        visited[i][j] = true;

        // Up
        if( i-1 >= 0){
            if(v[i-1][j] > v[i][j]){
                if(! visited[i-1][j]){
                    q.push(v[i-1][j]);
                    visited[i-1][j] = true;
                }
                //cout << "UP" << endl;
            }
        }
        // Down
        if( i+1 < r){
            if(v[i+1][j] > v[i][j]){
                if(!visited[i+1][j]){
                    q.push(v[i+1][j]);
                    visited[i+1][j] = true;
                }
                //cout << "DOWN" << endl;
            }
        }
        // Left
        if( j-1 >= 0){
            if(v[i][j-1] > v[i][j]){
                if(!visited[i][j-1]){
                    q.push(v[i][j-1]);
                    visited[i][j-1] = true;
                }
                //cout << "LEFT" << endl;
            }
        }
        // Right
        if( j+1 < c){
            if(v[i][j+1] > v[i][j]){
                if(!visited[i][j+1]){
                    q.push(v[i][j+1]);
                    visited[i][j+1] = true;
                }
                //cout << "RIGHT" << endl;
            }
        }
        q.pop();
    }
    
    return cnt;
}

inline void solve(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r,vector<int> (c));

    unordered_map<int,pair<int,int>> m;
    pair<int,int> p;

    FO(i,r){
        FO(j,c){
            cin >> v[i][j];
            p.first = i;
            p.second = j;
            m[v[i][j]] = p;
        }
    }

    int mx = 0;

    FO(i,r){
        FO(j,c){
            mx = max(mx,calmax(v, m, i, j, r, c));
        }
    }

    cout << mx << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}

