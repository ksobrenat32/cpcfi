// Problem link:
// https://codeforces.com/problemset/problem/1272/C

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,k;
    cin >> n >> k;

    string s;
    vector<char> v(k);

    cin >> s;

    long long cnt=0,res=0;

    FO(i,k){
        cin >> v[i];
    }

    for(char& c : s){
        if( find(v.begin(), v.end(), c) != v.end()){
            cnt++;
        } else {
            res += ( (cnt * (cnt + 1) ) / 2 );
            cnt = 0;
        }
    }
    res += ( (cnt * (cnt + 1) ) / 2 );

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
