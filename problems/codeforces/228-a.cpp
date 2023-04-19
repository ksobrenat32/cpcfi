// Problem link:
// https://codeforces.com/problemset/problem/228/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long t;
    set<long long> s;
    for(int i = 0; i < 4;i++){
        cin >> t;
        s.insert(t);
    }

    cout << 4 - s.size() << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
