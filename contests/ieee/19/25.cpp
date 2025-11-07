#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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

typedef unsigned long long ull;
const int MAX_VAL = 64;

// Template class for Segment Tree
// https://www.geeksforgeeks.org/cpp/segment-tree-in-cpp/

class FenwickTree {
private:
    vector<ull> bit;
    vector<int> arr;
    int n;

    void add(int idx, ull val) {
        idx++;
        for (; idx <= n; idx += idx & (-idx)) {
            bit[idx] += val;
        }
    }

    ull prefix_sum(int idx) {
        idx++;
        ull sum = 0ULL;
        for (; idx > 0; idx -= idx & (-idx)) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    FenwickTree(const vector<int>& a) : n(a.size()) {
        bit.resize(n + 1, 0ULL);
        arr = a;
        
        for (int i = 0; i < n; ++i) {
            add(i, (1ULL << arr[i]));
        }
    }

    void update(int idx, int new_val) {
        ull old_bit_val = (1ULL << arr[idx]);
        ull new_bit_val = (1ULL << new_val);
        ull delta = new_bit_val - old_bit_val;

        arr[idx] = new_val;
        add(idx, delta);
    }

    ull query(int l, int r) {
        return prefix_sum(r) - (l == 0 ? 0ULL : prefix_sum(l - 1));
    }
};

inline void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    FenwickTree fenwickTree(a);

    int l, r;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;

        ull res = fenwickTree.query(l - 1, r - 1);
        
        if (__builtin_popcountll(res) == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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
