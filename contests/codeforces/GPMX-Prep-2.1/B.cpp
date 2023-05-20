// Problem link:
// https://codeforces.com/gym/104375/problem/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    double n,k,l;
    cin >> n >> k >> l;

    cout << ceil( (n*k) / l) << endl;    
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
