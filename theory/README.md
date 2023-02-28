# CPCFI notes

## Operators

OPERATOR | WHAT | # ELEMENTS
--- | --- | ---
AND `&&` | Both true | 2
OR `\|\|` | One or both true | 2
XOR `^`  | Only one true | 2
NOT `~`  | Contrary | 1

## Significant values

1 | 0 | ... | 0 | 1
--- | --- | --- | --- | ---
More | | | | Less

## Bit things

Bitwise : Movement of bits and its operations  (with operators and movement of bits)

Bitmask : Filter with operations

## Save ints in single int

1. Initializate an int with 0's
2. Write a 1 as a flag where you want to save it
3. Move bits
4. Use and to save

Example:

32 | 31 | 30 | ... | 4 | 3 | 2 | 1 | 0
--- | --- | --- | --- | --- | --- | --- | --- | ---
 0 |  1 |  0 | ... | 1 | 0 | 0 | 1 | 0

Here you have saved 31, 4 and 1.

## Save int like a real number

For more precision you can use scanf:

```c
scanf("%d.%d",&a,&b);
```

### Geometry

PI

```c
#define PI acos(-1.0)
```

Épsilon

```c
#define EPS 1e-9
```

### Structures

Line

```c
struct line { double a,b,c; }
```

### Circle

#### Arch

To calculate the arch use `L=rθ`

#### Conversions

```c
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }
```

#### Function

```c
int insideCircle(point_i p, point_i c, int r){
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;
returb Euc < rSq ? 0 L Euc ==rSq > 1 : 2;
}
```

### Triangle

```math
A = sqrt(s * (s - a) * (s - b) * (s - c))
```

Being S the semiperimeter

```math
s = (a + b + c) / 2
```

## Sparce table

### Binary representation

A number can be represented with [log2 (N)] + 1 in powers of 2

### Prerequisites

- Inmutable array.
- Associative funtion for O(n log (n)) range query.
- Overlap friendly function O(1) range query (max, min,
 max common divisor, least common multiple)

### Table construction

1. Build matrix `(P+1) x N` , where N is the number of elements and
 P is the largest power of 2 that fits N `2^P = N`
2. Define a range combination function
3. Fill table with function

### Queries

- Overlap friendly
- Non overlap friendly

## Union find

### Functions

- Union : O ( log N )
- Find : O ( log N )

Add the smaller to the bigger

### Implementation

```c++
// Create node, size 1 and point to itself
linked[i] = i;
size[i] = 1;

// Find the representative
while ( i != linked[i] ){
    i = linked [1];

    return i;
}


// Union
union(u,v){
    x = find(u);
    y = find(v);

    if ( x != y ){
        if ( size[x] < size [y] ){
            swap(x,y);
        }
        // Change data
        y = linked[x];
        size[x] += size [y];
    }
}
```

## Fenwick Tree

Given an array of integer values, compute the range of
 associative functions between index [i,j)

### Complexity

- Construction O(N)
- Point update O(log (N))
- Range sum O(log (N))
- Ranfe update O(log (N))
- Adding index N/A
- Delete index N/A

### Responsability

A cell is responsible for other cells

The position of the least significant bit determines the
 range of responsability

### Range Queries

We compute the prefix sum up to a certain index, with lets us
 perform range queries

Ex. Find prefix sum up to index 7

```math
sum = A[7] + A[6] + A[4]
```

The worst case is when you query  a number as `((2 ^ n) + 1)`

### Point update

We can get into the cascade to the left by deleting the less
 significant bit and to the right by adding the LSB.

### Obtain LSB

```c++
return i & -i
```

## Segment tree

Data structure for processing a range query and updating an array value.

The advantage over the Fenwick tree is that this structure can support
 other queries but it requires more memory and the code is longer.

When representing a tree in an array we can get that the number of vertix
 can be represented as `v=2n-1` and to calculate the childs, we can use:

- left: `2i`
- right: `2i + 1`

## Complete search

Generate all posible solutions with brute force and then count or select the
 correct solution


## MISC

In c++ you can process between 10⁷ and 10⁸ operations per second.

You should always check time and memory

Write macros with UPPERCASE

- Complete search -> recursive
- Bruteforce -> iterative
