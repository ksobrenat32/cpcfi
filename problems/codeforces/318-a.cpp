// Problem link:
// https://codeforces.com/problemset/problem/318/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long n,k; cin >> n >> k;

    if( n%2 == 0){
        if ( k <= n/2 ) {
            cout << (2*k) - 1 << endl;
        } else {
            k -= n/2;
            cout << (2*k) << endl;
        }
    } else {
        if ( k <= n/2 + 1 ) {
            cout << (2*k) - 1 << endl;
        } else {
            k -= n/2 + 1;
            cout << (2*k) << endl;
        }
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
