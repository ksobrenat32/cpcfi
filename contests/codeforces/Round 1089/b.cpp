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

// If pi <= i then you should sit
// If pi > i then you should decide:
// If sit, the limit will be on pi
// If not sit, the limit is still on n;

inline void solve(){
    int n;
    cin >> n;

    vi p(n+1,0);
    for(int i=1;i<=n;i++) cin >> p[i];

    // Count free chairs
    int cnt = 0;
    for(int i=1;i<=n;i++){
        // If chair was already back, we can freely take it
        // We should never take a chair that will limit the max place
        // because we are now blocked from at least 1 chair in the future
        // (but most times more than one)
        if(p[i] <= i){
            cnt++;
        }
    }

    cout << cnt << endl;
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
