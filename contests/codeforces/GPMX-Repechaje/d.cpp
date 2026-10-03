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
    int n, k;
    cin >> n >> k;

    set<ll> s;
    ll t;
    FO(i, n){
        cin >> t;
        s.insert(t);
    }

    ll mx = 0;
    for (ll i = 0; i < n; i++){
        // If it was not found, check if we have k left
        if(s.find(i) == s.end()){
            // if no k left, i is the max
            if(k <= 0){
                mx = i;
                break;
            }
            // If k left, add the number
            else {
                s.insert(i);
                k--;
            }
        }
        mx = i + 1;
    }

    cout << mx << endl;
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


