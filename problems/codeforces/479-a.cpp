// Problem link:
// https://codeforces.com/problemset/problem/479/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int a,b,c; cin >> a >> b >> c;
    int abc,res;

    // One way
    if( a+b > a*b ){
        abc = a + b;
    } else {
        abc = a * b;
    }
    if( abc + c > abc * c){
        res = abc + c;
    } else {
        res = abc * c;
    }

    // The other way
    if( b+c > b*c ){
        abc = b + c;
    } else {
        abc = b * c;
    }
    if( abc + a > abc * a){
        res = max(res, abc + a );
    } else {
        res = max(res, abc * a );
    }

    cout << res << endl;

}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
