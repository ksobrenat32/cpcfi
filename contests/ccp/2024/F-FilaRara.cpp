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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/ccp24-fila-rara

inline void solve(){
    int n; cin >> n;
    string a,b;
    map<string,int> cnt;
    map<string,string> relations;

    FO(i,n-1){
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
        relations[a] = b;
    }

    // Get the first and last element
    string name = "";
    for(auto& [k,v]: cnt){
        // If it appears only one
        if(v == 1){
            // If it has a sucesor
            if(relations[k] != ""){
                name = k;
                break;
            }
        }
    }

    vector<string> ans;
    FO(i,n){
        ans.pb(name);
        name = relations[name];
    }

    reverse(all(ans));
    FO(i,n){
        cout << ans[i] << endl;
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
