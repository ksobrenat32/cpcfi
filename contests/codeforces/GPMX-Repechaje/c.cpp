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

struct Edge {
    int to;
    ll forwardCost;
    ll backwardCost;
};

int n;
vector<vector<Edge>> adj;
vector<ll> subtreeSize, downwardSum, answer;

void computeSubtree(int node, int parent){
    // Start with size 1 as each node is at least itself
    subtreeSize[node] = 1;
    // For each edge
    for (const Edge &edge : adj[node]){
        // If the edge points to the parent, ignore it
        if (edge.to == parent) continue;

        // Recurse into the child node
        computeSubtree(edge.to, node);

        // Once returned, add the total subtree size
        subtreeSize[node]  += subtreeSize[edge.to];

        // What the child already pays to reach its own subtree
        downwardSum[node] += downwardSum[edge.to];
        // Plus the hop node to child paid once per node in that subtree
        downwardSum[node] += edge.forwardCost * subtreeSize[edge.to];
    }
}


// Do the rerooting
void computeAnswers(int node, int parent){
    // For each edge
    for (const Edge &edge : adj[node]){
        // Ignore parent
        if (edge.to == parent) continue;
        // Start from the parent's answer
        answer[edge.to] = answer[node];
        // Nodes outside the subtree must now go up (child to parent) first
        answer[edge.to] += edge.backwardCost * (n - subtreeSize[edge.to]);
        // Nodes inside the subtree no longer pay the down hop (parent -> child)
        answer[edge.to] -= edge.forwardCost  * subtreeSize[edge.to];
        // Compute answers for the next node
        computeAnswers(edge.to, node);
    }
}

inline void solve(){
    cin >> n;

    // Make adj the total size
    adj.assign(n, {});
    int u, v; ll a, b;

    for (int i = 0; i < n - 1; i++){
        cin >> u >> v >> a >> b;
        u--; v--;
        adj[u].push_back({v, a, b});
        adj[v].push_back({u, b, a});
    }

    // Start everything as 0
    subtreeSize.assign(n, 0);
    downwardSum.assign(n, 0);
    answer.assign(n, 0);

    // Compute subtrees
    computeSubtree(0, -1);
    // The answer from root is the entire tree
    answer[0] = downwardSum[0];
    // Compute the other answers
    computeAnswers(0, -1);

    // Print everything
    for (int i = 0; i < n-1; i++){
        cout << answer[i] << " ";
    }
    cout << answer[n-1] << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    FO(tc, T) solve();

    return 0;
}
