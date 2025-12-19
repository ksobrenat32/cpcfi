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
    int n; cin >> n;
    vll v(n);
    FO(i, n) cin >> v[i];

    multiset<ll> s;

    FO(i,n){
        auto it = s.upper_bound(v[i]);
        // Search an upper bound, the nearest
        if(it != s.end()){
            // If found an upper, delete it
            s.erase(it);
        }
        // Append it, either as a new tower or replacing the old one
        s.insert(v[i]);
    }

    cout << s.size() << endl;
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
