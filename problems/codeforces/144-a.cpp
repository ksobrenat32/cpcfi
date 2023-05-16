// Problem link:
// https://codeforces.com/problemset/problem/144/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,r = 0; cin >> n;
    vector<int> v(n);
    pair<int, int> mn;
    pair<int, int> mx;

    mn.first = 1000;
    mx.first = -1;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        // Save min and max
        if( v[i] > mx.first){
            mx.first = v[i];
            mx.second = i;
        }
        if( v[i] <= mn.first){
            mn.first = v[i];
            mn.second = i;
        }
    }

    // For big one
    r += mx.second;
    r += n - 1 - mn.second ;

    // If they are crosswise
    if( mx.second > mn.second ){
        r -= 1;
    }

    cout << r << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
