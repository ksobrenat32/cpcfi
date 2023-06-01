// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/446462/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,k1,k2;
    cin >> n;
    cin >> k1;
    cin >> k2;

    int w,b;
    cin >> w >> b;

    // Posible white and black full
    int posw = min(k1,k2);
    int posb = n - max(k1,k2);

    // Extra, in diagonal
    int extraw = abs(k1-k2)/2;
    int extrab = extraw;

    if( w <= posw + extraw && b <= posb + extrab ){
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
