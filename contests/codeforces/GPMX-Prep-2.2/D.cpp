// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/444610/problem/D

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,h,w;
    // days, nu home, nu workplace
    cin >> n >> h >> w;
    
    char c;
    FO(i,n){
        cin >> c;
        if( c == 'Y' ){
            cout << 'Y';
            w++;
            h--;
        } else {
            if(w == 0){
                cout << 'Y';
                w++;
                h--;
            } else {
                cout << 'N';
            }
        }

        cout << ' ';
        cin >> c;
        if( c == 'Y' ){
            cout << 'Y';
            w--;
            h++;
        } else {
            if(h == 0){
                cout << 'Y';
                h++;
                w--;
            } else {
                cout << 'N';
            }
        }
        cout << endl;
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
