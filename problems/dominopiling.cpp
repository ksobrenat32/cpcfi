// Codeforces link:
// https://codeforces.com/problemset/problem/50/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int m,n;
    cin>>m>>n;
    cout<<floor((m*n)/2)<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
