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
// https://codeforces.com/group/kpNr48xCia/contest/615151/problem/I

inline void solve(){
    int a, b, c, r;
    cin >> a >> b >> c;
    r = a + b + c;
    vi res;

    res.push_back(r);
    if(a >= 500 && b >= 500 && c >=500){
        res.push_back(a + b + c - 300);
    }
    
    if ((a + b) >= 500){
        if (c >= 500){
            res.push_back(r-200);
        }
    }
    
    if ((a + c) >= 500){
        if (b >= 500){
            res.push_back(r-200);
        }
    }

    if ((b + c) >= 500){
        if (a >= 500){
            res.push_back(r-200);
        }
    }
    
    if ((a + b + c) >= 500){
        res.push_back(r-100);
    }
    
    int mn = 1e9;
    FO(i,sz(res)){
        mn = min(mn,res[i]);
    }


    cout << mn << endl;
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
