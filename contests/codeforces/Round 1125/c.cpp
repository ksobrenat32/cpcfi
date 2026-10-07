#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

inline void solve(){
    int n; cin >> n;
    vector<int> a(n);
    FO(i,n) cin >> a[i];

    map<ll, vector<int>> m;
    ll t;

    // Get all the audience love calc
    for(int i = 0; i < n-4; i++){
        t = a[i] + a[i+2] - a[i+4];
        m[t].push_back(i);
    }

    // Calc answer
    ll r = 0;
    ll tr = 0;
    int val;
    TR(y, m){
        auto vec = y.second;
        // For each love, chech how many valid pairs
        if(vec.size() < 2) continue;
        for(int i = 0; i < vec.size(); i++){
            // Assuming the remaining pairs are valid
            tr = vec.size()-i-1;
            val = vec[i];


            // If I can find a val+2 or val+4 
            if(binary_search(all(vec), val+2)){
                tr--;
            }
            if(binary_search(all(vec), val+4)){
                tr--;
            }
            r += tr;
        }
    }

    cout << r << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}

