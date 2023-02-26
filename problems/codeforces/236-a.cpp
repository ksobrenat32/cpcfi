// Codeforces link:
// https://codeforces.com/problemset/problem/236/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s,n;
    cin>>s;
    int count=0;

    for(auto c: s){
        if( find(n.begin(),n.end(),c) == n.end() ){
            n += c;
            count++;
        }
    }

    if(count%2 == 0){
        cout<<"CHAT WITH HER!"<<endl;
    } else {
        cout<<"IGNORE HIM!"<<endl;
    }
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
