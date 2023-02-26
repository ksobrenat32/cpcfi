// Codeforces link:
// https://codeforces.com/problemset/problem/266/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n,ct=0;
    cin>>n;

    char last,now;

    FO(i,n){
        cin>>now;

        if( now == last ){
            ct ++;
        }
        last = now;
    }

    cout<<ct<<endl;

}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
