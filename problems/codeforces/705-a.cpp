// Problem link:
// https://codeforces.com/problemset/problem/705/A

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n; cin >> n;
    string res = "I hate";

    for( short int i = 1; i < n; i++ ){
        if(i%2 != 0){
            res += " that I love";
        } else {
            res += " that I hate";
        }
    }

    res += " it";
    cout << res << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
