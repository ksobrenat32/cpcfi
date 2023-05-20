// Problem link:
// https://codeforces.com/gym/104375/problem/G

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    
    int n; cin >> n;

    if(n == 1){
        cout << "Jane" << endl;
        return;
    }

    bool p=false;
    // Jane = true
    // John = false
    int cnt=1;

    for(int i = 2; i < 6000; i++){
        for(int j = 0; j < 2; j++){
            cnt += i;
            if(cnt >= n){
                if(p){
                    cout << "Jane" << endl;
                } else {
                    cout << "John" << endl;
                }
                return;
            }
            if(p){
                p = false;
            } else {
                p = true;
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
