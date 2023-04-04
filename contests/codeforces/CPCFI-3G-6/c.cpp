// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/436446/problem/C

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < n; i++){
        if( i%2 == 0){
            for( int j = i; j < n; j+=2){
                if( s[j+1] == s[i] ){
                    cout << "NO" << endl;
                    return;
                }
            }
        } else {
            for( int j = i; j < n; j+=2){
                if( s[j+1] == s[i] ){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
