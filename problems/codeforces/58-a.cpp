// Problem link:
// https://codeforces.com/problemset/problem/58/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s;
    cin >> s;

    short int a=0;

    for(char& c : s){
        if( c == 'h' && a == 0){
            a++;
        } else if( c == 'e' && a == 1){
            a++;
        } else if( c == 'l' && a == 2){
            a++;
        } else if( c == 'l' && a == 3){
            a++;
        } else if( c == 'o' && a == 4){
            a++;
        }
    }

    if(a==5){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
