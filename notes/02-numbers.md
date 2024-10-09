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
