#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char> stack;
    string s;
    short int c=0,o=0;

    // Read string
    cin>>s;

    for(long unsigned int i=0;i < s.length(); i++){
        stack.push(s[i]);
    }

    while (!stack.empty()) {
        if(stack.top() == ')'){
            c++;
        } else {
            o++;
        }
        stack.pop();
        if(o>c){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    

    if(c==o){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}
