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

inline void solve() {
    int M; cin >> M;
    vector<pair<int, int>> dominoes(M);

    set<int> all_nodes;
    map<int, vector<int>> adj;
    
    int A, B;
    FO(i, M){
        cin >> A >> B;
        dominoes[i] = mp(A, B);
        all_nodes.insert(A);
        all_nodes.insert(B);

        adj[A].pb(i);
        if(A != B) {
            adj[B].pb(i);
        }
    }

    ll ans = 0;
    set<int> visited_nodes;
    TR(node, all_nodes) {
        if(visited_nodes.count(node)) continue;

        vector<int> component_ind;
        set<int> visited_nodes_component;
        set<int> component_nodes;

        queue<int> q;

        q.push(node);
        component_nodes.insert(node);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            // Check all adjacent dominoes
            for(int domino_idx : adj[u]) {
                if(visited_nodes_component.count(domino_idx)) continue;

                visited_nodes_component.insert(domino_idx);
                component_ind.pb(domino_idx);

                pair<int, int> domino = dominoes[domino_idx];
                int v;
                if(domino.F == u) {
                    v = domino.S;
                } else {
                    v = domino.F;
                }

                if(component_nodes.find(v) == component_nodes.end()) {
                    component_nodes.insert(v);
                    q.push(v);
                }
            }
        }

        // Mark all nodes in component as visited
        TR(n, component_nodes) {
            visited_nodes.insert(n);
        }

        int s = sz(component_ind);
        if(s == 0) continue;

        // Iterate with bitmask
        for(int mask = 1; mask < (1 << s); mask++) {
            map<int, int> d;
            map<int, vector<int>> sub_adj;
            set<int> sub_nodes;
            // Firsht node
            int fns = -1;

            for(int i=0; i < s; i++){
                if(mask & (1<<i)){
                    int domino_idx = component_ind[i];
                    int u = dominoes[domino_idx].F;
                    int v = dominoes[domino_idx].S;

                    sub_adj[u].pb(v);
                    if(u != v) {
                        sub_adj[v].pb(u);
                    }

                    d[u]++;
                    d[v]++;

                    sub_nodes.insert(u);
                    sub_nodes.insert(v);

                    if(fns == -1) {
                        fns = u;
                    }
                }
            }

            if(fns == -1) continue;

            int check = 0;

            // Check parity
            TR(n, d){
                if(n.S % 2 != 0) {
                    check++;
                }
            }

            if(check > 2) continue;

            // Check connectivity
            set<int> sub_vis;
            queue<int> q2;

            q2.push(fns);
            sub_vis.insert(fns);

            while(!q2.empty()) {
                int u = q2.front();
                q2.pop();

                TR(v, sub_adj[u]) {
                    if(sub_vis.find(v) == sub_vis.end()) {
                        sub_vis.insert(v);
                        q2.push(v);
                    }
                }
            }


            // Last check
            bool connected = true;
            TR(n, sub_nodes) {
                if(sub_vis.find(n) == sub_vis.end()) {
                    connected = false;
                    break;
                }
            }

            if(connected) {
                ans++;
            }
        }
    }



    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    FO(tc, T) {
        solve();
    }
    return 0;
}
