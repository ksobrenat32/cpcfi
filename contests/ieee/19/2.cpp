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

inline void solve(){
    ll n; cin >> n;
    if(n&1){
        cout << -1 << "\n";
        return;
    }
    // If power of 2
    if((n & (n - 1)) == 0){
        cout << -1 << "\n";
        return;
    }

    ll a,b,c;
    for(ll i = 1; i < n/2; i<<=1){
        a = (n/2) - i;
        b = (n/2);
        c = n + i;
        if((a+b+c == n*2) && ((a^b^c) == n) && (a != b) && (b != c) && (c != a)){
            cout << a << " " << b << " " << c << endl;
            return;
        }
    }
    cout << -1 << "\n";
}

int main(){
    // C++ speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
