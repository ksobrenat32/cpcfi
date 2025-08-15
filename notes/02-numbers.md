## Numbers

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

### Rounding

```c++
// Round down
int x = floor(float / float);
// Round up
int x = ceil(float / float);
```

### Absolute

```c++
float x = abs(a - b);
```

### Is prime?

Time complexity: O(sqrt(n))

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

### Is power of two?

```c++
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
```

### Greatest Common Divisor (GCD)

Time complexity: O(log(min(a,b)))

```c++
int gcd ( int a , int b ) {
    if ( b == 0) return a ;
    return gcd (b , a % b ) ;
}
```

### Least Common Multiple (LCM)

Time complexity: O(log(min(a,b)))

```c++
int lcm ( int a, int b ){
    return ( a * b ) / gcd ( a , b );
}
```

### Gauss sum

Sum of the first n numbers. Time complexity: O(1)

```c++
long long sum = n * (n+1) / 2;
```

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

### Bitwise

#### Basic Operations

```c++
int a = 5;      // 0101 in binary
int b = 3;      // 0011 in binary
int c = a & b;  // 0001 in binary (AND)
int d = a | b;  // 0111 in binary (OR)
int e = a ^ b;  // 0110 in binary (XOR)
int f = ~a;     // 1010 in binary (NOT)
int g = a << 1; // 1010 in binary (left shift)
int h = a >> 1; // 0010 in binary (right shift)
```

#### Operator Reference

OPERATOR | WHAT | # ELEMENTS
--- | --- | ---
AND `&&` | Both true | 2
OR `\|\|` | One or both true | 2
XOR `^`  | Only one true | 2
NOT `~`  | Contrary | 1

#### Significant values

1 | 0 | ... | 0 | 1
--- | --- | --- | --- | ---
More | | | | Less

#### Bit Concepts

**Bitwise**: Movement of bits and its operations (with operators and movement of bits)

**Bitmask**: Filter with operations

#### Save ints in single int

1. Initialize an int with 0's
2. Write a 1 as a flag where you want to save it
3. Move bits
4. Use and to save

Example:

32 | 31 | 30 | ... | 4 | 3 | 2 | 1 | 0
--- | --- | --- | --- | --- | --- | --- | --- | ---
 0 |  1 |  0 | ... | 1 | 0 | 0 | 1 | 0

Here you have saved 31, 4 and 1.

#### Get LSB (Least Significant Bit)

```c++
int getLSB(int i) {
    return i & -i;
}
```
