// Problem link:
// https://cses.fi/problemset/task//2205

#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n; cin >> n;
    long times = pow(2,n);
    int cnt[2];
    string r;

    vector<string> v;
    vector<string> tmp;

    v.push_back("0000000000000000");
    v.push_back("0000000000000001");
    // contador 
    cnt[0] = 0;
    // columna
    cnt[1] = 16 - 1;

    // Por columna
    for(int i = 2; i <= n; i++){
        tmp = v;
        cnt[1] = 16 - i;
        reverse(tmp.begin(), tmp.end());
        for(size_t j = 0; j < tmp.size(); j++){
            tmp[j][cnt[1]] = '1'; 
            v.push_back(tmp[j]);
        }
    }

    for(int i = 0; i < times; i++){
        cout << v[i].substr(16-n) << endl;
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
