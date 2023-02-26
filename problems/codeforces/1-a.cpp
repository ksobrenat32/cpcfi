// Codeforces link:
// https://codeforces.com/problemset/problem/1/A

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    double n,m,a;
    cin>>n>>m>>a;
    long long x,y;
    x = ceil(n/a);
    y = ceil(m/a);

    cout<<(x*y)<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
