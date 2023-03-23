// Problem link:
// https://codeforces.com/problemset/problem/894/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >> s;
    int cnt = 0;
    int sz = s.size();

    for(int i = 0; i < sz; i++){
        if( s[i] == 'Q'){
            for(int j = i; j < sz; j++){
                if(s[j] == 'A'){
                    for(int k = j; k < sz; k++){
                        if(s[k] == 'Q'){
                            cnt++;
                        }
                    }
                }
            }
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
