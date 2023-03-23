// Problem link:
// https://codeforces.com/problemset/problem/996/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long n=0; cin >> n;
    long long r=0;

    while ( n >= 100 ){
        n -= 100;
        r++;
    }

    while ( n >= 20 ){
        n -= 20;
        r++;
    }

    while ( n >= 10 ){
        n -= 10;
        r++;
    }

    while ( n >= 5 ){
        n -= 5;
        r++;
    }

    while ( n >= 1 ){
        n -= 1;
        r++;
    }

    cout << r << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
