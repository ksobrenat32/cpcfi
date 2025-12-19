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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

const ull MOD = (1e9)+7;

ull binpow(ull a, ull b, ull m) {
    if(b == 0) return 1;

    ull result = 1;
    while(b) {
        if (b & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result % m;
}

inline void solve(){
    ull a, b, c;
    cin >> a >> b >> c;

    ull x = binpow(b,c, MOD-1);
    ull y = binpow(a,x, MOD);

    cout << y << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
