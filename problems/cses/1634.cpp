#include <bits/stdc++.h>
using namespace std;

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
// https://cses.fi/problemset/task/1634/

inline void solve(){
    int n,x;
    cin >> n >> x;

    vi coins(n);
    FO(i,n){
        cin >> coins[i];
    }

    vll dp(x+1,INF);

    dp[0] = 0;
    FOR(i,1,x+1){
        FO(j,n){
            if( (i-coins[j]) >= 0 && dp[(i-coins[j])]+1 < dp[i] ){
                dp[i] = dp[i-coins[j]] + 1;
            }
        }
    }

    if(dp[x] == INF){
        dp[x] = -1;
    }
    cout << dp[x] << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
