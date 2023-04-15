// Problem link:
// https://codeforces.com/problemset/problem/136/A

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n; cin >> n;
    vector<int> v(n);
    FO(i,n){
        cin >> v[i];
    }

    FO(i,n){
        auto it = find(v.begin(),v.end(),(i+1));

        // Calculate index
        cout << it - v.begin() + 1 << " ";
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
