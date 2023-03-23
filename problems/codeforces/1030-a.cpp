// Problem link:
// https://codeforces.com/problemset/problem/1030/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;

    int t;
    FO(i,n){
        cin >> t;
        if(t == 1){
            cout << "HARD" << endl;
            return;
        }
    }

        cout << "EASY" << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
