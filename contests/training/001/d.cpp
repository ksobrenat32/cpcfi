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
    string s; int k;
    cin >> s;
    cin >> k;

    string res = "";
    ll cnt = 0;
    ll t = 0, j = 0;
    int n = sz(s);

    FO(i, n){
        if(s[i] >= '0' && s[i] <= '9'){
            j = i;
            while(s[j+1] >= '0' && s[j+1] <= '9' && j < n){
                j++;
            }
            if(j-i+1 > 6){
                cout << "unfeasible" << endl;
                return;
            }
            t = stoi(s.substr(i, j-i+1));
            
            if(cnt > k){
                cout << "unfeasible" << endl;
                return;
            }
            
            FO(k,t){
                res += s[j+1];
                cnt ++;
            }
            i = j+1;
        } else {
            res += s[i];
            cnt ++;
        }
    }

    if(cnt > k){
        cout << "unfeasible" << endl;
        return;
    }

    cout << res << endl;
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
