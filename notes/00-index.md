# Competitive programming notes

This are the notes that I use on competitive programming. They are a collection of algorithms and data structures that I have found useful. Everything is written in C++.

## Template

Use this as a template for all the solutions.

```c++
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

## Range of the variables

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

### Index

- [I/O tips](./01-io.md)
- [Numbers](./02-numbers.md)
- [Searching](./03-searching.md)
- [Graphs](./04-graphs.md)
- [Strings](./05-strings.md)
- [Algorithms](./06-algorithms.md)
- [Geometry](./07-geometry.md)