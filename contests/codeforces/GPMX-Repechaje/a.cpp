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

inline void solve(){
    ll n, q;
    cin >> n >> q;

    vll a(n);
    FO(i, n) cin >> a[i];

    vll bestStart(n), bestSuffix(n);

    bestStart[n - 1] = a[n - 1];
    bestSuffix[n - 1] = a[n - 1];

    for(int i = n - 2; i >= 0; i--){
        bestStart[i]   = max(a[i], a[i] + bestStart[i + 1]);
        bestSuffix[i]  = max(bestStart[i], bestSuffix[i + 1]);
    }

    ll t;
    FO(i, q){
        cin >> t;
        cout << bestSuffix[t] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    FO(tc, T) solve();

    return 0;
}
