// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/433780/problem/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int mx = 0;

    for( char& c : s){
        mx = max(mx,int(c));
    }

    cout << mx - 96 << endl;


}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
