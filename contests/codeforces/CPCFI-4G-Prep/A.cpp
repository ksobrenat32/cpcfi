#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://codeforces.com/problemset/problem/1800/A

inline void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    bool m=false,e=false,o=false,w=false;
 
    for(int i = 0; i < n; i++){
        if( (s[i] == 'm' ) && (!e && (!o && !w)) ){
            m = true;
        } else if( ( s[i] == 'e' ) && (m && (!o && !w))){
            e = true;
        } else if( ( s[i] == 'o' ) && ((m && e) && !w)){
            o = true;
        } else if( ( s[i] == 'w' ) && (m && (e && o))){
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
    for(int tc = 0; tc < T; tc++){
        solve();
    }
    return 0;
}
