#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    string abc="abcdefghijklmnopqrstuvwxyz";

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int l=0,x=0;

        for(char& c : s){
            l = abc.find(c);
            if(l>=x){
                x=l;
            }
        }
        cout<<x+1<<endl;

    }

    return 0;
}

