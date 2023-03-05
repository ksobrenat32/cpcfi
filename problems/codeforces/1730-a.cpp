// Problem link:
// https://codeforces.com/problemset/problem/1730/a

#include <bits/stdc++.h>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int c,n;
    cin >> n >> c;

    vector<short int> a(100,0);

    FO(i,n){
        short int o;
        cin >> o;
        o--;
        a[o]++;
    }

    int cost=0;

    FO(i,100){
        if( a[i] > c ){
            cost += c;
        } else {
            cost += a[i];
        }

    }

    cout << cost << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
