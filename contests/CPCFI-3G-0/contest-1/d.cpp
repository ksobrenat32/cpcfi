#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    short int t,i;
    cin>>t;

    for(i=0;i<t;i++){
        short int s,i;
        cin>>s;
        string r;

        for(i=9;i>=0;i--){
            if(s<10 && s<i){
                break;
            }
            s = s - i;
            if(i!=0){
                r = to_string(i) + r;
            }
        } 
        if(s==0){
            cout<<r<<endl;
        } else{
            cout<<s<<r<<endl;
        }
    }
    return 0;
}
