#include <bits/stdc++.h>
#include <set>
using namespace std;

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
// https://codeforces.com/problemset/problem/520/A

inline void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    TR(c, s){
        st.insert(c);
    }

    if(st.size() == 26){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
