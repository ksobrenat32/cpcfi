// Problem link:
// https://codeforces.com/problemset/problem/1559/b

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt=0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'B' || s[i] == 'R'){
            for (int j = i; j > 0; j--){
                if(s[j] == 'B' ){
                    s[j-1] = 'R';
                } else {
                    s[j-1] = 'B';

                }
            }
            cnt = 0;
            break;
        }
        cnt++;
    }

    if(cnt == n){
        s[0] = 'B';
    }

    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            if(s[i-1] == 'B' ){
                s[i] = 'R';
            } else {
                s[i] = 'B';
            }
        }
    }

    cout << s << endl;

}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
