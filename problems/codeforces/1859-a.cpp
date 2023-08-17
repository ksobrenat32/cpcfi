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
// https://codeforces.com/problemset/problem/1859/a

inline void solve(){
    int n; cin >> n;
    vll v(n);

    FO(i,n){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    if(v[0] == v[n-1]){
        cout << -1 << endl;
        return;
    }

    int repeated = 1;

    FOR(i,1,n){
        if(v[i-1] == v[i]){
            repeated++;
        } else {
            break;
        }
    }

    cout << repeated << " " << n-repeated << endl;
    FO(i,repeated){
        cout << v[0] << " ";
    }
    cout << endl;
    FOR(i,repeated,n){
        cout << v[i] << " ";
    }
    cout << endl;
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
