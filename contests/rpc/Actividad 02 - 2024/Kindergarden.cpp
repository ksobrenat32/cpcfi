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
    string s; cin >> s;
    int n = sz(s);
    int zero = 0, one = 0, two = 0;

    FO(i,n){
        if(s[i] == '0'){
            zero++;
        } else if(s[i] == '1'){
            one++;
        } else {
            two++;
        }
    }

    // Last position
    int last_pos = 0;
    int cnt = zero;
    char tmp;

    ll moves = 0;

    // Get all zeros at the start
    while(cnt > 0){
        // If this one is already correct
        if(s[last_pos] == '0'){
            last_pos++;
            cnt--;
            continue;
        }

        // If not correct
        FOR(i,last_pos,n){
            // If not a zero, continue
            if(s[i] != '0'){
               continue;
            } 
            // If 0 found, move it
            else {
                for(int j = i; j > last_pos; j--){
                    tmp = s[j-1];
                    s[j-1] = s[j];
                    s[j] = tmp;
                    moves++;
                }
                break;
            }
        }
    }

    last_pos = zero;
    cnt = one;

    // Get all ones at the start
    while(cnt > 0){
        // If this one is already correct
        if(s[last_pos] == '1'){
            last_pos++;
            cnt--;
            continue;
        }

        // If not correct
        FOR(i,last_pos,n){
            // If not a one, continue
            if(s[i] != '1'){
               continue;
            } 
            // If 1 found, move it
            else {
                for(int j = i; j > last_pos; j--){
                    tmp = s[j-1];
                    s[j-1] = s[j];
                    s[j] = tmp;
                    moves++;
                }
                break;
            }
        }
    }

    cout << moves << endl;
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