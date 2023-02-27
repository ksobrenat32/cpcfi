#include <iostream>

using namespace std;

int main(){
    // number
    string n;
    cin>>n;
    int wl = n.length();
    int count=0;

    for(int i=0;i<wl;i++){
        if(n[i] == '7' || n[i] == '4'){
            count++;
        }
    }

    if(count == 7 || count == 4){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }

    return 0;
}
