#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    int i;
    int t,x;
    int zero=0;
    int one=0;
    cin>>n;
    cin>>q;

    int array[n];

    for(i=0;i<n;i++){
        cin>>array[i];
        if(array[i]==0){
            zero++;
        } else {
            one++;
        }
    }

    for(i=0;i<q;i++){
        cin>>t;
        cin>>x;
        if(t==1){
            x--;
            if(array[x]==0){
                zero--;
                one++;
            } else{
                zero++;
                one--;
            }
            array[x]=1-array[x];
        } else {
            if(x<=one){
                cout<<1<<endl;
            } else{
                cout<<0<<endl;
            }
        }
    }


    return 0;
}
