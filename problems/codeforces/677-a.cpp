// Problem link:
// https://codeforces.com/problemset/problem/677/A

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n,h;
    cin >> n >> h;

    short int w=0,t;

    FO(i,n){
        cin >> t;
        if(t > h){
            w += 2;
        } else {
            w++;
        }
    }

    cout << w << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
