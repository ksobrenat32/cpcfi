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
// https://cses.fi/problemset/task/1628

void subsetRecur(int i, const vector<ll>& arr, vector<ll>& res, ll sum) {
    if (i == arr.size()) {
        res.push_back(sum);
        return;
    }
    subsetRecur(i+1, arr, res, sum);            // exclude arr[i]
    subsetRecur(i+1, arr, res, sum + arr[i]);   // include arr[i]
}

vector<ll> sumSubsets(const vector<ll>& arr){
    vector<ll> res;
    subsetRecur(0, arr, res, 0);
    return res;
}

inline void solve(){
    ll n, x; 
    cin >> n >> x;
    vll a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vll a1(a.begin(), a.begin() + n/2);
    vll a2(a.begin() + n/2, a.end());

    vector<ll> s1 = sumSubsets(a1);
    vector<ll> s2 = sumSubsets(a2);

    sort(s2.begin(), s2.end());

    ll cnt = 0;
    for (ll v : s1) {
        ll need = x - v;
        cnt += upper_bound(s2.begin(), s2.end(), need) - lower_bound(s2.begin(), s2.end(), need);
    }

    cout << cnt << endl;
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
