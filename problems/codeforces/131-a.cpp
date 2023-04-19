// Problem link:
// https://codeforces.com/contest/131/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >>s;
    int size = s.size();

    // Mayus
    if( s[0] < 91 ){
        for(int i = 1; i < size; i++){
            // If min
            if(s[i] > 96 ){
                cout << s << endl;
                return;
            }
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
    } else {
        for(int i = 1; i < size; i++){
            if(s[i] > 96 ){
                cout << s << endl;
                return;
            }
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s[0] = s[0] - 32;
        cout << s << endl;
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
