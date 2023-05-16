// Problem link:
// https://codeforces.com/problemset/problem/469/A

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,p,t; cin >> n;

    vector<bool> lvl(n,true);

    for(int a = 0; a < 2; a++){
        cin >> p;
        for(int i = 0; i < p; i++){
            cin >> t;
            lvl[t-1] = false;
        }
    }

    for(int i = 0; i < n; i++){
        if(lvl[i]){
            cout << "Oh, my keyboard!" << endl;
            return;
        }
    }

    cout << "I become the guy." << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
