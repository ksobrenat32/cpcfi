// Problem link:
// https://codeforces.com/contest/1800/problem/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long n,k; cin >> n >> k;
    string s; cin >> s;
    long cnt=0;
    unordered_map<int, int> m(0);

    for(long i = 0; i < n; i++){
        m[int(s[i])]++;
    }

    // Count already created
    for(int i = 0; i < 26; i++){
        while( m[i+65] > 0 && m[i+97] > 0 ){
            m[i+65]--;
            m[i+97]--;
            cnt++;
        }
    }

    // Create with k
    for(int i = 0; i < 26; i++){
        if(k <= 0){
            continue;
        }
        // Test upper
        while( m[i+65] >= 2 && k > 0){
            m[i+65] -= 2;
            k--;
            cnt++;
        }
        // Test lower
        while( m[i+97] >= 2 && k > 0){
            m[i+97] -= 2;
            k--;
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
