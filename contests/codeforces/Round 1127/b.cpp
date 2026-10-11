#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

// Simulate both paths, adding or deleting
ll sim2(vi a, int n, int ps, int m, int i){
    // If end, return the max value
    if(i>n-1) return m;

    ll res = a[i];

    // Try if leaving the value as is
    res = max(res, sim2(a, n, ps+a[i], max(m, a[i]),i+1));
    
    // Try if going less
    res = max(res, sim2(a, n, ps+(a[i] - ps), max(m, a[i]-ps),i+1));

    // Try if going up
    res = max(res, sim2(a, n, ps+(a[i] + ps), max(m, a[i]+ps),i+1));

    return res;
}

ll sim(vi &a, int n, int i, ll mx, ll mn, ll r){
    // If end, return the max value
    if(i>n-1) return r;

    // Get the best for this element, either add the max or substract the min
    ll t = a[i] + max(mx, -mn);

    // New max and min sums after choosing the best option
    ll nmx = a[i] + max(2*mx, 0LL);
    ll nmn = a[i] + min(2*mn, 0LL);
    ll best  = max(r, t);

    return sim(a, n, i + 1, nmx, nmn, best);
}

inline void solve(){
    int n; cin >> n;
    vi a(n);
    FO(i, n) cin >> a[i];

    //cout << sim2(a, n, a[0], a[0], 1) << endl;
    cout << sim(a, n, 1, a[0], a[0], a[0]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}

