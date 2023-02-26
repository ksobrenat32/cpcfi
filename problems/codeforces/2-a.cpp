// Codeforces link:
// https://codeforces.com/problemset/problem/2/A

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n;
    cin >> n;

    map<string, int> m;

    FO(i,n){
        string sk;
        int val;
        cin >> sk >> val;

        m[sk] += val ;
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
