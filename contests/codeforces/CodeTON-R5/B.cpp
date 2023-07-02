#include <bits/stdc++.h>
using namespace std;

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
// https://codeforces.com/contest/1842/problem/B

bool posible(ll x, ll a){
    if(x < a){
        return false;
    }
 
    while(x != 0){
        if( (x%2 == a%2) || (x%2 == 1 && a%2 == 0)){
            x = x >> 1;
            a = a >> 1;
        } else {
            return false;
        }  
    }
 
    return true;
}

inline void solve(){
    int n; cin >> n;
    ll x,r=0; cin >> x;

    vll a(n);
    vll b(n);
    vll c(n);

    FO(i,n){
        cin >> a[i];
    }
    FO(i,n){
        cin >> b[i];
    }
    FO(i,n){
        cin >> c[i];
    }

    FO(i,n){
        if(posible(x,a[i])){
            r = r|a[i];
        } else {
            break;
        }
    }
    FO(i,n){
        if(posible(x,b[i])){
            r = r|b[i];
        } else {
            break;
        }
    }
    FO(i,n){
        if(posible(x,c[i])){
            r = r|c[i];
        } else {
            break;
        }
    }
    if(r == x){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
