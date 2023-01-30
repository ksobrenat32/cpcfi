#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string sa,sb;
        // Obtain 2 string 
        cin>>sa>>sb;

        // Contador
        int ca=0,cb=0;

        for(char& c : sa){
            if(c=='M'){
                ca=0;
            } else if(c=='S'){
                ca--;
            } else if(c=='L'){
                ca++;
            } else if (c=='X') {
                if(sa[sa.length()-1]=='S'){
                    ca--;
                } else if(sa[sa.length()-1]=='L'){
                    ca++;
                }
            }
        }

        for(char& c : sb){
            if(c=='M'){
                cb=0;
            } else if(c=='S'){
                cb--;
            } else if(c=='L'){
                cb++;
            } else if (c=='X') {
                if(sb[sb.length()-1]=='S'){
                    cb--;
                } else if(sa[sa.length()-1]=='L'){
                    cb++;
                }
            }
        }

        if(ca==cb){
            cout<<'='<<endl;
        } else if(ca>cb){
            cout<<'>'<<endl;
        } else {
            cout<<'<'<<endl;
        }

    }

    return 0;
}

