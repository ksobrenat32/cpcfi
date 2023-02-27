#include <bits/stdc++.h>
#include <cmath>
#include <ostream>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        int ta;
        int zero=0;
        int one=0;
        int two=0;

        for(int i=0;i<n;i++){
            cin>>ta;
            ta = ta%3;
            if(ta==1){
                one++;
            } else if (ta==2) {
                two++;
            } else {
                zero++;
            }

        }

        int m = min(one,two);
        zero =  zero + m;
        one = one - m;
        two = two - m;
        
        zero = zero + floor(one/3) + floor(two/3);

        cout<<zero<<endl;

    }

    return 0;
}
