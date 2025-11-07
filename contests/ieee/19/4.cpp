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
const ll MOD = 1e9 + 7;

// https://www.geeksforgeeks.org/dsa/generate-unique-partitions-of-an-integer/

void printArray(int p[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    cout << p[i] << " "; 
    cout << endl; 
} 

void printAllUniqueParts(int n) 
{ 
    int p[n];
    int k = 0;
    p[k] = n;

    while (true) 
    { 
        printArray(p, k+1); 

        int rem_val = 0; 
        while (k >= 0 && p[k] == 1) 
        { 
            rem_val += p[k]; 
            k--; 
        } 

        if (k < 0) return; 

        p[k]--; 
        rem_val++; 


        while (rem_val > p[k]) { 
            p[k+1] = p[k]; 
            rem_val = rem_val - p[k]; 
            k++; 
        } 

        p[k+1] = rem_val; 
        k++; 
    } 
} 

inline void solve(){
    int m; cin >> m;

    for(int i = 1; i<=m; i++){
        printAllUniqueParts(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
