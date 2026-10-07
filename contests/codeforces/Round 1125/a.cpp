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
    ll x2, y2, r, tx, ty, tr, x, y;
    cin >> tx >> ty >> tr;

    r = tr * tr;
    set<ll> s;
    ll t = 0;

    while(t * t <= r){
        s.insert(t*t);
        t++;
    }

    // Search for a pair
    TR(v , s){
        if(s.find(r - v) != s.end()){
            x2 = v;
            y2 = r-v;
        }
    }

    x = (ll)sqrtl(x2);
    y = (ll)sqrtl(y2);


    cout << tx - x << " " << ty - y << endl;
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

