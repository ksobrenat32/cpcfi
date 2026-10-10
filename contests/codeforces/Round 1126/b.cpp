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
    int n, k; cin >> n >> k;

    int t;
    multiset<int> ms;
    FO(i, n){
        cin >> t;
        ms.insert(t);
    }
    t = *ms.rbegin();

    for(int i = 0; i <= t; i++){
        int num = ms.count(i);

        // If it can not satisfy mex for both, Bob wins
        if(num <= (k*2)-2){
            cout << "NO" << endl;
            return;
        } else if(num == (k*2) -1){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
