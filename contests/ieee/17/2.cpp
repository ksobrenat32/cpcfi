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
// https://csacademy.com/ieeextreme17/task/long_lines/

inline void solve(){
    ll n, h0, a, c, q;

    cin >> n >> h0 >> a >> c >>q;

    vll h(n,0);

    h[0] = h0;

    // Build heights
    for(int i = 1; i<n; i++){
        h[i] = (((a*h[i-1])+c)%q);
    }

    ll cnt = 0;
    stack<ll> s;
    s.push(0);

    for(ll i=1; i<n; i++){
        cnt += s.size();
        while(! s.empty() && h[i] >= h[s.top()]){
            s.pop();
        }
        s.push(i);
    }

    cout << cnt << endl;
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
