#include <bits/stdc++.h>
#include <vector>
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
// https://codeforces.com/problemset/problem/141/A

inline void solve(){
    string g;
    string h;
    string p;

    cin >> g >> h >> p;

    vi v(26,0);

    TR(c,g){
        v[c-'A']++;
    }
    TR(c,h){
        v[c-'A']++;
    }
    TR(c,p){
        v[c-'A']--;
    }

    FO(i,26){
        if(v[i] != 0){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
