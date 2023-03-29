// Problem link:
// https://codeforces.com/problemset/problem/1800/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    string s;
    cin >> s;
    bool m=false,e=false,o=false,w=false;

    FO(i,n){
        if((s[i] == 'm' || s[i] == 'M') && (!e && (!o && !w)) ){
            m = true;
        } else if( (s[i] == 'e' || s[i] == 'E' ) && (m && (!o && !w))){
            e = true;
        } else if( (s[i] == 'o' || s[i] == 'O' ) && ((m && e) && !w)){
            o = true;
        } else if( (s[i] == 'w' || s[i] == 'W' ) && (m && (e && o))){
            w = true;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if(w){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
