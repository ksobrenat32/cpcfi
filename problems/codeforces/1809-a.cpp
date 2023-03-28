// Problem link:
// https://codeforces.com/problemset/problem/1809/a

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s;
    cin >> s;
    unordered_map<char, int> m(0);
    int mx=0;

    for(char& c : s){
        m[c]++;
        mx = max(mx,m[c]);
    }

    if(mx == 1 || mx == 2){
        cout << 4 << endl;
        return;
    } else if(mx == 3){
        cout << 6 << endl;
        return;
    } else {
        cout << -1 << endl;
        return;
    }
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
