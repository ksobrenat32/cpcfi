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

ll max_prefix = 0;

class Node {
public:
    ll cnt = 0;
    Node* tails[26] = {};

    void insert(string &s, int n, int i){
        cnt++;
        if(cnt >= 2){
            max_prefix = max(max_prefix, (ll)i);
        }
        if(i >= n) return;
        int c = s[i] - 'a';
        if(tails[c] == nullptr) tails[c] = new Node();
        tails[c]->insert(s, n, i+1);
    }
};

inline void solve(){
    int n; cin >> n;
    Node root;
    string s;
    FO(i,n){
        cin >> s;
        root.insert(s, sz(s), 0);
    }

    cout << max_prefix << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    FO(tc, T) solve();

    return 0;
}
