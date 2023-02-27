#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t,count=0;
    int a,b,c,d;
    cin>>t;
 
    for(int i=0;i<t;i++){
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>d;

        if(a<b){
            count++;
        }
        if(a<c){
            count++;
        }
        if(a<d){
            count++;
        }
        cout<<count<<endl;
        count=0;
    }
    return 0;
}
