// Problem link:
// https://codeforces.com/problemset/problem/160/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    vector<int> v(n);
    bool f=false;

    FO(i,n){
        cin >> v[i];
    }

    sort(v.rbegin(),v.rend());

    int mine=0,bro=0,cnt;

    for(int i = 0; i < n; i++){
        cnt = 0;
        mine = 0;
        bro = 0;

        for(int j = 0; j < i; j++){
            mine += v[j];
            cnt++;
        }


        for(int j = i; j < n; j++){
            bro += v[j];            
        }

        if(mine > bro){
            f = true;
            break;
        }
    }

    if(f){
        cout << cnt << endl;
    } else {
        cout << cnt+1 << endl;
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
