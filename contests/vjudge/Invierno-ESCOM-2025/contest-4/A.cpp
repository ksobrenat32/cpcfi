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
// https://vjudge.net/contest/693191#problem/A

// Segment tree implementation
class SegmentTree {
private:
    vector<ll> d, vis;
    int size;

public:
    SegmentTree(int size) : size(size) {
        d.resize(4 * size);
        vis.resize(4 * size);
    }

    void build(int root_node, int left_node, int right_node, vector<ll> &arr){
        if(left_node == right_node){
            d[root_node] = arr[left_node];
            vis[root_node] = 0;
        }
    }

};

inline void solve(){

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
