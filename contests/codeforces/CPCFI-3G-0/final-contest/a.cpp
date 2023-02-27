#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        int c;
        int one=0;
        int two=0;
        int w=0;
        
        int a=0;
        int b=0;

        for(int i=0;i<n;i++){
            cin>>c;
            if(c==1){
                one++;
                w++;
            } else {
                two++;
                w=w+2;
            }
        }


        for(int i=0;i<two;i++){
            if(a==min(a,b)){
                a=a+2;
            } else {
                b=b+2;
            }
        }
        for(int i=0;i<one;i++){
            if(a==min(a,b)){
                a++;
            } else {
                b++;
            }
        }

        if(a==b){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
