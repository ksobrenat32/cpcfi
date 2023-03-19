// Problem link:
// https://codeforces.com/problemset/problem/271/A

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    int a,b,c,d;
    bool f=true;

    while(f){
        n++;
        a = n / 1000;
        b = (n % 1000) / 100;
        c = ((n % 1000) % 100) / 10;
        d = ((n % 1000) % 100) % 10;
        if( (a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d) ){
            break;
        }
    }

    cout << n << endl;




}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
