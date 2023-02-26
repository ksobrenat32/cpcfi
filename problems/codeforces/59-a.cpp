// Codeforces link:
// https://codeforces.com/problemset/problem/59/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s;
    cin >> s;

    int cu=0,cl=0;

    for( auto c : s ){
        if ( c >= 'A' && c <= 'Z' ){
            cu++;
        } else {
            cl++;
        }
    }

    if( cl >= cu ){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
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
