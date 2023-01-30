#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;

    short int l = s.size();

    if(s[0]!=s[l-1]){
        if(s[0]=='a'){
            s[l-1]='a';
        } else {
            s[l-1]='b';
        }
    }

    // Imprimir string
    cout<<s<<endl;
}

int main(){
    short int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}

