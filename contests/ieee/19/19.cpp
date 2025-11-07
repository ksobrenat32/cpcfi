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

const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;

const int CONVERSION_F = 212;
const int MAX_U = MAX_N * CONVERSION_F;

// Egyptian currency denominations in Piastres
// Simplified denominations, you can form original by multiplying by 25
vll denominations = {1, 2, 4, 20, 40, 80, 200, 400, 800};
vll dp(MAX_U + 1, 0);

void init(){
    dp[0] = 1;
    FOR(i, 1, MAX_U + 1){
        TR(c, denominations){
            if (i >= c) {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }
}

inline void solve(){
    int T;
    cin >> T;

    while (T--) {
        ll n, m, a;
        cin >> n >> m >> a;

        ll tu = n * CONVERSION_F;
        ll r = dp[tu];

        if (r == m && r == a) {
            cout << "TIE" << endl;
        } else {
            ll dm = min((r - m + MOD) % MOD, (m - r + MOD) % MOD);
            ll da = min((r - a + MOD) % MOD, (a - r + MOD) % MOD);

            if (dm < da) {
                cout << "Mikel" << endl;
            } else if (da < dm) {
                cout << "Andrew" << endl;
            } else {
                cout << "NONE" << endl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();

    return 0;
}
