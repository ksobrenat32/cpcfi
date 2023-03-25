// Wrong answer

#include <bits/stdc++.h>

using namespace std;

void solve(){
    long n, x=0, o=0;
    cin>>n;
    string s;
    cin>>s;
    long si=s.size();
    for(long i=0; i<3; i++){
        if(s[i]=='X'){
            x++;
        }else{
            o++;
        }
    }

    long cnt = 0, cntM = 0,tot;
    if(x>o){
        //Find X
        for(long i=0; i<si; i++){
            if(s[i]!='X'){
                cnt=i+1;
                cntM = cnt/3;
                i=si;
            }
        }
        tot=(si-cnt)/3;
    }else{
        //Find O
        for(long i=0; i<si; i++){
            if(s[i]!='O'){
                cnt=i+1;
                cntM = cnt/3;
                i=si;
            }
        }
        tot=(si-cnt)/3;
    }
    cout<<max(tot,cntM)<<endl;

    return;
}


int main(){
    solve();
    return 0;
}