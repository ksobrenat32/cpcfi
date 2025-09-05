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
// https://cses.fi/problemset/task/1640

inline void solve(){
    int n, w, t; 
    cin >> n >> w;
    map<int, vi> m;

    FO(i,n){
        cin >> t;
        m[t].push_back(i+1);
    }

    int s;
    int p1, p2;
    TR(x, m){
        s = w - x.first;
        if(m.find(s) != m.end()){
            // Get the first position
            FO(i, sz(x.second)){
                p1 = x.second[i];
                FO(j, sz(m[s])){
                    p2 = m[s][j];
                    if(p1 != p2){
                        cout << p1 << " " << p2 << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
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
