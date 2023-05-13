# Competitive programming notes

## Template

```c++
#include <bits/stdc++.h>
using namespace std;

// Optional
#define endl                    '\n'
#define fastIO()                ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

## ASCII

```txt
Dec 	Hex 	Oct 	Html 	Char
0 	0 	000 		NUL
1 	1 	001 		SOH
2 	2 	002 		STX
3 	3 	003 		ETX
4 	4 	004 		EOT
5 	5 	005 		ENQ
6 	6 	006 		ACK
7 	7 	007 		BEL
8 	8 	010 		BS
9 	9 	011 		TAB
10 	A 	012 		LF
11 	B 	013 		VT
12 	C 	014 		FF
13 	D 	015 		CR
14 	E 	016 		SO
15 	F 	017 		SI
16 	10 	020 		DLE
17 	11 	021 		DC1
18 	12 	022 		DC2
19 	13 	023 		DC3
20 	14 	024 		DC4
21 	15 	025 		NAK
22 	16 	026 		SYN
23 	17 	027 		ETB
24 	18 	030 		CAN
25 	19 	031 		EM
26 	1A 	032 		SUB
27 	1B 	033 		ESC
28 	1C 	034 		FS
29 	1D 	035 		GS
30 	1E 	036 		RS
31 	1F 	037 		US
32 	20 	040 	&#32; 	Space
33 	21 	041 	&#33; 	!
34 	22 	042 	&#34; 	\"
35 	23 	043 	&#35; 	#
36 	24 	044 	&#36; 	$
37 	25 	045 	&#37; 	%
38 	26 	046 	&#38; 	&
39 	27 	047 	&#39; 	'
40 	28 	050 	&#40; 	(
41 	29 	051 	&#41; 	)
42 	2A 	052 	&#42; 	*
43 	2B 	053 	&#43; 	+
44 	2C 	054 	&#44; 	,
45 	2D 	055 	&#45; 	-
46 	2E 	056 	&#46; 	.
47 	2F 	057 	&#47; 	/
48 	30 	060 	&#48; 	0
49 	31 	061 	&#49; 	1
50 	32 	062 	&#50; 	2
51 	33 	063 	&#51; 	3
52 	34 	064 	&#52; 	4
53 	35 	065 	&#53; 	5
54 	36 	066 	&#54; 	6
55 	37 	067 	&#55; 	7
56 	38 	070 	&#56; 	8
57 	39 	071 	&#57; 	9
58 	3A 	072 	&#58; 	:
59 	3B 	073 	&#59; 	;
60 	3C 	074 	&#60; 	<
61 	3D 	075 	&#61; 	=
62 	3E 	076 	&#62; 	>
63 	3F 	077 	&#63; 	?
64 	40 	100 	&#64; 	@
65 	41 	101 	&#65; 	A
66 	42 	102 	&#66; 	B
67 	43 	103 	&#67; 	C
68 	44 	104 	&#68; 	D
69 	45 	105 	&#69; 	E
70 	46 	106 	&#70; 	F
71 	47 	107 	&#71; 	G
72 	48 	110 	&#72; 	H
73 	49 	111 	&#73; 	I
74 	4A 	112 	&#74; 	J
75 	4B 	113 	&#75; 	K
76 	4C 	114 	&#76; 	L
77 	4D 	115 	&#77; 	M
78 	4E 	116 	&#78; 	N
79 	4F 	117 	&#79; 	O
80 	50 	120 	&#80; 	P
81 	51 	121 	&#81; 	Q
82 	52 	122 	&#82; 	R
83 	53 	123 	&#83; 	S
84 	54 	124 	&#84; 	T
85 	55 	125 	&#85; 	U
86 	56 	126 	&#86; 	V
87 	57 	127 	&#87; 	W
88 	58 	130 	&#88; 	X
89 	59 	131 	&#89; 	Y
90 	5A 	132 	&#90; 	Z
91 	5B 	133 	&#91; 	[
92 	5C 	134 	&#92; 	\
93 	5D 	135 	&#93; 	]
94 	5E 	136 	&#94; 	^
95 	5F 	137 	&#95; 	_
96 	60 	140 	&#96; 	`
97 	61 	141 	&#97; 	a
98 	62 	142 	&#98; 	b
99 	63 	143 	&#99; 	c
100 	64 	144 	&#100; 	d
101 	65 	145 	&#101; 	e
102 	66 	146 	&#102; 	f
103 	67 	147 	&#103; 	g
104 	68 	150 	&#104; 	h
105 	69 	151 	&#105; 	i
106 	6A 	152 	&#106; 	j
107 	6B 	153 	&#107; 	k
108 	6C 	154 	&#108; 	l
109 	6D 	155 	&#109; 	m
110 	6E 	156 	&#110; 	n
111 	6F 	157 	&#111; 	o
112 	70 	160 	&#112; 	p
113 	71 	161 	&#113; 	q
114 	72 	162 	&#114; 	r
115 	73 	163 	&#115; 	s
116 	74 	164 	&#116; 	t
117 	75 	165 	&#117; 	u
118 	76 	166 	&#118; 	v
119 	77 	167 	&#119; 	w
120 	78 	170 	&#120; 	x
121 	79 	171 	&#121; 	y
122 	7A 	172 	&#122; 	z
123 	7B 	173 	&#123; 	{
124 	7C 	174 	&#124; 	|
125 	7D 	175 	&#125; 	}
126 	7E 	176 	&#126; 	~
127 	7F 	177 	&#127; 	DEL
```
