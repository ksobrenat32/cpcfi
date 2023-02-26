// Problem link:
// https://codeforces.com/problemset/problem/116/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin >>n;

    // People, minimum capacity    
    int p=0,m=0;
    // exits, enters
    int a,b;

    FO(i,n){
        cin >> a >> b;
        p += b - a;
        if(p > m){
            m = p;
        }
    }
    cout << m << endl;    
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
