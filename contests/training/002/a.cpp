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
// https://codeforces.com/group/kpNr48xCia/contest/615822/problem/A

ll a, b, c, l, r;

// this evaluation is res/6
ll eval(ll x){
    return ((2 * a * x*x*x) + (3 * b * x*x) + (6 * c * x));
}

ll integral(ll l, ll r){
    return abs(eval(r) - eval(l));
}

ll gcd ( ll a , ll b ) {
    if ( b == 0) return a ;
    return gcd (b , a % b ) ;
}

inline void solve(){
    cin >> a >> b >> c >> l >> r;

    // get roots
    ll root1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    ll root2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);

    // Order roots
    if (root1 > root2) swap(root1, root2);

    ll res = 0;

    // No root
    if((root1 < l || r < root1) && (root2 < l || r < root2)){
        res = integral(l, r);
    }
    // Root 1
    else if(root2 < l || r < root2) {
        res = integral(l, root1) + integral(root1, r);
    }
    // Root 2
    else if(root1 < l || r < root1) {
        res = integral(l, root2) + integral(root2, r);
    } 
    // Root 1 and 2 inside
    else {
        res = integral(l, root1) + integral(root1, root2) + integral(root2, r);
    }

    ll p = res;
    ll q = 6;
    ll g = gcd(p,q);
    
    while(g != 1){
        g = gcd(p,q);
        p /= g;
        q /= g;
    }

    cout << p << "/" << q << endl;
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
