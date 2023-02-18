// Codeforces link:
// https://codeforces.com/group/qhNeDJ317x/contest/428227/problem/C
 
#include <bits/stdc++.h>
using namespace std;
 
#define FO(i, b)  for (int i = 0; i < (b); i++)
 
inline void solve(){
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    // Counter
    int c=0;
 
    FO(i,n/2){
        if ( s[i] == '0' && s[n-i-1] == '1'){
            c++;
        } else if ( s[i] == '1' && s[n-i-1] == '0'){
            c++;
        } else {
            break;
        }
    }
 
    cout << n - (c*2) << endl;
}
 
int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
