#include <bits/stdc++.h>
using namespace std;

#define endl                        '\n'
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& v : (arr))
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end()
#define sz(x)                       (int) x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// cout << setprecision(11);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://codeforces.com/contest/863/problem/B

inline void solve(){
    int n;

    cin >> n;
    n *= 2;

    vi w(n);

    FO(i,n){
        cin >> w[i];
    }
    sort(all(w));

    int res = INF;

    // remove 2 elements and instablity
    FOR(i,0,n){
        FOR(j,i+1,n){
            // remove i and j
            vi v;
            FOR(k,0,n){
                if(k != i && k != j){
                    v.pb(w[k]);
                }
            }

            // pair the remaining elements
            int instability = 0;
            for (size_t k = 0; k < v.size(); k += 2) {
                instability += abs(v[k] - v[k + 1]);
            }

            // update the result
            res = min(res, instability);
        }
    }

    cout << res << endl;
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
