// Codeforces link:
// https://codeforces.com/problemset/problem/791/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int a,b,c=0;
    cin>>a>>b;

    while ( a <= b ){
        c++;
        a = a * 3;
        b = b * 2;
    }

    cout<<c<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
