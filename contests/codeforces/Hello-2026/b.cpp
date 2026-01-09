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
    int n, k; cin >> n >> k;
    vi v(n);
    FO(i,n) cin >> v[i];

    vector<int> exists(n + 2, false);

    FO(i, n){
        if(v[i] <= n) exists[v[i]] = true;
    }

    int mex = 0;
    while(exists[mex]) mex++;

    cout << min(mex, k - 1) << endl;
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
