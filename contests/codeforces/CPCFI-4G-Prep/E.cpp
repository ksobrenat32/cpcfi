#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://codeforces.com/problemset/problem/71/A

int main(){
    int n;
    cin >> n;
    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        if( s.size() > 10 ){
            cout << s[0];
            cout << s.size()-2;
            cout << s[s.size()-1];
            cout << endl;
        } else {
            cout << s << endl;
        }
    }

    return 0;
}