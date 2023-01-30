#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;

    int zero=0,one=0,min=0;

    for(auto c : s){
        if(c=='1'){
            one++;
        } else {
            zero++;
        }
    }

    if(one>=zero){
        min=zero;
    } else {
        min=one;
    }

    if(min%2==0){
        cout<<"NET"<<endl;
    } else {
        cout<<"DA"<<endl;
    }

}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
