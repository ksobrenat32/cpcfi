## Search algorithms

### Binary search

Time complexity: O(log(n))

```c++
int bs(int N, int x, vector<int> v){
    int R = N-1;
    int L = 0;
    int m;

    while(L <= R){
        m = L + (R - L) / 2;

        if(v[m] == x){
            // Found
            return m;
        }

        if(v[mid] < x ){
            L = m + 1 ;
        } else {
            R = m - 1;
        }
    }

    // Not found
    return -1;
}
```

### Lower bound

Like binary search but returns the first element that is greater or equal to x. Time complexity: O(log(n))

```c++
lb = lower_bound(v.begin(), v.end(), x) - v.begin();
```

### Upper bound

Like binary search but returns the first element that is greater than x. Time complexity: O(log(n))

```c++
ub = upper_bound(v.begin(), v.end(), x) - v.begin();
```

### Pragmas for optimization

Pragmas are special directives for the compiler. In competitive programming, they are often used to enable specific CPU instructions or compiler optimizations that can make the code run faster.

```cpp
#pragma GCC optimize("Ofast")
#pragma GCC target("lzcnt,popcnt")
```

These pragmas are specific to GCC/G++ compilers. `O3` enables a high level of optimization. `unroll-loops` attempts to unroll loops for potential speedup. `target` enables specific instruction sets, which can provide significant performance improvements if the CPU supports them and the code can leverage them.

### Bitset

A `std::bitset` is a fixed-size sequence of N bits. It is useful for problems involving bit manipulation, as it provides a convenient and efficient way to represent and operate on sets of bits.

```cpp
#include <bitset>

// Create a bitset of size 10
std::bitset<10> b;

// Set, reset, and flip bits
b[1] = 1;
b[2] = 0;
b.flip(3);

// Count set bits
cout << b.count() << endl;

// Convert to string or unsigned long
cout << b.to_string() << endl;
cout << b.to_ulong() << endl;
```

### Counting with lower_bound and upper_bound

You can efficiently count the number of elements equal to `x` in a sorted range using `lower_bound` and `upper_bound`.

`lower_bound` returns an iterator to the first element not less than `x`.
`upper_bound` returns an iterator to the first element greater than `x`.

The difference between these two iterators gives the number of elements equal to `x`.

```cpp
// v is a sorted vector
auto lb = lower_bound(v.begin(), v.end(), x);
auto ub = upper_bound(v.begin(), v.end(), x);
int count = ub - lb;
```
