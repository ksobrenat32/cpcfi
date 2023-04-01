// Problem link:
// https://codeforces.com/problemset/problem/1786/B

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,w,h; cin >> n >> w >> h;
    // Cakes
    vector<long long> a(n);
    // Dispenser
    vector<long long> b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    long long log = 1e9,rad = (-1e9); 

    FO(i,n){
        rad = max(rad,b[i]+h - a[i]-w);
        log = min(log,b[i]-h - a[i]+w);
    }

    if(log >= rad){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // memoA needs to contain memoB
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
