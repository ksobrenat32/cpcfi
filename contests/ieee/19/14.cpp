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

inline void solve(){
    ll n, k; cin >> n >> k;

    vector<ll> a(n,0);
    FO(i, n-1) cin >> a[i+1];

    ll cgcd = 0;
    FOR(i, 1, n) {
        if (a[i] != 0) {
            if (cgcd == 0) {
                cgcd = a[i] * 2;
            } else {
                cgcd = __gcd(cgcd, a[i] * 2);
            }
        }
    }

    int Q; cin >> Q;
    FO(i, Q) {
        int x, y; cin >> x >> y;
        ll z = k - (a[x] + a[y]);
        if(z < 0) {
            cout << "No" << endl;
            continue;
        }

        if(cgcd == 0) {
            if (z == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            if (z % cgcd == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
