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
    string s1;
    string s2;

    cin >> s1 >> s2;

    if(s1 == s2){
        cout <<  "=" << endl;
        return;
    }

    int i = 0, j = 0;
    while(i < sz(s1) && j < sz(s2)){
        if(isdigit(s1[i]) && isdigit(s2[j])){
            string t1 = "", t2 = "";

            while(i < sz(s1) && isdigit(s1[i])) t1 += s1[i++];
            while(j < sz(s2) && isdigit(s2[j])) t2 += s2[j++];

            if(sz(t1) != sz(t2)){
                if(sz(t1) > sz(t2)){
                    cout << ">" << endl;
                } else {
                    cout << "<" << endl;
                }
                return;
            }

            if(t1 != t2){
                if(t1 > t2){
                    cout << ">" << endl;
                } else {
                    cout << "<" << endl;
                }
                return;
            }
        }
        else{
            if(s1[i] != s2[j]){
                if(s1[i] > s2[j]){
                    cout << ">" << endl;
                } else {
                    cout << "<" << endl;
                }
                return;
            }
            i++; j++;
        }
    }

    if(i < sz(s1)) cout << ">" << endl;
    else if(j < sz(s2)) cout << "<" << endl;
    else cout << "=" << endl;
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
