// Codeforces link:
// https://codeforces.com/problemset/problem/158/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n,k;
    cin>>n>>k;
    k--;

    int a[n];
    int c=0;

    FO(i,n){
        cin>>a[i];
    }

    FO(i,n){
        if(a[i]>0 && a[i]>=a[k]){
            c++;
        }
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
