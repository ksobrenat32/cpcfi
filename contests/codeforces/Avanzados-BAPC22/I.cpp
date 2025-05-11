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
// https://codeforces.com/group/EWiQAOHvVn/contest/606973/problem/I

inline void solve(){
    int n, q;
    cin >> n >> q;

    map<string, map<string, pair<double, double>>> s;

    string u1, u2;
    double v1, v2;
    string t;

    FO(i, n){
        // v1 u1 = v2 u2
        cin >> v1;
        cin >> u1;
        cin >> t;
        cin >> v2;
        cin >> u2;



        // For each old conversion, we need to add the new conversion
        s[u1][u2] = mp(v1, v2);
        s[u2][u1] = mp(v2, v1);
    }

    double d;
    FO(i,q){
        cin >> d;
        cin >> u1;
        cin >> t;
        cin >> u2;


        if (s[u1].count(u2)){
            cout << "impossible" << endl;
        } else {
            cout << fixed << setprecision(10);
            cout << (d * s[u1][u2].F) / s[u1][u2].S << endl;
        }
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
