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
// https://cses.fi/problemset/task/1731

inline void solve(){
    // String
    string s; cin>>s;
    // Size of the string
    int n = sz(s);

    // Number of words
    int k; cin>>k;
    // Words
    vector<string> d;
    string tmp_string;

    // Number of ways to build up to this index
    vll dp(n+1,0);

    // Just add the ones that are a substring
    FO(i,k){
        cin >> tmp_string;
        if (s.find(tmp_string) != string::npos) {
            d.push_back(tmp_string);
        }
    }

    k = sz(d);
    dp[0] = 1;

    int tmp_size;

    FO(i,n){
        // If imposible to get to this point, continue
        if(dp[i] == 0){
            continue;
        }

        FO(j,k){
            tmp_size = sz(d[j]);
            // If it does not fit, continue
            if(tmp_size > n-i){
                continue;
            }

            // Compare substrings, if equal, add a possibility
            if(s.substr(i,tmp_size) == d[j]){
                dp[i+tmp_size] += dp[i];
                dp[i+tmp_size] %= MOD;
            }
        }
    }

    cout << dp[n] << endl;
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