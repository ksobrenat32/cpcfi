// Codeforces link:
// https://codeforces.com/problemset/problem/282/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin>>n;
    int x=0;

    FO(i,n){
        string s;
        cin>>s;

        if(s.find("++") != string::npos){
            x++;
        } else {
            x--;
        }
    }

    cout<<x<<endl;

}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
