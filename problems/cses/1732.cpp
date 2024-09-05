#include <bits/stdc++.h>
using namespace std;

#define endl                        '\n'
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& v : (arr))
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end() 
#define sz(x)                       (int) x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// cout << setprecision(11);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://cses.fi/problemset/task/1732

// Using rolling hash
// https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/


inline void solve(){
    string s; cin >> s;
    int n = sz(s);

    ll prime = 17;
    ll tmp_prime = 1;

    ll prefix_hash = 0;
    ll suffix_hash = 0;

    vi res;

    // Compare hashes
    FOR(i,0,n-1){
        prefix_hash = (prefix_hash + (tmp_prime * s[i])) % MOD;
        suffix_hash = ((suffix_hash * prime) + s[(n-1)-i]) % MOD;

        if(prefix_hash == suffix_hash){
            res.push_back(i+1);
        }

        tmp_prime = (prime * tmp_prime) % MOD;
    }

    // Print res
    FO(i,sz(res)-1){
        cout << res[i] << " ";
    }
    if(sz(res) > 0){
        cout << res[sz(res)-1] << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
