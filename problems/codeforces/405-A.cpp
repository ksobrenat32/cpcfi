// Problem link:
// https://codeforces.com/problemset/problem/405/A

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    vector<int> a(n);

    FO(i,n){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    FO(i,n){
        cout << a[i] << " ";
    }
    cout << endl;

}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
