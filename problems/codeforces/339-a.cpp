// Codeforces link:
// https://codeforces.com/problemset/problem/339/A

#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <string>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

int c[3]={0,0,0};

void ct(string i){
    if(i=="1"){
        c[0]++;
    }
    if(i=="2"){
        c[1]++;
    }
    if(i=="3"){
        c[2]++;
    }
}

inline void solve(){
    string s,r;
    size_t p=0;
    string t;

    cin>>s;

    // Contar
    while ((p = s.find("+")) != string::npos ) {
        t = s.substr(0,p);
        ct(t);
        s.erase(0,p+1);
    }
    ct(s);

    // Print ones
    FO(i,c[0]){
        r.append("1+");
    }
    // Print two
    FO(i,c[1]){
        r.append("2+");
    }
    // Print three
    FO(i,c[2]){
        r.append("3+");
    }
    r.pop_back();
    cout<<r<<endl;

}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
