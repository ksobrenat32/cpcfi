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
// https://codeforces.com/group/kpNr48xCia/contest/615822/problem/D

bool secso(vll &h, vll &d){
    ll sz = 0;

    FO(i, sz(d)){
        if(h[i] > sz){
            sz = h[i];
        }
        
        sz -= d[i];

        if(sz <= 0) return false;
    }

    return true;
}

inline void solve(){
    int n; cin >> n;
    vll h(n);
    FO(i,n) cin >> h[i];
    vll d(n-1);
    FO(i,n-1) cin >> d[i];

    if(secso(h, d)){
        cout << "habibi" << endl;
        return;
    }

    // Try reversed
    reverse(all(h));
    reverse(all(d));
    
    if(secso(h, d)){
        cout << "habibi" << endl;
    } else {
        cout << "which" << endl;
    }
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
