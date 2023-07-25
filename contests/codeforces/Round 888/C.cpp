#include <bits/stdc++.h>
#include <map>
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
// https://codeforces.com/contest/1851/problem/C

inline void solve(){
    int n,k;
    cin >> n >> k;
    vi c(n);
    map<int, int> cn;

    FO(i,n){
        cin >> c[i];
        cn[c[i]]++;
    }

    if(c[0] == c[n-1]){
        if(cn[c[0]] >= k){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        // Complete c[0]
        int t = k;
        if(cn[c[0]] >= k){
            FO(i,n){
                if(c[i] == c[0]){
                    t--;
                }
                cn[c[i]]--;
                if(t == 0){
                    break;
                }
            }

            if(cn[c[n-1]] >= k){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

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
