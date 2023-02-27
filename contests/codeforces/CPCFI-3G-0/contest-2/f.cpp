#include <bits/stdc++.h>

using namespace std;

int main(){
    int na,nb;
    cin>>na>>nb;

    int k,m;
    cin>>k>>m;

    int arrA[na];
    int arrB[nb];

    int i;

    for(i=0;i<na;i++){
        cin>>arrA[i];
    }

    for(i=0;i<nb;i++){
        cin>>arrB[i];
    }

    if(arrA[k-1]<arrB[nb-m]){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}
