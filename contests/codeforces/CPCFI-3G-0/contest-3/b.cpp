#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int size = s.size();

        if(size%2 == 0){
            string a = s.substr(0,size/2);
            string b = s.substr(size/2,size);
            if(a==b){
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

