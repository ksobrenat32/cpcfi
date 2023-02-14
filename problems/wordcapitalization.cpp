// Codeforces link:
// https://codeforces.com/problemset/problem/281/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s;
    cin>>s;
    transform(s.begin(), s.begin()+1, s.begin(), ::toupper);
    cout<<s<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
