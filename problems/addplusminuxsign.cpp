// Codeforces link:
// https://codeforces.com/problemset/problem/1774/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    // Received string    
    string s;
    cin>>s;

    // Counter
    // 48 is 0 & 49 is 1
    int c=s[0]-48;
    
    for(int i=1;i<n;i++){
        if(c>0 && s[i]-48==1){
            cout<<"-";
            c--;
        } else {
            cout<<"+";
            c = c + s[i]-48;
        }
    }
    cout<<endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
