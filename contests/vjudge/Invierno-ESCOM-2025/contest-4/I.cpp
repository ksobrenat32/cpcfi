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
// https://vjudge.net/contest/693191#problem/I

inline void solve(){
    int n; cin >> n;
    int q; cin >> q;

    vector<set<int>> v(n);

    // Fill the vector with ordered sets
    FO(i,n){
        v[i].insert(i+1);
    }

    string s;
    int a, b;
    FO(i,q){
        cin >> s;
        cin >> a >> b;
        a--;
        b--;
        // Union of sets to new set
        if(s == "UNION"){
            set<int> newSet;
            // Union of a and b
            set_union(all(v[a]), all(v[b]), inserter(newSet, newSet.begin()));
            v.pb(newSet);
            // Clear the old sets
            v[a].clear();
            v[b].clear();
        }
        // Get of smallest b smallest element indexed in a
        else if(s == "GET"){
            cout << *next(v[a].begin(), b) << endl;
        }
    }
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
