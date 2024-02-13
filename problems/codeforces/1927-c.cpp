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
// https://codeforces.com/problemset/problem/1927/C

inline void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    set<int> a;
    set<int> b;
    set<int> nums;
    int t;

    FO(i, n){
        cin >> t;
        if(t <= k){
            a.insert(t);
            nums.insert(t);
        }
    }
    FO(i, m){
        cin >> t;
        if(t <= k){
            b.insert(t);
            nums.insert(t);
        }
    }

    int i = 1;

    if(sz(nums) < k){
        cout << "NO" << endl;
        return;
    }

    TR(x, nums){
        if(x != i){
            cout << "NO" << endl;
            return;
        }
        if(i == k){
            break;
        }
        i++;
    }

    int only_in_a = 0;
    int in_both = 0;

    TR(x, a){
        if(b.find(x) == b.end()){
            only_in_a++;
        } else {
            in_both++;
        }
    }
    int only_in_b = sz(b) - in_both;

    in_both -= max(only_in_a, only_in_b) - min(only_in_a, only_in_b);

    if(in_both >= 0 && in_both%2 == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
