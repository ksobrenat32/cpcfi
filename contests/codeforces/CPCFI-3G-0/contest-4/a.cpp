#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<long long> ar(n),di(n),dd(n);

    // leer arreglo 
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    // Calcular daños izquierda
    for(int i=1;i<n;i++){
        if(ar[i-1]>ar[i]){
            di[i] = ar[i-1]-ar[i]; 
        }
        di[i] += di[i-1];
    }

    // Calcular daños derecha
    
    reverse(ar.begin(),ar.end());

    for(int i=1;i<n;i++){
        if(ar[i-1]>ar[i]){
            dd[i] = ar[i-1]-ar[i]; 
        }
        dd[i] += dd[i-1];
    }

    reverse(dd.begin(),dd.end());

    for(int i=0;i<m;i++){
        long long int s,t;
        cin>>s>>t;

        s--;
        t--;

        if(s<t){
            cout<<abs(di[s]-di[t])<<endl;
        } else {
            cout<<abs(dd[s]-dd[t])<<endl;
        }
    }

    return 0;
}
