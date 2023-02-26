// Codeforces link:
// https://codeforces.com/problemset/problem/486/A

#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long n;
    cin>>n;

    if(n%2 == 0){
        cout<<(n/2)<<endl;
    } else {
        cout<<(n/2)-n<<endl;
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
