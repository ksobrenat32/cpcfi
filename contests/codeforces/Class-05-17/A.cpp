// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/444168/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >> s;
    vector<char> abc(26,0);
    map<char,int> cnt;
 
    for(size_t i = 0; i < s.size(); i++){
        abc[s[i]-97]++;
        cnt[s[i]]++;
    }
 
    if(cnt.size() > 2){
        cout << "YES" << endl;
    } else {
        bool t;
        if(cnt.size() == 2){
            t = true;
        } else {
            t = false;
        }
        for(int i = 0; i < 26; i++){
            if(abc[i] == 1){
                t = false;
            }
        }
        if(t){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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
