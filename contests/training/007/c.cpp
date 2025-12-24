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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

inline void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<ld>> prob(n, vector<ld> (n));

    FO(i,n){
        FO(j,n){
            cin >> prob[i][j];
        }
    }

    vector<ld> old(n,0);
    old[0] = 1;

    FO(rep , m){
        vector<ld> nw(n,0);
        FO(i, n){
            FO(j, n){
                nw[j] += prob[i][j] * old[i];
            }
        }
        old = nw;
    }

    TR(x, old){
        cout << x << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
