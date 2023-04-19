// Problem link:
// https://codeforces.com/problemset/problem/133/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >> s;
    for(long unsigned i = 0; i < s.size(); i++){
        if( s[i] == 'H' || (s[i] == 'Q' || s[i] == '9')){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
