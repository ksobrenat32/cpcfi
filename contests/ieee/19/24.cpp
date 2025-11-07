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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

string build(multiset<int>& ms) {
    // Base case
    if(ms.empty()) return "";

    // Remove the largest element
    int largest = *ms.rbegin();
    ms.erase(prev(ms.end()));

    int needed = largest / 2;

    if(sz(ms) < needed) {
        return "No";
    }

    // Create the inner string
    multiset<int> inner_ms;
    for(int i = 0; i < needed; i++) {
        auto val = ms.rbegin();
        // Find the largest element that can go inside
        while(val != ms.rend() && *val > largest-2) {
            ++val;
        }
        if(val == ms.rend()) {
            return "No";
        }

        // Move the largest needed elements to the inner multiset
        inner_ms.insert(*val);
        ms.erase(prev(val.base()));
    }

    string missing = build(ms);
    if(missing == "No") {
        return "No";
    }

    string inner = build(inner_ms);
    if(inner == "No") {
        return "No";
    }

    return "(" + inner + ")" + missing;
}

inline void solve(){
    int n; cin >> n;
    int t;

    multiset<int> ms;
    bool possible = true;
    FO(i, n){
        cin >> t;
        ms.insert(t);

        if(t%2 != 0){
            possible = false;
        }
    }

    if(!possible){
        cout << "No" << endl;
        return;
    }
    
    string res = build(ms);
    if(res == "No") {
        cout << res << endl;
        return;
    } else {
        cout << "Yes" << endl;
        cout << res << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
