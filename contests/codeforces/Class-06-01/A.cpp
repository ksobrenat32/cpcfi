// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/446634/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    bool activate = false;

    int mx=-1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'P' && activate){
            cnt++;
        }
        if(s[i] == 'A'){
            if(activate){
                mx = max(mx,cnt);    
                cnt = 0;
            } else {
                activate = true;
            }
            
        }
    }
    mx = max(mx,cnt);    
    if( mx == -1){
        mx = 0;
    }
    cout << mx << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
