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
typedef vector<ull> vull;

inline void solve(){
    ull n;
    cin >> n;
    
    vull a(n);
    vull b(n);

    FO(i,n) cin >> a[i];

    // Does not matter because b1 = ai
    FO(i,n) cin >> b[i];

    ull cnt = 0;

    ull g1, g2;

    // Left edge
    g1 = gcd(a[0], a[1]);
    if(g1 < a[0]) cnt++;

    // Right edge
    g1 = gcd(a[n-2], a[n-1]);
    if(g1 < a[n-1]) cnt++;
    
    // Avoid edges
    for(int i = 1; i<n-1; i++){
        g1 = gcd(a[i-1], a[i]);
        g2 = gcd(a[i], a[i+1]);

        if(lcm(g1, g2) < a[i]) cnt++;
    }

    cout << cnt << endl;
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
