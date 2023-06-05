// Problem link:
// https://cses.fi/problemset/task/1633/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FO(i, b)  for (int i = 0; i < (b); i++)

long long times(long long n, vector<long long> &memo){
    if (memo[n] != 0){
        return memo[n];
    } else {
        for(int i = 1; i <= 6; i++){
            if(n-i >= 0){
                memo[n] += times(n-i, memo);
                memo[n] %= MOD;
            }
        }
        return memo[n];
    }
}

inline void solve(){
    long long n;
    cin >> n;
    vector<long long> memo(1e6,0);
    memo[0] = 1;

    cout << times(n,memo) << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
