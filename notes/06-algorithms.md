
## General algorithms

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