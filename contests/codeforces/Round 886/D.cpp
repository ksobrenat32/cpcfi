#include <algorithm>
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
// https://codeforces.com/contest/1850/problem/D

inline void solve(){
    int n;
    ll k;
    cin >> n >> k;

    vll a(n);

    FO(i,n){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    int cnt = 1;
    int mxcnt = 1;

    FO(i,n-1){
        if(a[i+1]-a[i] <= k){
            cnt++;
        } else {
            mxcnt = max(mxcnt,cnt);
            cnt = 1;
        }
    }
    mxcnt = max(mxcnt,cnt);

    if(cnt == n){
        cout << 0 << endl;
        return;
    }

    cout << n - mxcnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
