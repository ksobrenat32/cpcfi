// Problem link:
// https://codeforces.com/gym/104412/problem/I

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    if( (n/k) >= m){
        cout << "Iron fist Ketil" << endl;
    } else {
        cout << "King Canute" << endl;
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
