// Problem link:
// https://codeforces.com/problemset/problem/200/B

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n; cin >> n;
    double tmp;
    double cnt=0;
    FO(i,n){
        cin >> tmp;
        cnt += tmp;
    }

    cout << cnt / n << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
