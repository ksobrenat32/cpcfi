// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/442711/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int w,d,h;
    cin >> w >> d >> h;

    int a,b,f,g;
    cin >> a >> b >> f >> g;

    // Get the nearest to ab wall in x,y
    int mabx = min(a,w-a);
    int maby = min(b,d-b);
    int mabxy = min(mabx,maby);
    
    // Get the nearest fg wall in x,y
    int mfgx = min(f,w-f);
    int mfgy = min(g,d-g);
    int mfgxy = min(mfgx,mfgy);

    // Get distance in the same plano 
    int dx = abs(a - f);
    int dy = abs(b - g);

    // height + 
    //cout << "ABXY: " << mabxy << endl;
    //cout << "FGXY: " << mfgxy << endl;
    cout << h + (2 * min(mabxy,mfgxy)) + dx + dy << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
