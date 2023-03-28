// Problem link:
// https://codeforces.com/problemset/problem/1809/b

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long double n; cin >> n;
    cout.setf(ios::fixed);
    cout << setprecision(0) << ceil(sqrtl(n)) - 1 << endl; 
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}