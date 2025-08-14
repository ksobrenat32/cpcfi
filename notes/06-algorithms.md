
## General algorithms

### Union Find (Disjoint Set Union)

#### Functions

- Union: O(log N)
- Find: O(log N)

Add the smaller to the bigger (union by size).

#### Implementation

```c++
class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n);
        // Create node, size 1 and point to itself
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Find the representative
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    // Union two sets
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x != y) {
            if (size[x] < size[y]) {
                swap(x, y);
            }
            // Change data
            parent[y] = x;
            size[x] += size[y];
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### Fenwick Tree (Binary Indexed Tree)

Given an array of integer values, compute the range of associative functions between index [i,j).

#### Complexity

- Construction: O(N)
- Point update: O(log N)
- Range sum: O(log N)
- Range update: O(log N)
- Adding index: N/A
- Delete index: N/A

#### Responsibility

A cell is responsible for other cells. The position of the least significant bit determines the range of responsibility.

#### Implementation

```c++
class FenwickTree {
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    // Add val to position idx (1-indexed)
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    
    // Get prefix sum up to idx (1-indexed)
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
    
    // Get range sum [l, r] (1-indexed)
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};
```

### Sparse Table

#### Binary representation

A number can be represented with [log2(N)] + 1 in powers of 2.

#### Prerequisites

- Immutable array
- Associative function for O(n log n) range query
- Overlap friendly function O(1) range query (max, min, gcd, lcm)

#### Implementation

```c++
class SparseTable {
    vector<vector<int>> st;
    vector<int> logs;
    
public:
    SparseTable(vector<int>& arr) {
        int n = arr.size();
        int maxLog = 0;
        while ((1 << maxLog) <= n) maxLog++;
        
        st.assign(maxLog, vector<int>(n));
        logs.assign(n + 1, 0);
        
        // Precompute logs
        for (int i = 2; i <= n; i++) {
            logs[i] = logs[i / 2] + 1;
        }
        
        // Fill first row
        for (int i = 0; i < n; i++) {
            st[0][i] = arr[i];
        }
        
        // Fill table
        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = max(st[j-1][i], st[j-1][i + (1 << (j-1))]);
            }
        }
    }
    
    // O(1) range maximum query
    int query(int l, int r) {
        int j = logs[r - l + 1];
        return max(st[j][l], st[j][r - (1 << j) + 1]);
    }
};
```

### Rolling hash

A rolling hash is a hash function where the input is hashed in a window that moves through the input. The hash value at each window is calculated from the hash value of the previous window. This is useful to compare strings in O(1) time.

```c++
// Rolling hash
struct Hash {
    // Prime number and modulo
    long long p = 31, m = 1e9 + 7;
    long long hash_value;
    Hash(const string& s)
    {
        long long hash_so_far = 0;
        long long p_pow = 1;
        const long long n = s.length();
        for (long long i = 0; i < n; ++i) {
            hash_so_far
                = (hash_so_far + (s[i] - 'a' + 1) * p_pow)
                  % m;
            p_pow = (p_pow * p) % m;
        }
        hash_value = hash_so_far;
    }
    bool operator==(const Hash& other)
    {
        return (hash_value == other.hash_value);
    }
};

// Usage
int main(){
    string s = "hello";

    return 0;
}

```

#### KMP

```c++
// LPS for s, lps[i] could also be defined as the longest prefix which is also a proper suffix
vi computeLPS(string s){
    size_t len = 0;
    size_t M = s.size();
    vi lps(M, 0);

    size_t i = 1;
    while(i < M) {
        if( s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0){
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Get number of occurrences of a pattern in a text using KMP
// O(N+M)
size_t KMPOccurrences(string pattern, string text){
    vi lps = computeLPS(pattern); // LPS array

    size_t M = pattern.size();
    size_t N = text.size();

    size_t i = 0; // Index for text
    size_t j = 0; // Index for pattern

    size_t cnt = 0; // Counter

    while ((N - i) >= (M - j)) {
        // Watch for the pattern
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        // If the full match found
        if (j == M) {
            cnt++;
            j = lps[j - 1];
        }

        // Mismatch after j matches
        else if (i < N && pattern[j] != text[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return cnt;
}
```

### Segment tree

In this case we are going to use a segment tree to store the product of the elements of an array. Be careful with overflows.

```c++
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

        cout << res << endl;
    }
};
```

### Binpow

```c++
long long power(long long a, long long b, long long m) {
    long long result = 1 % m;
    a %= m;
    while(b) {
        if (b & 1) 
        result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}
```