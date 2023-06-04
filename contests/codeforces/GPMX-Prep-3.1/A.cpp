// Problem link:
// https://codeforces.com/gym/104412/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int k; cin >> k;
    string s; cin >> s;
    
    int cnt = 0;

    for(int i = 0; i < k;i++){
        switch (s[i]) {
            case '1':
                cnt++;
                break;
            case '2':
                cnt++;
                break;
            case '3':
                cnt++;
                break;
            case '4':
                cnt++;
                break;
            case '5':
                cnt++;
                break;
            case '7':
                cnt++;
                break;
            case '9':
                cnt++;
                break;
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
