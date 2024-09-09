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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/Expandiendo-el-negocio

bool isValid(vi &v, int x, int m){
    int stores = 1;
    int last = v[0];
    for(size_t i = 1; i < v.size(); i++){
        if(v[i] - last >= m){
            stores++;
            last = v[i];
            if(stores == x){
                return true;
            }
        }
    }
    return false;
}

int max_distance(vi &v, int x){
    int n = v.size();
    int l = 0;
    int r = v[n - 1] - v[0];
    int m;
    int res = 0;

    // With binary search on the answer
    while (l <= r) {
        m = (l+r) / 2;

        if(isValid(v,x,m)){
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

inline void solve(){
    int n; cin >> n;
    vi v(n);
    FO(i,n){
        cin >> v[i];
    }
    int m; cin >> m;

    sort(all(v));

    cout << max_distance(v, m) << endl;
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
