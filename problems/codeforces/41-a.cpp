// Problem link:
// https://codeforces.com/problemset/problem/41/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s,t;
    cin >> s >> t;

    reverse(s.begin(), s.end());

    if( s == t){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
