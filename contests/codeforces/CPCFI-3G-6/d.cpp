// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/436446/problem/D

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,q; cin >> n >> q;
    vector<long long> a(n,0);
    long long t;

    FO(i,n){
        cin >> t;
        if(i > 0){
            a[i] = a[i-1] + t;
        } else {
            a[i] = t;
        }
    }

    FO(i,q){
        int l,r,k;
        cin >> l >> r >> k;
        long long diff;

        if( (l-1) == 0 ){
            diff = a[r-1];
        } else {
            diff = a[r-1] - a[l-2];
        }

        t = k * ( r - l + 1);

        if( (a[n-1] + t - diff)%2 == 0 ){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}