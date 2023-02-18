// Codeforces link:
// https://codeforces.com/group/qhNeDJ317x/contest/428227/problem/E

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long int n;
    cin >> n;

    long long c=0;
    long long int a[n];

    FO(i,n){
        cin >> a[i];
    }

    FO(i,n-1){
        if( (a[i] + a[i+1]) < ((a[i])*(-1) + a[i+1]*(-1)) ){
            a[i] = a[i] * (-1);
            a[i+1] = a[i+1] * (-1);
        }
    }

    FO(i,n){
        c += a[i];
    }

    cout << c << endl;

}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
