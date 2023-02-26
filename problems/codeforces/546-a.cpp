// Codeforces link:
// https://codeforces.com/problemset/problem/546/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long int k,n,w;
    cin >> k >> n >> w ;

    long long int tp=0;

    FO(i,w){
        tp += ( (i + 1) * k);
    }


    if ( (tp - n) < 0 ){
        cout << 0 << endl;
    } else {
        cout << tp - n << endl;
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
