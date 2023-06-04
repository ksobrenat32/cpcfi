// Problem link:
// https://codeforces.com/gym/104412/problem/K

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,k;
    cin >> n >> k;

    vector<vector<int>> v(n,vector<int> (n));
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i <= n-k; i++){
        for(int j = 0; j <= n-k; j++){
            if( (v[i][j] == v[i+k-1][j]) && (v[i][j] == v[i][j+k-1]) && (v[i][j] == v[i+k-1][j+k-1])){
                cnt++;
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
