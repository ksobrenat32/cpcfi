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


class DisjointSets{
    private:
        vector<int> parents;
        vector<int> sizes;
        int components;
    public:
        DisjointSets(int size) : parents(size), sizes(size,1), components(size){
            for(int i=0; i<size; i++){parents[i] = i;}
        }

        int find(int x) {return parents[x] == x ? x : (parents[x] = find(parents[x]));}

        bool unite(int x, int y){
            int x_root = find(x);
            int y_root = find(y);

            if(x_root == y_root) {return false;}

            if(sizes[x_root] < sizes[y_root]) {swap(x_root,y_root);}
            sizes[x_root] += sizes[y_root];
            parents[y_root] = x_root;
            components--;
            return true;
        }

        vector<int> getAllComponentSizes(){
            map<int, int> component_sizes;
            for (int i = 0; i < parents.size(); ++i){
                int root = find(i);
                if (component_sizes.find(root) == component_sizes.end()){
                    component_sizes[root] = sizes[root];
                }
            }

            vector<int> result;
            for (auto& [root, size] : component_sizes) {
                result.push_back(size);
            }

            return result;
        }


        bool connected(int x, int y) { return find(x) == find(y);}
        int getSize(int x) {return sizes[find(x)];}
        int getComponents() const {return components;}
};

inline void solve(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    FO(i,n) cin >> grid[i];

    // Adj
    vector<vector<int>> adj(n*m, vector<int> (0));

    int p1, p2, p3;

    // Add horizontal pass (row-wise)
    for(int i = 0; i < n; i++){
        p1 = -1;
        p2 = -1;
        for(int j = 0; j < m; j++){
            if(p1 == -1 && grid[i][j] != '.'){
                p1 = j;
            }
            if(grid[i][j] == '.' && p1 != -1){
                p2 = j-1;
                // we found edges
                while(p1<p2){
                    adj[(i*m)+p1].push_back((i*m)+p2);
                    adj[(i*m)+p2].push_back((i*m)+p1);
                    p1++;
                    p2--;
                }
                p1 = -1;
                p2 = -1;
            }
        }
    
        if(p1 != -1 && grid[i][m-1] != '.'){
            p2 = m-1;
            // we found edges
            while(p1<p2){
                adj[(i*m)+p1].push_back((i*m)+p2);
                adj[(i*m)+p2].push_back((i*m)+p1);
                p1++;
                p2--;
            }
            p1 = -1;
            p2 = -1;
        }
    }
    
    // Add vertical pass (column-wise)
    for (int j = 0; j < m; j++) {
        p1 = -1;
        p2 = -1;
        for (int i = 0; i < n; i++) {
            if (p1 == -1 && grid[i][j] != '.') {
                p1 = i;
            }
            if (grid[i][j] == '.' && p1 != -1) {
                p2 = i-1;
                while (p1 < p2) {
                    int a = p1 * m + j;
                    int b = p2 * m + j;
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                    p1++;
                    p2--;
                }
                p1 = -1;
                p2 = -1;
            }
        }
    
        if (p1 != -1 && grid[n-1][j] != '.') {
            p2 = n - 1;
            while (p1 < p2) {
                int a = p1 * m + j;
                int b = p2 * m + j;
                adj[a].push_back(b);
                adj[b].push_back(a);
                p1++;
                p2--;
            }
            p1 = -1;
            p2 = -1;
        }
    }

    // Print adj for debugging
    /*
    for(int i=0; i<n*m; i++){
        cout << "Cell " << i << ": ";
        for(auto v: adj[i]){
            cout << v << " ";
        }
        cout << "\n";
    }
    */

    DisjointSets ds(n*m);

    for(int i=0; i<n*m; i++){
        for(auto v: adj[i]){
            ds.unite(i, v);
        }
    }

    vector<set<int>> comp(n*m);
    for(int i=0; i<n*m; i++){
        comp[ds.find(i)].insert(i);
    }


    int x, y;
    for(auto c: comp){
        if(c.empty()) continue;  // Skip empty components
        
        vector<int> cell(10,0);
        for(auto v: c){
            x = v/m;
            y = v%m;
            if(grid[x][y] == '.') continue;  // Skip '.' cells
            cell[grid[x][y]-'0']++;
        }

        // Get the number that would make the less changes
        int best = INT_MAX;
        int best_num = -1;

        for(int i=0; i<=9; i++){
            int changes = 0;
            for(int j=0; j<=9; j++){
                changes += cell[j] * abs(i - j);
            }

            if(changes < best){
                best = changes;
                best_num = i;
            }
        }

        // Update the grid
        for(auto v: c){
            x = v/m;
            y = v%m;
            if(grid[x][y] != '.'){  // Only update non-'.' cells
                grid[x][y] = '0' + best_num;
            }
        }
    }


    // Output the grid
    for(int i=0; i<n; i++){
        cout << grid[i] << "\n";
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
