#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    
    vector<string> v;

    // Lee contraseñas
    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        v.push_back(s);
    }

    // Lee contraseña buena
    string p;
    cin>>p;
    long unsigned int l = p.size();

    // Calcula tiempo maximo
    int cont=0;
    for(long unsigned int i=0; i<v.size();i++){
        if(v[i].size() <= l){
            cont ++;
        }
    }

    int max = cont + ( floor((cont-1)/k) * 5 );
    
    // Calcula tiempo minimo
    cont=0;
    for(long unsigned int i=0; i<v.size();i++){
        if(v[i].size() < l){
            cont ++;
        }
    }

    int min = cont + ( floor(cont/k) * 5 ) + 1;

    cout<<min<<" "<<max<<endl;

    return 0;
}
