// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/433780/problem/A

#include <bits/stdc++.h>
#include <random>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];

    sort(v.begin(),v.end());

    cout << v[1] << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
