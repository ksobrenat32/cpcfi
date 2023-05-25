// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/445452/problem/D

#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<char,int>> v;

    // Add first
    v.push_back(make_pair(s[0], 1));
    int top = 0;
    int mx = 0;

    for(int i = 1; i < n; i++){
        if(s[i] == v[top].first){
            v[top].second++;
        } else {
            v.push_back(make_pair(s[i], 1));
            top++;
            
        }
    }

    for(size_t i = 0; i < v.size(); i++){
        mx = max( mx, v[i].second);
    }

    cout << mx + 1 << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
