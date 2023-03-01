// Problem link:
// https://codeforces.com/problemset/problem/266/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n,t;
    cin >> n >> t;

    string s;
    cin >> s;

    FO(i,t){
        for( int j = 0; j < (n - 1); j++){
            if(s[j]=='B' && s[j+1]=='G'){
                s[j] = 'G';
                s[j+1] = 'B';
                j++;
            }
        }
    }

    cout << s << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
