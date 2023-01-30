#include <iostream>
#include <iterator>

using namespace std;

int main(){
    int i,n;
    cin>>n;

    for(i=0;i<n;i++){
        string word;
        cin>>word;
        int wsize=word.length();

        if(wsize > 10){
            char fch = word[0];
            char lch = word[wsize - 1 ];
            cout<<fch<<wsize-2<<lch<<endl;
        } else {
            cout<<word<<endl;
        }

    }
    return 0;
}
