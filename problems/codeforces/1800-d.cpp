// Problem link:
// https://codeforces.com/contest/1800/problem/D

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long n; cin >> n;
    string s; cin >> s;

    long long diff = 0;

    // Count all repeated strings
    for(long long i = 0; i < n-2;i++){
        if(s[i] == s[i+2]){
            diff++;
        }
    }

    cout << n - 1 - diff << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
