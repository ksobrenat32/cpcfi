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
