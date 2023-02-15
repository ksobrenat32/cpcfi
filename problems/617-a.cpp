// Codeforces link:
// https://codeforces.com/problemset/problem/617/A

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    float x;
    cin>>x;
    cout<<ceil(x/5)<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
