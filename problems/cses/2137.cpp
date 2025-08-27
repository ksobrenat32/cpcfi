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
// https://cses.fi/problemset/task/2137

#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")

bitset<3001> a[3001];

inline void solve(){
    int n; cin >> n; 
    string s;

    FO(i,n){
        cin >> s;
        FO(j,n) a[i][j] = s[j]-'0';
    }

    ll cnt=0;
    ll t;

    bitset<3001> r;
    FO(i,n){
        FOR(j,i+1,n){
            r = a[i] & a[j];
            t = r.count();
            cnt += (t*(t-1))/2;
        }
    }

    cout << cnt << endl;
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
