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
// https://codeforces.com/contest/1851/problem/B

inline void solve(){
    int n;
    cin >> n;
    vll a(n);
    vll even;
    vll odd;
    vll res;

    FO(i,n){
        cin >> a[i];
        if(a[i]%2 == 0){
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }

    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());

    int oddI = 0;
    int evenI = 0;

    FO(i,n){
        if(a[i]%2 == 0){
            res.push_back(even[evenI]);
            evenI++;
        } else {
            res.push_back(odd[oddI]);
            oddI++;
        }
    }

    FOR(i,1,n){
        if(res[i-1] > res[i]){
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
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
