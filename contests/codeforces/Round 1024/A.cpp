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
// https://codeforces.com/contest/2102/problem/0

inline void solve(){
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    // n: size of the array
    // m: sum of the array
    // p: size of the subarray
    // q: sum of the subarray

    // If we have leftover, we can always make it
    if (n % p != 0) {
        cout << "YES" << endl;
    } else {
        // If no leftover, checck the condition
        if(m == (n/p) * q){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    FO(tc,T){
        //cout << "Case #" << tc + 1 << ": ";
        solve();
    }
    return 0;
}
