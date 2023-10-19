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

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://codeforces.com/problemset/problem/492/B

inline void solve(){
    int n;
    ll t;
    ll l;
    cin >> n >> l;

    vll v(n,0);
    ll start = INF;
    ll end = 0;

    FO(i,n){
        cin >> t;
        v[i] = t;
        start = min(start, t);
        end = max(end, t);
    }

    sort(all(v));

    ll maxDist = 0;
    FOR(i,1, n){
        maxDist = max(maxDist, (v[i] - v[i-1]));
    }
    
    ll minDistance = -1;
    minDistance = max(minDistance, start);
    minDistance = max(minDistance, l - end);

    cout << setprecision(11);
    cout << max( (double)minDistance, ((double)(maxDist) / 2) ) << endl;
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
