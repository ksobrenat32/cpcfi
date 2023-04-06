// Problem link:
// https://codeforces.com/contest/1800/problem/E1

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n,k; cin >> n >> k;
    string s,t; cin >> s >> t;
    vector<long long> m(26,0);

    // If a letter can be moved everywhere
    if( n >= (2*k) ){
        FO(i,n){
            m[s[i]-97]++;
        }
        FO(i,n){
            m[t[i]-97]--;
        }
        FO(i,26){
            if(m[i] > 0){
                cout << "NO" << endl;
                return;       
            }       
        }
        cout << "YES" << endl;
    }
    // If it can't be moved
    else if ( n <= k ) {
        // Print output
        if(s == t){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    // It can be moved but not all
    else {
        // Test middle
        if( s.substr(n-k,(2*k)-n) != t.substr(n-k,(2*k)-n) ){
            cout << "NO" << endl;
            return;
        }
        FO(i,n-k){
            m[s[i]-97]++;
        }
        FO(i,n-k){
            m[s[n-i-1]-97]++;
        }
        FO(i,n-k){
            m[t[i]-97]--;
        }
        FO(i,n-k){
            m[t[n-i-1]-97]--;
        }
        FO(i,26){
            if(m[i] > 0){
                cout << "NO" << endl;
                return;       
            }       
        }
        cout << "YES" << endl;
    }
    
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}