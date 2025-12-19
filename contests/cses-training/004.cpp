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

class Edge {
public:
    int u;
    int v;
    int w;

    Edge(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    }
};


inline void solve(){
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;

    int a, b, c;

    for(int i = 0; i<E; i++){
        cin >> a >> b >> c;
        edges.pb(Edge(a, b, c));
    }

    // Bellman-Ford algorithm to detect negative cycle
    vector<ll> dist(V + 1, 0);
    vector<int> parent(V + 1, -1);
    
    int x = -1; // node that is part of negative cycle
    
    // Run Bellman-Ford for V iterations
    FO(i, V){
        x = -1;
        TR(e, edges){
            if(dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }
    
    if(x == -1){
        cout << "NO\n";
        return;
    }
    
    // x is affected by negative cycle, go back V steps to be in the cycle
    FO(i,V){
        x = parent[x];
    }
    
    // Extract the cycle
    vector<int> cycle;
    int curr = x;
    do {
        cycle.pb(curr);
        curr = parent[curr];
    } while(curr != x);
    cycle.pb(x);
    
    reverse(all(cycle));
    
    cout << "YES\n";
    TR(node, cycle){
        cout << node << " ";
    }
    cout << "\n";
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
