// Codeforces link:
// https://codeforces.com/problemset/problem/263/A

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int s=5,x;
    FO(i,s){
        FO(j,s){
            cin>>x;
            if(x==1){
                cout<<abs(floor(s/2)-i)+abs(floor(s/2)-j)<<endl;
                return;
            }
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
