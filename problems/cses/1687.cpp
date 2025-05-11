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
// https://cses.fi/problemset/task/1687

inline void solve(){
    int n,q; cin >> n >> q;
    int t;
    vi v(n+1);

    // Vector for binary lifting
    vector<vector<int>> f(n+1,vector<int> (n+1,0));

    // Read the array
    v[0] = 0;
    FOR(i,1,n+1){
        cin >> t;
        v[i] = t;
    }

    // Make binary lifting ancestors
    FOR(i,1,n+1){

    }

    int x,k;
    FO(i,q){
        cin >> x >> k;
        t = x;

        // This was O(n)
        //while(k--){
            //t = v[t];
            //if(t == 0){
                //cout << -1 << endl;
                //goto exit;
            //}
        //}
        //cout << t << endl;
        //exit:;

        // Using binary lifting to make it faster
        while(k > 0){

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
