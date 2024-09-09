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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/xor-array

inline void solve(){
    int n;
    cin>>n;
    while(n != 0){
        vi v(n);
        vi r(n);
        FO(i,n){
            cin>>v[i];
        }

        // Undo the XOR operation
        r[0] = v[0];
        FOR(i,1,n){
            r[i] = v[i] ^ v[i-1];
        }

        FO(i,n){
            cout<<r[i]<<" ";
        }
        cout << endl;

        cin >> n;
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
