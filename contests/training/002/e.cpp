#include <bits/stdc++.h>

using namespace std;

#define ll long long


vector<ll> trialDivision(ll n){
    vector<ll> fact;
    while(n%2 == 0){
        fact.push_back(2);
        n/=2;
    }

    for(ll d = 3; d*d <=n; d+=2){
        while(n%d == 0){
            fact.push_back(d);
            n/=d;
        }
    }

    if(n>1) fact.push_back(n);
    return fact;
}


inline void solve(){
    ll n; cin>>n;
    vector<ll> arns = trialDivision(n);


    string arns_modo_sexo = "";
    for(int i=0; i<arns.size(); i++){
        arns_modo_sexo+=to_string(arns[i]);
        arns_modo_sexo+="x";
    }
    arns_modo_sexo.pop_back();
    cout<<arns_modo_sexo<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}