#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int ax,ay;
    cin>>ax>>ay;

    int bx,by;
    cin>>bx>>by;

    int cx,cy;
    cin>>cx>>cy;

    if(min(cx,bx)<ax && ax<max(cx,bx)){
        cout<<"NO"<<endl;
        return 0;
    }

    if(min(cy,by)<ay && ay<max(cy,by)){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    return 0;
}
