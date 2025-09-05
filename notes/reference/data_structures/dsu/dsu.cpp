// Implements a Disjoint Set Union (DSU) data structure with path compression and union by size.
// Time Complexity: O(α(n)) for find, unite, connected and size queries, where α is the inverse Ackermann function.
// Space Complexity: O(n)
// Based on: https://usaco.guide/gold/dsu?lang=cpp

class DSU{
    private:
        vector<int> parent;
        vector<int> component_size;
        int num_components;
    public:
        DSU(int n) : parent(n), component_size(n,1), num_components(n){
            for(int i=0; i<n; i++){parent[i] = i;}
        }

        int find(int i) {return parent[i] == i ? i : (parent[i] = find(parent[i]));}

        bool unite(int i, int j){
            int root_i = find(i);
            int root_j = find(j);

            if(root_i == root_j) {return false;}

            if(component_size[root_i] < component_size[root_j]) {swap(root_i,root_j);}
            component_size[root_i] += component_size[root_j];
            parent[root_j] = root_i;
            num_components--;
            return true;
        }

        vector<int> get_all_component_sizes(){
            vector<int> sizes;
            for (int i = 0; i < parent.size(); ++i){
                if (parent[i] == i){
                    sizes.push_back(component_size[i]);
                }
            }
            return sizes;
        }


        bool connected(int i, int j) { return find(i) == find(j);}
        int size(int i) {return component_size[find(i)];}
        int components() const {return num_components;}
};
