// Codeforces link:
// https://codeforces.com/problemset/problem/69/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n;
    cin >> n;

    int x=0,y=0,z=0;

    FO(i,n){
        int tx,ty,tz;
        cin >> tx >> ty >> tz;
        x += tx;
        y += ty;
        z += tz;
    }

    if ( x == 0 && y == 0 && z == 0 ){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
