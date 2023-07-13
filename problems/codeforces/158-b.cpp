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
// https://codeforces.com/problemset/problem/158/B

inline void solve(){
    int n,t; cin >> n;

    vi v(5,0);

    FO(i,n){
        cin >> t;
        v[t]++;
    }

    int cnt = 0;

    cnt += v[4];

    t = min(v[1],v[3]);
    cnt += t;
    v[1] -= t;
    v[3] -= t;
    cnt += v[3];

    cnt += v[2]/2;
    if(v[2]%2 != 0){
        cnt ++;
        v[1] -= 2;
    }

    if( v[1] > 0){
        cnt += ceil(double(v[1])/4);
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
