// Codeforces link:
// https://codeforces.com/problemset/problem/118/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s,r;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(auto c : s){
        switch (c) {
            case 'a':
                break;
            case 'e':
                break;
            case 'i':
                break;
            case 'o':
                break;
            case 'u':
                break;
            case 'y':
                break;
            default:
                r+='.';
                r+=c;
        }
    }
    cout<<r<<endl;

}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
