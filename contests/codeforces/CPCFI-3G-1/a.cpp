// Codeforces link:
// https://codeforces.com/group/qhNeDJ317x/contest/428227/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    char c;
    cin >> c;
    string s="codeforces";

    if( s.find(c) == string::npos ){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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
