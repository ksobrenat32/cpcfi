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
    ll l, r;
    cin >> l >> r;

    ll cnt = 0;
    ll n = 1;
    set<ll> s;
    while(cnt < r){
        cnt += n++;
        if(cnt <= r){
            s.insert(cnt);
        }
    }

    ll total;
    if(s.find(l) != s.end()){
        total = (ll)distance(s.find(l), s.end());
    } else {
        total = (ll)distance(s.upper_bound(l), s.end());
    }

    cout << total << endl;
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

