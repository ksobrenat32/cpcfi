// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/442145/problem/H

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    int x = n/4;
    int y; 

    if( n%4 >= 2){
        y = x + 1;
    } else {
        y = x;
    }

    cout << x * y << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
