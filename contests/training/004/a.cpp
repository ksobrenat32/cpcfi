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
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> e(m);

    FO(i,n){
        cin >> a[i];
    }
    FO(i,m){
        cin >> e[i];
    }

    // Compress e
    vector<ll> ce;
    ll last;
    last = e[0];
    ce.push_back(last);
    FOR(i, 1 ,m){
        if(e[i] < last){
            last = e[i];
            ce.push_back(last);
        }
    }
    int sce = ce.size();
    int x, l, r, mid, p;

    FO(i,n){
        ll rmn = a[i];

        x = -1;

        while(rmn > 0){
            l = x+1;
            r = sce-1;
            p = -1;

            while(l <= r){
                mid = (l+r) / 2;
                if(ce[mid] <= rmn){
                    p = mid;
                    r = mid -1;
                } else {
                    l = mid +1;
                }
            }

            if(p == -1) break;
            rmn = rmn % ce[p];
            x = p;
        }
        
        cout << rmn << endl;
    }
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
