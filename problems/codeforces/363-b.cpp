// Problem link:
// https://codeforces.com/problemset/problem/363/b

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long n,k;
    cin >> n >> k;

    vector<int> v(n);
    FO(i,n){
        cin >> v[i];
    }

    // postion / value
    long long a[2];
    int t=0;

    // First value
    for(int j = 0; j < k; j++){
        t += v[j];
    }
    a[0] = 1;
    a[1] = t;

    // everything else
    for(int i = 1; i < (n-k)+1; i++){
        t -= v[i-1] ;
        t += v[i+(k-1)];

        if( t < a[1]){
            a[0] = i+1;
            a[1] = t;
        }
    }

    cout << a[0] << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}