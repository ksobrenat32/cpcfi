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

// 7
// (7*0.9) + (0.1* 77)


inline void solve(){
    string s; cin >> s;
    
    long double v = s[0]-'0';
    long double t;
    long double n;

    for(int i = 1; i<sz(s); i++){
        cout << i << " : " << v << endl;
        t = s[i] - '0';
        v = (v * 0.9) + (0.1 *((10 * v) +t));
    }

    cout << v << endl;
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
