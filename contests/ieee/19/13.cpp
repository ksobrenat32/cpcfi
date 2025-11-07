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

const ll MOD = 998244353;

// Get binary exponentiation with modulo
ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Modular inverse using Fermat's little theorem
ll modInv(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

inline void solve() {
    ll n, m; cin >> n >> m;
    
    map<ll, ll> counts;
    ll current_sum = 0;
    ll s;

    FO(i, n) {
        cin >> s;
        // count the number of occurrences of each element, this will help to 
        counts[s]++;
        current_sum = (current_sum + s) % MOD;
    }

    // S looks like:
    // S = (A*S_0 + B) / (C*S_0 + D)

    // Initial state: S_new = S_0 = (1*S_0 + 0) / (0*S_0 + 1)
    ll A = 1, B = 0, C = 0, D = 1;
    ll x;
    int t;

    // Recalculation vars
    ll numerator;
    ll lp, rp, po, tn;

    FO(i, m) {
        cin >> t;

        if (t == 1) {
            cin >> x;
            x %= MOD;

            A = (A + (x * C) % MOD) % MOD;
            B = (B + (x * D) % MOD) % MOD;
            
            // New sum
            current_sum = (current_sum + (n * x) % MOD) % MOD;
        } else { 
            // When inverting, we have:
            // S_new = 1 / S_old
            // Thus:
            // A_new = C_old
            // B_new = D_old
            // C_new = A_old
            // D_new = B_old
            swap(A, C);
            swap(B, D);

            // Recalculate all sum
            int k = sz(counts);

            // n=0 case
            if(k == 0) {
                current_sum = 0;
                cout << 0 << endl;
                continue;
            }

            // Precompute P_i and Q_i
            vector<ll> P(k), Q(k);
            int idx = 0;
            TR(p, counts){
                P[idx] = (p.S * ((A * p.F)%MOD + B)) % MOD;
                Q[idx] = ((C * p.F)%MOD + D) % MOD;
                idx++;
            }

            // Precompute prefix and suffix products of Q
            vector<ll> prefix_prod_Q(k), suffix_prod_Q(k);
            prefix_prod_Q[0] = Q[0];
            FOR(j, 1, k) {
                // Compute prefix product
                prefix_prod_Q[j] = (prefix_prod_Q[j - 1] * Q[j]) % MOD;
            }
            suffix_prod_Q[k - 1] = Q[k - 1];
            rFOR(j, k - 2, -1) {
                // Compute suffix product
                suffix_prod_Q[j] = (suffix_prod_Q[j + 1] * Q[j]) % MOD;
            }

            numerator = 0;
            
            FO(i, k){
                if(i==0){
                    lp = 1;
                } else {
                    lp = prefix_prod_Q[i-1];
                }

                if(i==k-1){
                    rp = 1;
                } else {
                    rp = suffix_prod_Q[i+1];
                }

                po = (lp * rp) % MOD;
                tn = (P[i] * po) % MOD;

                numerator = (numerator + tn) % MOD;
            }

            current_sum = (numerator * modInv(prefix_prod_Q[k-1], MOD)) % MOD;
        }
        
        cout << (current_sum + MOD) % MOD << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    FO(tc, T) {
        solve();
    }
    return 0;
}
