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
// https://csacademy.com/ieeextreme17/task/labradoodle/

bool canCreate(string s1, string s2, string r){
    int c = 0;
    int p = sz(r);

    FO(i,sz(r)-2){
        if(sz(s1) < i){
            break;
        }
        if(s1[i] != r[i]){
            break;
        } else {
            p -= 1;
            c++;
        }
    }

    if(p > sz(s2)){
        return false;
    }

    if(r.substr(sz(r)-p,p) == s2.substr(sz(s2)-p,p)){
        if( (p >= 3 && c >= 3) || (p >= 2 && c >= 3 ) || (p >= 3 && c >= 2)){
            return true;
        } else {
            return false;
        }
    } else{
        return false;
    }
}

inline void solve(){
    int n, m;
    cin >> n >> m;

    map<string, vector<string>> pre;
    map<string, vector<string>> pos;
    
    string t;

    FO(i,n){
        cin >> t;
        if(sz(t) >= 3){
            pre[t.substr(0,3)].push_back(t);
            pos[t.substr(t.size()-3,3)].push_back(t);
        }
    }

    string pe;
    string po;

    FO(i,m){
        cin >> t;

        if(sz(t) < 5 ){
            cout << "none" << endl;
            continue;
        }

        pe = t.substr(0,3);
        po = t.substr(t.size()-3,3);
        vector<pair<string, string>> v;

        if(sz(pre[pe]) == 0 || sz(pos[po]) == 0){
            cout << "none" << endl;
        } else {
            FO(j, sz(pre[pe])){
                FO(k, sz(pos[po])){
                    if(canCreate(pre[pe][j] , pos[po][k], t)){
                        v.push_back(make_pair(pre[pe][j], pos[po][k]));
                    }
                }
            }

            if(sz(v) == 1){
                cout << v[0].first << " " << v[0].second << endl; 
            } else if( sz(v) > 1){
                cout << "ambiguous" << endl;
            } else {
                cout << "none" << endl;
            }
        }
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
