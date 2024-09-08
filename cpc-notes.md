# Competitive programming notes

## Vim configuration

```vim
" Set internal encoding of vim
set encoding=utf-8
" Sintax highlighting
syntax on
" Show line number
set number
" Show command
set showcmd
"  Show line where the cursor is
set cursorline
" Identify specific file types
filetype indent on
" Command autocompletation
set wildmenu
" Highlight matching (){}[]
set showmatch
" Searching configuration
set incsearch
set hlsearch
" How to set splitted content
set splitbelow
set splitright
set diffopt=vertical
" Configure indents as 4 spaces
set tabstop=8 softtabstop=0 expandtab shiftwidth=4 smarttab
" set the backspace to delete normally
set backspace=indent,eol,start
```

## Template

```c++
#include <bits/stdc++.h>
using namespace std;

// Optional
#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define debug(x)                cout << #x << " = "; _debug(x); cout << endl;
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end() 
#define sz(x)                   (int) x.size()
#define LB(arr, x)              lower_bound(all(arr), x)-(arr).begin()
#define UB(arr, x)              upper_bound(all(arr), x)-(arr).begin()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void solve(){
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
```

## Variables

Type | Range | bytes
--- | --- | ---
bool | true or false | 1 bit
signed char |  -128 to 127 | 1
unsigned char | 0 to 255 | 1
short int | -32,768 to 32,767 | 2
unsigned short int | 0 to 65,535 | 2
unsigned int | 0 to 4,294,967,295 | 4
int | -2,147,483,648 to 2,147,483,647 | 4
long int | -2,147,483,648 to 2,147,483,647 | 4
unsigned long int | 0 to 4,294,967,295 | 4
long long int | -(2^63) to (2^63)-1 | 8
unsigned long long int | 0 to 18,446,744,073,709,551,615 | 8
float | -3.4×10^38 to 3.4×10^38 | 4
double | -1.7×10^308 to1.7×10^308 | 8
long double | -1.1×10^4932 to1.1×10^4932 | 12

## Input

Read while input is provided

```c++
while(getline(cin, s))
```

## Number theory

### Prime

```c++
bool prime(int t){
    if(t%2 == 0){
        return false;
    } else {
        for(int i=3; i*i <=t; i+=2){
            if((t%i)==0){
                return false;
            }
        }
    }
    return true;
}
```

### Greatest common divisor

```c++
int gcd ( int a , int b ) {
    if ( b == 0) return a ;
    return gcd (b , a % b ) ;
}
```

### Least common multiple

```c++
int lcm ( int a, int b ){
    return ( a * b ) / gcd ( a , b );
}
```

### Gaus

```c++
long long sum = n * (n+1) / 2;
```

## Binary search

```c++
int bs(int N, int x, vector<int> v){
    int R = N-1;
    int L = 0;
    int mid;

    while(L <= R){
        mid = L + (R - L) / 2;

        if(v[mid] == x){
            return mid;
        } 
        
        if(v[mid] < x ){
            L = mid + 1 ;
        } else {
            R = mid - 1;
        }
    }

    return -1;
}
```

### Lower bound

```c++
int lb(int N, int x, vector<int> v){
    int R = N-1;
    int L = 0;
    int mid;

    while(L <= R){
        mid = L + (R - L) / 2;

        if(v[mid] == x){
            while( v[mid] == x){
                mid--;
            }
            return mid+1;
        } 
        
        if(v[mid] < x ){
            L = mid + 1 ;
        } else {
            R = mid - 1;
        }
    }

    return -1;
}
```

### Upper bound

```c++
int ub(int N, int x, vector<int> v){
    int R = N-1;
    int L = 0;
    int mid;

    while(L <= R){
        mid = L + (R - L) / 2;

        if(v[mid] == x){
            while( v[mid] == x){
                mid++;
            }
            return mid-1;
        } 
        
        if(v[mid] < x ){
            L = mid + 1 ;
        } else {
            R = mid - 1;
        }
    }

    return -1;
}
```

## Graphs

### BFS

If near the beggining

```c++
void bfs(int s, vector<vector<int>> &adj, vector<bool> &visited, int n){
    queue<int> q;
    q.push(s);
    visited[q.front()]=true;

    while(! q.empty()){
        cout << q.front() << endl;
        for(size_t i = 0; i < adj[q.front()].size(); i++){
            if(!visited[adj[q.front()][i]]){
                q.push(adj[q.front()][i]);
                visited[adj[q.front()][i]]=true;
            }
        }
        q.pop();
    }
}
```

### DFS

If near a leaf

```c++
void dfs(int s, vector<vector<int>> &adj, vector<bool> &visited){
    if(visited[s]){
        return;
    }
    cout << s << endl;
    visited[s]=true;
    for(size_t i = 0; i < adj[s].size(); i++){
        dfs(adj[s][i]);
    }
}
```

### Conex

Print connected notes

```c++
void conex(int s, vector<vector<int>> &adj, vector<bool> &visited){
    for(size_t i = 0; i < adj.size(); i++){
        if(!visited[i]){
            bfs(i);            
        }
        cout << endl;
    }
}
```

## Strings

### To upper and to lower case

```c++
transform(s.begin(), s.end(), s.begin(), ::toupper);
transform(s.begin(), s.end(), s.begin(), ::tolower);

```

### Substrings

```c++
string a = s.substr(0,size/2);
string b = s.substr(size/2,size);
```

### Find a char

Location

```c++
int l = s.find(c);
```

If exists

```c++
if( s.find(c) != string::npos ){
    // YES
} else {
    // NO
}
```

For each find

```c++
for(char& c : s){
    // If found
    if( find(v.begin(), v.end(), c) != v.end()){
    }
}
```

### Substrings with steroids

```c++
int a;
int b;
int c;
char comma;
char colon;

// Createa a stringstream object
stringstream ss(fullString);
// Extract the strings 

ss >> a >> colon >> b >> comma >> c;
```

### Read a line including spaces

tmp is the string to save the line

```c++
getline(cin,tmp);
```

### Algorithms

#### Rolling hash

```c++
struct Hash {
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

## Number manipulation

### Rounding

```c++
int x = floor(float / float);
int x = ceil(float / float);
```

### Absolute

```c++
float x = abs(a - b);
```

### Printing

To print n leading zeros

```c++
cout << setw(n) << setfill('0') << x << endl;
```

To print with all the presition a long double

```c++
cout.setf(ios::fixed);
cout << setprecision(0) << n << endl;
```

## Organizing and finding

### Sort

It cant sort anything O(n log(n))

```c++
sort(t.begin(), t.end());
```

### Reverse sort

```c++
sort(t.rbegin(), t.rend());
```

### Reverse

```c++
reverse(t.begin(), t.end());
```

### Max and min

```c++
int mx = max( mx, x );
int mi = min( mi, x );
```

## Math

### Combinations

Number of ways to make a square of size k x k in a grid of size n x n

```c++
ll sqr_comb(ll n){
    ll r=0;
    for(ll i=1; i<=n; i++){
        r += (n-i+1)*(n-i+1);
    }
    return r;
}
```


## ASCII useful

![ASCII TABLE](https://upload.wikimedia.org/wikipedia/commons/thumb/d/dd/ASCII-Table.svg/2522px-ASCII-Table.svg.png)
