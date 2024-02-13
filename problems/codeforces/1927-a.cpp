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
// https://codeforces.com/problemset/problem/1927/A

inline void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int start = -1, end = -1;
    FO(i, n){
        if(s[i] == 'B'){
            start = i;
            break; 
        }
    }
    if(start == -1){
        cout << 0 << endl;
    }

    rFOR(i, n, -1){
        if(s[i] == 'B'){
            end = i;
            break; 
        }
    }

    if(start == end){
        cout << 1 << endl;
    } else {
        cout << end - start + 1 << endl;
    }

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
