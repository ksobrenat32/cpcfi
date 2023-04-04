// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/436446/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int a,b,c;
    cin >> a >> b >> c;

    if( a + b == c){
        cout << '+' << endl;
    } else {
        cout << '-' << endl;
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
