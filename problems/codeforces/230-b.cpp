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
// https://codeforces.com/problemset/problem/230/B

bool prime(ll t){
    if(t==1){
        return false;
    }
    if(t==2){
        return true;
    }
    if(t%2 == 0){
        return false;
    } else {
        for(ll i=3; i*i <=t; i+=2){
            if((t%i)==0){
                return false;
            }
        }
    }
    return true;
}

inline void solve(){
    ll val;
    cin >> val;
    double sq = sqrt(val);

    if( ceil(sq) != sq && floor(sq) != sq){
        cout << "NO" << endl;
        return;
    }

    if(prime(sqrt(val))){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
