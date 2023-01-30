#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,n,temp;
    cin>>n;

    if(n%2!=0){
        cout<<"0"<<endl;
        return 0;
    }

    temp=2;
    n=n/2;

    for(i=1;i<n;i++){
        temp=temp*2;
    }

    cout<<temp<<endl;

    return 0;
}
