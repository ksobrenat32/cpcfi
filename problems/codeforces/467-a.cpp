// Problem link:
// https://codeforces.com/problemset/problem/467/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    int cnt = 0;
    int p,q;

    for(int i = 0; i < n;i++){
        cin >> p >> q;
        if( (q-p) >= 2 ){
            cnt++;
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
