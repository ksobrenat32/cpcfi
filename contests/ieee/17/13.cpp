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
// https://csacademy.com/ieeextreme17/task/resaturant_cipher/

inline void solve(){
    vi v(7,0);
    string t;
    
    getline(cin, t);
    FO(i, sz(t)){
        if(t[i]-97 < 7 && t[i]-97 >= 0){
            v[t[i]-97] += 1;
        }
    }

    int mx = 0;
    FO(i, 7){
        if(v[i] > v[mx]){
            mx = i;
        }
    }

    cout << char(mx + 65) << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    cin.ignore();
    FO(tc,T){
        solve();
    }
    return 0;
}
