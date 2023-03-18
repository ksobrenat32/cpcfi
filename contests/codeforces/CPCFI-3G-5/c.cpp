// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/433780/problem/C

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    vector<long long> v(n);

    long long mx=-1e9,smx=-1e9;

    FO(i,n){
        cin >> v[i];
        if( v[i] > mx ){
            smx = mx;
            mx = v[i];
        } else {
            if( v[i] > smx ){
                smx = v[i];
            }
        }
    }

    for(int i = 0; i < n; i++ ){
        if(v[i] != mx){
            cout << v[i] - mx << " ";
        } else {
            cout << v[i] - smx << " ";
        }
        
    }
    cout << endl;

}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
