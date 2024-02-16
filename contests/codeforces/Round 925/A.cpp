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
// https://codeforces.com/contest/1931/problem/A

char intToChar(int x){
    char c;
    c = (char)(x + 96);
    return c;
}

inline void solve(){
    int n; cin >> n;
    string s;

    if(n <= 28){
        s.push_back(intToChar(1));
        s.push_back(intToChar(1));
        n -= 2;
        s.push_back(intToChar(n));
    } else if (n < 53){
        s.push_back(intToChar(1));
        s.push_back(intToChar(26));
        n -= 27;
        s.push_back(intToChar(n));
    } else {
        s.push_back(intToChar(26));
        s.push_back(intToChar(26));
        n -= 52;
        s.push_back(intToChar(n));
    }

    sort(all(s));
    cout << s << endl;
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
