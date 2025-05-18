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
// https://codeforces.com/problemset/problem/2108/C

inline void solve(){
    int n;
    cin >> n;

    vll a(n);
    FO(i,n){
        cin>>a[i];
    }

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    // We always have at least one clone
    int clones = 1;
    int i = 1;

    while(i < n){
        // going up
        while(i < n && a[i] >= a[i-1]){
            i++;
        }
        // going down
        while(i < n && a[i] <= a[i-1]){
            i++;
        }
        // going up again
        if(i < n){
            clones++;
        }
    }

    cout << clones << endl;
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
