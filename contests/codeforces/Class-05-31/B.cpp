// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/446462/problem/B

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string orig,sorted;
    cin >> orig;
    sorted = orig;
    sort(sorted.begin(),sorted.end());

    if(orig == sorted){
        cout << "YES" << endl;
        return;
    }

    bool twoOne = false;

    for(size_t i = 1; i < orig.size();i++){
        if(orig[i] == '1' && orig[i-1] == '1'){
            twoOne = true;
        }
        if( (orig[i] == '0' && orig[i-1] == '0') && twoOne){
            cout << "NO" << endl;
            return;
        }

    }
    cout << "YES" << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
