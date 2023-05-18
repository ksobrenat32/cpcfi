// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/444333/problem/A
// easy pisy

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    short int n;
    cin >> n;

    // Save
    int x[n];
    int p;
    bool even;

    // Read
    FO(i,n){
        cin >> x[i];
    }

    // Check the condition
    if( ( x[0]%2 == 0 && x[1]%2 == 0 ) || ( x[1]%2 == 0 && x[2]%2 == 0) || ( x[0]%2 == 0 && x[2]%2 == 0) ){
        even=true;
    } else {
        even=false;
    }

    FO(i,n){
        if(even){
            if( x[i]%2 != 0){
                p = i;
            }
        } else {
            if( x[i]%2 == 0){
                p = i;
            }
        }
    }
    
    cout << p+1 << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
