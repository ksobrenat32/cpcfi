#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s,t;
    cin>>s>>t;

    long unsigned int i;

    long long res=1;

    int f=t.find('a'); 

    // Si en t hay una a no se agregan valores, se cambia por el mismo
    if(t=="a"){
        res=1;
    // Si hay mas de 2 a, será infinito
    } else if(f!=-1){
        res=-1;
    } else {
        // Hacer la potencia de 2 siendo el exponente el tamaño
        for(i=0;i<s.size();i++){
            res = res * 2;
        }
    }
    cout<<res<<endl;
}

int main(){
    int q;
    cin>>q;

    while(q--){
        solve();
    }

    return 0;
}

