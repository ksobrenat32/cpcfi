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
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// cout << setprecision(11);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://codeforces.com/contest/2118/problem/C

// Beauty calculation
int beauty(ll x) {
    return __builtin_popcountll(x);
}

// Find cost to next beauty level
ull next_cost(ll x) {
    for (int i = 0; i < 64; ++i) {
        if (((x >> i) & 1) == 0) {
            ll want = x | (1ULL << i);
            return want - x;
        }
    }
    return ULLONG_MAX;
}

void solve() {
    int n;
    cin >> n;
    ull k;
    cin >> k;

    vector<ll> a(n);
    // (cost, index)
    priority_queue<pair<ull, int>, vector<pair<ull, int>>, greater<>> pq;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pq.push({next_cost(a[i]), i});
    }

    while (k > 0 && !pq.empty()) {
        pair<ull, int> x = pq.top();
        if (x.F > k) break; // We do not have enough
        
        pq.pop();
        k -= x.F;
        a[x.S] += x.F;
        pq.push({next_cost(a[x.S]), x.S});
    }

    ll res = 0;
    for (ll x : a){
        res += beauty(x);
        //cout << x << " ";
    }
    //cout << endl;
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
