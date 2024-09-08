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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/tablero-simple

// Based on the formula for the sum of squares:
ll square_counting(int n){
    ll res = 0;
    FOR(i,1,n+1){
        res += (n - i + 1) * (n - i + 1);
    }
    return res;
}

// Based on the formula for the sum of rectangles (combinatory logic):
// We need to remember that the sum of the first n natural numbers is n * (n + 1) / 2
// So, if we want to calculate the sum of the first n squares, we can use the formula.
ll rectangle_counting(int n){
    ll l = n;
    return (l * (l + 1) / 2) * (l * (l + 1) / 2);;
}

inline void solve(){
    string s;
    int n;
    while(getline(cin, s)) {
        n = stoi(s);
        cout << square_counting(n) << " " << rectangle_counting(n) << endl;
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
