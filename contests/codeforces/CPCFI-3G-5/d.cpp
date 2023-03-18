// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/433780/problem/D

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long n; cin >> n;
    vector<long long> a(n);

    int val=0;

    FO(j,n){
        cin >> a[j];
    }

    // No duplicates
    long long t = a[0];
    vector<long long> v;
    v.push_back(t);
    FO(j,n){
        if(a[j] != t){
            v.push_back(a[j]);
        }
        t = a[j];
    }

    long ssize = v.size();

    for(long i=0; i < ssize; i++){
        if( (i == 0) && (v[i] < v[i+1]) ){
            val++;
        } else if( (i == (ssize-1)) && (v[i-1] > v[i]) ){
            val++;
        } else if(v[i-1] > v[i] && v[i] < v[i+1]){
            val++;
        }
    }

    if(val > 1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}