// Problem link:
// https://codeforces.com/problemset/problem/148/A

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int k, l, m, n ,d;
    cin >> k >> l >> m >> n >> d;
    
    int cnt = 0;

    for(int i = 0; i < d; i++){
        if((i+1)%k == 0){
            cnt++;
        } else if((i+1)%l == 0){
            cnt++;
        } else if((i+1)%m == 0){
            cnt++;
        } else if((i+1)%n == 0){
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
