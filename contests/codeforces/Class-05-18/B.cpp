// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/444333/problem/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    if( n%2 == 0 ){
        for(int i = 0; i < n-2; i+=2){
            cout << s[i] << s[i+1] << '-';
        }
        cout << s[n-2] << s[n-1] << endl;
    } else {
        for(int i = 0; i < n-3; i+=2){
            cout << s[i] << s[i+1] << '-';
        }
        cout << s[n-3] << s[n-2] << s[n-1] << endl;
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
