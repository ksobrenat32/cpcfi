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
// https://codeforces.com/contest/1881/problem/A

inline void solve(){
    int n,m;
    cin >> n >> m;

    string x,s;
    cin >> x >> s;

    int cnt = 0;

    if(m > n){
        while(sz(s) > sz(x)){
            x += x;
            cnt++;
        }
        if(x == s || x.find(s) != string::npos){
            cout << cnt << endl;
            return;
        } else {
            x += x;
            cnt++;
            if(x == s || x.find(s) != string::npos){
                cout << cnt << endl;
                return;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }


    do{
        if(x == s || x.find(s) != string::npos){
            cout << cnt << endl;
            return;
        }
        x += x;
        cnt++;
    } while (x.find(s) != string::npos);

    if( x == s || x.find(s) != string::npos){
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    FO(tc,T){
        //cout << "Case: " << tc + 1 << endl;
        solve();
    }
    return 0;
}
