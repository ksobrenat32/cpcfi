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
// https://codeforces.com/contest/1931/problem/C

inline void solve(){
    int n; cin >> n;
    vi a(n);

    FO(i,n){
        cin >> a[i];
    }

    int beg = a[0];
    int end = a[n-1];
    int strt = 0;
    int fnsh = 0;

    for(strt = 0; strt < n; strt++){
        if(a[strt] != beg){
            break;
        }
    }

    // If all the same
    if(strt == n){
        cout << 0 << endl;
        return;
    }

    reverse(all(a));

    for(fnsh = 0; fnsh < n; fnsh++){
        if(a[fnsh] != end){
            break;
        }
    }

    if(beg == end){
        cout << n - (strt + fnsh) << endl;
    } else {
        cout << min(n-fnsh, n-strt) << endl;
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
