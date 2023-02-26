// Codeforces link:
// https://codeforces.com/problemset/problem/112/A

#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string a,b;
    cin>>a>>b;

    transform(a.begin(),a.end(),a.begin(), ::toupper);
    transform(b.begin(),b.end(),b.begin(), ::toupper);

    if(a==b){
        cout<<0<<endl;
    } else {
        if(a<b){
            cout<<-1<<endl;
        } else {
            cout<<1<<endl;
        }
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
