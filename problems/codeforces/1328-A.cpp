// Problem link:
// https://codeforces.com/problemset/problem/1328/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    double a,b;
    int res;
    cin >> a >> b;

    res = (ceil(a/b) * b) - a;


    cout << setprecision(0) << res << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
