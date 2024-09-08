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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/Accidente

inline void solve(){
    string s;
    while(getline(cin, s)) {
        int in = 0;
        int out = 0;
        int people = 0;

        FO(i,sz(s)){
            if(s[i] == '+'){
                // If no one was out
                if(out == 0){
                    // Is someone not registered
                    people++;
                }// else is the same client entering so we erase the exit
                else{
                    out--;
                }
                // There is another one inside
                in++;
            } else {
                // If no one was inside, he was before
                if(in == 0){
                    people++;
                } // Else it was a client we already considered
                else{
                    in--;
                }
                out++;
            }
            //cout << "P: " << s[i] << " " << people << endl;
        }

        cout << people << endl;
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