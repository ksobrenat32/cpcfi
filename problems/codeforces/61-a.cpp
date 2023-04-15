// Problem link:
// https://codeforces.com/problemset/problem/61/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s1,s2; cin >> s1 >> s2;

    for(size_t i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i]){
            cout << 1;
        } else {
            cout << 0;
        }
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
