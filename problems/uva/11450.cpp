// Problem link:
// https://onlinejudge.org/external/114/11450.pdf

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int m,c;
    cin >> m >> c;

    vector<vector <int>> v(c);
    vector<vector <bool>> memo(c,vector<bool> (m,false));

    short int t,k;

    // Leer valores
    FO(i,c){
        cin >> t;
        FO(j,t){
            cin >> k;
            v[i].push_back(k);
        }
    }

    // Caso base
    for(size_t i = 0; i < v[0].size(); i++){
        if( (m-v[0][i]) >= 0){
            memo[0][m-v[0][i]]=true;
        }
    }

    // Cada caso
    for(int i = 1; i < c; i++){
        for(int j = 0; j < m; j++){
            if(memo[i-1][j] == true){
                for(size_t k = 0; k < v[i].size(); k++){
                    if( (j-v[i][k]) >=0 ) {
                        memo[i][j-v[i][k]]=true;
                    }
                }
            }
        }
    }

    int res=-1;

    // Obtener mas bajo
    for(int i = 0; i < m; i++){
        if(memo[c-1][i] == true){
            res = i;
            break;
        }
    }

    if(res == -1){
        cout << "no solution" << endl;
    } else {
        cout << m - res << endl;
    }
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
