// Codeforces link:
// https://codeforces.com/problemset/problem/96/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s;
    cin >> s;

    int c=1,l;

    l = s[0];

    for(long unsigned int i = 1; i < s.size() ; i++){
        if(l == s[i]){
            c++;
        } else {
            l = s[i];
            c = 1;
        }

        if(c >= 7) {
            cout << "YES" <<endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
