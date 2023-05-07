// Problem link:
//https://codeforces.com/contest/472/problem/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

bool prime(int x){
    if(x%2 == 0){
        return false;
    } else {
        for(int i=3; i*i <=x; i+=2){
            if((x%i)==0){
                return false;
            }
        }
    }
    return true;
}

inline void solve(){
    int n; cin >> n;
    
    // Try half
    if ( n%2 == 0 ){
        if( ! prime(n/2)){
            cout << n/2 << ' ' << n/2 << endl;
            return;
        }
    }

    int x,y;

    for(x = 4; x < n; x++){
        if(prime(x)){
            continue;
        }

        y = n - x;
        if( !prime(y) && !prime(x)){
            cout << x << ' ' << y << endl;
            return;
        }
    }
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
