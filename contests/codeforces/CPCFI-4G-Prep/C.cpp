#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://codeforces.com/problemset/problem/208/A

int main(){
    string s,r;
    cin >> s;

    for(int i = 0; i < int(s.size()); i++){
        if(s.substr(i,3) == "WUB"){
            i+=2;
            if( r.empty() ){
                continue;
            }
            if(r[r.size()-1] == ' '){
                continue;
            }
            r += ' ';
        } else {
            r += s[i];
        }
    }

    cout << r << endl;
    return 0;
}