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

const ll MOD = (1e9) + 7;
const ll MAX = 1e6;
array<ll, MAX> fact;
array<ll, MAX> i_fact;

ll binpow(ll a, ll b){
    ll arns = 1;
    a%=MOD;
    while(b>0){
        if(b&1)
           arns = (arns*a)%MOD;
        a = (a*a)%MOD;
        b>>=1; 
    }
    return arns;
}
 
ll modInv(ll a, ll m=MOD){
    return binpow(a,MOD-2);
}
 
void factorial(){
    fact[0] = fact[1] = 1;
    for(int i=2; i<MAX; i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }
 
    i_fact[MAX-1] = modInv(fact[MAX-1]);
    for(int i=MAX-2; i>=0; i--){
        i_fact[i] = (i_fact[i+1]*(i+1))%MOD;
    }
 
}
 
ll bn_coef(ll n, ll k){
    return fact[n] * i_fact[n-k]%MOD *i_fact[k]%MOD;
}

inline void solve(){
    ll n; cin >> n;
    cout << bn_coef((2*n)-1, n) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    factorial();

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
