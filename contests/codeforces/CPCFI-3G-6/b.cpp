// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/436446/problem/B

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    int t;
    int even=0,odd=0;

    FO(i,n){
        cin >> t;
        if( t%2 == 0){
            even += t;
        } else {
            odd += t;
        }
    }

    if ( even > odd){
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl; 
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
