#include <bits/stdc++.h>
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
// https://codeforces.com/problemset/problem/208/A

inline void solve(){
    string s,r;
    cin >> s;
    FO(i,sz(s)){
        if(s.substr(i,3) == "WUB"){
            i+=2;
            if( r.empty() ){
                continue;
            }
            if(r[sz(r)-1] == ' '){
                continue;
            }
            r += ' ';
        } else {
            r += s[i];
        }
    }

    cout << r << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
