// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/442145/problem/I

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >> s;
    unsigned long long full;
    full = stoi(s);
    vector<int> v(11,0);

    for(size_t i = 0;i < s.size(); i++){
        if( v[ int(s[i]) - 48 ] > 0 ){
            v[ s[i] - 48 ]++;
        } else if( v[ s[i] - 48 ] == -1 ){
            continue;
        } else if( (s[i]) == '0' ){
            continue;
        }
        else {
            if( full%( s[i] - 48 ) == 0 ){
                v[ s[i] - 48 ]++;
            } else {
                v[ s[i] - 48 ] = -1;
            }
        }
    }

    int res=0;
    for(int i = 0; i < 11; i++){
        if(v[i] > 0){
            res += v[i];
        }
    }

    cout << res << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
