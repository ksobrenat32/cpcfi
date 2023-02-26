// Problem link:
// https://codeforces.com/problemset/problem/977/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long int n,k;
    cin >> n >> k;

    while(k--){
        if( n%10 != 0){
            n--;
        } else {
            n /= 10;
        }
    }
    
    cout << n << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
