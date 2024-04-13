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
// https://codeforces.com/contest/1956/problem/C

void print_perm(int n){
    FO(i,n){
        cout << i+1 << " ";
    }
    cout << endl;
}

inline void solve(){
    int n; cin >> n;

    // Calculate sum
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += i * ((2*i) - 1);
    }

    // Number of operators
    int m = (2*n) - 1;

    cout << s << " " << m << endl;

    for(int i = n; i > 1; i--){
        cout << "2 " << i << " ";
        print_perm(n);
        cout << "1 " << i-1 << " ";
        print_perm(n);
    }
    cout << "2 " << 1 << " ";
    print_perm(n);
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
