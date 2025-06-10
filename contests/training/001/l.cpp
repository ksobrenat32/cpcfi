#include <bits/stdc++.h>
using namespace std;

#define endl                        '\n'
#define FO(i, b)                    for (ll i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& v : (arr))
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end()
#define sz(x)                       (ll) x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// cout << setprecision(11);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://codeforces.com/group/kpNr48xCia/contest/615151/problem/L

inline void solve(){
    ll n;
    cin >> n;

    vector<string> v;
    ll p;
    string t;
    bool srch;
    bool x;

    FO(i,n){
        cin >> t;
        srch = true;
        FO(j,sz(v)){
            // Different size
            if(sz(t) != sz(v[j])){
                continue;
            }

            // For all the string
            FO(w, sz(t)){
                p = v[j].find(t[0], w);
                
                // first char found
                if(p != string::npos){
                    x = true;
                    FO(k,sz(t)){
                        // its different
                        if(t[k] != v[j][(p+k)%sz(t)]){
                            x = false;
                            break;
                        }
                    }
                    if(x){
                        // found same
                        srch = false;
                        break;
                    }
                }
            }
        }
        // No same found
        if(srch){
            v.push_back(t);
        }
    }

    /*
    FO(i, sz(v)){
        cout << v[i] << endl;
    }
    */

    cout << sz(v) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
