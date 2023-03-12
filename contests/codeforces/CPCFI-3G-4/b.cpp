// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/431889/problem/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;

    int t;
    int alone=0;
    // av bought
    int avb = 0;
    // av used
    int avu = 0;

    FO(i,n){
        cin >> t;
        if(t==1){
            alone++;
            if( ( avb > avu )){
                avu++;
            } else {
                avu++;
                avb++;
            }
        } else {
            while(alone >= 3 ){
                alone -= 2;
                avu--;
            }
        }
    }

    cout << avb << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
