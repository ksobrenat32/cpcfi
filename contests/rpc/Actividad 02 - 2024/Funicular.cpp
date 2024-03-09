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

inline void solve(){
    ll n, c;
    cin >> n >> c;

    vll v(n);
    FO(i,n){
        cin >> v[i];
    }

    // Only imposible is if the first one uses all hours
    if( (v[0] / c) >= n){
        cout << "impossible" << endl;
        return;
    }

    // Result <time, position>
    pair<ll,ll> r = mp(INF, -1);
    ll people = 0;
    ll time = 0;

    FOR(i,0,n){
        people += v[i];
        time = floor(people / double(c));
        
        // If more time than remaining, stop
        if(time > n-(i+1)){
            break;
        }

        // Negatives are not needed
        if(time <= 0){
            time = 0;
        }

        // Get the smallest
        if(time < r.first){
            r.first = time;
            r.second = i;
        }

        // Found the smallest
        if(time == 0){
            break;
        }

        people -= c;
    }

    cout << r.second << endl;
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
