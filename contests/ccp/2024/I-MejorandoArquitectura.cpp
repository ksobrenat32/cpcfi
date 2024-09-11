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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/Mejorando-la-arquitectura

class segment_tree {
    public:
        vi bt;
        int orig_size;

    segment_tree(vi v){
        // Create the tree
        bt.resize(4*sz(v)+1);
        orig_size = sz(v);

        // Copy values
        for(int i = 0; i < sz(v); i++){
            bt[sz(v) + i] = v[i];
        }

        // Build the tree
        for(int i = sz(v)-1; i > 0; i--){
            bt[i] = bt[i*2] * bt[(i*2)+1];
        }
    }

    void update(int node, int value){
        // Update the value
        node += orig_size;

        // Update the parents
        bt[node] = value;

        while(node > 1){
            node /= 2;
            bt[node] = bt[node*2] * bt[(node*2)+1];
        }
    }

    void query(int a, int b){
        ll res = 1;

        a += orig_size;
        b += orig_size;

        while(a <= b){
            if(a % 2 == 1){
                res *= bt[a];
                a++;
            }

            if(b % 2 == 0){
                res *= bt[b];
                b--;
            }

            a /= 2;
            b /= 2;
        }

        if(res > 0){
            cout << "+" << endl;
        }else if(res < 0){
            cout << "-" << endl;
        }else{
            cout << "0" << endl;
        }
    }
};

void solve(){
    int n,q; cin >> n >> q;
    vi v(n);

    FO(i,n){
        cin >> v[i];
        if(v[i] > 0){
            v[i] = 1;
        } else if(v[i] < 0){
            v[i] = -1;
        } else {
            v[i] = 0;
        }
    }

    // Build segment tree
    segment_tree st(v);

    char c;
    int a,b;

    FO(i,q){
        cin >> c >> a >> b;

        // change
        if(c == 'C'){
            if(b > 0){
                b = 1;
            } else if(b < 0){
                b = -1;
            } else {
                b = 0;
            }
            st.update(a-1,b);
        }else{
            st.query(a-1,b-1);
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
