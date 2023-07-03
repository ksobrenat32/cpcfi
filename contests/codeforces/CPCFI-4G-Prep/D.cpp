#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://codeforces.com/problemset/problem/118/A

int main(){
    string s,r;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(char& c : s){
        switch (c) {
            case 'a':
                break;
            case 'e':
                break;
            case 'i':
                break;
            case 'o':
                break;
            case 'u':
                break;
            case 'y':
                break;
            default:
                r+='.';
                r+=c;
        }
    }

    cout<<r<<endl;

    return 0;
}