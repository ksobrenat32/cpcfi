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
// https://codeforces.com/problemset/problem/455/A

inline void solve(){
    int n;
    cin >> n;

    vi v(n);

    // Save max value
    vll memo(1e6,0);
    // Save times
    vll times(1e6,0); 
    
    FO(i,n){
        cin >> v[i];
        times[v[i]]++;
    }

    // In case of number one
    memo[1] = times[1];

    FOR(i,2,1e6){
        // two cases, or we take the number or we dont, we compare it an make the sum
        if(memo[i-1] > memo[i-2] + i * times[i]){
            // Not taking it is better
            memo[i] = memo[i-1];
        } else {
            // Taking this number
            memo[i] = memo[i-2] + i * times[i];
        }
    }

    cout << memo[1e6 - 1] << endl;
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
