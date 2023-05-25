// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/445186/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >> s;
    size_t cnt = 0;

    for(size_t i = 0; i < s.size(); i++){
        if( s[i] == 'a' ){
            cnt++;
        }
    }

    if( cnt == s.size() ){
        cout << "NO" << endl;
        return;
    }

    if( s[s.size()-1] != 'a'){
        cout << "YES" << endl;
        cout << 'a' << s << endl;
        return;
    } else if( s[0] != 'a'){
        cout << "YES" << endl;
        cout << s << 'a' << endl;
        return;
    }

    for(size_t i = 1; i < s.size(); i++){
        if ( s[(s.size()-1 )- i] != 'a'){
            cout << "YES" << endl;
            cout << s.substr(0, i) << 'a' << s.substr(i) << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
