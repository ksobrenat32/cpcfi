#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;
const ll MOD = 1e9 + 7;

inline void solve(){
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    int cnt = 0;
    vector<int> flip(n + 1, 0);
    int current_flips = 0;

    for(int i = 0; i < n; i++){
        current_flips += flip[i];
        if(current_flips % 2 == 1){
            if(s[i] == 'S'){
                s[i] = 'H';
            } else {
                s[i] = 'S';
            }
        }
        
        if(s[i] == 'S'){
            // Need to flip
            if(i + k > n){
                cout << -1 << "\n";
                return;
            }
            flip[i]++;
            flip[i + k]--;
            current_flips++;
            cnt++;
        }
    }
    
    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
