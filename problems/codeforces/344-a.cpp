// Problem link:
// https://codeforces.com/problemset/problem/344/A

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    vector<string> v(n);

    FO(i,n){
        cin >> v[i];
    }

    int cnt = 1;
    string lst = v[0];

    for( int i = 1; i < n ; i++){
        if (v[i] != lst){
            cnt++;
            lst = v[i];
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
