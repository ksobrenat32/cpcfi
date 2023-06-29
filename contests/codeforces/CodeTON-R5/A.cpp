// Problem link:
// https://codeforces.com/contest/1842/problem/0

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& (v) : (arr))
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


inline void solve(){
    int n, m;
    cin >> n >> m;
    long long ts = 0;
    long long te = 0;
    long long tmp;

    FO(i,n){
        cin >> tmp;
        ts += tmp;
    }

    FO(i,m){
        cin >> tmp;
        te += tmp;
    }

    if(ts > te){
        cout << "Tsondu" << endl;
    } else if (te > ts){
        cout << "Tenzing" << endl;
    } else {
        cout << "Draw" << endl;
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
