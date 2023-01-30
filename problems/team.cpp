// Codeforces link:
// https://codeforces.com/problemset/problem/231/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

// Solution
inline void solve(){
    int n;
    cin>>n;

    int t=0;

    FO(i,n){
        int p=0;
        FO(j, 3){
            int c;
            cin>>c;
            p += c;
        }
        if(p>1){
            t++;
        }
    }
    cout<<t<<endl;
}

int main(){
    int T=1;
    FO(tc,T){
        solve();
    }
    return 0;
}
